#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
private : vector<int> parent, size;
public :
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int main(){
    int n,m;
    ifstream inputFile("edges.txt");
    if(!inputFile){
        cerr<<"Error opening file!"<<endl;
        return 1;
    }
    inputFile>>n>>m;

    DisjointSet unionFind(n);
    vector<vector<int>> edges;

    for(int i=0;i<m;i++){
        int u,v,wt;
        inputFile>>u>>v>>wt;
        edges.push_back({wt,u,v});
    }
    
    sort(edges.begin(),edges.end());

    int mstWeight = 0;
    vector<vector<int>> mstEdges;

    for(auto edge : edges){
        int wt = edge[0];
        int u = edge[1];
        int v = edge[2];

        if(unionFind.findParent(u) != unionFind.findParent(v)){
            unionFind.unionBySize(u,v);
            mstEdges.push_back({u,v,wt});
            mstWeight += wt;
        }
    }
    cout<<"Edge"<<"\t"<<"Cost"<<endl;
    for(auto edge : mstEdges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        cout<<u<<"--"<<v<<"\t"<<wt<<endl;
    }
    cout<<"Total Weight of MST : "<<mstWeight<<endl;
}