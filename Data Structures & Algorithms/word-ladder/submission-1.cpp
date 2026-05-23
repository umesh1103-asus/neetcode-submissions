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
        wordList.push_back(beginWord);
        unordered_map<string, vector<string>> adj;
        unordered_map<string, bool> visited;
        unordered_map<string, bool> inQueue;
        
        // create adjency list 
        for(int i=0;i<wordList.size();i++){
            visited[wordList[i]] = false;
            inQueue[wordList[i]] = false;
            for(string s:wordList){
                if(isEdge(wordList[i], s)) {
                    adj[wordList[i]].push_back(s);
                    adj[s].push_back(wordList[i]);
                    cout << "edge " << wordList[i] << " -> " << s << endl;
                }
            }
        }

        // use BFS starting from beginWord
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()){
            auto [word, dist] = q.front();
            if(word==endWord) return dist;
            q.pop();
            for(string next:adj[word]){
                if(!visited[next]){
                    visited[next] = true;
                    cout << "adding: " << next << endl;
                    q.push({next, dist+1});
                } 
            }
        }

        return 0;
    }
};
