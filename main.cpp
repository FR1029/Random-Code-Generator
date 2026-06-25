#include "generator/ProgramGenerator.cpp"
#include "printer/Printer.cpp"
#include <filesystem>
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    srand(time(nullptr));
    if(argc < 2){
        std::cerr << "Usage: " << argv[0] << " <number_of_statements>\n";
        return 1;
    }
    int stmtCount = std::stoi(argv[1]);
    if (stmtCount <= 0) {
        std::cerr << "Number of statements must be positive\n";
        return 1;
    }
    ProgramGenerator generator;
    Program program = generator.generate(stmtCount);
    fs::create_directories("output");
    std::string filename = "output/generated.cpp";
    Printer::print(program, filename);
    std::cout << "Generated program saved to: " << filename << "\n";
    return 0;
}