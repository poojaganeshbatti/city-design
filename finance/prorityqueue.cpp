#include <bits/stdc++.h>
using namespace std;

int main() {
    // Min-heap: ATM distance from user
    priority_queue<int, vector<int>, greater<int>> atmDistances;
    atmDistances.push(10);
    atmDistances.push(5);
    atmDistances.push(15);

    cout << "Nearest ATMs:\n";
    while(!atmDistances.empty()) {
        cout << "ATM at distance: " << atmDistances.top() << "\n";
        atmDistances.pop();
    }
}
