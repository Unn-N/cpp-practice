#include<iostream>
#include<vector>
#include<algorithm>
#include <queue>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	int height;
	Node(int val) :val(val), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(Node* p) {
	if (p == nullptr) {
		return 0;
	}
	else
		return p->height;
}

void updateHeight(Node* p) {
	// [踩坑] 曾直接访问 p->left->height、p->right->height。
	// p 非空不代表孩子非空；用 getHeight 统一将空子树高度记为 0。
	int left = getHeight(p->left);
	int right = getHeight(p->right);
	p->height = max(left, right) + 1;
}

// [踩坑] 最初旋转函数只定义在 insert 后面；调用前需要声明或提前定义。
Node* rotateRight(Node* root);
Node* rotateLeft(Node* root);

Node* insert(Node* root, int x) {
	if (root == nullptr) {
		Node* p = new Node(x);
		return p;
	}

	// [踩坑] 最初只写了向左插入的分支，向右时会漏插并走到没有返回值的函数末尾。
	// 左右分支分别处理，随后统一更新高度并返回子树根。
	if (x < root->val) {
		root->left = insert(root->left, x);
	}
	else if (x > root->val) {
		root->right = insert(root->right, x);
	}
	updateHeight(root);

	// [踩坑] 回顾时曾把右侧过高的平衡因子算成正数；此处约定为左高减右高。
	int balance = getHeight(root->left) - getHeight(root->right);

	if (balance > 1 && x < root->left->val) {
		return rotateRight(root);
	}

	if (balance > 1 && x > root->left->val) {
		// [踩坑] 曾只用临时变量接住第一次旋转的结果，没有更新 root->left。
		// 必须先把左子树的新根接回，第二次旋转才能沿正确连接进行。
		root->left = rotateLeft(root->left);
		return rotateRight(root);
	}

	if (balance < -1 && x > root->right->val) {
		return rotateLeft(root);
	}

	if (balance < -1 && x < root->right->val) {
		root->right = rotateRight(root->right);
		return rotateLeft(root);
	}

	return root;
}

Node* rotateRight(Node* root) {
	Node* b = root->left;
	root->left = b->right;
	b->right = root;
	updateHeight(root);
	updateHeight(b);
	// [踩坑] 最初两个旋转函数都漏了返回值；调用者需要新根来接回这棵子树。
	return b;
}

Node* rotateLeft(Node* root) {
	Node* b = root->right;
	root->right = b->left;
	b->left = root;
	updateHeight(root);
	updateHeight(b);
	// [踩坑] 最初两个旋转函数都漏了返回值；调用者需要新根来接回这棵子树。
	return b;
}
void levelOrder(Node* root)
{
	queue<Node*> q;
	q.push(root);
	bool first = true;
	bool seenEmpty = false;
	bool complete = true;
	while (!q.empty()) {
		if (q.front()->left != nullptr) {
			if (seenEmpty) {
				complete = false;
			}
			q.push(q.front()->left);
		}
		else {
			seenEmpty = true;
		}
		if (q.front()->right != nullptr) {
			if (seenEmpty) {
				complete = false;
			}
			q.push(q.front()->right);
		}
		else {
			seenEmpty = true;
		}
		if (!first) {
			cout << " ";
		}
		cout << q.front()->val;
		first = false;
		
		q.pop();
	}
	// [踩坑] 曾把换行和 Yes/No 放在循环内，导致每个节点都输出一次判断。
	// 遍历结束后才输出最终结论；该问题是检查时自己发现的。
	cout << '\n';
	if (complete)
		cout << "Yes";
	else
		cout << "No";
}

int main() {
	int n;
	cin >> n;
	vector<int>nums;
	while (n--) {
		int a;
		cin >> a;
		nums.push_back(a);
	}
	Node* root = nullptr;
	for (auto x : nums) {
		root = insert(root, x);
	}

	levelOrder(root);
	return 0;
}