#include "logarithm.hpp"

#include <cmath>
#include <sstream>

#include "base.hpp"
#include "constant.hpp"
#include "variable.hpp"

namespace jmath
{
    Logarithm::Logarithm()
    {
        JMath jm;
        m_base = jm.createConstant(M_E);
        m_expr = jm.createVariable();
    }
    Logarithm::~Logarithm()
    {
    }
    Expression::Type Logarithm::type() const
    {
        return Type::Logarithm;
    }
    double Logarithm::evaluate(double x) const
    {
        // log_b of a
        double a = std::log(m_expr->evaluate(x));
        double b = std::log(m_base->evaluate(x));
        return a / b;
    }

    std::string Logarithm::toString() const
    {
        std::stringstream ss;
        ss << "log_{";

        ss << m_base->toString();

        ss << "}(";

        ss << m_expr->toString();

        ss << ")";
        return ss.str();
    }
    ExprRef Logarithm::derivative() const
    {

    }
    std::shared_ptr<Expression> Logarithm::simplify() const
    {
        
    }
    void Logarithm::setBase(const ExprRef &base)
    {
        m_base = base;
    }
    ExprRef Logarithm::base() const
    {
        return m_base;
    }
    void Logarithm::setExpr(const ExprRef &expr)
    {
        m_expr = expr;
    }
    ExprRef Logarithm::expr() const
    {
        return m_expr;
    }
}