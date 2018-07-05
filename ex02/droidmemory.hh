#ifndef _DROIDMEMORY_
#define _DROIDMEMORY_

#include <iostream>

class DroidMemory
{
    public:
	DroidMemory();
	~DroidMemory();

	size_t getFingerPrint() const;
	void setFingerPrint(size_t fingerPrint);
	size_t getExp() const;
	void setExp(size_t exp);

	DroidMemory& operator<<(DroidMemory const& other);
	DroidMemory const& operator>>(DroidMemory& other);
	DroidMemory& operator+=(DroidMemory const& other);
	DroidMemory& operator+=(size_t const other);
	DroidMemory operator+(DroidMemory const& other) const;
	DroidMemory operator+(size_t const other) const;

	bool operator==(DroidMemory const& other) const;
	bool operator!=(DroidMemory const& other) const;
	bool operator>(DroidMemory const& other) const;
	bool operator>(size_t const& other) const;
	bool operator>=(DroidMemory const& other) const;
	bool operator>=(size_t const& other) const;
	bool operator<(DroidMemory const& other) const;
	bool operator<(size_t const& other) const;
	bool operator<=(DroidMemory const& other) const;
	bool operator<=(size_t const& other) const;
    private:
	size_t _fingerPrint;
	size_t _exp;
};

std::ostream& operator<<(std::ostream& os, DroidMemory const& droid);

#endif
