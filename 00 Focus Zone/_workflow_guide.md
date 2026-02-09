# Focus Zone Workflow Guide

**You are helping the user manage their high-efficiency weekly focus zone.**

## Core Concept

This is an **attention-focusing workspace** that operates on a weekly cycle. Its purpose is to:
- Let you focus on what's truly important right now
- You provide attention focus and creative decisions
- Claude integrates vault-wide information, matches relevant materials, organizes work materials

---

## File Structure

```
00 Focus Zone/
├── _this_week.md            ← Current work file (always this name)
├── _template_this_week.md   ← Week file template
├── _alias_map.md            ← Mapping colloquial names to formal names
├── _workflow_guide.md       ← This file
├── _archive/                ← Completed week records
│   ├── 2026-W04.md
│   └── ...
├── {{year}}-W{{week}}_schedule.ics  ← Current week calendar (double-click to import to Mac Calendar)
└── [This week's temporary documents]
```

---

## Week File Structure

Each week file contains five sections:

### 1. Original Dictation
Records your raw expression in flow state, keeping the authentic flavor of your thinking.

### 2. Task List
Claude converts dictation into specific executable tasks, confirms uncertainties with you.

### 3. Reference Materials
Claude searches the entire vault for materials relevant to this week's tasks, copies key excerpts here, notes source paths.

### 4. Progress Log
Records progress by date, new ideas, adjustment decisions.

### 5. To Be Archived
At week's end when organizing, mark outputs to be archived back to other vault locations.

---

## Collaboration Workflow

### Monday (or cycle start)
1. You dictate what you want to do this week
2. Claude converts to task list
3. Claude searches vault, pulls relevant materials

### Mid-week
1. You push tasks forward, add ideas anytime
2. Claude helps organize progress log
3. When new needs arise, Claude continues searching and adding materials

### Weekend (or cycle end)
1. Review this week's progress
2. Archive outputs to corresponding vault locations
3. **Execute memory-review (memory calibration)**: Agent shows user this week's memory operation list, calibrates memory strategy through interview, writes results to `MEMORY_LOG.md`
4. Rename `_this_week.md` to `2026-WXX.md` and move to `_archive/`
5. Create new `_this_week.md` to start next cycle (inherit unfinished tasks + memory iteration actions)

---

## Search Scope

Claude will search for relevant materials in the following locations:

| Folder | Content Type |
|--------|--------------|
| 01 Materials | Personal archives, methodology, reading notes |
| 02 Tools | Prompt templates, analysis tools |
| 06 Skills | Custom skills |
| MEMORY.md | Long-term dynamic memory (Layer 2) |
| PROCEDURES.md | Procedural memory (Layer 3) |

---

## Usage Example

**Your dictation:**
> This week I want to organize the documentation, it was too scattered before. Also need to prepare for Wednesday's client meeting with demo plan.

**Claude's processing:**
1. Breaks down into two tasks: documentation organization, client meeting prep
2. Searches relevant existing documentation
3. Searches for related project background
4. Excerpts key content to reference materials section
5. Confirms uncertainties with you

---

## Three-Phase Workflow

### Phase 1: Week Startup (Sunday/Monday)

| Step | You Do | Claude Does |
|------|--------|-------------|
| 1 | Dictate what you want to do this week | Convert to specific tasks, ask about uncertainties |
| 2 | Dictate confirmed time points | Search vault for relevant materials |
| 3 | Confirm tasks and schedule | Generate wiki-links, schedule, .ics calendar file |

### Phase 2: Mid-Week Progression

| Step | You Do | Claude Does |
|------|--------|-------------|
| 1 | Add progress/ideas anytime | Update progress log |
| 2 | Request new materials | Continue searching, generating documents |
| 3 | Face uncertain decisions | Provide relevant information to aid decision |

### Phase 3: Weekend Archiving

| Step | You Do | Claude Does |
|------|--------|-------------|
| 1 | Confirm this week's outputs | List items to be archived |
| 2 | Confirm archiving locations | Move documents to corresponding vault locations |
| 3 | Give feedback on agent's memory operations | ★ Execute memory-review: Show memory operation list, calibrate memory strategy |
| 4 | — | Write review results to `MEMORY_LOG.md`, update MEMORY.md / PROCEDURES.md |
| 5 | — | Move `_this_week.md` to `_archive/`, create new week (inherit iteration actions) |

---

## Alias Mapping

When dictating, you can use any names you're comfortable with; Claude will reference [[_alias_map]] for matching.

Common mappings:
- [Colloquial name] → [Formal name]
- [Nickname] → [Official name]

---

## Calendar Sync

Each week generates a `.ics` file (like `2026-W05_schedule.ics`):
1. Find the file in Finder
2. Double-click to open
3. Mac Calendar will automatically pop up import prompt
4. Confirm import
