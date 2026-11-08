#include<iostream>

using namespace std;

class List {
private:
	struct Node {
		int val;
		Node* next;
		Node(int val) :val(val), next(nullptr) {}
	};
	Node* sentinel;
	int len;

public:
	List(int first) {
		sentinel = new Node(0);
		sentinel->next = new Node(first);
		len = 1;
	}

	List() {
		sentinel = new Node(0);
		sentinel->next = nullptr;
		len = 0;
	}
	~List() {
		Node* p = sentinel;
		while (p) {
			Node* next = p->next;
			delete p;
			p = next;
		}
	}

	void push_front(int x) {
		Node* p = new Node(x);
		p->next = sentinel->next;
		sentinel->next = p;
		len++;
	}

	void print() {
		Node* p = sentinel->next;
		while (p) {
			cout << p->val << " ";
			p = p->next;
		}
	}

	bool isEmpty() {
		return sentinel->next == nullptr;
	}

	int length() {
		return len;
	}

	int get(int k) {
		if (k < 0 || k >= len) {
			throw out_of_range("index out of range");
		}
		Node* p = sentinel->next;

		for (int i = 0; i < k; i++) {
			p = p->next;
		}
		return p->val;
	}

	bool remove(int k) {
		if (k < 0 || k >= len) {
			return false;
		}
		Node* p = sentinel;
		for (int i = 0; i < k; i++) {
			p = p->next;
		}
		Node* q = p->next;
		p->next = q->next;
		delete q;
		len--;
		return true;

	}
};