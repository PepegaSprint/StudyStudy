#include "MatrixBase.h"


class Matrix3D : public MatrixBase
{
public:
    Matrix3D() : MatrixBase(m_size) {};
    virtual int element(unsigned int i, unsigned int j) const;
    virtual int& element(unsigned int i, unsigned int j);
    


private:
    static const int m_size = 3;
    int arr[m_size][m_size];

};

