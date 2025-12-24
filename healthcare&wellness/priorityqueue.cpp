#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<pair<int,string>, vector<pair<int,string>>, greater<>> pq;

    pq.push({5, "Main Street"});
    pq.push({2, "Highway"});
    pq.push({8, "City Center"});

    cout << "Traffic signal priority:\n";
    while(!pq.empty()) {
        auto top = pq.top(); pq.pop();
        cout << "Priority " << top.first << ": " << top.second << "\n";
    }
}
