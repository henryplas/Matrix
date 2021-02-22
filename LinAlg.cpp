// LinAlg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"


using namespace std;

int main()
{
    Matrix<int>  *m = new Matrix<int>(3, 4, 12);

    cout << (*m)(1, 2);

}
