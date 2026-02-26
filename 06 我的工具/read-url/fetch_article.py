#!/usr/bin/env python3
"""Playwright-based article fetcher with WeChat MP support."""

import json
import sys

from playwright.sync_api import sync_playwright
from bs4 import BeautifulSoup


def block_resources(route):
    if route.request.resource_type in ("image", "media", "font"):
        route.abort()
    else:
        route.fallback()


def parse_wechat(soup):
    title_el = soup.select_one("#activity-name")
    content_el = soup.select_one("#js_content")
    time_el = soup.select_one("#publish_time")
    author_el = soup.select_one("#js_author_name")

    if not content_el:
        return None

    return {
        "title": title_el.get_text(strip=True) if title_el else "",
        "author": author_el.get_text(strip=True) if author_el else "",
        "publish_time": time_el.get_text(strip=True) if time_el else "",
        "content": content_el.get_text("\n", strip=True),
    }


def parse_generic(soup):
    article = soup.select_one("article")
    if article:
        body = article
    else:
        body = soup.select_one("body") or soup
    title_el = soup.select_one("title")
    return {
        "title": title_el.get_text(strip=True) if title_el else "",
        "author": "",
        "publish_time": "",
        "content": body.get_text("\n", strip=True),
    }


def fetch(url):
    with sync_playwright() as p:
        browser = p.chromium.launch(
            headless=True,
            args=["--disable-blink-features=AutomationControlled"],
        )
        context = browser.new_context(
            user_agent="Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) "
            "AppleWebKit/537.36 (KHTML, like Gecko) "
            "Chrome/125.0.0.0 Safari/537.36"
        )
        page = context.new_page()
        page.route("**/*", block_resources)

        try:
            page.goto(url, wait_until="networkidle", timeout=30000)
        except Exception as e:
            browser.close()
            return {"success": False, "error": f"Page load failed: {e}"}

        html = page.content()
        browser.close()

    soup = BeautifulSoup(html, "html.parser")

    is_wechat = "mp.weixin.qq.com" in url
    result = parse_wechat(soup) if is_wechat else None
    if not result:
        result = parse_generic(soup)

    result["success"] = bool(result.get("content"))
    if not result["success"]:
        result["error"] = "No content extracted"
    return result


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(json.dumps({"success": False, "error": "Usage: fetch_article.py <url>"}))
        sys.exit(1)

    output = fetch(sys.argv[1])
    print(json.dumps(output, ensure_ascii=False))
