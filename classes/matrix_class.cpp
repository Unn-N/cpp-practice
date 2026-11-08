#include<iostream>

using namespace std;

class Matrix {
public:
	int arr[3][3];

	Matrix() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				arr[i][j] = 0;
			}
		}
	}
	Matrix operator+(const Matrix& other)const;
	Matrix operator-(const Matrix& other)const;
	Matrix operator*(const Matrix& other)const;

	friend ostream& operator<<(ostream& os, const Matrix& m);
};

ostream& operator<<(ostream& os, const Matrix& m) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			os << m.arr[i][j] << " ";
		}
		os << endl;
	}
	return os;
}

Matrix Matrix::operator+(const Matrix& other)const {
	Matrix res;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res.arr[i][j] = this->arr[i][j] + other.arr[i][j];
		}
	}
	return res;
}

Matrix Matrix::operator-(const Matrix& other)const {
	Matrix res;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			res.arr[i][j] = this->arr[i][j] - other.arr[i][j];
		}
	}
	return res;
}

Matrix Matrix::operator*(const Matrix& other)const {
	Matrix res;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				res.arr[i][j] += this->arr[i][k] * other.arr[k][j];
			}
		}
	}
	return res;
}

int main() {
	Matrix a, b;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a.arr[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> b.arr[i][j];
		}
	}

	cout << a + b;
	cout << a - b;
	cout << a * b;
}