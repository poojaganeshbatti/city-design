#include <iostream>
#include <queue>
using namespace std;

struct Institution {
    int id;
    int distance; // distance from residential area
    bool operator<(const Institution &other) const {
        return distance > other.distance; // min-heap
    }
};

int main() {
    priority_queue<Institution> pq;
    pq.push({1, 5});
    pq.push({2, 3});
    pq.push({3, 7});

    cout << "Institutions by nearest distance:\n";
    while(!pq.empty()) {
        cout << "Institution " << pq.top().id 
             << " at distance " << pq.top().distance << endl;
        pq.pop();
    }
    return 0;
}
