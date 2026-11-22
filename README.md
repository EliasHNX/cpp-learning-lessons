# C++ lessons and practice

A collection of C++17 console exercises covering fundamentals, modern C++, problem solving, and small game-related systems. Examples were developed incrementally with coding assistance and are learning exercises rather than a finished game.

## Programs

Each source file is a separate program with its own `main()`. Compile one at a time.

| Program | Topics |
|---|---|
| [Store](lessons/store.cpp) | Classes, encapsulation, const getters, vectors, lookup, validation, removal |
| [Character and ownership](lessons/character_and_ownership.cpp) | Health, damage, references, constructors/destructors, `unique_ptr`, `make_unique`, `move`, borrowing, `reset`, finite-ammo reload |
| [Second-smallest distinct value](lessons/second_smallest.cpp) | Two-pass search, duplicate handling, empty input, candidate flags, compound predicates |
| [Number tools](lessons/number_tools.cpp) | Counting, summing, inclusive ranges, longest streaks, counting runs, neighboring values |
| [Equal pairs](lessons/equal_pairs.cpp) | Nested loops, distinct positions, avoiding reversed duplicate pairs |
| [Interactive game actions](lessons/game_actions.cpp) | `enum class`, keyboard menu, scope, persistent state, loop control, input failure recovery |

The distinct-value exercise began as a second-largest search and was adapted to second-smallest. Its current saved implementation finds second-smallest.

## Compile and run

Requires a C++17 compiler such as GCC, Clang, or an appropriately configured MSVC environment. For GCC, from this repository's root:

```sh
g++ -std=c++17 lessons/equal_pairs.cpp -o equal_pairs
```

Run with `./equal_pairs` on a Unix-like shell or `.\equal_pairs.exe` in Windows PowerShell. On Windows you can explicitly name the output `equal_pairs.exe` in the compile command.

For the interactive example:

```sh
g++ -std=c++17 lessons/game_actions.cpp -o game_actions
```

Enter `1` to shoot, `2` to reload, `3` to inspect, or `0` to quit. Invalid numbers redisplay the menu. Nonnumeric input is cleared and discarded through the next newline. End of input exits the loop. Ammo persists between actions during a run.

## Learning material

- [Lesson notes](docs/LESSONS.md): concepts, examples, and debugging lessons.
- [Learning roadmap](docs/ROADMAP.md): a flexible sequence of topics.
- [Progress and practice checks](docs/PROGRESS.md): implemented examples and useful follow-up tests.
- [Future 2D game](docs/GAME_IDEAS.md): a gradually built graphical project.

## Limits of these exercises

- Integers and sums are intended for small practice inputs; general large-input code should choose suitable numeric types and validate bounds.
- Equal-pair counting is quadratic and is intended for at most 2,000 elements in this exercise.
- Range helpers assume the lower bound is no greater than the upper bound.
- The menu reads formatted integers, not strictly validated entire lines: a numeric prefix such as `1abc` can first be read as `1`. Strict line parsing is a future exercise.
- Displaying health zero does not destroy a character object. Gameplay death and C++ object lifetime are separate concepts.
- The examples preserve the learning code, including simple formatting and diagnostic messages. They are not a complete engine integration or production architecture.
