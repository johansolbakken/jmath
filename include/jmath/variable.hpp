#pragma once

#include "expression.hpp"

namespace jmath
{
    class Variable : public Expression
    {
    public:
        Variable();
        ~Variable() override;

        Type type() const override;
        double evaluate(double x) const override;
        std::string toString() const override;
        ExprRef derivative() const override;
        std::shared_ptr<Expression> simplify() const override;
    };
}