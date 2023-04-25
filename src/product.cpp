#include "product.hpp"

#include "expression.hpp"
#include "sum.hpp"
#include "constant.hpp"

#include <sstream>

namespace jmath
{
    Product::Product() : m_lhs(std::make_shared<Constant>(1)), m_rhs(std::make_shared<Constant>(1)) {}
    Product::~Product() = default;

    Expression::Type Product::type() const { return Type::Product; }

    double Product::evaluate(double x) const
    {
        return m_lhs->evaluate(x) * m_rhs->evaluate(x);
    }

    std::string Product::toString() const
    {
        std::stringstream ss;
        ss << "(" << m_lhs->toString() << ")*";
        ss << "(" << m_rhs->toString() << ")";
        return ss.str();
    }

    ExprRef Product::derivative() const
    {
        auto d_rhs = m_rhs->derivative();
        auto d_lhs = m_lhs->derivative();

        auto a = std::make_shared<Product>();
        a->setRhs(d_rhs);
        a->setLhs(m_lhs);

        auto b = std::make_shared<Product>();
        b->setRhs(m_rhs);
        b->setLhs(d_lhs);

        auto sum = std::make_shared<Sum>();
        sum->setRhs(a);
        sum->setLhs(b);

        return sum;
    }

    std::shared_ptr<Expression> Product::simplify() const
    {
        auto rhs = m_rhs->simplify();
        auto lhs = m_lhs->simplify();

        if (rhs->type() == Type::Constant)
        {
            auto rhs_c = std::static_pointer_cast<Constant>(rhs);
            if (rhs_c->value() == 0)
                return rhs;
        }

        if (lhs->type() == Type::Constant)
        {
            auto lhs_c = std::static_pointer_cast<Constant>(lhs);
            if (lhs_c->value() == 0)
                return lhs;
        }

        if (rhs->type() == Type::Constant)
        {
            auto rhs_c = std::static_pointer_cast<Constant>(rhs);
            if (rhs_c->value() == 1)
                return lhs;
        }

        if (lhs->type() == Type::Constant)
        {
            auto lhs_c = std::static_pointer_cast<Constant>(lhs);
            if (lhs_c->value() == 1)
                return rhs;
        }

        auto product = std::make_shared<Product>();
        product->setLhs(lhs);
        product->setRhs(rhs);
        return product;
    }

    void Product::setRhs(const ExprRef &expr) { m_rhs = expr; }
    ExprRef Product::rhs() const { return m_rhs; }
    void Product::setLhs(const ExprRef &expr) { m_lhs = expr; }
    ExprRef Product::lhs() const { return m_lhs; }
}