#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> distances = {10, 5, 15, 3}; // distance to hospitals
    sort(distances.begin(), distances.end());
    cout << "Hospitals ranked by nearest distance: ";
    for(int d: distances) cout << d << " ";
    return 0;
}
