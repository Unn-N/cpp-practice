#include<iostream>
#include<algorithm>
using namespace std;

template<typename T>
class list {
private:
	struct node {
		T data;
		node* next;
		node(T data) :data(data), next(nullptr) {}
	};
	node* head;
	node* tail;

public:
	list() :head(nullptr), tail(nullptr) {}
	void Insert(T item) {
		node* newnode = new node(item);
		if (head == nullptr) {
			head = newnode;
			tail = newnode;
			return;
		}
		newnode->next = head;
		head = newnode;
	}

	void Append(T item) {
		node* newnode = new node(item);
		if (head == nullptr) {
			head = newnode;
			tail = newnode;
			return;
		}
		tail->next = newnode;
		tail = newnode;
	}
	int count() {
		node* p = head;
		int idx = 0;
		while (p) {
			idx++;
			p = p->next;
		}
		return idx;
	}
	void htot() {
		if (head == nullptr || head->next == nullptr)return;
		node* p = head->next;

		tail->next = head;
		head->next = nullptr;
		tail = head;
		head = p;
	}
	void ttoh() {
		if (head == nullptr || head->next == nullptr)return;
		node* p = head;
		while (p->next->next != nullptr) {
			p = p->next;
		}
		tail->next = head;
		p->next = nullptr;
		head = tail;
		tail = p;
	}
	void display() {
		if (head == nullptr) {
			cout << "emptylist" << endl;
			return;
		}
		node* p = head;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	void SortList() {
		int len = count();
		if (len == 0) {
			cout << "emptylist" << endl;
			return;
		}
		T* arr = new T[len];
		node* p = head;
		for (int i = 0; i < len; i++) {
			arr[i] = p->data;
			p = p->next;
		}
		for (int i = 0; i < len - 1; i++) {
			for (int j = 0; j < len - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					swap(arr[j], arr[j + 1]);
				}
			}
		}
		for (int i = 0; i < len; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		delete[] arr;
	}
};

int main() {
	string type;
	int n;
	cin >> type >> n;
	if (type == "int") {
		list<int>link1;
		list<int>link2;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			link1.Append(x);
			link2.Insert(x);
		}
		cout << link1.count() << endl;
		link1.display();
		link1.ttoh();
		link1.display();
		cout << link2.count() << endl;
		link2.display();
		link2.htot();
		link2.display();
		link1.SortList();
	}
	else if (type == "char") {
		list<char> link1, link2;
		for (int i = 0; i < n; i++) {
			char x;
			cin >> x;
			link1.Append(x);
			link2.Insert(x);
		}
		cout << link1.count() << endl;
		link1.display();
		link1.ttoh();
		link1.display();
		cout << link2.count() << endl;
		link2.display();
		link2.htot();
		link2.display();
		link1.SortList();
	}
	return 0;
}
