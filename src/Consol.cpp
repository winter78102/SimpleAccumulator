#include<Reader/Consol/Consol.h>
#include <string>
#include <regex>
#include <iterator>

void Consol::GetString() {

    std::cout << "type your number with space between them\n" << std::flush;
    std::string Line;
    while (Line.empty()) {
        std::getline(std::cin, Line);
    }
    _InputString = Line;
}