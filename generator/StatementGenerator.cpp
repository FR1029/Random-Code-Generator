#pragma once

#include "../ast/Statement.h"
#include "../semantic/SymbolTable.h"
#include "ExpressionGenerator.cpp"
#include <memory>

class StatementGenerator {
private:
    SymbolTable& table;
    int counter = 0;

public:
    explicit StatementGenerator(SymbolTable& t) : table(t) {}
    std::string freshVariable() {
        return "v" + std::to_string(counter++);
    }
    std::unique_ptr<Statement> generate() {
        ExpressionGenerator exprGen(table);
        if (table.empty() || rand() % 2 == 0) {
            std::string var = freshVariable();
            table.add(var);
            return std::make_unique<DeclarationStatement>(var, exprGen.generate(3));
        }
        auto vars = table.getAll();
        std::string target = vars[rand() % vars.size()];
        return std::make_unique<AssignmentStatement>(target, exprGen.generate(3));
    }
};