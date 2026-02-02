class Twitter {
public:

vector<unordered_set<int>> v;
vector<pair<int, int>> t;
    Twitter() {
        v.resize(501);
        for(int i=1; i<=500; i++){
            v[i].insert(i);
        }
    }
    
    void postTweet(int userId, int tweetId) {
       t.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int cnt=0;
        for(int i=t.size()-1; i>=0; i--){
            if(v[userId].count(t[i].first)){
                ans.push_back(t[i].second);
                if(++cnt == 10) break;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        v[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(v[followerId].count(followeeId)){
            v[followerId].erase(followeeId);
        }
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