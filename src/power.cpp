#include "power.hpp"

#include "constant.hpp"
#include "product.hpp"
#include "variable.hpp"
#include "base.hpp"

#include <sstream>
#include <cmath>

namespace jmath
{
    Power::Power() : m_power(std::make_shared<Constant>(1)), m_base(std::make_shared<Variable>()) {}
    Power::~Power() = default;

    Expression::Type Power::type() const { return Type::Power; }

    double Power::evaluate(double x) const
    {
        return std::pow(m_base->evaluate(x), m_power->evaluate(x));
    }

    std::string Power::toString() const
    {
        std::stringstream ss;
        ss << m_base->toString() << "^(" << m_power->toString() << ")";
        return ss.str();
    }

    ExprRef Power::derivative() const
    {
        if (m_base->type() == Type::Constant)
        {
            if (m_power->type() == Type::Constant)
            {
                JMath math;
                auto constant = math.createConstant(0);
                return constant;
            }
            else
            {
                
            }
        }
        if (m_power->type() == Type::Constant)
        {
            auto c = std::static_pointer_cast<Constant>(m_power);
            auto a = std::make_shared<Constant>();
            a->setValue(c->value());
            if (c->value() == 1)
            {
                return a;
            }

            auto b = std::make_shared<Power>();
            b->setPower(c->value() - 1);

            auto p = std::make_shared<Product>();
            p->setLhs(a);
            p->setRhs(b);
            return p;
        }

        return nullptr;
    }

    std::shared_ptr<Expression> Power::simplify() const
    {
        auto power = std::make_shared<Power>();
        power->setPower(m_power);
        return power;
    }

    void Power::setPower(double c) { m_power = std::make_shared<Constant>(c); }
    void Power::setPower(const ExprRef &cref) { m_power = cref; }
    ExprRef Power::power() const { return m_power; }

    void Power::setBase(const ExprRef &cref) { m_base = cref; }
    ExprRef Power::base() const { return m_base; }
}