/// Bryce Paubel 12/20/22
// Class definition for a grammar to parser class

#include <iostream>
#include <string>
#include <vector>

#include "../include/gtp.h"

// Build a list of rules
// Each rule has a list of expansions
// Each expansion has its own rule and a first set

class Expansion {
    public:
        std::vector<std::string> first;
        std::string rule;
};

class Rule {
    public:
        std::string name;
        std::vector<Expansion> expansions;
};

std::string GTP::buildParser() {
    // Output string
    std::string output;

    std::vector<std::string> ruleLines;

    // Extract the lines from the string
    std::string temp = "";
    for (unsigned int i = 0; i < source.length(); i++) {
        if (source[i] != '\n' && source[i] != '\r') { 
            temp += source[i];
        } else {
            ruleLines.push_back(temp);
            temp = "";
        }
    }
    if (temp.length() != 0) {
        ruleLines.push_back(temp);
    }

    // TO-DO: VERY LITTLE CHECKING, ASSUMES THAT THE USER FOLLOWS THE PROPER FORMAT

    // Parse the rules
    std::vector<Rule> rules;
    for (std::string line : ruleLines) {
        std::vector<std::string> words;
        // Extract the words the rule
        std::string temp = "";
        for (unsigned int i = 0; i < line.length(); i++) {
            if (line[i] != ' ') { 
                temp += line[i];
            } else {
                words.push_back(temp);
                temp = "";
            }
        }
        if (temp.length() != 0) {
            words.push_back(temp);
        }

        // Now store it into a rule
        Rule tempRule;
        tempRule.name = words[0];

        bool firstDone = false;
        bool ruleDone = false;
        Expansion tempExpansion;
        for (unsigned int i = 2; i < words.size(); i++) {
            if (words[i] == "-") {
                firstDone = true;
            } else if (!firstDone) {
                tempExpansion.first.push_back(words[i]);
            } else if (words[i] == "|") {
                tempExpansion.rule = words[i - 1];
                ruleDone = true;
            } else if (i == words.size() - 1) {
                tempExpansion.rule = words[i];
                ruleDone = true;
            }

            if (firstDone && ruleDone) {
                tempRule.expansions.push_back(tempExpansion);
                tempExpansion.rule = "";
                tempExpansion.first.clear();
                firstDone = false;
                ruleDone = false;
            }
        }

        rules.push_back(tempRule);
    }

    for (Rule r : rules) {
        std::cout << r.name << " ";
        for (Expansion ex : r.expansions) {
            std::cout << "First set: ";
            for (std::string s : ex.first) {
                std::cout << s << " ";
            }
            std::cout << "Rule: " << ex.rule << " ";
        }
        std::cout << std::endl;
    }

    return "";
}