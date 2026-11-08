#include <iostream>
#include <map>
#include <string>
#include <numeric>

using namespace std;

// 基类
class Goods {
protected:
    double price;
public:
    Goods(double p) : price(p) {}
    double getPrice() const { return price; }
};

// 派生类
class Shirt : public Goods {
    string origin;
    string fabric;
public:
    Shirt(double p, const string& o, const string& f)
        : Goods(p), origin(o), fabric(f) {
    }

    bool operator<(const Shirt& other) const {
        if (price != other.price) return price < other.price;
        if (origin != other.origin) return origin < other.origin;
        return fabric < other.fabric;
    }
};

int main() {
    map<Shirt, int> inventory;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "price") {
            double total = accumulate(
                inventory.begin(), inventory.end(), 0.0,
                [](double acc, const pair<Shirt, int>& entry) {
                    return acc + entry.first.getPrice() * entry.second;
                }
            );
            cout << total << endl;
            break;

        }
        else if (cmd == "in") {
            int n; double p; string o, f;
            cin >> n >> p >> o >> f;
            if (n <= 0) { cout << "wrong" << endl; continue; }
            inventory[Shirt(p, o, f)] += n;

        }
        else if (cmd == "out") {
            int n; double p; string o, f;
            cin >> n >> p >> o >> f;
            if (n <= 0) { cout << "wrong" << endl; continue; }
            Shirt key(p, o, f);
            auto it = inventory.find(key);
            if (it == inventory.end() || it->second == 0) {
                cout << "wrong" << endl;
            }
            else if (it->second >= n) {
                it->second -= n;
                cout << "next" << endl;
            }
            else {
                cout << "out " << it->second << endl;
                it->second = 0;
            }

        }
        else if (cmd == "num") {
            double p; string o, f;
            cin >> p >> o >> f;
            auto it = inventory.find(Shirt(p, o, f));
            cout << (it != inventory.end() ? it->second : 0) << endl;
        }
    }

    return 0;
}