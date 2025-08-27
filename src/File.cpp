#include "File/File.h"

void File::SetFileAddr(){
    std::cin>>_FileAddr;
}

void File:: GetString(){
    std::cout<<">>type the address of file\n";
    SetFileAddr();
    std::ifstream InputFile(_FileAddr);
    if (!InputFile.is_open()) {
        std::cerr << ">>Error: could not open file: " <<_FileAddr << std::endl;
    }
    std::string BaseString,LineString;

    while (std::getline(InputFile, LineString)) {
        BaseString=BaseString+" "+ LineString;

    }
    _InputString=BaseString;

}