# Original C programmer habits

Unlike `agbcc-quirks.md` (what the *compiler* does to any equivalent C —
deterministic, true every time), this file is about what the *original
developers* tended to write: their style, when there's a choice of several
C shapes that all compile to the same bytes. This is statistical, not
deterministic, so **frequency is the whole point** — a habit seen once is
a coincidence, a habit seen many times is something to default to.

## Entry format

```
### <habit name>
- **Frequency**: N functions
- **Seen in**: FuncA (file), FuncB (file), ...
- **Description**: what the pattern is and when it applies
```

Every time you spot a candidate habit (a stylistic choice, not a
compiler-forced one) in a function that just reached MATCHING:
1. Check `src/*.c` siblings to see if the same choice appears elsewhere.
2. If there's no entry for it yet and you've now seen it in 2+ places,
   add one with the functions found so far.
3. If an entry already exists and this function repeats it, **increment
   Frequency and append the function to Seen in** — don't just leave the
   count stale. The count is the evidence; keep it current.
4. A single occurrence isn't worth an entry yet — note it mentally and
   check again next time a similar function comes up, but don't record
   n=1 here (it'd just be noise to re-verify later).

## Observed so far

*(none confirmed yet — add findings here as they're corroborated across
multiple matched functions, not from a single instance)*
