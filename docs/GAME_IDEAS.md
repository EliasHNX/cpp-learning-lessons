# Future 2D game ideas

Build a graphical 2D game in small playable increments while continuing to learn C++.

Start with one character in one test area: walking, jumping, sprinting, collision and a useful camera. Longer-term ideas include coherent graphics, three to five locations, enemy behavior, NPC conversations, damage and death, inventory, save/load and settings. These are evolving feature ideas, not a release deadline.

Normal classes can hold character or weapon state and behavior. Enum classes can name actions or states such as Shoot/Reload/Inspect or Idle/Running/Hurt/Dead. An action value selects behavior; a state can determine whether that behavior is allowed.

Godot with C++ is one possible implementation route. Engine setup, game style and final tooling are separate future decisions. Save/load should be designed around the actual progress implemented: for example player state, inventory, location progress and relevant conversation flags.

Keep a playable version working, test small changes, and alternate features with debugging and C++ understanding. A day spent fixing a bug or understanding existing code also contributes to the project.
