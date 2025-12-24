#include <bits/stdc++.h>
using namespace std;

struct Housing {
    int demand;
    int houseID;
};

bool cmp(Housing a, Housing b) { return a.demand > b.demand; }

int main() {
    vector<Housing> houses = {{50, 1}, {30, 2}, {70, 3}, {20,4}};

    // Greedy allocation: sort by highest demand
    sort(houses.begin(), houses.end(), cmp);

    cout << "Housing allocation based on demand:\n";
    for(auto h : houses)
        cout << "House " << h.houseID << " -> Demand: " << h.demand << "\n";
}
