# earley-parser

A parser for context-free grammar. A class project.
Runs the earley parser algorithm. That is, an algorithm that parses a sentences given a context-free grammar.
There could be multiple possible parses. In which case, the one with the highest weight is selected. Weights are given in the context-free grammar rules.

There was assignment options that make the parsing more efficient, at the cost of not always outputting the most optimal parse as far as the weights go.
Uncomment marked lines around 157 to enable those speedups

## How to run

Build the project with GNU make. Requires C++14 or later. No other dependencies.
Then run as `./main file.gr file.sen`

Note: The wallstreet example takes a while if non-standard speedups aren't used.

## Examples

See wallstreet.par and arith.par for example outputs
