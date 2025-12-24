#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> residentialData; // key: house number, value: resident name

    residentialData[101] = "Alice";
    residentialData[102] = "Bob";
    residentialData[103] = "Charlie";

    // Fast search, insertion, deletion O(log n)
    residentialData[104] = "David";
    residentialData.erase(102);

    cout << "Residential Records:\n";
    for(auto it : residentialData)
        cout << "House " << it.first << ": " << it.second << "\n";
}
