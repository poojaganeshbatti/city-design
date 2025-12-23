#include <bits/stdc++.h>
using namespace std;

struct Zone {
    string name;
    int score; // higher score = higher priority
};

int main(){
    priority_queue<pair<int,string>> pq;

    pq.push({85,"Zone A"});
    pq.push({70,"Zone B"});
    pq.push({95,"Zone C"});

    while(!pq.empty()){
        auto [score, name] = pq.top(); pq.pop();
        cout<<"Allocate resources to "<<name<<" with score "<<score<<"\n";
    }

    return 0;
}
