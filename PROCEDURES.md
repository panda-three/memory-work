---
title: PROCEDURES.md
type: procedural-memory
version: 1.0
priority: 0
description: |
  Procedural memory (Layer 3).
  Records user's action patterns in specific contexts—not "what they know" but "how they do it."
  Each memory is a "context→action sequence" pair, extracted from actual behavior.
  When AI recognizes matching context, it can proactively suggest the process.
created: 2026-02-09
---

# PROCEDURES.md

> Procedural memory: your pattern library for how you act in specific contexts.

---

## Usage Guide

### Relationship with Other Memory Layers

| Layer | Records | Example |
|-------|---------|---------|
| Layer 0 Persistent | Who you are | "I am an AI prompt engineer" |
| Layer 2 Dynamic | What you know, what you judged | "Core products can't rely on external teams" |
| **Layer 3 Procedural** | **How you do things when X happens** | **"Before external negotiation, establish internal consensus"** |

### Write Conditions

- Same behavioral pattern appears **2+ times** in different events
- Extracted from actual behavior in _this_week.md, not preset
- User confirms before writing

### Entry Format

```
## [Pattern Name]
- **trigger**: What context triggers this pattern
- **pattern**: Action sequence (in order)
- **evidence**: Which actual events was this extracted from
- **exception**: Known exception cases
- **confidence**: Low/Medium/High (increases with verification count)
```

### Invocation Method

When AI detects current task matches a trigger, proactively prompt:
> "This scenario matches your [Pattern Name] pattern. Following previous approach, next step is [specific step]. Want to proceed with this rhythm?"

---

## Example Procedures

### Example: Week Startup Process
- **trigger**: Start of each week (Sunday or Monday)
- **pattern**:
  1. User dictates what they want to do this week
  2. AI breaks down into specific tasks, confirms uncertainties with user
  3. AI searches entire vault for relevant materials
  4. User provides confirmed time points
  5. AI schedules, generates wiki-links, generates .ics calendar file
  6. User confirms tasks and schedule
- **evidence**: W05 week startup, W06 week startup
- **exception**: If last week has many unfinished tasks, inherit first then start
- **confidence**: High (2 complete cases, stable process formed)

### Example: Week-End Archiving
- **trigger**: End of week (Friday or Sunday)
- **pattern**:
  1. User confirms this week's outputs
  2. AI lists items to be archived
  3. User confirms archiving locations
  4. AI moves documents to corresponding locations in vault
  5. User participates in memory calibration
  6. AI executes memory-review: shows memory operation list, chats about whether it helped
  7. AI writes review results to MEMORY_LOG.md, updates MEMORY.md / PROCEDURES.md
  8. AI moves `_this_week.md` to `_archive/`, creates new week (inherits unfinished tasks + iteration actions)
- **evidence**: Multiple week archiving cycles
- **exception**: None
- **confidence**: High

---

## Add Your Own Procedures

As you use this system, AI will identify your recurring patterns and propose adding them here.
Each procedure makes AI better understand your work rhythm and proactively support you.

---

## Version History

| Date | Version | Changes |
|------|---------|---------|
| 2026-02-09 | v1.0 | Initial version for open-source Memory Work project with example procedures |
