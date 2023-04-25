#include "sum.hpp"

#include "constant.hpp"

#include <sstream>

namespace jmath
{
    Sum::Sum() : m_lhs(std::make_shared<Constant>(0)), m_rhs(std::make_shared<Constant>(0)) {}
    Sum::~Sum() = default;

    Expression::Type Sum::type() const { return Type::Sum; }

    double Sum::evaluate(double x) const
    {
        return m_lhs->evaluate(x) + m_rhs->evaluate(x);
    }

    std::string Sum::toString() const
    {
        std::stringstream ss;
        ss << m_lhs->toString() << " + ";
        ss << m_rhs->toString();
        return ss.str();
    }

    ExprRef Sum::derivative() const
    {
        Sum *sum = new Sum();
        sum->setLhs(m_lhs->derivative());
        sum->setRhs(m_rhs->derivative());
        return std::shared_ptr<Sum>(sum);
    }

    std::shared_ptr<Expression> Sum::simplify() const
    {
        auto rhs = m_rhs->simplify();
        auto lhs = m_lhs->simplify();

        if (rhs->type() == Type::Constant)
        {
            auto rhs_c = std::static_pointer_cast<Constant>(rhs);
            if (rhs_c->value() == 0)
                return lhs;
        }

        if (lhs->type() == Type::Constant)
        {
            auto lhs_c = std::static_pointer_cast<Constant>(lhs);
            if (lhs_c->value() == 0)
                return rhs;
        }

        auto sum = std::make_shared<Sum>();
        sum->setLhs(lhs);
        sum->setRhs(rhs);
        return sum;
    }

    void Sum::setRhs(const ExprRef &expr) { m_rhs = expr; }
    ExprRef Sum::rhs() const { return m_rhs; }
    void Sum::setLhs(const ExprRef &expr) { m_lhs = expr; }
    ExprRef Sum::lhs() const { return m_lhs; }

}