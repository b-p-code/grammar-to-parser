#!/bin/bash

rm b-lang_parser.c
rm example_parser.c
rm exampleGrammar1_parser.c
rm exampleGrammar2_parser.c
rm exampleGrammar3_parser.c
../gtp exampleGrammar1
../gtp exampleGrammar2
../gtp exampleGrammar3
../gtp grammar
../gtp b-lang