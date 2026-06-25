#pragma once

#include "../ast/Program.h"
#include "../semantic/SymbolTable.h"
#include "StatementGenerator.cpp"

class ProgramGenerator {
public:
    Program generate(int count) {
        Program program;
        SymbolTable table;
        StatementGenerator stmtGen(table);
        for (int i = 0; i < count; i++) program.statements.push_back(stmtGen.generate());
        return program;
    }
};