class Solution {
private:
    bool isEdge(string s1, string s2){
        int count = 0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) count++;
        }
        return count==1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        unordered_map<string, vector<string>> buckets;

        for (string word : wordList) {
            for (int i = 0; i < word.size(); i++) {
                string pattern = word;
                pattern[i] = '*';
                buckets[pattern].push_back(word);
            }
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();

            if (curr == endWord) return dist;

            for (int i = 0; i < curr.size(); i++) {
                string pattern = curr;
                pattern[i] = '*';

                for (string next : buckets[pattern]) {
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push({next, dist + 1});
                    }
                }
            }
        }

        return 0;
    }
};
