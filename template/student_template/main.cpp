#include<iostream>
#include<string>
#include <algorithm>

using namespace std;

class Student {
private:
	int id;
	string name;
	int score;
public:
	Student() :id(0), name(""), score(0) {}
	Student(int a, string b, int c) :id(a), name(b), score(c) {}
	int getScore()const ;
	int getId()const;

	bool operator>(const Student&other)const;

	friend istream& operator>>(istream& in,Student& s);
	friend ostream& operator<<(ostream& out,const Student& s);

};

template<typename T>
class Array {
private:
	int size;
	T* arr;
public:
	Array(int n) {
		size = n;
		arr = new T[n];
	}
	~Array() {
		delete[] arr;
	}
	void sort();

	template<typename U>
	friend istream& operator>>(istream& in, Array<U>& a);

	template<typename U>
	friend ostream& operator << (ostream & out, const Array<U>&a);
};

int Student::getId()const {
	return id;
}

int Student::getScore()const {
	return score;
}

bool Student::operator>(const Student& other)const {
	if (this->score > other.score) {
		return true;
	}
	else {
		return false;
	}
}

istream& operator>>(istream& in, Student& s) {
	in >> s.id >> s.name >> s.score;
	return in;
}

ostream& operator<<(ostream& out,const Student& s) {
	out << s.id;
	return out;
}



template<typename T>
void Array<T>::sort() {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template<typename T>
istream& operator>>(istream& in, Array<T>& a) {
	for (int i = 0; i < a.size; i++) {
		in >> a.arr[i];
	}
	return in;
}

template<typename T>
ostream
& operator<<(ostream& out, const Array<T>& a) {
	for (int i = 0; i < a.size; i++) {
		out<< a.arr[i] << " ";
	}
	return out;
}




int main() {
	int num;
	cin >> num;
	Array<int> array_int(num);
	cin >> array_int;
	array_int.sort();
	
	Array<double> array_double(num);
	cin >> array_double;
	array_double.sort();

	Array<string> array_string(num);
	cin >> array_string;
	array_string.sort();
	
	Array<Student> array_student(num);
	cin >> array_student;
	array_student.sort();

	cout << array_int << endl;
	cout << array_double << endl;
	cout << array_string << endl;
	cout << array_student << endl;
}