#include<iostream>

using namespace std;

template<typename T>
struct Node {
	T val;
	Node* next;
	Node(T val) :val(val), next(nullptr) {}
};

template<typename T>
class List {
public:
	Node<T>* dummy;
	List() {
		dummy = new Node<T>(T{});
		dummy->next = nullptr;
	}
	virtual ~List() {}

	virtual void Insert(T val) {
		Node<T>* prev = dummy;
		while (prev->next && prev->next->val > val) {
			prev = prev->next;
		}
		Node<T>* node = new Node<T>(val);
		node->next = prev->next;
		prev->next = node;
	}

	virtual void Remove(T val) {
		Node<T>* prev = dummy;
		while (prev->next) {
			if (prev->next->val == val) {
				Node<T>* del = prev->next;
				prev->next = del->next;
				delete del;
			}
			else {
				prev = prev->next;
			}
		}
	}

	T& operator[](int idx) {
		Node<T>* p = dummy->next;
		while (idx-- > 0 && p)p = p->next;
		return p->val;
	}

	friend istream& operator>>(istream& is, List<T>& ls) {
		int cnt;
		is >> cnt;
		for (int i = 0; i < cnt; i++) {
			T v;
			is >> v;
			ls.insert(v);
		}
		return is;
	}

	friend ostream& operator<<(ostream& os, List<T>& ls) {
		Node<T>* p = ls.dummy->next;
		bool first = true;
		while (p) {
			if (!first) {
				os << ' ';
			}
			os << p->val;
			first = false;
			p = p->next;
		}
		return os;
	}
};

template<class T>
class Stack :public List<T> {
public:
	void Insert(T val) override{
		Node<T>* node = new Node<T>(val);
		node->next = this->dummy->next;
		this->dummy->next = node;
	}
	void Remove(T)override {
		Node<T>* d = this->dummy;
		if (d->next) {
			Node<T>* del = d->next;
			d->next = del->next;
			delete del;
		}
	}
};


template<class T>
class Queue : public List<T> {
public:
	void Insert(T val) override {              
		Node<T>* prev = this->dummy;
		while (prev->next) prev = prev->next;
		prev->next = new Node<T>(val);
	}
	void Remove(T) override {                 
		Node<T>* d = this->dummy;
		if (d->next) { Node<T>* del = d->next; d->next = del->next; delete del; }
	}
};


template<class T>
void run(char sc) {
	List<T>* c;
	if (sc == 'S') c = new Stack<T>();
	else if (sc == 'Q') c = new Queue<T>();
	else c = new List<T>();
	cin >> *c;  cout << *c << "\n";           
	char op; cin >> op;
	if (op == 'A') { T v; cin >> v; c->Insert(v); }
	else if (sc == 'L') { T v; cin >> v; c->Remove(v); }
	else c->Remove(T{});                      
	cout << *c << "\n";                      
	int idx; cin >> idx; cout << (*c)[idx] << "\n";  
	delete c;
}

int main() {
	char sc, tc; cin >> sc >> tc;
	if (tc == 'I') run<int>(sc);
	else if (tc == 'D') run<double>(sc);
	else run<char>(sc);
}