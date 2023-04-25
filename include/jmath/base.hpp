#pragma once

#include <memory>

#include "expression.hpp"

namespace jmath
{
    class Constant;
    class Power;
    class Product;
    class Sum;
    class Fraction;
    class Variable;
    class Logarithm;

    class JMath
    {
    public:
        std::shared_ptr<Constant> createConstant(double d);
        std::shared_ptr<Power> createPower(const ExprRef &power);
        std::shared_ptr<Power> createPower(double power);
        std::shared_ptr<Product> createProduct(const ExprRef &lhs, const ExprRef &rhs);
        std::shared_ptr<Sum> createSum(const ExprRef &lhs, const ExprRef &rhs);
        std::shared_ptr<Product> createProduct(double lhs, double rhs);
        std::shared_ptr<Fraction> createFraction(const ExprRef &num, const ExprRef &denom);
        std::shared_ptr<Fraction> createFraction(double num, double denom);
        std::shared_ptr<Variable> createVariable();
        std::shared_ptr<Logarithm> createLog();
    };
}