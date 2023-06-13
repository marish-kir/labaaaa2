#include <QCoreApplication>
#include "factories.h"
#include <iostream>

std::string generateProgram(const std::shared_ptr< AbstractFactory >& program) {
     std::string str = "MyClass";
     auto myClass = program->NewClass(str);
     myClass->Add(
        program->NewMethod( "testFunc1", "void", 0 ),
        AbstractClassUnit::PUBLIC);
     myClass->Add(
        program->NewMethod( "testFunc2", "void", AbstractMethodUnit::STATIC ),
        AbstractClassUnit::PRIVATE);
     myClass->Add(
        program->NewMethod( "testFunc3", "void", AbstractMethodUnit::VIRTUAL | AbstractMethodUnit::CONST ),
        AbstractClassUnit::PUBLIC);
     std::shared_ptr< AbstractMethodUnit > method = program->NewMethod( "testFunc4", "void",AbstractMethodUnit::CONST );
     method->Add( program->NewPrintOperator( R"(Hello, world!\n)" ) );
     myClass->Add( method, AbstractClassUnit::PROTECTED );
     myClass->Add(program->NewMethod( "testFunc5", "void", AbstractMethodUnit::VIRTUAL | AbstractMethodUnit::CONST ),
     AbstractClassUnit::PUBLIC);

     return myClass->Compile();

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout << generateProgram(std::make_shared< CppFactory >()) << std::endl;
    std::cout << std::endl;
    return a.exec();
}
