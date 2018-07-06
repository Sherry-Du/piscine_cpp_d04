#include "droidmemory.hh"
#include <cstdlib>

DroidMemory::DroidMemory():_fingerPrint(random()), _exp(0){}

DroidMemory::~DroidMemory(){}

size_t DroidMemory::getFingerPrint() const
{
    return this->_fingerPrint;
}
void DroidMemory::setFingerPrint(size_t fingerPrint)
{
    this->_fingerPrint = fingerPrint;
}
size_t DroidMemory::getExp() const
{
    return this->_exp;
}
void DroidMemory::setExp(size_t exp)
{
    this->_exp = exp;
}

DroidMemory& DroidMemory::operator<<(DroidMemory const& other)
{
    _exp += other.getExp();
    _fingerPrint ^= other.getFingerPrint();
    return *this;
}
DroidMemory const& DroidMemory::operator>>(DroidMemory& other)
{
    other.setExp(other.getExp() + _exp);
    other.setFingerPrint(other.getFingerPrint()^_fingerPrint);
    return *this;
}

DroidMemory& DroidMemory::operator+=(DroidMemory const& other)
{
    _exp += other.getExp();
    _fingerPrint ^= other.getFingerPrint();
    return *this;
}
DroidMemory& DroidMemory::operator+=(size_t const other)
{
    _exp += other;
    _fingerPrint ^= other;
    return *this;
}

DroidMemory DroidMemory::operator+(DroidMemory const& other) const
{
    DroidMemory dm;
    dm.setExp(_exp + other.getExp());
    dm.setFingerPrint(_fingerPrint ^ other.getFingerPrint());
    return dm;
}
DroidMemory DroidMemory::operator+(size_t const other) const
{
    DroidMemory dm;
    dm.setExp(_exp + other);
    dm.setFingerPrint(_fingerPrint ^ other);
    return dm;
}

bool DroidMemory::operator==(DroidMemory const& other) const
{
    return ((_exp == other._exp) && (_fingerPrint == other._fingerPrint));
}
bool DroidMemory::operator!=(DroidMemory const& other) const
{
    return ((_exp != other._exp) || (_fingerPrint != other._fingerPrint));
}
bool DroidMemory::operator>(DroidMemory const& other) const
{
    return (_exp > other._exp);
}
bool DroidMemory::operator>(size_t const& other) const
{
    return (_exp > other);
}
bool DroidMemory::operator>=(DroidMemory const& other) const
{
    return (_exp >= other._exp);
}
bool DroidMemory::operator>=(size_t const& other) const
{
    return (_exp >= other);
}
bool DroidMemory::operator<(DroidMemory const& other) const
{
    return (_exp < other._exp);
}
bool DroidMemory::operator<(size_t const& other) const
{
    return (_exp < other);
}
bool DroidMemory::operator<=(DroidMemory const& other) const
{
    return (_exp <= other._exp);
}
bool DroidMemory::operator<=(size_t const& other) const
{
    return (_exp <= other);
}

std::ostream& operator<<(std::ostream& os, DroidMemory const& droid)
{
    std::cout << "DroidMemory '" << droid.getFingerPrint() << "', " << droid.getExp();
    return os;
}

