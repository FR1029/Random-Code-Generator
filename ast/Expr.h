#pragma once

#include <memory>
#include <string>

class Expr {
public:
    virtual ~Expr() = default;
    virtual std::string print() const = 0;
};

class NumberExpr : public Expr {
public:
    int value;
    explicit NumberExpr(int v) : value(v) {}
    std::string print() const override {
        return std::to_string(value);
    }
};

class VariableExpr : public Expr {
public:
    std::string name;
    explicit VariableExpr(std::string n) : name(std::move(n)) {}
    std::string print() const override {
        return name;
    }
};

class BinaryExpr : public Expr {
public:
    std::string op;
    std::unique_ptr<Expr> lhs;
    std::unique_ptr<Expr> rhs;
    BinaryExpr(std::string op, std::unique_ptr<Expr> lhs, std::unique_ptr<Expr> rhs) : op(std::move(op)), lhs(std::move(lhs)), rhs(std::move(rhs)) {}
    std::string print() const override {
        return "(" + lhs->print() + " " + op + " " + rhs->print() + ")";
    }
};