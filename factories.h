#ifndef FACTORIES_H
#define FACTORIES_H
#include "abstractunits.h"
#include "cppunits.h"

class AbstractFactory
{
public:
    virtual std::shared_ptr < AbstractClassUnit > NewClass(const std::string& name) = 0;
    virtual std::shared_ptr < AbstractMethodUnit > NewMethod(const std::string& name, const std::string& returnType, AbstractUnit::Flags flags) = 0;
    virtual std::shared_ptr < AbstractPrintOperatorUnit > NewPrintOperator(const std::string& text ) = 0;
    virtual ~AbstractFactory() = default;
};

class CppFactory:public AbstractFactory
{
public:
    std::shared_ptr < AbstractClassUnit > NewClass(const std::string& name){
        return std::shared_ptr < AbstractClassUnit >(new CppClassUnit(name));
    }
    std::shared_ptr < AbstractMethodUnit > NewMethod(const std::string& name, const std::string& returnType, AbstractUnit::Flags flags){
        return std::shared_ptr < AbstractMethodUnit >(new CppMethodUnit(name,returnType,flags));
    }
    std::shared_ptr < AbstractPrintOperatorUnit > NewPrintOperator(const std::string& text ){
        return std::shared_ptr < AbstractPrintOperatorUnit >(new CppPrintOperatorUnit(text));
    }
};

#endif // FACTORIES_H
