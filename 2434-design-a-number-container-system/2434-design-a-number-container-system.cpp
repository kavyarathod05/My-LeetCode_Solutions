class NumberContainers {
public:
    //index, number
    unordered_map<int, int> mp;
    //number/index
    unordered_map<int,set<int>> idx;
    NumberContainers() {
        mp.reserve(100000);
    }
    
    void change(int index, int number) {
        if(mp.count(index)){
            int x= mp[index];
            idx[x].erase(index);
            if(idx[x].size()==0) idx.erase(x);
        }
        mp[index]= number;
        idx[number].insert(index);
    }
    
    int find(int number) {
        if(idx.count(number)==0) return -1;
        return *(idx[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */