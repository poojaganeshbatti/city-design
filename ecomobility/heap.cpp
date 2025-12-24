#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> trafficSignal;

    trafficSignal.push(5);  // Low congestion
    trafficSignal.push(20); // High congestion
    trafficSignal.push(10);

    cout << "Highest priority traffic signal: "
         << trafficSignal.top() << endl;

    return 0;
}
