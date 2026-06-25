#pragma once

#include "../ast/Program.h"
#include <fstream>
#include <string>

class Printer {
public:
    static void print(const Program& program,const std::string& filename) {
        std::ofstream out(filename);
        if (!out.is_open()) throw std::runtime_error("Failed to open output file");
        out << "int main() {\n";
        for (const auto& stmt : program.statements) out << "    " << stmt->print() << "\n";
        out << "\n";
        out << "    return 0;\n";
        out << "}\n";
    }
};