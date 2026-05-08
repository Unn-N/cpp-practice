#include<iostream>
#include<cstring>
using namespace std;

class mystrcla {
public:
	char str[101];
	int len;
	mystrcla(char* s);
	void strout();
	bool strispal();
};

mystrcla::mystrcla(char* s) {
	len = strlen(s);
	for (int i = 0; i < len; i++) {
		str[i] = s[i];
	}
}

void mystrcla::strout() {
	for (int i = 0; i < len; i++) {
		cout << str[i];
	}
	cout << endl;
}

bool mystrcla::strispal() {
	char temp[101];
	for (int i = 0; i < len; i++) {
		temp[i] = str[len - i - 1];
	}
	temp[len] = '\0';
	for (int i = 0; i < len; i++) {
		if (str[i] != temp[i])return false;
	}
	return true;
}

int main() {
	char s[101];
	cin >> s;
	mystrcla mystr(s);
	mystr.strout();
	if (mystr.strispal()) {
		cout << "True";
	}
	else {
		cout << "False";
	}
}