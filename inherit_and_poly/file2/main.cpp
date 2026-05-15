#include<iostream>
#include<string>

using namespace std;

class File {
protected:
	string filename;
	int filesize;
public:
	File() {}
	virtual ~File() {}

	virtual void UpdateFile(string change, int code) = 0;
	virtual void show() = 0;
};

class ChangeEncode_name :public File {
public:
	int fileEncoder;
	ChangeEncode_name(string name, int size, int code) {
		filename = name;
		filesize = size;
		fileEncoder = code;
	}
	void UpdateFile(string change, int code)override {
		filename = change;
		fileEncoder = code;
	}
	void show()override {
		cout << filename << " " << filesize << " ";
		if (fileEncoder == 0)cout << "UNICODE";
		if (fileEncoder == 1)cout << "ASCII";
		if (fileEncoder == 2)cout << "ANSI";
		if (fileEncoder == 3)cout << "UTF8";
	}
};

class ChangeEncode_size :public File {
public:
	int fileEncoder;
	ChangeEncode_size(string name, int size, int code) {
		filename = name;
		filesize = size;
		fileEncoder = code;
	}
	void UpdateFile(string change, int code)override {
		filesize = stoi(change);
		fileEncoder = code;
	}
	void show()override {
		cout << filename << " " << filesize << " ";
		if (fileEncoder == 0)cout << "UNICODE";
		if (fileEncoder == 1)cout << "ASCII";
		if (fileEncoder == 2)cout << "ANSI";
		if (fileEncoder == 3)cout << "UTF8";
	}
};

int main() {
	string name;
	int size;
	int code;
	cin >> name >> size >> code;
	char cmd;
	cin >> cmd;

	
	if (cmd == 'N') {
		
		string newName;
		int newCode;
		cin >> newName >> newCode;
		File *p=new ChangeEncode_name (name, size, code);
		p->UpdateFile(newName, newCode);
		cout << "change_encodeAndname:";
		p->show();
		cout << endl;
	}
	else if (cmd == 'S') {
		
		string  newSize;
		int newCode;
		cin >> newSize >> newCode;
		File*p =new ChangeEncode_size (name, size, code);
		p->UpdateFile(newSize, newCode);
		cout << "change_encodeAndsize:";
		p->show();
		cout << endl;
	}
	else {
		cout << "No such operation!" << endl;
	}
	return 0;
}