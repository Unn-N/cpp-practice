#include<iostream>

using namespace std;

template<typename T>
class Transport {
public:
	T* products;
	Transport() {
		products = new T[5];
	}
	~Transport() {
		delete[] products;
	}
	void append(T);
	int find(T);
};

template<typename T>
void Transport<T>::append(T t) {
	static int index = 0;
	products[index++] = t;
}

template<typename T>
int Transport<T>::find(T item) {
	for (int i = 0; i < 5; i++) {
		if (products[i] == item) {
			return i;
		}
	}
	return -1;
}

class Book {
private:
	int id;
	char* bookname;
public:
	Book() {}
	Book(int id, char* name) :id(id), bookname(name) {}
	bool operator==(const Book& other) const {
		return this->id == other.id;
	}
	string getBookName() {
		return bookname;
	}
};

int main() {
	Book* arr = new Book[5];
	Transport<Book> t;
	for (int i = 0; i < 5; i++) {
		int id;
		char name[100];
		cin >> id >> name;
		arr[i] = Book(id, name);
		t.append(arr[i]);
	}

	int id;
	cin >> id;

	int pos = t.find(Book(id, nullptr));
	cout << t.products[pos].getBookName();
	delete[] arr;
	return 0;
}