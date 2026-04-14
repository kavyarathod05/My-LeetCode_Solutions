class Twitter {
public:
    int time;
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweetMap;
    
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        followMap[userId].insert(userId);

        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > minHeap;

        for (int followee : followMap[userId]) {
            if (tweetMap[followee].size() > 0) {
                for (auto it : tweetMap[followee]) {
                    minHeap.push({it.first, it.second});
                    if (minHeap.size() > 10) minHeap.pop();
                }
            }
        }

        vector<int> temp;
        while (!minHeap.empty()) {
            temp.push_back(minHeap.top().second);
            minHeap.pop();
        }

        reverse(temp.begin(), temp.end());

        return temp;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};