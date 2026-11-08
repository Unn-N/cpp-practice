
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 根据字符串计算 KMP 的 next 数组
vector<int> buildNext(const string& s) {
    int n = s.size();
    vector<int> nxt(n);

    nxt[0] = -1;

    int i = 0;
    int j = -1;

    while (i < n - 1) {
        if (j == -1 || s[i] == s[j]) {
            i++;
            j++;
            nxt[i] = j;
        }
        else {
            j = nxt[j];
        }
    }

    return nxt;
}

int main() {
    char head, tail;
    int n;

    cin >> head >> tail >> n;

    if (n < 1 || n > 30) {
        cout << "ERROR" << endl;
        return 0;
    }

    vector<int> givenNext(n);

    for (int i = 0; i < n; i++) {
        cin >> givenNext[i];
    }

    // 检查首尾字符是否合法
    bool valid = (head == '0' || head == '1')
        && (tail == '0' || tail == '1');

    string s(n, '?');

    s[0] = head;

    if (n > 1) {
        s[n - 1] = tail;
    }
    else if (head != tail) {
        valid = false;
    }

    // 根据 next 数组逐个推导中间字符
    if (valid) {
        for (int i = 1; i < n - 1; i++) {
            int k = givenNext[i + 1];

            if (k == 0) {
                // 没有非空的相同真前缀和真后缀
                // 当前字符必须与首字符不同
                s[i] = (head == '0') ? '1' : '0';
            }
            else if (k > 0 && k <= i) {
                // 当前字符必须与对应前缀的末尾字符相同
                s[i] = s[k - 1];
            }
            else {
                valid = false;
                break;
            }
        }
    }

    // 重新计算 next 数组，验证构造结果
    if (valid) {
        vector<int> calculatedNext = buildNext(s);

        if (calculatedNext != givenNext) {
            valid = false;
        }
    }

    // 输出结果
    if (valid) {
        cout << s << endl;
    }
    else {
        cout << "ERROR" << endl;
    }

    return 0;
}
