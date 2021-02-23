#include "Matrix.h"

using namespace std;


template <class mat_type>
Matrix<mat_type>::Matrix(int dim_x, int dim_y, mat_type inst) :
	dimx(dim_x), dimy(dim_y)
{
	for (int i = 0; i < dim_x; i ++)
		mat.push_back(vector<mat_type>(dim_y, inst));
}

template <class mat_type>
Matrix<mat_type>::Matrix(int dim_x, int dim_y) :
	dimx(dim_x), dimy(dim_y)
{
	for (int i = 0; i < dim_x; i++)
		mat.push_back(vector<mat_type>(dim_y));
}


template <class mat_type> 
Matrix<mat_type>::Matrix(vector<vector<mat_type>> & m) :
	mat(m), dimx(), dimy()
{
	
}


template <class mat_type>
Matrix<mat_type>& Matrix<mat_type>::transpose()
{
	vector<vector<mat_type>> trans_vec(this.mat[0].size(), vector<mat_type>());

	for (int i = 0; i < this.mat.size(); i++)
	{
		for (int j = 0; j < this.mat[i].size(); j++)
		{
			trans_vec[j].push_back(this.mat[i][j]);
		}
	}

	Matrix ret(trans_vec);
	return &ret; 
}


//TODO
//Matrix& Matrix::transpose(Matrix& m)
//{
//
//}

template <class mat_type>
ostream& operator<<(ostream& os, const Matrix<mat_type>& m)
{
	os << "[";

	for (size_t i = 0; i < m.mat.size(); ++i) 
	{

		os << "[";

		for (size_t j = 0; j < m.mat[i].size(); ++j) 
		{
			os << " " << m.mat[i][j];
		}		

		if (i == m.mat.size() - 1)
		{
			os << "]";
		}
		else
		{
			os << "]" << endl;
		}
	}

	os << "]" << endl;
	return os;
}


template <typename mat_type>
mat_type& Matrix<mat_type>::operator() (size_t x, size_t y)
{
	return mat[x][y];
}

