class Twitter {
public:

    unordered_map<int,set<int>> followees;
    unordered_map<int,vector<pair<int,int>>> tweets;
    int time = 0;

    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        auto cmp = [](pair<int,int> a, pair<int,int> b){ return a.first < b.first; };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        for(auto &t: tweets[userId]){
            pq.push(t);
        }
        for(int followee: followees[userId]){
            for(auto &t: tweets[followee]){
                pq.push(t);
            }
        }

        int count = 0;
        vector<int>ret;
        while(!pq.empty() && count < 10){
            ret.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)return;
        else{
            followees[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)return;
        else{
            followees[followerId].erase(followeeId);
        }
    }
};

