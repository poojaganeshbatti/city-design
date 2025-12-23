#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> hospitalBeds;
    hospitalBeds["HospitalA"] = 50;
    hospitalBeds["HospitalB"] = 30;
    hospitalBeds["HospitalC"] = 40;

    cout << "Beds in HospitalB: " << hospitalBeds["HospitalB"] << endl;
    hospitalBeds["HospitalB"] -= 1; // patient admitted
    cout << "Beds in HospitalB after admitting 1 patient: " << hospitalBeds["HospitalB"] << endl;
    return 0;
}
