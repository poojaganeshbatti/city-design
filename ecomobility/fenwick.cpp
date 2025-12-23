#include <bits/stdc++.h>
using namespace std;

// Fenwick Tree / Binary Indexed Tree
class FenwickTree {
    vector<int> bit;
    int n;
public:
    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0); // 1-based indexing
    }

    // Update index i (1-based) by value delta
    void update(int i, int delta) {
        while (i <= n) {
            bit[i] += delta;
            i += i & -i; // Move to next responsible node
        }
    }

    // Query prefix sum from 1 to i
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i; // Move to parent
        }
        return sum;
    }

    // Query range sum from l to r
    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    int n;
    cout << "Enter number of zones: ";
    cin >> n;

    FenwickTree ft(n);

    // Example: Add initial bed capacities per zone
    cout << "Enter bed capacities for each zone:\n";
    for (int i = 1; i <= n; i++) {
        int beds;
        cin >> beds;
        ft.update(i, beds);
    }

    cout << "Query sum of beds from zone 2 to 5: " << ft.rangeQuery(2, 5) << endl;

    // Update: Add 10 beds to zone 3
    ft.update(3, 10);
    cout << "After updating, sum of beds from zone 2 to 5: " << ft.rangeQuery(2, 5) << endl;

    return 0;
}
