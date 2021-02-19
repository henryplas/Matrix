#include "Matrix.h"
using namespace std;

template <class mat_type>
Matrix<mat_type>::Matrix(int dim_x = 0, int dim_y = 0, mat_type inst = 0) :
	dimx(dim_x), dimy(dim_y)
{
	mat = new vector<vector<mat_type>>(dim_x);
	for (auto i : dim_x)
		mat->push_back(vector<mat_type>(dim_y, inst));

}

ostream& operator<<(ostream& os, const Matrix& m)
{
	for (int i = 0; i < m.size(); ++i) {
		os << m.p[i][0];
		for (int j = 1; j < m[i].size(); ++j) {
			os << " " << m.p[i][j];
		}
		os << endl;
	}
	return os;
}