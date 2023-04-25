#include <jmath/jmath.hpp>

#include <iostream>
#include <map>

#include <jmath/fraction.hpp>

int main()
{
    jmath::JMath jm;

    auto a = jm.createConstant(1);
    auto b = jm.createPower(2);
    auto y = jm.createProduct(a, b);

    std::cout << y->toString() << std::endl;

    auto dy = y->derivative();
    std::cout << dy->simplify()->toString() << std::endl;

    auto ddy = dy->derivative();
    std::cout << ddy->simplify()->toString() << std::endl;

/*

    std::cout << y->simplify()->toString() << std::endl;
    auto d = y->derivative();
    // auto dd = d->derivative();
    // auto ddd = dd->derivative();
    std::cout << d->simplify()->toString() << std::endl;

    auto l = jm.createLog();
    std::cout << l->toString() << std::endl;
    std::cout << l->evaluate(5) << std::endl;*/
}