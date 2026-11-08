#include<iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int x) :val(x), next(nullptr) {}
};

void josephus(int n, int k) {
	if (n <= 0 || k <= 0)return;

	Node dummy(0);
	Node* tail = &dummy;

	for (int i = 1; i <= n; i++) {
		tail->next = new Node(i);
		tail = tail->next;
	}

	Node* head = dummy.next;
	tail->next = head;

	int count = 1;
	Node* p = head;
	Node* prev = tail;

	while (p->next!=p) {
		
		
		if (count == k) {
			cout << p->val << "->";

			Node* removed = p;
			prev->next = p->next;
			p = p->next;
			delete removed;

			count = 1;
		}
		else {
			prev = p;
			p = p->next;
			count++;
		}

	}
	cout << p->val << endl;
	delete p;

}

int main() {
	int n, k;
	cin >> n >> k;

	josephus(n, k);


	return 0;
}