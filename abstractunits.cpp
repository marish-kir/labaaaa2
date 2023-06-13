#include "abstractunits.h"

void AbstractUnit::Add(const std::shared_ptr<AbstractUnit>& unit, Flags flags){
    throw std::runtime_error( "Not supported" );
}
std::string AbstractUnit::GenerateShift( unsigned int level ) const{
    static const auto DEFAULT_SHIFT = " ";
     std::string result;
     for( unsigned int i = 0; i < level; ++i ) {
     result += DEFAULT_SHIFT;
     }
     return result;

}

const std::vector<std::string> AbstractClassUnit::ACCESS_MODIFIERS = { "public","protected", "private"};


void AbstractClassUnit::Add( const std::shared_ptr<AbstractUnit>& unit, Flags flags )
{

    int accessModifier = PRIVATE;
    if( flags < ACCESS_MODIFIERS.size() )
    {
       accessModifier = flags;
    }
    m_fields[accessModifier].push_back( unit );
}



void AbstractMethodUnit::Add(const std::shared_ptr<AbstractUnit>& unit, Flags /* flags */  )
{
   m_body.push_back( unit );
}
