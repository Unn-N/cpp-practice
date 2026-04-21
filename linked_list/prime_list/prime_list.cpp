#include<iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int val) :val(val), next(nullptr) {}
};

class List {
private:
	Node* head;
	int len;
public:
	List():head(nullptr) {}
	~List() {
		Node* p = head;
		while (p != nullptr) {
			Node* temp = p;
			p = p->next;
			delete temp;
		}
		head = nullptr;
	}

	bool isPrime(int n) {
		if (n < 2)return false;
		if (n == 2)return true;
		if (n % 2 == 0)return false;
		for (int i = 3; i * i <= n; i += 2) {
			if (n % i == 0)return false;
		}
		return true;
	}

	void insert(int n) {
		if (!isPrime(n)) {
			return;
		}

		Node* newNode = new Node(n);

		if (head == nullptr || n < head->val) {
			newNode->next = head;
			head = newNode;
			return;
		}

		Node* pre = head;
		while (pre->next != nullptr && pre->next->val < n) {
			pre = pre->next;
		}
		newNode->next = pre->next;
		pre->next = newNode;
	}

	void print() {
		Node* p = head;
		bool first = true;
		while (p != nullptr) {
			if (!first) {
				cout << " ";
			}
			cout << p->val;
			first = false;
			p = p->next;
		}
		cout << endl;
	}
};

int main() {
	List list;
	int num;

	while (cin >> num) {
		list.insert(num);
	}

	list.print();

	return 0;
}
