#pragma once

#include "expression.hpp"

namespace jmath
{
    class Product;
    class Power : public Expression
    {
    public:
        Power();
        ~Power() override;
        Type type() const override;
        double evaluate(double x) const override;
        std::string toString() const override;
        ExprRef derivative() const override;
        std::shared_ptr<Expression> simplify() const override;

        void setPower(double c);
        void setPower(const ExprRef &cref);
        ExprRef power() const;

        void setBase(const ExprRef &cref);
        ExprRef base() const;

    private:
        ExprRef m_base;
        ExprRef m_power;
    };
}