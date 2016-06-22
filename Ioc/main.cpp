#include <iostream>
#include "IocContainer.hpp"

class ICar
{
public:
    virtual ~ICar()
    {
        // Do nothing
    }

    virtual void test() = 0;
};

class Bus: public ICar
{
public:
    virtual void test() override
    {
        std::cout << "Bus::test" << std::endl;
    }
};

class Car : public ICar
{
public:
    virtual void test() override
    {
        std::cout << "Car::test" << std::endl;
    }
};

int main()
{
    IocContainer<ICar> ioc;

    try
    {
        ioc.registerType<Bus>("bus");
        ioc.registerType<Car>("car");
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl; 
    }

    std::shared_ptr<ICar> bus = ioc.resolveShared("bus");
    bus->test();
    std::shared_ptr<ICar> car = ioc.resolveShared("car");
    car->test();

    return 0;
}