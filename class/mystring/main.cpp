#include<iostream>

using namespace std;

class MyString {
public:
	char* str;
	int maxLength;

	MyString(char* s, int len) {
		maxLength = len;
		str = new char[maxLength + 1];

		int i = 0;
		while (i < maxLength && s[i] != '\0') {
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	~MyString() {
		delete[]str;
	}

	int strLen() const {
		int len = 0;
		while (str[len] != '\0') {
			len++;
		}
		return len;
	}

	void strCat(char* s) {
		int nowLen = strLen();
		int addLen = 0;

		while (s[addLen] != '\0') {
			addLen++;
		}

		if (nowLen + addLen > maxLength) {
			addLen = maxLength - nowLen;
		}

		for (int i = 0; i < addLen; i++) {
			str[nowLen + i] = s[i];
		}
		str[nowLen + addLen] = '\0';
	}

	MyString& operator=(const MyString& other) {
		if (this == &other)return *this;

		delete[] str;

		maxLength = other.maxLength;
		str = new char[maxLength + 1];

		int i = 0;
		while (other.str[i] != '\0') {
			str[i] = other.str[i];
			i++;
		}
		str[i] = '\0';
		return *this;
	}
};

int main() {
	char a[100], b[100];
	cin >> a >> b;

	MyString A(a, 200);
	MyString B(b, 200);

	cout << A.strLen() << endl;
	A.strCat(B.str);
	cout << A.str << endl;
	cout << A.strLen() << endl;

	return 0;
}