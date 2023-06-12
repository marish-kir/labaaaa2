#include <QCoreApplication>
#include "classunit.h"
#include "printoperatorunit.h"
#include <iostream>
#include <memory>
#include <cassert>
#include "methodunit.h"

std::string generateProgram() {
     std::string str = "MyClass";
     ClassUnit* myClass = new ClassUnit("MyClass");
     myClass->add(
     std::make_shared< MethodUnit >( "testFunc1", "void", 0 ),
     ClassUnit::PUBLIC
     );
     myClass->add(
     std::make_shared< MethodUnit >( "testFunc2", "void", MethodUnit::STATIC ),
     ClassUnit::PRIVATE
     );
     myClass->add(
     std::make_shared< MethodUnit >( "testFunc3", "void", MethodUnit::VIRTUAL |
    MethodUnit::CONST ),
     ClassUnit::PUBLIC
     );
     auto method = std::make_shared< MethodUnit >( "testFunc4", "void",
    MethodUnit::STATIC );
     method->add( std::make_shared< PrintOperatorUnit >( R"(Hello, world!\n)" ) );
     myClass->add( method, ClassUnit::PROTECTED );
     return myClass->compile();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << generateProgram() << std::endl;
    return a.exec();
}
