#pragma once

#include "../ast/Expr.h"
#include "../semantic/SymbolTable.h"
#include <cstdlib>
#include <memory>

class ExpressionGenerator {
private:
    SymbolTable& table;
public:
    explicit ExpressionGenerator(SymbolTable& t) : table(t) {}
    std::unique_ptr<Expr> generate(int depth) {
        if (depth <= 0) {
            if (!table.empty() && rand() % 2) {
                auto vars = table.getAll();
                return std::make_unique<VariableExpr>(vars[rand() % vars.size()]);
            }
            return std::make_unique<NumberExpr>(rand() % 100);
        }
        int choice = rand() % 3;
        if (choice == 0) return std::make_unique<NumberExpr>(rand() % 100);
        if (choice == 1 && !table.empty()) {
            auto vars = table.getAll();
            return std::make_unique<VariableExpr>(vars[rand() % vars.size()]);
        }
        static const std::string ops[] = {"+", "-", "*", "/"};
        return std::make_unique<BinaryExpr>(ops[rand() % 4], generate(depth - 1), generate(depth - 1));
    }
};