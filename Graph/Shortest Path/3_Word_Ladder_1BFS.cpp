#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    queue<pair<string, int>> q;
    q.push({beginWord, 1}); // initially insert the start word
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(beginWord); // clear the word from set who have been inserted to the set

    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == endWord)
        {
            return steps;
        }

        // apply brute force
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (st.find(word) != st.end())
                {
                    q.push({word, steps + 1});
                    st.erase(word);
                }
            }

            word[i] = original;
        }
    }

    return 0;
}

int main()
{
    return 0;
}