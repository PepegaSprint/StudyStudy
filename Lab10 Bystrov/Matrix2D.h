#include "MatrixBase.h"

class Matrix2D : public MatrixBase
{
public:
    Matrix2D() : MatrixBase(m_size) {};
    virtual int element(unsigned int i, unsigned int j) const;
    virtual int& element(unsigned int i, unsigned int j);
    


private:
   static const int m_size = 2;
   int arr[m_size][m_size];

};
