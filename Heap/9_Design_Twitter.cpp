#include <bits/stdc++.h>
using namespace std;

class Twitter{
    private:
        unordered_map<int, vector<pair<int,int>>> userTweets;
        unordered_map<int, unordered_set<int>> userFollows;
        int timestamp;
    public:
        Twitter(){
            timestamp = 0;
        }

        void postTweet(int userId, int tweetId){
            userTweets[userId].push_back({timestamp++, tweetId});
        }

        vector<int> getNewsFeed(int userId){
            vector<int> feed;

            priority_queue<tuple<int,int,int>> maxHeap; // (timestamp, userId, index)

            userFollows[userId].insert(userId); // Ensure the user follows themselves

            for(int followeeId : userFollows[userId]){
                if(userTweets[followeeId].empty()) continue;

                int index = userTweets[followeeId].size();
                auto [time,tweetId] = userTweets[followeeId][index-1];
                maxHeap.push({time, followeeId, index-1});
            }

            while(!maxHeap.empty() && feed.size() <10){
                auto [time, followeeId, index] = maxHeap.top();
                maxHeap.pop();


                int tweetId = userTweets[followeeId][index].second;
                feed.push_back(tweetId);

                if(--index >= 0){
                    auto [nextTime, nextTweetId] = userTweets[followeeId][index];
                    maxHeap.push({nextTime, followeeId, index});
                }
            }

            return feed;
        }

        void follow(int followerId, int followeeId){
            userFollows[followerId].insert(followeeId);
        }

        void unfollow(int followerId, int followeeId){
            if(followerId != followeeId){
                userFollows[followerId].erase(followeeId);
            }
        }
};
// Time Complexity: O(N log K), where N is the total number of tweets from the user and their followees, and K is the number of followees. The priority queue operations take log K time for each tweet processed.