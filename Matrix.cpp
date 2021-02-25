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
	mat(m), dimx(m.size()), dimy(m[0].size())
{}


template<typename mat_type>
Matrix<mat_type>::Matrix(const Matrix<mat_type>& m)
{
	vector<vector<mat_type>> a(m.shape().first, vector<mat_type>(m.shape().second, 0));

	for (size_t i = 0; i < a.size(); i++)
	{
		for (size_t j = 0; j < a[0].size(); j++)
		{
			a[i][j] = m.vec()[i][j];
		}
	}

	*this = Matrix<mat_type>(a);
}


template <class mat_type>
Matrix<mat_type> Matrix<mat_type>::transpose()
{

	vector<vector<mat_type>> trans_vec(this->mat[0].size(), vector<mat_type>());

	for (size_t i = 0; i < this->mat.size(); i++)
	{
		for (size_t j = 0; j < this->mat[i].size(); j++)
		{
			trans_vec[j].push_back(this->mat[i][j]);
		}
	}
	
	Matrix ret(trans_vec);

	return ret; 
}




//TODO
//Matrix& Matrix::transpose(Matrix& m)
//{
//
//}

template <class mat_type>
Matrix<mat_type> Matrix<mat_type>::matmul(Matrix<mat_type>& m)
{
	vector<vector<mat_type>> a = this->vec();
	vector<vector<mat_type>> b = m.vec();
	vector<vector<mat_type>> c(a.size(), vector<mat_type>(b[0].size(), 0));

	if (a[0].size() != b.size())
	{
		throw "Matrices don't match (H x W @ W x H)";
	}

	for (int i = 0; i < c.size(); ++i) 
	{
		for (int j = 0; j < c[0].size(); ++j) 
		{
			for (int k = 0; k < a[0].size(); ++k) 
			{
				c[i][j] += (a[i][k] * b[k][j]);
			}
		}
	}
		
	Matrix ret(c);
	return ret;
}

template<typename mat_type>
pair<size_t, size_t> Matrix<mat_type>::shape() const
{
	return make_pair(this->mat.size(), this->mat[0].size());
}

template<typename mat_type>
vector<vector<mat_type>> Matrix<mat_type>::vec() const
{
	return mat;
}

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

//template <typename mat_type>
//Matrix<mat_type>& Matrix<mat_type>::operator=(const Matrix<mat_type>& m)
//{
//	Matrix<mat_type> ret(m.vec());
//	return ret;
//}


