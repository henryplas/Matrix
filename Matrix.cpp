#include "Matrix.h"
using namespace std;

template <class mat_type>
Matrix<mat_type>::Matrix(int dim_x, int dim_y, mat_type inst) :
	dimx(dim_x), dimy(dim_y)
{
	mat = new vector<vector<mat_type>>(dim_x);
	for (int i = 0; i < dim_x; i ++)
		mat->push_back(vector<mat_type>(dim_y, inst));

}


template <class mat_type>
ostream& operator<<(ostream& os, const Matrix<mat_type>& m)
{
	os << "[";
	for (int i = 0; i < m.mat->size(); ++i) 
	{

		os << "[";

		for (int j = 1; j < m.mat[i]->size(); ++j) 
		{
			os << " " << m.mat[i][j];
		}

		os << "]" << endl;
	}

	os << "]" << endl;
	return os;
}