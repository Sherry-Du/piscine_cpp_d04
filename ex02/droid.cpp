#include "droid.hh"
#include "droidmemory.hh"

Droid::Droid(std::string serial):_serial(serial), _energy(50), _attack(25), _toughness(15), _status(new std::string("Standing by")), _battleData(new DroidMemory())
{
    std::cout << "Droid '" << _serial << "' Activated" << std::endl;
}

Droid::~Droid()
{
    if(_status)
	delete _status;
    std::cout << "Droid '" << _serial << "' Destroyed" << std::endl;
}

Droid::Droid(Droid const& droid):_serial(droid._serial), _energy(50), _attack(25), _toughness(15), _status(new std::string(*(droid._status))), _battleData(new DroidMemory(*(droid._battleData)))
{
    std::cout << "Droid '" << _serial << "' Activated, Memory Dumped" << std::endl;
}

std::string Droid::getId() const
{
    return this->_serial;
}

void Droid::setId(std::string serial)
{
    this->_serial = serial;
}

size_t Droid::getEnergy() const
{
    return this->_energy;
}

void Droid::setEnergy(size_t energy)
{
    if(energy > 100)
	energy = 100;
    this->_energy = energy;
}

size_t Droid::getAttack() const
{
    return this->_attack;
}

size_t Droid::getToughness() const
{
    return this->_toughness;
}

std::string* Droid::getStatus() const
{
    return this->_status;
}

void Droid::setStatus(std::string* status)
{
    if(this->_status)
	delete this->_status;
    this->_status = status;
}

bool Droid::operator==(Droid const& other) const
{
    bool isEqual = (*_status == *(other._status));
    return isEqual;
}
	
bool Droid::operator!=(Droid const& other) const
{
    bool notEqual = (*_status != *(other._status));
    return notEqual;
}

Droid& Droid::operator=(Droid const& droid)
{
    if (this != &droid)
    {
        if(this->_status)
	    delete this->_status;
        this->_status = new std::string(*(droid._status));
        this->_energy = droid._energy;
        this->_serial = droid._serial;
	if(_battleData)
	    delete _battleData;
	_battleData = new DroidMemory(*(droid.getBattleData()));
    }
    return *this;
}

Droid& Droid::operator<<(size_t& other)
{
    size_t required = 100 - this->_energy;
    if(other >= required)
    {
        _energy = 100;
        other -= required;
    }
    else
    {
        _energy += other;
        other = 0;
    }
    return *this;
}

void Droid::setBattleData(DroidMemory* dm)
{
    this->_battleData = dm;
}
DroidMemory* Droid::getBattleData() const
{
    return this->_battleData;
}

std::ostream& operator<<(std::ostream& os, Droid const& droid)
{
    std::cout << "Droid '" << droid.getId() << "', " << *(droid.getStatus()) << ", " << droid.getEnergy();
    return (os);
}

int main()
{
 DroidMemory dm;
 DroidMemory dn;
 DroidMemory dg;
 dm += 42;
 DroidMemory dn1 = dm;
 std::cout << dm << std::endl;
 dn << dm;
 dn >> dm;
 dn << dm;
 std::cout << dn << std::endl;
 std::cout << dm << std::endl;
 dg = dm + dn1;

 Droid d("rudolf");
 Droid d2("gaston");
 size_t DuraSell = 40;
 d << DuraSell;
 d.setStatus(new std::string("having some reset"));
 d2.setStatus(new std::string("having some reset"));
 if (d2 != d && !(d == d2))
 std::cout << "a droid is a droid, all its matter is what it’s doing"<<
 std::endl;
 d(new std::string("take a coffee"), 20);
 std::cout << d << std::endl;
 while (d(new std::string("Patrol around"), 20))
{
 if (!d(new std::string("Shoot some ennemies"), 50))
 d(new std::string("Run Away"), 20);
 std::cout << d << std::endl;
 }
 std::cout << d << std::endl;
 return (0);
 }



