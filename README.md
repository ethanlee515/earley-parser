# earley-parser

A parser for context-free grammar. A class project.
Runs the earley parser algorithm. That is, an algorithm that parses a sentences given a context-free grammar.
There could be multiple possible parses. In which case, the one with the highest weight is selected. Weights are given in the context-free grammar rules.

There was assignment options that make the parsing more efficient, at the cost of not always outputting the most optimal parse as far as the weights go.
I forgot if this particular version is the one that implements those non-standard speedups, unfortunately.

## How to run

Build the project with GNU make. Requires C++17 or later. No other dependencies.

## Examples

TODO
