// Copyright [2024] <Jason Ossai>
#ifndef TEXTWRITER_HPP
#define TEXTWRITER_HPP

#include "RandWriter.hpp"
#include <string>

class TextWriter {
public:
    TextWriter(const std::string& sourceText, int order, int length);
    std::string generateText();
    void writeToFile(const std::string& filename);

private:
    RandWriter randWriter;
    int outputLength;
};

#endif  // TEXTWRITER_HPP
