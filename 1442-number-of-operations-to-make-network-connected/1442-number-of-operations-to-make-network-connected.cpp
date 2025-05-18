class Solution {
public:
    int findParent(int x, vector<int>& parent){
        if(parent[x]==x){
            return x;
        }
        return findParent(parent[x] , parent);
    }
    void unionNode(int a, int b, vector<int>&parent, vector<int>& rank){
         a = findParent(a, parent);
         b= findParent(b,parent);
        if(a==b) return ;
        if(rank[a]  < rank[b]){
            parent[a] =b;
        }
        else if(rank[b]< rank[a]){
            parent[b]= a;
        }
        else{
            parent[b]=a;
            rank[a]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> parent(n), rank(n,0);
        iota(parent.begin(), parent.end(), 0);
        int extra=0;
        for(auto &e: connections){
            int u = e[0];
            int v = e[1];
            if(findParent(u, parent) != findParent(v,parent)){
                unionNode(u,v,parent,rank);
            }
            else{
                extra++;
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(findParent(i,parent)==i){
                c++;
            }
        }
        int need = c-1;
        return (extra>=need)?need:-1;
    }
};