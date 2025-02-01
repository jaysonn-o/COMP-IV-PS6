// Copyright [2024] <Jason Ossai>
#ifndef RANDWRITER_HPP
#define RANDWRITER_HPP

#include <string>
#include <map>

class RandWriter {
public:
    RandWriter(std::string text, int k);
    int orderK() const;
    int freq(std::string kgram) const;
    int freq(std::string kgram, char c) const;
    char kRand(std::string kgram);
    std::string generate(std::string kgram, int L);
    std::string getText() const;  // Getter for text
    friend std::ostream& operator<<(std::ostream& os, const RandWriter& rw);

private:
    std::string text;
    int k;
    std::map<std::string, std::map<char, int>> kgram_freq;
    void calculateFreq();
};

#endif  // RANDWRITER_HPP
