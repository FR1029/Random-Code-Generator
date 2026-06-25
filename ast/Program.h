#pragma once

#include "Statement.h"
#include <memory>
#include <vector>

class Program {
public:
    std::vector<std::unique_ptr<Statement>> statements;
};