// Bryce Paubel 12/20/22
// Class declaration for a grammar to parser class

#ifndef GTP_H
#define GTP_H

#include <string>

class GTP {
    private:
        std::string source;
    public:
        GTP(std::string source) {
            this->source = source;
        }
        std::string buildParser();
};

#endif