#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> patientRecord;

    patientRecord[101] = "Patient A";
    patientRecord[102] = "Patient B";
    patientRecord[103] = "Patient C";

    cout << "Patient ID 102: "
         << patientRecord[102] << endl;

    return 0;
}
