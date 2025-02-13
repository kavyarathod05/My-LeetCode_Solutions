class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long n = nums.size();
               priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end()); 

        long long cnt=0;
        while(pq.top()<k && pq.size()>=2){
            long long first= pq.top();
            pq.pop();
            long long second= pq.top();
            pq.pop();
            cnt++;
            long long newnum= first*2+ second;
            pq.push(newnum);
        }
        return cnt;
    }
};