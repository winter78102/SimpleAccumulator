#include <Parser/Parser.h>

void Parser::Parse() {
    std::string Token, Remain;

    std::regex Matched(R"(\d+(?:\.\d+)?)");

    std::sregex_iterator begin(_InputString.begin(), _InputString.end(), Matched);
    std::sregex_iterator end;
    _Storage.clear();
    for (auto it = begin; it != end; ++it) {
        _Storage.push_back(std::stoi(it->str()));
    }
}

std::vector<double> Parser::GetStorage() {
    return _Storage;
}
