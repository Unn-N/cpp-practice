#include<iostream>

using namespace std;

class Student {
private:
	int id;
	char name[100];
	int score;
public:
	bool operator<(Student& other) {
		return this->score < other.score;
	}
	friend istream& operator>>(istream& is, Student& s) {
		is >> s.id >> s.name >> s.score;
		return is;
	}
	friend ostream& operator<<(ostream& os, const Student& s) {
		os << s.id;
		return os;
	}
	

};

template<typename T>
class Array {
private:
	int size;
	T* element;
public:
	~Array() { delete[] element; }
	Array(int num) {
		size = num;
		element = new T[size];
	}
	friend istream& operator>>(istream& is, Array& arr) {
		for (int i = 0; i < arr.size; i++) {
			is >> arr.element[i];
		}
		return is;
	}
	friend ostream& operator<<(ostream& os, const Array& arr) {
		for (int i = 0; i < arr.size; i++) {
			os << arr.element[i]<<" ";
		}
		return os;
	}
	void sort() {
		for (int i = 0; i < size-1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (element[j + 1] < element[j]) {
					T temp = element[j];      
					element[j] = element[j + 1];
					element[j + 1] = temp;
				}
			}
		}
	}
};

int main() {
	int num;
	cin >> num;
	/*Array<int> array_int(num);
	cin >> array_int;
	array_int.sort();
	cout << array_int << endl;*/

	Array<Student> array_student(num);
	cin >> array_student;
	array_student.sort();
	cout << array_student << endl;
	
}