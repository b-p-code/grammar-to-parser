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

bool iscapital(char x)
{
    if (x >='A' && x <= 'Z') {
        return true;
    } else { 
        return false;
    }
}

bool containsEmpty(std::vector<std::string> words) {
    for (std::string w : words) {
        if (w == "empty") {
            return true;
        }
    }
    return false;
}

std::string generateNestedIfAux(std::vector<std::string> rules) {
    std::string output = "";
    if (rules.empty()) {
        return "";
    } else {
        if (iscapital(rules[0][0])) {
            output += rules[0] + "();";
        } else if (rules[0] == "empty") { 
            output += generateNestedIfAux(std::vector<std::string>(rules.begin() + 1, rules.end()));
        } else {
            output += "tk = scanner();\n";
            output += generateNestedIfAux(std::vector<std::string>(rules.begin() + 1, rules.end()));
        }
    }

    return output;
}

std::string generateNestedIf(Rule r) {
    std::string output = "";

    bool hasEmpty = false;

    for (Expansion ex : r.expansions) {
        if (containsEmpty(ex.first)) {
            hasEmpty = true;
        }
    }

    std::cout << hasEmpty << std::endl;
    if (r.expansions.size() == 1) {
        if (r.expansions[0].first[0] != "empty") {
            output += "if (tk.ID == " + r.expansions[0].first[0];
        }

        output += ") {\n";
        output += generateNestedIfAux(r.expansions[0].terms);
        output += " }";

        if (hasEmpty) {
            output += " else { return; }\n";
        } else {
            output += " else { error(); }\n";
        }
    } else {
        if (r.expansions[0].first[0] != "empty") {
            output += "if (tk.ID == " + r.expansions[0].first[0];
        }
        for (unsigned int i = 1; i < r.expansions[0].first.size(); i++) {
            output += " || tk.ID == " + r.expansions[0].first[i];
        }
        output += ") {\n";
        output += generateNestedIfAux(r.expansions[0].terms);
        output += "}";

        for (unsigned int i = 1; i < r.expansions.size(); i++) {
            if (r.expansions[i].first[0] != "empty") {
                output += " else if (tk.ID == " + r.expansions[i].first[0];
            }
            for (unsigned int j = 1; j < r.expansions[i].first.size(); j++) {
                if (r.expansions[i].first[j] != "empty") {
                    output += " || tk.ID == " + r.expansions[i].first[j];
                }
            }
            output += ") {\n";
            output += generateNestedIfAux(r.expansions[i].terms);
            output += "} ";
        }

        if (hasEmpty) {
            output += " else { return; }\n";
        } else {
            output += " else { error(); }\n";
        }
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
        output += "void " + r.name + "() { \n";
        output += generateNestedIf(r);
        output += "}";
    }

    return output;
}