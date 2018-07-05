#ifndef _DROID_
#define _DROID_

#include <iostream>
#include "droidmemory.hh"

class Droid
{
    public:
	Droid(std::string serial = "");
	~Droid();
	Droid(Droid const& droid);

	std::string getId() const;
	void setId(std::string serial);

	size_t getEnergy() const;
	void setEnergy(size_t energy);
	
	size_t getAttack() const;

	size_t getToughness() const;

	std::string* getStatus() const;
	void setStatus(std::string* status);

	void setBattleData(DroidMemory* dm);
	DroidMemory* getBattleData() const;

	bool operator==(Droid const& other) const;	
	bool operator!=(Droid const& other) const;
	Droid& operator=(Droid const& droid);
	Droid& operator<<(size_t& other);
    private:
	std::string _serial;
	size_t _energy;
	size_t const _attack;
	size_t const _toughness;
	std::string* _status;
	DroidMemory* _battleData;
};

std::ostream& operator<<(std::ostream& os, Droid const& droid);

#endif
