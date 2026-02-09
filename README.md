# Memory Work

> An AI-first knowledge management system with evolvable memory

**Memory Work** is a framework for building a personal AI partner that truly knows you—not through training, but through a four-layer memory architecture that grows and adapts over time.

---

## What Is This?

Traditional AI assistants suffer from "amnesia"—every conversation starts from scratch. You spend time re-explaining context, repeating preferences, and manually feeding background information.

Memory Work solves this by giving Claude a **persistent, evolving memory system** that:

- **Remembers** your decisions, preferences, and work patterns
- **Learns** from surprises—when you act differently than expected
- **Adapts** through weekly calibration conversations
- **Scales** through divide-and-conquer zone architecture

---

## Core Features

### 🧠 Four-Layer Memory Architecture

```
Layer 0 · Persistent Memory   SOUL.md / USER.md          Identity-level, rarely changes
Layer 1 · Working Memory      _this_week.md              Weekly focus, append-only
Layer 2 · Dynamic Memory      MEMORY.md                  Has lifecycle, cross-week
Layer 3 · Procedural Memory   PROCEDURES.md              Context→Action patterns
```

### 🎯 Surprise-Driven Learning

Based on research from [Titans](https://arxiv.org/abs/2501.00663) and [MemSkill](https://arxiv.org/abs/2501.03313):

- AI detects "surprise"—deviations from established patterns
- High surprise → proposes writing to memory (with your confirmation)
- Low surprise → no noise, no clutter
- Weekly calibration → memory strength adjusts based on usefulness

### 📅 Week-Based Rhythm

- **Monday**: Dictate your week, AI structures it
- **Mid-week**: Work in flow, AI tracks progress
- **Friday**: Review & archive, memory calibration

### 🏛️ Zone Agent System

Each area of your knowledge base has its own "agent":
- **Focus Zone**: Weekly work rhythm
- **Materials**: Personal archives (high-sensitivity protection)
- **Tools**: Reusable templates
- **Skills**: Custom AI capabilities

### 🔧 Extensible Skills

Package your workflows as reusable skills:
```
06 Skills/
├── datetime-check/     ← Time calibration
├── ics-generator/      ← Calendar export
├── memory-review/      ← Memory calibration
└── your-skill/         ← Your custom skill
```

---

## Quick Start

### Prerequisites

- **Obsidian** (or any Markdown-based note-taking app)
- **Claude Desktop** with Projects or Claude Code (Cowork)
- Basic familiarity with Markdown

### Installation

1. **Clone or download this repo**
   ```bash
   git clone https://github.com/yourusername/memory-work.git
   cd memory-work
   ```

2. **Open in Obsidian**
   - Open Obsidian
   - "Open folder as vault"
   - Select the `memory-work` folder

3. **Configure for Claude**
   - If using Claude Desktop Projects: Add this folder as a project
   - If using Claude Code: Open this folder in your IDE

4. **Customize core files**
   - Edit `USER.md` with your information
   - Customize `SOUL.md` for Claude's personality
   - Review `AGENTS.md` behavioral rules

5. **Start your first week**
   - Open `00 Focus Zone/_this_week.md`
   - Start dictating what you want to do this week
   - Claude will structure it and pull relevant materials

---

## How It Works

### Session Startup (Automatic)

Every time Claude starts a conversation, it automatically:

1. Executes `datetime-check` (calibrates time)
2. Reads `SOUL.md` (who am I?)
3. Reads `USER.md` (who am I helping?)
4. Reads `_this_week.md` (what's the current focus?)
5. Reads `MEMORY_LOG.md` (memory system state)
6. Loads relevant memories from `MEMORY.md` and `PROCEDURES.md`

**You don't manually feed context. The system maintains it.**

### Memory Evolution

```
Conversation → Surprise Detection → Write Proposal → User Confirms → Memory Updated
                     ↓ (if not surprising)
                   Silent Pass
```

Every week:
```
Week Review → memory-review skill → Show operations → User feedback → Calibration
```

### Procedural Learning

When you do something the same way 2+ times:
```
Pattern Detected → Propose adding to PROCEDURES.md → User confirms → AI suggests it next time
```

---

## Architecture

```
memory-work/
├── AGENTS.md                   ← AI behavioral instructions
├── SOUL.md                     ← AI personality & relationship
├── USER.md                     ← Your profile (quick reference)
├── MEMORY.md                   ← Dynamic memory (Layer 2)
├── PROCEDURES.md               ← Procedural memory (Layer 3)
│
├── 00 Focus Zone/              ← Weekly work rhythm
│   ├── _this_week.md           ← Current week (Layer 1)
│   ├── _template_this_week.md
│   ├── _workflow_guide.md
│   ├── MEMORY_LOG.md           ← Memory system log
│   ├── ITERATION_LOG.md        ← Architecture evolution log
│   └── _archive/               ← Past weeks
│
├── 01 Materials/               ← Your personal archives
│   ├── About Me/               ← High-sensitivity profiles
│   ├── Methodology/
│   ├── Thinking/
│   └── ...
│
├── 02 Tools/                   ← Reusable templates
│
└── 06 Skills/                  ← Custom AI capabilities
    ├── datetime-check/
    ├── ics-generator/
    ├── memory-review/
    └── your-skill/
```

---

## Example Workflows

### Starting Your Week

```
You: "This week I want to finish the project proposal,
      prep for the client meeting on Wednesday,
      and write that blog post I've been putting off."

Claude:
1. Breaks down into tasks
2. Searches your vault for related materials
3. Generates schedule
4. Creates .ics calendar file
5. Asks you to confirm uncertainties
```

### Memory Calibration (Friday)

```
Claude: "Let's review this week's memory operations.
         I wrote 2 new entries, retrieved 3 existing ones.

         The 'project decision' entry I wrote—did that help you this week?
         Should I keep tracking your pattern of [X behavior]?
         Anything important I missed?"

You: [Provide feedback]

Claude: [Adjusts memory strength, surprise threshold, archives old memories]
        [Writes calibration results to MEMORY_LOG.md]
```

---

## Design Principles

### 1. Voice-First
Dictate naturally. Don't force yourself into structured input.

### 2. Surprise-Driven
Only write to memory when something deviates from established patterns. No noise.

### 3. User-Confirmed
AI never writes to long-term memory without your explicit confirmation.

### 4. Evolvable
Memory system has lifecycle. Strong memories persist, weak ones fade. Weekly calibration keeps it relevant.

### 5. Divide & Conquer
Each zone has its own agent with specific rules. System scales to any vault size.

---

## Inspiration

This system is built on insights from:

- **[Titans: Learning to Memorize at Test Time](https://arxiv.org/abs/2501.00663)** — Surprise-driven memory formation
- **[MemSkill: Transferrable and Evolvable Memory Skill Library](https://arxiv.org/abs/2501.03313)** — Skill-based memory patterns
- **Obsidian PKM best practices** — Markdown-first, local-first, link-first
- **Real-world usage** — Battle-tested in managing 10+ parallel projects

---

## Roadmap

- [ ] Skills marketplace (share and discover community skills)
- [ ] Memory visualization (graph view of memory activation patterns)
- [ ] Multi-language support (currently English-focused)
- [ ] Mobile companion app (quick dictation on the go)
- [ ] Advanced memory decay algorithms (more nuanced lifecycle management)

---

## Contributing

We welcome contributions! Whether it's:
- New skills to add to the library
- Improvements to the memory protocols
- Documentation enhancements
- Bug fixes

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

---

## License

MIT License - see [LICENSE](LICENSE) for details.

---

## Acknowledgments

Created by [Your Name] (@yourusername)

Based on the "Focus Zone" methodology developed through real-world practice managing AI consulting, product development, and teaching workflows.

Special thanks to:
- Anthropic team for Claude
- Obsidian team for the incredible PKM platform
- The AI research community for Titans and MemSkill papers

---

## Get Started

Ready to build your AI partner?

1. Clone this repo
2. Open in Obsidian
3. Customize `USER.md` and `SOUL.md`
4. Start your first week in `_this_week.md`

Your AI will learn about you with every conversation. Not through training—through collaboration.

---

**Questions? Ideas? Issues?**

- Open an issue on GitHub
- Join our Discord community (coming soon)
- Follow updates: [@yourusername](https://twitter.com/yourusername)
