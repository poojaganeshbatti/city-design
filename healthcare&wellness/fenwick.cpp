#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> BIT;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        BIT.assign(n + 1, 0);
    }

    void update(int index, int value) {
        for (++index; index <= n; index += index & -index)
            BIT[index] += value;
    }

    int query(int index) {
        int sum = 0;
        for (++index; index > 0; index -= index & -index)
            sum += BIT[index];
        return sum;
    }
};

int main() {
    FenwickTree ft(5);

    ft.update(0, 20); // beds in hospital 0
    ft.update(1, 15);
    ft.update(2, 10);

    cout << "Total available beds (0 to 2): " 
         << ft.query(2) << endl;

    return 0;
}
