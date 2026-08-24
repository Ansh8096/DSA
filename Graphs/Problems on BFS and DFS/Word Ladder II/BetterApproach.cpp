#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> wordLadder2_BT(vector<string> &words, string &start, string &end) {
    
    unordered_set<string> st(words.begin(), words.end());
    queue<vector<string>> q;
    vector<string> usedWords;
    vector<vector<string>> ans;

    q.push({start});
    st.erase(start);

    while (!q.empty()){

        int level = q.size();
        for(auto usedWord: usedWords){
            st.erase(usedWord);
        }
        usedWords.clear();

        for(int i=0;i<level;i++){
            auto currSequence = q.front();
            string word = currSequence.back();
            q.pop();
            
            if(word == end){
                if(ans.size() == 0) ans.push_back(currSequence);
                else if(currSequence.size() == ans[0].size()) ans.push_back(currSequence);
                continue;
            } 

            for (int idx = 0; idx < word.length(); idx++){
                string temp = word;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    temp[idx] = ch;
                    if(st.find(temp) != st.end()){
                        // marks as visisted
                        usedWords.push_back(temp);

                        currSequence.push_back(temp);
                        q.push(currSequence);
                        currSequence.pop_back();
                    }
                }
            }
            
        }
    }
    
    return ans;

}
int main() {

    string start = "hit";
    string end = "cog";

    vector<string> words = {
        "hot",
        "dot",
        "dog",
        "lot",
        "log",
        "cog"
    };

    vector<vector<string>> ans = wordLadder2_BT(words, start, end);

    cout << "All shortest transformation sequences:\n";

    for (const auto& sequence : ans) {
        for (const auto& word : sequence) {
            cout << word << " ";
        }
        cout << "\n";
    }

    return 0;
}
