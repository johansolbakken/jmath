#include "constant.hpp"

namespace jmath
{
    Constant::Constant() {}
    Constant::Constant(double val) : m_value(val) {}
    Constant::~Constant() = default;

    Expression::Type Constant::type() const { return Type::Constant; }

    double Constant::evaluate(double x) const
    {
        return m_value;
    }

    std::string Constant::toString() const
    {
        return std::to_string(m_value);
    }

    ExprRef Constant::derivative() const
    {
        // Derivative of a constant is 0
        Constant *cc = new Constant();
        cc->setValue(0);
        return std::shared_ptr<Constant>(cc);
    }

    std::shared_ptr<Expression> Constant::simplify() const
    {
        Constant *cc = new Constant();
        cc->setValue(m_value);
        return std::shared_ptr<Constant>(cc);
    }

    void Constant::setValue(double v) { m_value = v; }
    double Constant::value() const { return m_value; }

}