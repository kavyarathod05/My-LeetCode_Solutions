#include<bits/stdc++.h>
class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<int>ans(n,0);
        vector<bool>online(n,true);
        map<int,int>mp;

        sort(events.begin(),events.end(), [](const vector<string> &a, const vector<string> &b) {
        int t1 = stoi(a[1]);
            int t2 = stoi(b[1]);
            if(t1==t2){
                return a[0]=="OFFLINE" && b[0]!="OFFLINE";
            }

            return t1<t2;
    });
       for(auto i:events){
        auto type = i[0];
        auto time= stoi(i[1]);
        if(type=="MESSAGE"){
            auto ids=i[2];
            for(int i=0;i<n;i++){
                if(online[i]==false){
                    if(mp[i]<=time){
                        online[i]=true;
                    }
                }
            }
                if(ids=="ALL"){
                    for(int i=0;i<n;i++){
                        ans[i]++;
                    }
                }
                else if(ids=="HERE"){
                    for(int i=0;i<n;i++){
                        if(online[i]){
                            ans[i]++;
                        }
                    }
                }
                else{
                    stringstream ss(ids);
                    string id;
                    while(ss>>id){
                        int idd= stoi(id.substr(2));
                        ans[idd]++;
                    }
                }
        }
        else{
            int id= stoi(i[2]);
            online[id]= false;
            mp[id]= time+60;
        }
       }

        return ans;
    }
};