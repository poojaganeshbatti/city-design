#include <bits/stdc++.h>
using namespace std;

struct ATM {
    int id;
    int usage;
};

bool cmp(ATM a, ATM b) { return a.usage > b.usage; }

int main() {
    vector<ATM> atms = {{101, 50}, {102, 70}, {103, 30}};

    sort(atms.begin(), atms.end(), cmp);

    cout << "ATMs ranked by usage:\n";
    for(auto atm: atms)
        cout << "ATM " << atm.id << " -> Usage: " << atm.usage << "\n";
}
