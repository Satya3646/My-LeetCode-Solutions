class Solution {
public:
    void dfs(string &word, string &beginWord, vector <string> &path, unordered_map <string, int> &depthMap, vector <vector <string>> &ans)
    {
        if(word == beginWord) // if beginWord is reached then add to answer.
        {
            // reversal need since we are doing reverse DFS.
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }
        int steps = depthMap[word]; // 
        for(int i = 0; i < word.size(); i++) // combinations of words.
        {
            char original = word[i];
            for(char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                // if the depth of new word is one less than the depth of current word then its will result in shortest path. 
                if(depthMap.count(word) && depthMap[word]+1 == steps)
                {
                    path.push_back(word);
                    dfs(word, beginWord, path, depthMap, ans);
                    path.pop_back();
                }
            }
            word[i] = original; // restore.
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> dict(wordList.begin(), wordList.end()); // fast access.
        queue <string> q; // each queue element is a path made or words.
        q.push(beginWord);
        unordered_map <string, int> depthMap; // map to store the depth at which each word appeared during BFS, BFS gives the shortest depth for each node.
        depthMap[beginWord] = 1;
        dict.erase(beginWord);

        while(!q.empty())
        {
            // pop the list at the front.
            string curr = q.front();
            q.pop();
            int steps = depthMap[curr];

            if(curr == endWord)
                break;

            for(int i = 0; i < curr.size(); i++) // combinations of words.
            {
                char original = curr[i];
                for(char c = 'a'; c <= 'z'; c++)
                {
                    curr[i] = c;
                    if(dict.count(curr))
                    {
                        q.push(curr);
                        dict.erase(curr);
                        depthMap[curr] = steps+1;
                    }
                }
                curr[i] = original; // restore.
            }
        }
        
        vector <vector <string>> ans;
        if(depthMap.find(endWord) == depthMap.end())
            return ans;
        vector <string> path = {endWord};
        dfs(endWord, beginWord, path, depthMap, ans);
        return ans;
    }
};