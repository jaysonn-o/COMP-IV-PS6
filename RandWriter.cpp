// Copyright [2024] <Jason Ossai>
#include "RandWriter.hpp"
#include <stdexcept>
#include <iostream>
#include <ctime>
#include <random>

RandWriter::RandWriter(std::string text, int k) : text(text), k(k) {
    if (text.length() < static_cast<std::string::size_type>(k)) {
        throw std::invalid_argument("Text length must be at least k");
    }
    calculateFreq();
    std::srand(std::time(0));
}

void RandWriter::calculateFreq() {
    for (size_t i = 0; i < text.length(); ++i) {
        std::string kgram = text.substr(i, k);
        // Ensure circular nature is handled
        char nextChar = text[(i + k) % text.length()];

        kgram_freq[kgram][nextChar]++;
    }
}

int RandWriter::orderK() const {
    return k;
}

int RandWriter::freq(std::string kgram) const {
    if (kgram.length() != static_cast<std::string::size_type>(k)) {
        throw std::invalid_argument("kgram is not of length k");
    }
    if (kgram_freq.find(kgram) != kgram_freq.end()) {
        int sum = 0;
        for (auto& pair : kgram_freq.at(kgram)) {
            sum += pair.second;
        }
        return sum;
    }
    return 0;
}

int RandWriter::freq(std::string kgram, char c) const {
    if (kgram.length() != static_cast<std::string::size_type>(k)) {
        throw std::invalid_argument("kgram is not of length k");
    }
    if (kgram_freq.find(kgram) != kgram_freq.end()) {
        if (kgram_freq.at(kgram).find(c) != kgram_freq.at(kgram).end()) {
            return kgram_freq.at(kgram).at(c);
        }
    }
    return 0;
}

char RandWriter::kRand(std::string kgram) {
    if (kgram.length() != static_cast<std::string::size_type>(k)) {
        throw std::invalid_argument("kgram is not of length k");
    }
    if (kgram_freq.find(kgram) == kgram_freq.end()) {
        throw std::invalid_argument("No such kgram");
    }

    int totalFreq = freq(kgram);
    int c = std::rand() % totalFreq;

    for (const auto& pair : kgram_freq.at(kgram)) {
        c -= pair.second;
        if (c < 0) {
            return pair.first;
        }
    }

    throw std::runtime_error("Random character generation failed");
}

std::string RandWriter::generate(std::string kgram, int L) {
    if (kgram.length() != static_cast<std::string::size_type>(k)) {
        throw std::invalid_argument("kgram is not of length k");
    }
    if (static_cast<std::string::size_type>(L) < static_cast<std::string::size_type>(k)) {
        throw std::invalid_argument("Length L must be at least k");
    }
    std::string result = kgram;
    for (int i = k; i < L; ++i) {
        result += kRand(result.substr(i - k, k));
    }
    return result;
}

std::string RandWriter::getText() const {
    return text;
}

std::ostream& operator<<(std::ostream& os, const RandWriter& rw) {
    os << "Order: " << rw.k << "\n";
    for (const auto& kgram_pair : rw.kgram_freq) {
        os << kgram_pair.first << ": ";
        for (const auto& char_pair : kgram_pair.second) {
            os << char_pair.first << "(" << char_pair.second << "), ";
        }
        os << "\n";
    }
    return os;
}
