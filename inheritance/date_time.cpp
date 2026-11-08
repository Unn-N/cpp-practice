#include<iostream>
#include<string>
using namespace std;

int daysInMonth(int y, int m) {
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)) return 29;
	return days[m];
}

class Date {
protected:
	int year, month, day;
public:
	Date() { year = 1; month = 1; day = 1; }
	void SetDate(int y, int m, int d) { year = y; month = m; day = d; }
	void PrintDate() { cout << year << "/" << month << "/" << day; }
};

class Time {
protected:
	int hour, minute, second;
public:
	Time() { hour = 0; minute = 0; second = 0; }
	void SetTime(int h, int m, int s) { hour = h; minute = m; second = s; }
	void PrintTime() { cout << hour << ":" << minute << ":" << second; }
};

class DateTime : public Date, public Time {
public:
	DateTime() {}
	void incrementSeconds(long long s) {
		long long totalSec = (long long)hour * 3600 + minute * 60 + second + s;
		second = totalSec % 60;
		minute = (totalSec / 60) % 60;
		hour = (totalSec / 3600) % 24;
		long long extraDays = totalSec / 86400;
		day += extraDays;
		while (day > daysInMonth(year, month)) {
			day -= daysInMonth(year, month);
			month++;
			if (month > 12) { month = 1; year++; }
		}
	}
	void PrintDateTime() {
		PrintDate(); cout << " "; PrintTime(); cout << endl;
	}
};

int main() {
	int n; cin >> n;
	DateTime dt;
	while (n--) {
		string cmd; cin >> cmd;
		if (cmd == "PrintDateTime") dt.PrintDateTime();
		else if (cmd == "incrementSeconds") {
			long long s; cin >> s; dt.incrementSeconds(s);
		}
		else if (cmd == "SetDate") {
			int y, m, d; cin >> y >> m >> d; dt.SetDate(y, m, d);
		}
		else if (cmd == "SetTime") {
			int h, m, s; cin >> h >> m >> s; dt.SetTime(h, m, s);
		}
		else if (cmd == "PrintDate") {
			dt.PrintDate(); cout << endl;
		}
		else if (cmd == "PrintTime") {
			dt.PrintTime(); cout << endl;
		}
		else cout << "没有这个函数！" << endl;
	}
}