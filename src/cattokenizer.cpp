//
// CatTokenizer
//

#include "headers/cattokenizer.h"
#include "headers/easify.h"

static bool isDepth(char c) { return c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']'; }
static bool isSep(char c)   { return c == '.' || c == ';' || c == ':' || c == ','; }

std::vector<std::string> ttok(const std::string& data) {
    std::vector<std::string> Tokens;
    std::string token;
    size_t i = 0;
    while (i < data.size()) {
        char c = data[i];

        if (std::isspace((unsigned char)c) || isSep(c) || isDepth(c)) {
            if (!token.empty()) { Tokens.push_back(token); token.clear(); }
            if (isSep(c) || isDepth(c)) Tokens.push_back(std::string(1, c));
            ++i;
            continue;
        }

        if (c == '"' || c == '\'') {
            if (!token.empty()) { Tokens.push_back(token); token.clear(); }
            std::string s(1, c);
            ++i;
            while (i < data.size() && data[i] != c) s += data[i++];
            if (i < data.size()) { s += c; ++i; }
            Tokens.push_back(s);
            continue;
        }

        token += c;
        ++i;
    }
    if (!token.empty()) Tokens.push_back(token);
    return Tokens;
}

void fttok(const std::string& path) {
    auto source = ReadFile(path);
    std::istringstream ss(source);
    std::string line;
    while (std::getline(ss, line)) {
        auto tks = ttok(line);
        PrintVector(tks);
    }
}
