#pragma once

#include "Expr.h"
#include <memory>
#include <string>

class Statement {
public:
    virtual ~Statement() = default;
    virtual std::string print() const = 0;
};

class DeclarationStatement : public Statement {
public:
    std::string name;
    std::unique_ptr<Expr> expr;
    DeclarationStatement(std::string n, std::unique_ptr<Expr> e) : name(std::move(n)), expr(std::move(e)) {}
    std::string print() const override {
        return "int " + name + " = " + expr->print() + ";";
    }
};

class AssignmentStatement : public Statement {
public:
    std::string name;
    std::unique_ptr<Expr> expr;
    AssignmentStatement(std::string n, std::unique_ptr<Expr> e) : name(std::move(n)), expr(std::move(e)) {}
    std::string print() const override {
        return name + " = " + expr->print() + ";";
    }
};