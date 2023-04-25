#pragma once

#include <memory>
#include <string>

namespace jmath
{
    class Expression
    {
    public:
        enum class Type
        {
            Expression,
            Constant,
            Variable,
            Sum,
            Product,
            Power,
            Fraction,
            Logarithm
        };

    public:
        virtual ~Expression() = default;
        virtual Type type() const { return Type::Expression; }
        virtual double evaluate(double x) const = 0;
        virtual std::shared_ptr<Expression> derivative() const = 0;
        virtual std::string toString() const = 0;
        virtual std::shared_ptr<Expression> simplify() const = 0;
    };

    using ExprRef = std::shared_ptr<Expression>;
}