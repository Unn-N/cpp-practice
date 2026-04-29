#include<iostream>
#include<algorithm>
using namespace std;

class Student {
private:
	int id;
	int score;
public:
	void set(int a, int b) {
		id = a;
		score = b;
	}
	int getId() { return id; }
	int getScore() { return score; }
};
void max(Student* p) {
	int m = 0;
	for (int i = 0; i < 4; i++) {
		if (p[i].getScore() > m) {
			m = p[i].getScore();
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3 - i; j++) {
			if (p[j].getId() > p[j + 1].getId()) {
				swap(p[j], p[j + 1]);
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		if (p[i].getScore() == m) {
			cout << p[i].getId() << " " << p[i].getScore() << endl;
		}
	}
}

int main() {
	Student s[4];
	int id;
	int score;
	for (int i = 0; i < 4; i++) {
		cin >> id >> score;
		s[i].set(id, score);
	}
	max(s);
	return 0;
}