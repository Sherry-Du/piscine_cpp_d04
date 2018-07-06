#include <cstdlib>
#include "carrier.hh"

Carrier::Carrier(std::string id) : _id(id), _energy(300), _attack(100), _toughness(90), _speed(0)
{
    for (int i = 0; i != 5; i++)
    {
	_droids[i] = NULL;
    }
}

Carrier::~Carrier()
{
    for (int i = 0; i != 5; i++)
    {
	if (_droids[i])
	    delete _droids[i];
    }
}

std::string Carrier::getId() const
{
    return this->_id;
}
void Carrier::setId(std::string id)
{
    this->_id = id;
}
size_t Carrier::getEnergy() const
{
    return this->_energy;
}
void Carrier::setEnergy(size_t energy)
{
    if(energy > 100)
	energy = 100;
    this->_energy = energy;
}

size_t Carrier::getAttack() const
{
    return this->_attack;
}

size_t Carrier::getToughness() const
{
    return this->_toughness;
}

size_t Carrier::getSpeed() const
{
    return this->_speed;
}
void Carrier::setSpeed(size_t speed)
{
    this->_speed = speed;
}

Carrier& Carrier::operator<<(Droid*& droid)
{
    for (int i = 0; i < 5; ++i) {
	if (!_droids[i]) {
	    _droids[i] = droid;
	    droid = NULL;
	    ~(*this);
	    return *this;
	}
    }
    return *this;
}

Carrier& operator<<(Carrier& carrier, size_t& other)
{
    if (carrier.getEnergy() + other > 600) {
	other -= 600 - carrier.getEnergy();
	carrier.setEnergy(600);
    } else {
	carrier.setEnergy(carrier.getEnergy() + other);
	other = 0;
    }
    return carrier;
}

Carrier& Carrier::operator>>(Droid*& droid)
{
    for (int i = 0; i < 5; ++i) {
	if (_droids[i]) {
	    droid = _droids[i];
	    _droids[i] = NULL;
	    ~(*this);
	    return *this;
	}
    }
    droid = NULL;
    return *this;
}

Droid const *&Carrier::operator[](unsigned int const index)
{
    return (Droid const *&)_droids[index];
}

Droid const *Carrier::operator[](unsigned int const i) const
{
    return _droids[i];
}

Carrier& Carrier::operator~()
{
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
	if (!(_droids[i]))
	    count++;
    }
    if(count)
	_speed = 100 - (10 * count);
    else
	_speed = 0;
    return *this;
}

bool Carrier::operator()(int x, int y)
{
    size_t required;
    int count = 0;
    for (int i = 0; i != 5; i++)
    {
        if (!(_droids[i]))
	    count++;
    }
    required = (abs(x) + abs(y)) * (10 + count);
    if (_speed <= 0 || required > _energy)
	return false;
    else
	return true;
}

std::ostream& operator<<(std::ostream& os, Carrier const& carrier)
{
    std::cout << "Carrier '" << carrier.getId() << "; Droid(s) on-board:";
    for (int i = 0; i != 5; ++i)
    {
        if (carrier[i])
 	    std::cout << '[' << i << "] : Droid '" << carrier[i] << "', Standing by, " << carrier[i]->getEnergy() << std::endl;
        else
	    std::cout << '[' << i << "] : Free" << std::endl;
    }
    std::cout << "Speed : " << carrier.getSpeed() << ", Energy " << carrier.getEnergy() << std::endl;
    return os;
}


