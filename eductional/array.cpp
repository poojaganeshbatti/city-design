#include <iostream>
using namespace std;

int main() {
    int studentPopulation[5] = {200, 350, 400, 150, 500};

    cout << "Student population in each institution:\n";
    for(int i=0;i<5;i++){
        cout << "Institution " << i << ": " << studentPopulation[i] << endl;
    }

    return 0;
}
