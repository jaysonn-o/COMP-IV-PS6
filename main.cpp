// Copyright [2024] <Jason Ossai>

#include <iostream>
#include <fstream>
#include <sstream>
#include "RandWriter.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: TextWriter <order> <length>\n";
        return 1;
    }
    int order = std::stoi(argv[1]);      // Changed k to order
    int length = std::stoi(argv[2]);     // Changed L to length

    std::string inputText, line;
    while (std::getline(std::cin, line)) {
        inputText += line + "\n";
    }

    try {
        RandWriter writer(inputText, order);  
        std::string kgram = inputText.substr(0, order);  
        std::cout << writer.generate(kgram, length) << std::endl;  
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
