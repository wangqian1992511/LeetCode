struct nodeT {
    int userId, tweetIdx, postTime;
};

struct heapCompT {
    bool operator()(nodeT &a, nodeT &b) {
        return a.postTime < b.postTime;
    }
};

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        tiktok = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        followee[userId].insert(userId);
        tweet[userId].push_front(tweetId);
        if (tweet[userId].size() > 10)
            tweet[userId].pop_back();
        postTime[tweetId] = tiktok++;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<nodeT, vector<nodeT>, heapCompT> heap;
        for (auto it: followee[userId])
            if (tweet.count(it))
                heap.push({it, 0, postTime[tweet[it][0]]});
        for (int i = 0; i < 10; i++)
            if (!heap.empty()){
                nodeT node = heap.top();
                heap.pop();
                ans.push_back(tweet[node.userId][node.tweetIdx]);
                node.tweetIdx++;
                if (node.tweetIdx < tweet[node.userId].size()) {
                    node.postTime = postTime[tweet[node.userId][node.tweetIdx]];
                    heap.push(node);
                }
            }
        return ans;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followee[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followee[followerId].erase(followeeId);
    }
private:
    unordered_map<int, unordered_set<int>> followee;
    unordered_map<int, deque<int>> tweet;
    unordered_map<int, int> postTime;
    int tiktok;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
