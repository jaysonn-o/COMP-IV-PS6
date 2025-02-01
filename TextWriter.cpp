// Copyright [2024] <Jason Ossai>
#include "TextWriter.hpp"
#include "RandWriter.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// Constructor for TextWriter class
TextWriter::TextWriter(const std::string& sourceText, int order, int length)
    : randWriter(sourceText, order), outputLength(length) {}

// Method to generate text
std::string TextWriter::generateText() {
    // Generate initial k-gram to start the random text generation
    std::string seed = randWriter.generate(randWriter.getText().substr(0, randWriter.orderK()), randWriter.orderK());

    // Use the RandWriter to generate text of the desired length
    return randWriter.generate(seed, outputLength);
}

// Method to write generated text to a file
void TextWriter::writeToFile(const std::string& filename) {
    std::string generatedText = generateText();
    std::ofstream outputFile(filename);

    if (outputFile.is_open()) {
        outputFile << generatedText;
        outputFile.close();
        std::cout << "Text successfully written to " << filename << std::endl;
    }
    else {
        std::cerr << "Error: Could not open file " << filename << std::endl;
    }
}

// Main function
int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: TextWriter <order> <length>\n";
        return 1;
    }

    // Get command-line arguments
    int k = std::stoi(argv[1]);         // Order for the Markov model
    int L = std::stoi(argv[2]);         // Length of the generated text

    std::string inputText, line;

    // Read input text from standard input (can be redirected from a file)
    while (std::getline(std::cin, line)) {
        inputText += line + "\n";
    }

    try {
        // Create TextWriter object and generate text
        TextWriter writer(inputText, k, L);
        std::string generatedText = writer.generateText();

        // Print generated text to standard output
        std::cout << generatedText << std::endl;

        // Optionally, write generated text to a file (uncomment the next line if desired)
        // writer.writeToFile("generated_text.txt");
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
