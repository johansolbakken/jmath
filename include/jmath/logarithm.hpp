#pragma once

#include "expression.hpp"

namespace jmath
{
    class Logarithm : public Expression
    {
    public:
        Logarithm();
        ~Logarithm() override;

        Type type() const override;
        double evaluate(double x) const override;
        std::string toString() const override;
        ExprRef derivative() const override;
        std::shared_ptr<Expression> simplify() const override;

        void setBase(const ExprRef &base);
        ExprRef base() const;

        void setExpr(const ExprRef &expr);
        ExprRef expr() const;

    private:
        ExprRef m_base;
        ExprRef m_expr;
    };
}