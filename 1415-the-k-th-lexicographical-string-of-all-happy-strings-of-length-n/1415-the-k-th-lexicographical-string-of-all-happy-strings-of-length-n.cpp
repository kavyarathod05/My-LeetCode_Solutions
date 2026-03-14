class Solution {
public:
    void generate(string curr, char prev, vector<string>& ans, int n){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }

        if(prev != 'a'){
            generate(curr + 'a', 'a', ans, n);
        }

        if(prev != 'b'){
            generate(curr + 'b', 'b', ans, n);
        }

        if(prev != 'c'){
            generate(curr + 'c', 'c', ans, n);
        }
    }

    string getHappyString(int n, int k) {
        vector<string> ans;

        generate("", '#', ans, n);

        if(ans.size() < k) return "";
        return ans[k-1];
    }
};