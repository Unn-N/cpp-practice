#include<iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node() {
		val = 0;
		next = nullptr;
	}
	Node(int val, Node* next) :val(val), next(next) {}
};

class List {
public:
	Node* head;
	List() { head = nullptr; }
};

int main() {
	int n;
	cin >> n;
	int* arr1 = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	int headNum;
	cin >> headNum;

	List l;
	Node* arr2 = new Node[n];
	for (int i = 0; i < n; i++) {
		arr2[i].val = i + 1;
	}
	for (int i = 0; i < n; i++) {
		int nextNum = arr1[i];
		if (nextNum == 0) {
			arr2[i].next = nullptr;
		}
		else {
			arr2[i].next = &arr2[nextNum - 1];
		}
	}
	l.head = &arr2[headNum - 1];

	Node* p = l.head;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	return 0;
}