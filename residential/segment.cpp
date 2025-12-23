#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;
public:
    SegmentTree(vector<int>& data){
        n = data.size();
        tree.resize(4*n);
        build(data,0,n-1,1);
    }

    void build(vector<int>& data,int l,int r,int node){
        if(l==r){ tree[node]=data[l]; return; }
        int mid=(l+r)/2;
        build(data,l,mid,2*node);
        build(data,mid+1,r,2*node+1);
        tree[node]=tree[2*node]+tree[2*node+1]; // sum of population/utilities
    }

    int query(int ql,int qr,int l,int r,int node){
        if(qr<l || ql>r) return 0;
        if(ql<=l && r<=qr) return tree[node];
        int mid=(l+r)/2;
        return query(ql,qr,l,mid,2*node)+query(ql,qr,mid+1,r,2*node+1);
    }
};

int main(){
    vector<int> population = {120, 80, 150, 90, 60}; // residents per zone
    SegmentTree st(population);

    cout<<"Population from zone 1 to 3: "<<st.query(1,3,0,population.size()-1,1)<<"\n";
    return 0;
}
