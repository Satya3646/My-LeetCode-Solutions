class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set <string> s(wordList.begin(), wordList.end()); // put all the words into unordered_set for fast search and erase.
        if(s.find(endWord) == s.end())
            return 0;

        queue <pair <string, int>> q;
        q.push({beginWord, 1}); // since we need to count the total words in the path pass 1.
        while(!q.empty())
        {
            auto [str, steps] = q.front();
            q.pop();
            if(str == endWord)
                return steps;
            for(int j = 0; j < str.size(); j++) // Selects index in the current string.
            {
                string tmp = str; // temporary string which represents the word we need to search for next step.
                for(char c = 'a'; c <= 'z'; c++) // 
                {
                    if(c == str[j]) // Same word need not be searched again.
                        continue;
                    tmp[j] = c; // Replace the character at jth index.
                    auto it = s.find(tmp);
                    if(it != s.end()) // if modified word that has one character difference to str is found the push to queue.
                    {
                        q.push({*it, steps+1});
                        s.erase(it); // erase from the set since word can be used only once.
                    }
                }
            }
        }
        return 0;
    }
};