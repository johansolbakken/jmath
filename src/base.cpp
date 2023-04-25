#include "base.hpp"

#include <memory>
#include <cmath>
#include <string>
#include <sstream>

#include "expression.hpp"
#include "constant.hpp"
#include "fraction.hpp"
#include "power.hpp"
#include "product.hpp"
#include "sum.hpp"
#include "variable.hpp"
#include "logarithm.hpp"

namespace jmath
{
    std::shared_ptr<Constant> JMath::createConstant(double d)
    {
        auto constant = std::make_shared<Constant>();
        constant->setValue(d);
        return constant;
    }

    std::shared_ptr<Power> JMath::createPower(const ExprRef &power)
    {
        auto linear = std::make_shared<Power>();
        linear->setPower(power);
        return linear;
    }

    std::shared_ptr<Power> JMath::createPower(double power)
    {
        return createPower(createConstant(power));
    }

    std::shared_ptr<Product> JMath::createProduct(const ExprRef &lhs, const ExprRef &rhs)
    {
        auto product = std::make_shared<Product>();
        product->setRhs(rhs);
        product->setLhs(lhs);
        return product;
    }

    std::shared_ptr<Sum> JMath::createSum(const ExprRef &lhs, const ExprRef &rhs)
    {
        auto sum = std::make_shared<Sum>();
        sum->setRhs(rhs);
        sum->setLhs(lhs);
        return sum;
    }

    std::shared_ptr<Product> JMath::createProduct(double lhs, double rhs)
    {
        return createProduct(createConstant(lhs), createConstant(rhs));
    }

    std::shared_ptr<Fraction> JMath::createFraction(const ExprRef &num, const ExprRef &denom)
    {
        auto frac = std::make_shared<Fraction>();
        frac->setNumerator(num);
        frac->setDenominator(denom);
        return frac;
    }

    std::shared_ptr<Fraction> JMath::createFraction(double num, double denom)
    {
        return createFraction(createConstant(num), createConstant(denom));
    }

    std::shared_ptr<Variable> JMath::createVariable()
    {
        return std::make_shared<Variable>();
    }

    std::shared_ptr<Logarithm> JMath::createLog()
    {
        return std::make_shared<Logarithm>();
    }
}