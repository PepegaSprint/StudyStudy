#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"
#include "MatrixBase.h"
using namespace std;

void fillArray(MatrixBase&arr, int startValue)
{
    for (int i = 0; i < arr.size(); i++)
        for (int j = 0; j < arr.size(); j++)
           arr.element(i,j) = startValue++;
}


int main()
{
    Matrix2D m2a, m2b;
    Matrix3D m3a, m3b;
    
    fillArray(m2a, 4);
    fillArray(m2b, 2);
    fillArray(m3a, 6);
    fillArray(m3b, 1);
    cout << m2a << endl;
    cout << m2b << endl;
    cout << m3a << endl;
    cout << m3b << endl;
    m2a +=  m2b;
    m3b *= 3;
    cout << m2a << endl;
    cout << m3b << endl;


    return 0;
}

