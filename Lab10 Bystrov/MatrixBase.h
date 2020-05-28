#pragma once
#include <iostream>

class MatrixBase
{

public:
	virtual int element(unsigned int i, unsigned int j) const = 0;
	virtual int& element(unsigned int i, unsigned int j) = 0;

	unsigned int size() const;
	void operator*=(int iMult);
	void operator+=(MatrixBase &iAdd);


protected:
	MatrixBase(unsigned int iSize) : m_size(iSize) {};

private:
	const unsigned int m_size;
};
std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix);
