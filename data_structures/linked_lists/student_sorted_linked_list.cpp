#include<iostream>
#include<string>

using namespace std;

template<typename T>
struct Node {
	T val;
	Node* next;
	Node(T val) :val(val), next(nullptr) {}
};

struct Student {
	int id;
	string name;
	Student(int id, string name) :id(id), name(name) {}
	bool operator<(Student& other) {
		return this->id < other.id;
	}
	friend ostream& operator<<(ostream& os, Student st) {
		os << st.name;
		return os;
	}
};

template<typename T>
class LinkedList {
private:
	Node<T>* head = nullptr;
public:
	void insert(T val) {
		Node<T>* newNode = new Node<T>(val);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		if (newNode->val < head->val) {
			newNode->next = head;
			head = newNode;
			return;
		}
		Node<T>* p = head;
		while (p->next && p->next->val < newNode->val) {
			p = p->next;
		}
		newNode->next = p->next;
		p->next = newNode;
	}
	void print()const {
		Node<T>* p = head;
		while (p) {
			cout << p->val << endl;
			p = p->next;
		}
	}

	~LinkedList() {
		Node<T>* p = head;
		while (p) {
			Node<T>* q = p->next;
			delete p;
			p = q;
		}
	}
};

int main() {
	LinkedList <Student>ls;
	string name;
	int id;

	while (cin >> name>> id) {
		ls.insert(Student(id, name));
	}
	ls.print();
	return 0;
}