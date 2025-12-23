#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;
public:
    SegmentTree(vector<int>& data) {
        n = data.size();
        tree.resize(2*n);
        for(int i=0;i<n;i++) tree[n+i]=data[i];
        for(int i=n-1;i>0;i--) tree[i]=tree[2*i]+tree[2*i+1];
    }
    int query(int l, int r) { // sum in [l,r)
        int res=0;
        l+=n; r+=n;
        while(l<r){
            if(l%2) res+=tree[l++];
            if(r%2) res+=tree[--r];
            l/=2; r/=2;
        }
        return res;
    }
};

int main(){
    vector<int> capacity = {50, 30, 20, 40}; // hospital capacities
    SegmentTree st(capacity);
    cout << "Total capacity of zone 1-3: " << st.query(1,4) << endl; // 30+20+40=90
    return 0;
}
