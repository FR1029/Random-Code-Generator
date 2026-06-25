#pragma once

#include <string>
#include <vector>

class SymbolTable {
private:
    std::vector<std::string> vars;

public:
    void add(const std::string& name) {
        vars.push_back(name);
    }

    bool empty() const {
        return vars.empty();
    }

    const std::vector<std::string>& getAll() const {
        return vars;
    }
};