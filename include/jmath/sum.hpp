#pragma once

#include "expression.hpp"

namespace jmath
{
    class Sum : public Expression
    {
    public:
        Sum();
        ~Sum() override;

        Type type() const override;
        double evaluate(double x) const override;
        std::string toString() const override;
        ExprRef derivative() const override;
        std::shared_ptr<Expression> simplify() const override;

        void setRhs(const ExprRef &expr);
        ExprRef rhs() const;
        void setLhs(const ExprRef &expr);
        ExprRef lhs() const;

    private:
        ExprRef m_lhs, m_rhs;
    };
}