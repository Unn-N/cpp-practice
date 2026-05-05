#include<iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int val) :val(val), next(nullptr) {}
};

class List {
public:
	Node* head;
	Node* tail;
	List() { head = nullptr; }
	void insert(int n);
	void print();
	void solution();
};

//插入到尾部
void List::insert(int n) {
	Node* newNode = new Node(n);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

void List::print() {
	if (head == nullptr) {
		cout << "NULL" << endl;
		return;
	}
	Node* p = head;
	while (p != nullptr) {
		if (p->next != nullptr) {
			cout << p->val << " ";
		}
		else {
			cout << p->val;
		}
		p = p->next;
	}
	cout << endl;
}
//双指针维护两个链表，注意偶数链表尾节点可能问题
void List::solution() {
	if (head == nullptr || head->next == nullptr)return;

	Node* oddHead = head;
	Node* oddTail = oddHead;
	Node* evenHead = head->next;
	Node* evenTail = evenHead;
	Node* p = evenHead->next;
	bool isOdd = true;

	while (p != nullptr) {
		if (isOdd) {
			oddTail->next = p;
			oddTail = p;
		}
		else {
			evenTail->next = p;
			evenTail = p;
		}
		p = p->next;
		isOdd = !isOdd;
	}

	evenTail->next = nullptr;
	oddTail->next = evenHead;
	head = oddHead;
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		List list;
		while (m--) {
			int val;
			cin >> val;
			list.insert(val);
		}
		list.solution();
		list.print();
	}

	return 0;
}