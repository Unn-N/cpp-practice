#include<iostream>
#include<string>
#include<cctype>

using namespace std;

struct Node {
	char val;
	Node* next;
	Node* pre;
	Node() {
		val = ' ';
		next = nullptr;
		pre = nullptr;
	}
	Node(char c) {
		val = c;
		next = nullptr;
		pre = nullptr;

	}
};

class List {
public:
	Node* head;
	Node* tail;
	List() {
		head = nullptr;
		tail = nullptr;
	}
	void append(char c) {
		if (head == nullptr) {
			Node* p = new Node(c);
			head = p;
			tail = p;
		}
		else {
			Node* p = new Node(c);
			tail->next = p;
			p->pre = tail;
			tail = p;
		}

	}
	void remove(Node* n) {
		
		Node* p = n;
		if (p->pre == nullptr&&p->next!=nullptr) {
			head = p->next;
			p->next->pre = nullptr;
			p->next = nullptr;
			delete p;
		}
		else if (p->next == nullptr&&p->pre!=nullptr) {
			tail = p->pre;
			p->pre->next = nullptr;
			p->pre = nullptr;
			delete p;
		}
		else if (p->pre == nullptr && p->next == nullptr) {
			head = nullptr;
			tail = nullptr;
			delete p;
		}
		else {
			p->pre->next = p->next;
			p->next->pre = p->pre;
			delete p;
		}
	}
	void print() {
		if (head == nullptr) {
			cout << -1;
		}
		else {
			Node* p = head;
			while (p) {
				cout << p->val;
				p = p->next;
			}
		}
	}
};

bool canRemove(char left, char right) {
	return (left != right) && (toupper(left) == toupper(right));
}

int main() {
	string str;
	cin >> str;
	List list = List();
	for (auto x : str) {
		list.append(x);
	}

	Node* cur = list.head;
	while ((list.head != list.tail) && cur != list.tail) {
		if (canRemove(cur->val, cur->next->val)) {
			Node* p = cur;
			if (cur->pre != nullptr) {
				cur = cur->pre;
				list.remove(p->next);
				list.remove(p);
			}
			else {
				list.remove(p->next);
				list.remove(p);
				cur = list.head;
			}
		}
		else {
			cur = cur->next;
		}
	}
	list.print();
	return 0;
}
/*还是会犯老错误, Node的生命周期,不能局部声明变量,要用new*/
//还有就是,head是一个身份.想要转移head的指向,应该写head=foo,而不是foo=head