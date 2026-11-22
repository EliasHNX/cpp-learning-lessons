# Progress and practice checks

## Implemented examples

- Store/product classes: lookup, unique IDs, validation and removal.
- Character damage/healing and finite-reserve gun logic.
- Exclusive ownership, moving, borrowing and visible destruction.
- Distinct-value search, candidate tracking and empty-input handling.
- Count/sum helpers and inclusive/outside range predicates.
- Threshold streak lengths, number of streaks, and increasing runs.
- Equal-value pair counting without self/reversed pairs.
- Enum-driven actions and an interactive persistent-state menu.
- Recovery from nonnumeric input and end-of-input handling.

## Useful tests

| Exercise | Input / operation | Expected result |
|---|---|---|
| Equal pairs | `{4,2,4,4,2}` | 4 |
| Equal pairs | `{7,7,7}` / `{1,2,3}` | 3 / 0 |
| Distinct search | All equal / empty | No second distinct value / no numbers |
| Count and sum above | `{-8,-3,-5}`, threshold -6 | 2 / -8 |
| Count inside and outside | `{-7,-6,-5,-3,0}`, bounds -6 to -3 | 3 / 2 |
| Range count | `{-8,-3,-5}`, bounds -5 to -5 | 1 |
| Threshold longest run | `{6,8,9,1,7}`, threshold 5 | 3 |
| Threshold longest run | `{6,5,7}`, threshold 5 | 1 |
| Run count | `{6,8,2,9,7,10}`, threshold 5 | 2 |
| Increasing longest run | `{2,4,1,3,5,7,2}` | 4 |
| Increasing longest run | Empty / singleton / all equal | 0 / 1 / 1 |
| Reload | Loaded 3, capacity 6, reserve 6 | Loaded 6, reserve 3 |
| Reload | Loaded 2, capacity 6, reserve 1 | Loaded 3, reserve 0 |
| Interactive menu | `hello`, Shoot, Inspect, Quit | Recover, loaded 2, preserve 2, exit |

Some tests were explored during lessons; this table also includes follow-up cases. It is a practice checklist, not a claim of automated coverage for every row.

## Review skills

Practice variable scope, correct loop indices, safe neighboring access, argument lists, return placement, assignment direction, nested condition flow, and preserving resources during transfers. Read compiler diagnostics before changing code. Explain why a method works and test a new case before treating it as retained knowledge.
