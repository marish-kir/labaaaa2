#ifndef UNIT_H
#define UNIT_H
#include <string>
#include <memory>
#include <cassert>

class Unit
{
public:
    using Flags = unsigned int;
    virtual void add(const std::shared_ptr<Unit>& unit, Flags flags);
    virtual std::string compile( unsigned int level = 0 ) const = 0;
    virtual ~Unit() = default;
protected:
    virtual std::string generateShift( unsigned int level ) const;
};

#endif // UNIT_H
