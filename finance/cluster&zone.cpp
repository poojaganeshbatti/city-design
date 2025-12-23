#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> zones = {5, 20, 25, 80, 90};
    vector<vector<int>> clusters(2);

    for (int z : zones) {
        if (z < 50) clusters[0].push_back(z);
        else clusters[1].push_back(z);
    }

    cout << "Low-demand zones: ";
    for (int x : clusters[0]) cout << x << " ";

    cout << "\nHigh-demand zones: ";
    for (int x : clusters[1]) cout << x << " ";
}
