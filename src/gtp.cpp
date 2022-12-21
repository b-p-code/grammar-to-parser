/// Bryce Paubel 12/20/22
// Class definition for a grammar to parser class

#include <iostream>
#include <string>
#include <vector>

#include "../include/gtp.h"

std::string GTP::buildParser() {
    // Output string
    std::string output;

    std::vector<std::string> rules;

    std::string temp = "";
    for (unsigned int i = 0; i < source.length(); i++) {
        if (source[i] != '\n' && source[i] != '\r') { 
            temp += source[i];
        } else {
            rules.push_back(temp);
            temp = "";
        }
    }

    if (temp.length() != 0) {
        rules.push_back(temp);
    }

    return "";

}