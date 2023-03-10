Bryce Paubel 12/20/22
C++ program which takes in a grammar + first sets and generates a recursive-descent parser for it in C.
This program assumes that the user provides an LL(1) grammar which is not left-recursive.

Assumptions:
    The parser assumes that all tokens are defined in a separate file (which you may have to manually include),
    and that they use a token structure that has a tokenID.

Format:
    follow whitespace EXACTLY
    make sure any empty productions appear at the end of the rule
    (words which begin with uppercase are terminals - use the empty keyword for epsilon)
    Show the grammar rule, but list the first sets for each rule in the beginning
    Nonterminal -> terminal terminal - Nonterminal terminal | terminal - terminal

Compilation:
    To compile, use the 'make' command along with the provided Makefile in the project directory

Running:
    To run, use ./gtp, since the Makefile will compile to the project directory

    The command either takes in a file argument or text from standard input:
    usage: ./gtp [file] or ./gtp[< file]