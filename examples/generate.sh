#!/bin/bash

rm exampleGrammar1_parser.c exampleGrammar2_parser.c grammar_parser.c
../gtp exampleGrammar1
../gtp exampleGrammar2
../gtp grammar