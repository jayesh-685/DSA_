#include "bits/stdc++.h"
using namespace std;

class disjointSet {
    public:
    vector<int> par, rank;
    
    disjointSet (int n) {
        par.resize(n+1);
        rank.resize(n+1, 0);
        
        for (int i=0; i<n+1; i++)   par[i]=i;
    }
    
    int findPar (int node) {
        if (par[node] == node)  return node;
        
        return par[node] = findPar(par[node]);
    }
    
    void unionByRank (int n1, int n2) {
        int p1=findPar(n1), p2=findPar(n2);
        
        if (p1 != p2) {
            // if we merge smaller set with larger set then there is no change in rank of either of the sets
            // rank only changes if we merge sets with equal rank
            if (rank[p1] < rank[p2]) {
                par[p1] = p2;
            } else if (rank[p2] < rank[p1]) {
                par[p2] = p1;
            } else {
                par[p1] = p2;
                rank[p2]++;
            }
        }
    }
    
    
};

int main () {
    return 0;
}