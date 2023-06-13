#include "cppunits.h"

std::string CppClassUnit:: Compile( unsigned int level ) const
{
    std::string result = GenerateShift( level ) + "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i )
    {
           if( m_fields[i].empty() ) {
              continue;
           }
           result += ACCESS_MODIFIERS[ i ] + ":\n";
           for( const auto& f : m_fields[i] )
           {
               result += f->Compile( level + 1 );
           }
            result += "\n";
        }
    result += GenerateShift( level ) + "};\n";
    return result;
}
std::string CppMethodUnit::Compile( unsigned int level ) const
{
    std::string result = GenerateShift( level );
    if( m_flags & STATIC )
    {
        result += "static ";
    }
    else if( m_flags & VIRTUAL )
    {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";

    if( m_flags & CONST ) {
        result += " const";
    }
    result += " {\n";
    for( const auto& b : m_body )
    {
        result += b->Compile( level + 1 );
    }
    result += GenerateShift( level ) + "}\n";
    return result;
}

std::string CppPrintOperatorUnit::Compile(unsigned int level) const
{
    return GenerateShift(level) + "printf( \"" + m_text + "\" );\n";
}
