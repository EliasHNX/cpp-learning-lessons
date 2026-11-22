# Lesson notes

## Classes and encapsulation

A class combines state with operations on that state. `Product`, `Store`, `Character`, and `Gun` illustrate private fields, public methods, constructors and const getters. Validation prevents invalid prices, negative damage and duplicate IDs. A container's current size and a separately maintained static counter represent different things; printing a counter does not update it.

## Copies, references and read-only borrowing

Passing a `Character` by value produces a separate object. Mutating that copy does not change the original. Passing `Character&` borrows the original and permits mutation. Passing `const Character&` borrows without allowing mutation through that reference. Likewise, `const vector<int>&` avoids copying a whole input vector for a read-only function.

Ordinary objects and references use dot access. Pointers, including `unique_ptr`, use arrow access. Dereferencing a pointer with `*` accesses its object, which can be passed to a reference parameter.

## Scope, lifetime and destructors

A local object is destroyed when its scope ends. Local variables in a scope are normally destroyed in reverse construction order. A destructor is named with a tilde followed by the class name, has no return type and takes no parameters. Destructor messages make lifetime visible; those messages do not themselves cause destruction. Member cleanup is automatic for the strings and value members used in these exercises.

Declaring a variable inside an `if` block hides that variable outside the block. If later code needs a selected action, declare the shared variable in an enclosing scope and assign it within the branches. Never use an uninitialized value after invalid input.

## Modern C++ ownership

`make_unique` creates an object and returns a `unique_ptr` owning it. The pointer cannot be copied. Moving it transfers ownership; the character itself is not recreated. The moved-from unique pointer becomes empty. When an owning pointer is destroyed, it destroys its object. `reset()` can destroy an owned object early. Do not dereference an empty pointer.

An ordinary local object already has automatic cleanup. Use `unique_ptr` when exclusive movable ownership or separately controlled lifetime is useful; it is not required for every game object.

## Function inputs and outputs

Parameters name what a function receives. Arguments supply those values at a call site. A threshold is a cutoff supplied by the caller; changing it changes the selection rule without rewriting the function. An integer-returning function must return its result on every relevant path. A return inside a scan can stop it too early; accumulating functions generally return after the scan.

## Counting and summing

Both patterns start at zero, visit elements, and apply a condition. A count adds one for each match. A sum adds the matching value. Strictly above excludes equality. An inclusive range requires a value to be at least the lower bound AND at most the upper bound. Outside a valid inclusive range means below the lower bound OR above the upper bound.

Empty input naturally yields zero for these count/sum scans. Negative values must be compared according to their actual numeric order. For `{-8, -3, -5}` and a cutoff of `-6`, the matching values are `-3` and `-5`: count two, sum minus eight.

## Distinct extrema and candidate flags

Distinct means different in value: repeated maxima do not become a second distinct maximum. A simple two-pass algorithm finds the maximum, then the greatest value below it. Reverse the comparisons for second-smallest. A boolean `found` distinguishes no candidate from a real answer, making zero a harmless placeholder rather than an assumed valid extreme. Guard empty input before indexing element zero.

Track candidates in input order. The scan does not sort them. With maximum nine in `{6, 2, 9, 7}`, second-largest candidates change from six to seven. Diagnostic prints placed at assignments reveal when state changes.

## Streaks and best-so-far

A threshold streak is an uninterrupted group of qualifying values. Track current length and longest length, resetting current to zero at a nonqualifying value. Update the best only when current beats it. Updating best as the streak grows also handles a streak reaching the end of the vector.

Counting groups is different from counting their lengths. The run-counting example remembers whether a run is active, counts it once when it ends, and counts one final active run after the loop. Repeated low values must not create extra groups.

For a strictly increasing contiguous run, compare neighboring values. A nonempty vector starts at length one; a break starts a new run of length one. Empty input returns zero. Equal neighboring values break a strictly increasing run. Ensure the next index exists before accessing it.

## Equal-value pairs

Compare each position only with later positions. An inner index starting just after the outer index avoids self-pairs and reversed duplicate pairs. Each loop must advance its own index. A position may participate in multiple different pairs.

For `{4, 2, 4, 4, 2}`, the three fours form three pairs and the two twos form one: total four. `{7, 7, 7}` gives three; `{1, 2, 3}` gives zero.

Two separate full scans do about `2n` iterations and have linear time complexity. The equal-pair nested scan checks `n(n-1)/2` pairs, which is quadratic. Frequency counting is an upcoming optimization, not part of this implementation.

## Enums and action-driven behavior

An `enum class` defines a scoped set of named values such as Shoot, Reload and Inspect. The enum type, a variable of that type and one enum value are different things. Naming an action does not execute it; code checks the value and performs behavior.

The console example uses enum-driven shooting, reloading and inspection. An empty magazine does not fire. Inspection reads state without changing it. Reloading transfers the smaller of available space and spare bullets; increase loaded ammo and decrease the reserve by the same amount. The total number of bullets stays unchanged during a reload.

## Interactive menus and input streams

Place persistent state before the repeating menu loop. `break` exits that loop; `continue` skips action handling and begins the next iteration. Map allowed numeric choices to named enum values and skip invalid choices before using an action.

After reading a number, `cin.fail()` reports a failed conversion or stream error. Calling it without using its boolean result does not handle the failure. On a failed read, exit if input ended. Otherwise clear the error flags, ignore through the next newline and continue. Clearing flags alone leaves the bad input waiting. Discarding after clearing lets later input be read. A `while (true)` menu with explicit quit avoids relying on a choice variable whose value may change on a failed extraction.

## Debugging habits

Read the first compiler diagnostic, check names and argument lists, inspect braces to identify each `else`, and trace the variable receiving an assignment. C++ keywords are case-sensitive. Multi-character operators such as `<<` cannot be split into separate tokens. Predict a result, run the program, compare it with the prediction, and test boundary cases as well as normal cases.
