#include <bits/stdc++.h>
using namespace std;

struct Route {
    string name;
    int time; // minutes
    int pollution; // score
};

bool compare(Route a, Route b){
    if(a.time != b.time) return a.time < b.time; // faster first
    return a.pollution < b.pollution; // less pollution preferred
}

int main(){
    vector<Route> routes = {{"Route A",10,50},{"Route B",8,60},{"Route C",12,40}};
    sort(routes.begin(), routes.end(), compare);

    cout<<"Ranked Eco-Routes:\n";
    for(auto &r: routes)
        cout<<r.name<<" (Time: "<<r.time<<" mins, Pollution: "<<r.pollution<<")\n";

    return 0;
}
