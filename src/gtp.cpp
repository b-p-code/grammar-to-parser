/// Bryce Paubel 12/20/22
// Class definition for a grammar to parser class

#include <iostream>
#include <string>
#include <vector>

#include "../include/gtp.h"

// TO-DO: ADD MUCH MORE ERROR CHECKING

// Build a list of rules
// Each rule has a list of expansions
// Each expansion has its own rule and a first set

class Expansion {
    public:
        std::vector<std::string> first;
        std::vector<std::string> terms;
};

class Rule {
    public:
        std::string name;
        std::vector<Expansion> expansions;
};

std::string generateNestedIf(Rule r) {
    std::string output = "";

    if (r.expansions.size() == 1) {
        output += "if (tk.ID == " + r.expansions[0].first[0];
        for (unsigned int i = 1; i < r.expansions[0].first.size(); i++) {
            output += " || tk.ID == " + r.expansions[0].first[i];
        }
        output += ") { ";

        output += "}";
    } else {
        
    }


    return output;
}

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
            // Based on the booleans, determine what to do with
            // the current word within the rule
            if (words[i] == "-") {
                firstDone = true;
            } else if (!firstDone) {
                tempExpansion.first.push_back(words[i]);
            } else if (words[i] == "|") {
                ruleDone = true;
            } else if (i == words.size() - 1) {
                tempExpansion.terms.push_back(words[i]);
                ruleDone = true;
            } else {
                tempExpansion.terms.push_back(words[i]);
            }

            // If we have finished a rule and the first sets, we have a new expansion
            if (firstDone && ruleDone) {
                tempRule.expansions.push_back(tempExpansion);
                tempExpansion.terms.clear();
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
            std::cout << "Rule: ";
            for (std::string s : ex.terms) {
                std::cout << s << " ";
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    // Data is now parsed
    
    for (Rule r : rules) {
        
    }

    return generateNestedIf(rules[0]);
}