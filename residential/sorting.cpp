#include <bits/stdc++.h>
using namespace std;

struct Zone {
    string name;
    int accessibility; // higher = better
    int population; // lower = better
};

bool compare(Zone a, Zone b){
    if(a.accessibility != b.accessibility) return a.accessibility > b.accessibility;
    return a.population < b.population;
}

int main(){
    vector<Zone> zones = {{"Zone A",80,120},{"Zone B",90,150},{"Zone C",85,100}};
    sort(zones.begin(), zones.end(), compare);

    cout<<"Ranked Residential Zones:\n";
    for(auto &z: zones)
        cout<<z.name<<" (Accessibility: "<<z.accessibility<<", Population: "<<z.population<<")\n";

    return 0;
}
