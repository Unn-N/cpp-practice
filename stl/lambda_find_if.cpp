#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> v;

int main()
{
    int threshold = 0;
    // 示例数据
    v = {1, 2, 3, 4, 5};

    // 不能捕获静态存储期变量（如全局变量），直接在 lambda 里用 threshold
    auto it = find_if(v.begin(), v.end(), [threshold](int i) {
        return i > threshold;
    });

    if (it != v.end())
    {
        cout << "Found: " << *it << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    return 0;
}
