class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.size();
        string temp1 = s1;
        swap(temp1[0],temp1[2]);
        string temp2= s1;
        swap(temp2[1],temp2[3]);
        cout<<temp1<<" "<<temp2<<endl;
        for(int i=0;i<2;i++){
            if(temp1==s2) return true;
            if(temp2==s2) return true;
            swap(s2[i], s2[i+2]);
            if(temp1==s2) return true;
            if(temp2==s2) return true;
            swap(s2[i], s2[i+2]);
        }
        return false;
    }
};