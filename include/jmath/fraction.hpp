#pragma once

#include "expression.hpp"

#include <assert.h>
#include <sstream>

namespace jmath
{
    class Fraction : public Expression
    {
    public:
        Fraction() : m_numerator(std::make_shared<Constant>(1)), m_denominator(std::make_shared<Constant>(1)) {}
        ~Fraction() override = default;

        Type type() const override { return Type::Fraction; }

        double evaluate(double x) const override
        {
            auto num = m_numerator->evaluate(x);
            auto denom = m_denominator->evaluate(x);
            assert(denom != 0 && "Denominator cannot be zero!");
            return num / denom;
        }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "(" << m_numerator->toString() << ") / ";
            ss << "(" << m_denominator->toString() << ")";
            return ss.str();
        }

        ExprRef derivative() const override
        {
            return std::shared_ptr<Constant>(0);
        }

        std::shared_ptr<Expression> simplify() const override
        {
            Constant *cc = new Constant();
            cc->setValue(0);
            return std::shared_ptr<Constant>(cc);
        }

        void setNumerator(const ExprRef &num) { m_numerator = num; }
        ExprRef numerator() const { return m_numerator; }

        void setDenominator(const ExprRef &denom) { m_denominator = denom; }
        ExprRef denominator() const { return m_denominator; }

    private:
        ExprRef m_numerator;
        ExprRef m_denominator;
    };
}