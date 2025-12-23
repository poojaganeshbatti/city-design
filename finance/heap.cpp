#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    // {distance, ATM_ID}

    pq.push({300, 1});
    pq.push({150, 2});
    pq.push({400, 3});

    cout << "Nearest ATM selected:\n";
    cout << "ATM ID: " << pq.top().second
         << ", Distance: " << pq.top().first << endl;
}
