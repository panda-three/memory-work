# Quick Start Guide

Get Memory Work up and running in 15 minutes.

---

## Prerequisites

Before you start, make sure you have:

- [ ] **Obsidian** installed ([download here](https://obsidian.md))
- [ ] **Claude Desktop** or **Claude Code** access
- [ ] Basic familiarity with Markdown

---

## Step 1: Get the Files

### Option A: Clone with Git

```bash
git clone https://github.com/yourusername/memory-work.git
cd memory-work
```

### Option B: Download ZIP

1. Go to the [GitHub repo](https://github.com/yourusername/memory-work)
2. Click "Code" → "Download ZIP"
3. Extract to your preferred location

---

## Step 2: Open in Obsidian

1. Launch Obsidian
2. Click "Open folder as vault"
3. Navigate to and select the `memory-work` folder
4. Click "Trust" when prompted (this is your local vault)

---

## Step 3: Connect to Claude

### Using Claude Desktop

1. Open Claude Desktop
2. Go to Projects
3. Click "Create Project"
4. Name it "Memory Work"
5. Add the `memory-work` folder as project knowledge

### Using Claude Code (Cowork)

1. Open your IDE (VS Code, Cursor, etc.)
2. Open the `memory-work` folder
3. Start Claude Code
4. Claude will automatically have access to the vault

---

## Step 4: Customize Your Profile

### Edit USER.md

Open `USER.md` and fill in your information:

```markdown
**Name**: Your Name
**Profession**: Your Job Title
**Location**: Your City

### Current Roles
- Your Role 1 — Description
- Your Role 2 — Description

### Professional Domain
- Your skill 1
- Your skill 2
```

### Customize SOUL.md (Optional)

Want to change Claude's personality? Edit `SOUL.md` to adjust:
- Communication style
- Humor level
- Formality
- Boundaries

---

## Step 5: Start Your First Week

1. **Open the Focus Zone**
   - Navigate to `00 Focus Zone/_this_week.md`

2. **Talk to Claude**
   - Start a new conversation in Claude
   - Claude will automatically read the startup files

3. **Dictate Your Week**
   ```
   You: "This week I want to [describe your goals and tasks].
         I have a meeting on [day] about [topic].
         Also need to finish [project]."
   ```

4. **Claude Will:**
   - Break down your dictation into tasks
   - Search your vault for relevant materials
   - Create a schedule
   - Ask for clarifications

5. **Confirm and Go**
   - Review Claude's proposed structure
   - Make any adjustments
   - Start working!

---

## Step 6: Daily Usage

### During the Week

Just talk to Claude about your work:
- "How's that task going?"
- "Add this to the progress log"
- "Search for materials about [topic]"
- "Generate a report on [subject]"

Claude maintains context automatically.

### Recording Progress

Claude will ask if you want progress updates recorded. Example:

```
Claude: "Want me to add this to today's progress log?"
You: "Yes"
```

---

## Step 7: Week-End Review

### Friday (or end of your week)

1. **Start the review**
   ```
   You: "Let's do the week review"
   ```

2. **Memory calibration**
   Claude will show you:
   - What it remembered this week
   - What memories it activated
   - Proposals it made

   Then ask:
   - Were these memories helpful?
   - Should I remember this differently?
   - Anything I missed?

3. **Archive**
   ```
   You: "Archive this week"
   ```

   Claude will:
   - List outputs to archive
   - Confirm destinations
   - Move files
   - Create next week's file

---

## Tips for Success

### 1. Dictate Naturally

Don't try to structure your thoughts. Just say what's on your mind.

**Good:** "This week is about the client project, need to wrap that up, also that blog post thing"

**Less good:** "Task 1: Client project completion. Subtask 1.1: Review documentation..."

### 2. Use Aliases

Create shortcuts in `_alias_map.md`:

```
the project → [[03 Projects/Main Client Project]]
that client → Smith Corp
```

### 3. Trust the Memory System

Let Claude propose what to remember. You just confirm or decline.

### 4. Weekly Rhythm

The system works best with consistent weekly cycles:
- Monday: Start fresh
- Mid-week: Flow state
- Friday: Review and reset

---

## Common Questions

### "Do I need to set up everything perfectly first?"

No! Start with just `USER.md` customized. The system will grow with you.

### "What if I miss a week?"

No problem. Just start a new week when you're ready. Claude will continue from wherever you left off.

### "Can I use this without Obsidian?"

Yes, but you'll lose some features (graph view, wiki-links). Any Markdown editor works.

### "Will Claude forget things between conversations?"

Not with Memory Work. It reads the memory files every time you start a conversation.

---

## Next Steps

Once you're comfortable with the basics:

1. **Add your materials** to `01 Materials/`
2. **Create custom skills** in `06 Skills/`
3. **Explore zone agents** to understand fine-grained control
4. **Read the full documentation** in `/docs`

---

## Need Help?

- Check [docs/TROUBLESHOOTING.md](TROUBLESHOOTING.md)
- Open an issue on GitHub
- Join the community Discord (coming soon)

---

**You're ready to go!** 🎉

Open Claude, start your first week, and let Memory Work grow with you.
