#ifndef CPPUNITS_H
#define CPPUNITS_H
#include "abstractunits.h"

class CppClassUnit : public AbstractClassUnit
{
public:
    CppClassUnit( const std::string& name ) : AbstractClassUnit(name){}
    std::string Compile( unsigned int level = 0 ) const;
};
class CppMethodUnit : public AbstractMethodUnit
{
public:
    CppMethodUnit( const std::string& name, const std::string& returnType, Flags flags ) : AbstractMethodUnit(name,returnType,flags){}
    std::string Compile( unsigned int level ) const;
};

class CppPrintOperatorUnit : public AbstractPrintOperatorUnit
{
public:
    CppPrintOperatorUnit( const std::string& text ) : AbstractPrintOperatorUnit( text ) { }
    std::string Compile( unsigned int level = 0 ) const;
};
#endif // CPPUNITS_H
