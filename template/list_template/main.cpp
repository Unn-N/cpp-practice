#include<iostream>
#include<string>
using namespace std;

struct Node {
	int id;
	string name;
	Node* next;
	Node(int a, string b) :id(a), name(b), next(nullptr) {}
};

template<typename T>
class List {
private:
	Node* head;
public:
	List() {
		head = nullptr;
	}
	~List() {
		Node* p = head;
		while (p) {
			Node* q = p->next;
			delete p;
			p = q;
		}
	}
	void insert(int id, string name) {
		Node* newNode = new Node(id, name);
		if (head == nullptr) {
			head = newNode;
			return;
		}

		if (id < head->id) {
			newNode->next = head;
			head = newNode;
			return;
		}

		Node* p = head;
		while (p->next && p->next->id < id) {
			p = p->next;
		}
		newNode->next = p->next;
		p->next = newNode;
	}

	void print()const {
		Node* p = head;
		while (p) {
			cout << p->name << endl;
			p = p->next;
		}
	}
};

int main() {
	string name;
	List <int> l;
	int id;
	while (cin >> name >> id) {
		l.insert(id, name);
	}
	l.print();
	return 0;
}