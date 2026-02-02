class Twitter {
public:

vector<unordered_set<int>> v;
unordered_map<int, vector<pair<int,int>>> tweets;
int timer=0;

    Twitter() {
        v.resize(501);
        for(int i=1; i<=500; i++){
            v[i].insert(i);
        }
        
    }
    
    void postTweet(int userId, int tweetId) {
       tweets[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<tuple<int, int, int, int>> pq;
        for(auto it:v[userId]){
            if(!tweets[it].empty()){
                int idx=tweets[it].size()-1;
                pq.push({tweets[it][idx].first, tweets[it][idx].second, it, idx});
            }
        }

        while(!pq.empty() && ans.size()<10){
            auto [time, id, ind, idx]=pq.top();
            pq.pop();
            ans.push_back(id);
            if(idx>0){
                pq.push({tweets[ind][idx-1].first, tweets[ind][idx-1].second, ind, idx-1});
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