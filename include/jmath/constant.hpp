#pragma once

#include "expression.hpp"

namespace jmath
{
    class Constant : public Expression
    {
    public:
        Constant();
        Constant(double val);
        ~Constant() override;

        Type type() const override;
        double evaluate(double x) const override;
        std::string toString() const override;
        ExprRef derivative() const override;
        std::shared_ptr<Expression> simplify() const override;

        void setValue(double v);
        double value() const;

    private:
        double m_value;
    };
}