#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <set>

void analyze_document(const std::string & fname);

int main(int argc, char **argv)
{
    const std::string FNAME = argv[1];

    analyze_document(FNAME);

    return 0;
}

void analyze_document(const std::string & fname)
{
    std::ifstream file(fname);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << fname << std::endl;
        return;
    }

    std::map<std::string, int> word_count;
    std::string word;

    while (file >> word) {
        std::string clean_word;
        for (char c : word) {
            if (std::isalpha(static_cast<unsigned char>(c))) {
            clean_word += std::tolower(static_cast<unsigned char>(c));
            }
        }

        if (!clean_word.empty()) {
        word_count[clean_word]++;
        }
    }

    
    std::multimap<int, std::string, std::greater<int>> sorted_words;

    
    for (const auto& entry : word_count) {
        sorted_words.insert({entry.second, entry.first});
    }

    
    
    
    int count = 0;
    /*
    for (const auto& entry : sorted_words) {
        std::cout << entry.second << ": " << entry.first << std::endl;
        if (++count == 20) {
            break;
        }
    }
    */
    

}