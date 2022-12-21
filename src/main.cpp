// CS4280 P2 Bryce Paubel 10/16/22
// This program takes in a program string from either standard input or a file
// and determines if it is a valid program as well as generating a parse tree

#include <iostream>
#include <string>

#include "../include/files.h"
#include "../include/gtp.h"

using namespace std;

bool checkArguments(int args, char** argv);
bool onlyWS(string);

int main(int args, char** argv) {
    string inputTotal = "";
    string fileName = "";
    string outputFileName = "";
    string input = "";
    string output = "";
    
    // Check arguments
    if (!checkArguments(args, argv)) {
        cout << "Improper arguments, usage is: ./frontEnd [file] or ./frontEnd [< file]" << endl;
        return 1;
    }

    fileName = argv[1];
    if (!readFromFile(fileName, inputTotal)) {
        std::cout << "Input error in reading from file, file may not exist or be readable!" << std::endl;
        return 1;
    }

    outputFileName = fileName + "_parser.c";


    // Quick check for empty input
    if (inputTotal == "" || inputTotal.empty()) {
        std::cout << "Input error in reading string, file or input is empty" << std::endl;
        return 1;
    }

    // Quick check for whitespace only input
    if (onlyWS(inputTotal)) {
        std::cout << "Input error. Input contains only whitespace." << std::endl;
        return 1;
    }
    
    // SEND NEW STRING FOR PARSER INTO OUTPUT STRING
    GTP gtp(inputTotal);
    gtp.buildParser();

    // Output to files
    if (createFile(outputFileName)) {
        if (!writeIntoFile(outputFileName, output)) {
            cout << "Error in writing to " << outputFileName << endl;
            return 1;
        }
    } else {
        cout << "Error in creating " << outputFileName << endl;
        return 1;
    }
    return 0;
}

/*
    checkArguments
    Determines if the input arguments are appropriate

    Input: int, char**
    These are the argument inputs

    Output: bool
    Boolean determining if the number of arguments is proper
*/
bool checkArguments(int args, char** argv) {
    if (args != 2) {
        return false;
    } else {
        return true;
    }
}

/*
    onlyWS
    Determines if a given string is only whitespace

    Input: string
    String to be checked

    Output: bool
    Boolean determining if the string is just whitespace or no
*/
bool onlyWS(string input) {
    // Check to make sure the file isn't just full of whitespace
    bool onlyWS = true;
    for (unsigned int i = 0; i < input.length(); i++) {
        if (!isspace(input[i])) {
            onlyWS = false;
        }
    }
    return onlyWS;
}