#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <vector>
using std::ostream;

template<class mat_type>
class Matrix;

template<class mat_type>
ostream& operator<<(ostream&, const Matrix<mat_type>& m);

template <class mat_type>
class Matrix
{
	friend ostream& operator<< <>(ostream&, const Matrix<mat_type>& m);

	mat_type& operator()(const unsigned&, const unsigned&);

private:
	std::vector<std::vector<mat_type>> mat;
	int dimx;
	int dimy;
	

public:

	Matrix(int dim_x, int dim_y, mat_type inst);

};


#endif