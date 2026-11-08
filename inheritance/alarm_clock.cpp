#include<iostream>
#include<string>

using namespace std;

class Clock {
private:
	int H;
	int M;
	int S;
public:
	Clock() {
		H = 0;
		M = 0;
		S = 0;
	}
	void SetTime(int h, int m, int s) {
		H = h;
		M = m;
		S = s;
	}
	void ShowTime() {
		cout <<"Now:" << H << ":" << M << ":" << S << endl;
	}
};

class AlarmClock : public Clock {
private:
	int AH;
	int AM;
public:
	AlarmClock() {
		AH = 0;
		AM = 0;
	}
	void SetAlarm(int ah, int am) {
		AH = ah;
		AM = am;
	}
	void ShowAlarm() {
		cout <<"AlarmTime:" << AH << ":" << AM << endl;
	}
};

int main() {
	int n;
	cin >> n;
	AlarmClock clock;
	while (n--) {
		string function;
		cin >> function;
		
		if (function == "SetTime") {
			int h, m, s;
			cin >> h >> m >> s;
			
			clock.SetTime(h, m, s);
		
		}
		else if (function == "SetAlarm") {
			int ah, am;
			cin >> ah >> am;
			
			clock.SetAlarm(ah, am);
			
		}
		else if (function == "ShowTime") {
			clock.ShowTime();
		}
		else if (function == "ShowAlarm") {
			clock.ShowAlarm();
		}
		else {
			cout << "没有这个函数！" << endl;
		}
	}
	return 0;
}