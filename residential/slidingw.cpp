#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> population = {10, 20, 30, 40, 50, 60, 70};
    int k = 3; // window size (zones)

    int window_sum = 0;
    for(int i=0;i<k;i++) window_sum += population[i];
    cout << "Population in first zone: " << window_sum << "\n";

    for(int i=k;i<population.size();i++){
        window_sum += population[i] - population[i-k];
        cout << "Population in zone ending at index " << i << ": " << window_sum << "\n";
    }
}
