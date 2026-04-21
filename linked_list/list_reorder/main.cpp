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

	Node* findMid();
	Node* reverse(Node* h);
	void merge(Node* l1, Node* l2);

public:
	List() {
		head = nullptr;
	}

	~List() {
		Node* p = head;
		while (p != nullptr) {
			Node* temp = p;
			p = p->next;
			delete temp;
		}
	}

	void append(int val) {
		Node* newNode = new Node(val);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node* p = head;
		while (p->next != nullptr) {
			p = p->next;
		}
		p->next = newNode;
	}

	void reorder() {
		if (!head || !head->next) return;

		Node* mid = findMid();
		Node* l2 = mid->next;
		mid->next = nullptr;
		l2 = reverse(l2);
		merge(head, l2);
	}

	void display() {
		Node* p = head;
		while (p) {
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}

	void ascend() {

	}
};

Node* List::findMid() {
	Node* fast = head;
	Node* slow = head;
	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

Node* List::reverse(Node* h) {
	Node* cur = h;
	Node* pre = nullptr;
	while (cur) {
		Node* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}

void List::merge(Node* l1, Node* l2) {
	while (l1 != nullptr && l2 != nullptr) {
		Node* next1 = l1->next;
		Node* next2 = l2->next;

		l1->next = l2;
		l2->next = next1;

		l1 = next1;
		l2 = next2;
	}
}

int main() {
	List list;

	list.append(1);
	list.append(2);
	list.append(3);
	list.append(4);
	list.append(5);

	list.display();
	list.reorder();
	list.display();

	return 0;
}