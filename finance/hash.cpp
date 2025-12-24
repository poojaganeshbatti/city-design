#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, string> transactions; // txnID -> user

    transactions[1001] = "Alice";
    transactions[1002] = "Bob";
    transactions[1003] = "Charlie";

    // Fast lookup
    int txnID = 1002;
    if(transactions.find(txnID) != transactions.end())
        cout << "Transaction " << txnID << " belongs to " << transactions[txnID] << "\n";
}
