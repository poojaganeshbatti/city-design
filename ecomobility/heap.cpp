#include <bits/stdc++.h>
using namespace std;

int main() {
    // Min-heap for selecting next optimal route
    priority_queue<pair<int,string>, vector<pair<int,string>>, greater<>> pq;

    pq.push({10, "Route A"});
    pq.push({5, "Route B"});
    pq.push({8, "Route C"});

    while(!pq.empty()){
        auto [time, route] = pq.top(); pq.pop();
        cout<<"Choose route: "<<route<<" with estimated time "<<time<<" mins\n";
    }

    return 0;
}
