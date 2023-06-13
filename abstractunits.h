#ifndef ABSTRACTUNITS_H
#define ABSTRACTUNITS_H
#include <vector>
#include <string>
#include <memory>
#include <cassert>

class AbstractUnit
{
public:
    using Flags = unsigned int;
    virtual void Add(const std::shared_ptr<AbstractUnit>& unit, Flags flags);
    virtual std::string Compile( unsigned int level = 0 ) const = 0;
    virtual ~AbstractUnit() = default;
protected:
    virtual std::string GenerateShift( unsigned int level ) const;
};

class AbstractClassUnit : public AbstractUnit
{
public:
    enum AccessModifier {
     PUBLIC,
     PROTECTED,
     PRIVATE
     };

    static const std::vector< std::string > ACCESS_MODIFIERS;
protected:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<AbstractUnit>>;
    std::vector<Fields> m_fields;

public:
    explicit AbstractClassUnit( const std::string& name ) : m_name(name){
         m_fields.resize( ACCESS_MODIFIERS.size() );
    }
    void Add(const std::shared_ptr< AbstractUnit >& unit, Flags flags );

};
class AbstractMethodUnit:public AbstractUnit
{
protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<AbstractUnit>>  m_body;
public:
     enum Modifier {
     STATIC = 1,
     CONST = 1 << 1,
     VIRTUAL = 1 << 2,
     };

public:
    AbstractMethodUnit( const std::string& name, const std::string& returnType, Flags flags ) : m_name( name ), m_returnType( returnType ), m_flags( flags ){}
    void Add(const std::shared_ptr<AbstractUnit>& unit, Flags /* flags */ = 0 );


};
class AbstractPrintOperatorUnit:public AbstractUnit
{
public:
    explicit AbstractPrintOperatorUnit( const std::string& text ) : m_text( text ) { }
protected:
     std::string m_text;
};

#endif // ABSTRACTUNITS_H
