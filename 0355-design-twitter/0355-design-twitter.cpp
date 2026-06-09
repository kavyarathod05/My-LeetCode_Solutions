class Twitter {
public:
    // a time counter to keep track of latest feed , int
    // track of who follows whom int, unordered_map<int>
    unordered_map<int, unordered_set<int>> follo;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int timer;
    Twitter() { timer = 0; }

    void postTweet(int userId, int tweetId) {
        // tweet with tweetId , by user userId
        // unique tweetId so key is tweetId
        // for a userId we need its all tweets so we need a vector
        // int , pair<int,int> => {userId, {timestamp, tweetId}}
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // 10 most recent tweet ID's in the user's news feed
        // return 10 latest of whom user follows and its own
        // most recent to least recent
        // problem is max heap 10 most recent means top 10 
        priority_queue<pair<int,int>> pq;
        // first fetch all from its own 
        for(auto it:tweets[userId]){
            pq.push(it);
        }
        // now all its followers of userId
        for(auto followers : follo[userId]){
            for(auto it:tweets[followers]){
                pq.push(it);
            }
        }
        vector<int> ans;
        for(int i=0;i<10;i++){
            if(!pq.empty()){
                auto top = pq.top();
                pq.pop();
                ans.push_back(top.second);
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        // user with followerId follows followeeId
        follo[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        // user with followerId unfollows followeeId
        follo[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */