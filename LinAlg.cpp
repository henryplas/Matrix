// LinAlg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"


using namespace std;

int main()
{
    Matrix<int>  *m = new Matrix<int>(3, 4, 12);
    
    vector<vector<int>> a(4, vector<int>(5, 8));


    //indexing test
    cout << (*m)(1, 2) << endl;


    (*m)(1, 2) = 2;

    cout << (*m)(1, 2) << endl;

    Matrix<int> q(a);

    cout << q << endl;

    cout << q.transpose() << endl;


}
