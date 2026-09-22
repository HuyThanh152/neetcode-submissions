class Twitter {
public:
int timeStamp;
unordered_map<int, unordered_set<int>> dsFl;
unordered_map<int, vector<pair<int, int>>> dsTweet;

    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        dsTweet[userId].push_back({timeStamp++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        dsFl[userId].insert(userId);

    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

for (int followeeId : dsFl[userId]){
        auto & tweet = dsTweet[followeeId];
        int n = tweet.size();
        for(int i = n-1; i >=   max(0, n - 10); i--){
           minHeap.push(tweet[i]);
        while(minHeap.size()> 10){
            minHeap.pop();}
        }
}
vector<int> res;
while(!minHeap.empty()){
    res.push_back(minHeap.top().second);
    minHeap.pop();
}
reverse(res.begin(), res.end());
return res;     
        
    }
    
    void follow(int followerId, int followeeId) {
        dsFl[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId) 
            dsFl[followerId].erase(followeeId);
        return;
    }
};
