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
	


private:
	std::vector<std::vector<mat_type>> mat;
	int dimx;
	int dimy;

	
public:

	Matrix(int dim_x, int dim_y, mat_type inst);
	Matrix(int dim_x, int dim_y);
	Matrix(std::vector<std::vector<mat_type>> &obj);
	Matrix(const Matrix<mat_type>& m);

	Matrix transpose();
	//Matrix& transpose(Matrix& m);
	Matrix matmul(Matrix& m);
	std::pair<std::size_t, std::size_t> shape() const;
	std::vector<std::vector<mat_type>> vec() const;
	mat_type& operator() (const size_t a, const size_t b);
	//Matrix& operator=(const Matrix& m);

};


#endif