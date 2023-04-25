#include "variable.hpp"

#include "constant.hpp"

namespace jmath
{
    Variable::Variable() {}
    Variable::~Variable() {}

    Expression::Type Variable::type() const { return Type::Variable; }

    double Variable::evaluate(double x) const { return x; }

    std::string Variable::toString() const
    {
        return "x";
    }

    ExprRef Variable::derivative() const
    {
        Constant *cc = new Constant();
        cc->setValue(1);
        return std::shared_ptr<Constant>(cc);
    }

    std::shared_ptr<Expression> Variable::simplify() const
    {
        Variable *v = new Variable();
        return std::shared_ptr<Variable>(v);
    }

}