#ifndef _CARRIER_
#define _CARRIER_

#include <iostream>
#include "droid.hh"

class Carrier
{
    public:
	Carrier(std::string id);
	~Carrier();

	std::string getId() const;
	void setId(std::string serial);

	size_t getEnergy() const;
	void setEnergy(size_t energy);
	
	size_t getAttack() const;

	size_t getToughness() const;

	size_t getSpeed() const;
	void setSpeed(size_t speed);

	Carrier& operator<<(Droid*& droid);
	Carrier& operator>>(Droid*& droid);
	Droid const *&operator[](unsigned int const index);
	Droid const *operator[](unsigned int const i) const;
	Carrier& operator~();
	bool operator()(int x, int y);
    private:
	std::string _id;
	size_t _energy;
	size_t const _attack;
	size_t const _toughness;
	size_t _speed;
	Droid* _droids[5];
};

std::ostream& operator<<(std::ostream& os, Carrier const& carrier);

#endif
