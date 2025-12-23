#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Institution {
    string name;
    int capacity;
    int distance; // distance from residential
};

bool compare(const Institution &a, const Institution &b) {
    // Higher capacity & lower distance preferred
    if(a.capacity != b.capacity)
        return a.capacity > b.capacity;
    return a.distance < b.distance;
}

int main() {
    vector<Institution> institutions = {
        {"School A", 500, 3},
        {"College B", 300, 2},
        {"University C", 1000, 5}
    };

    sort(institutions.begin(), institutions.end(), compare);

    cout << "Institutions ranked by capacity & proximity:\n";
    for(auto ins: institutions)
        cout << ins.name << " - Capacity: " << ins.capacity 
             << ", Distance: " << ins.distance << endl;

    return 0;
}
