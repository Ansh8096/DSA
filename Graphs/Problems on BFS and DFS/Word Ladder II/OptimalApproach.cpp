#include <bits/stdc++.h>
using namespace std;
void dfs(string curr, string start, unordered_map<string, int> & mpp, vector<vector<string>>& ans, vector<string>& seq){
    string temp = seq.back();

    if(curr == start){
        reverse(seq.begin(), seq.end());
        ans.push_back(seq);
        reverse(seq.begin(), seq.end());
        return;
    }
    
    for(int i=0;i<temp.length();i++){
        char org = temp[i];
        int steps = mpp[temp];

        for(char ch = 'a'; ch <= 'z'; ch++){
            temp[i] = ch;
            if(mpp.find(temp) != mpp.end() && mpp[temp] < steps){
                seq.push_back(temp);
                dfs(temp,start,mpp,ans,seq);
                seq.pop_back();
            }
        }
        temp[i] = org;
    }
}
vector<vector<string>> wordLadder2_OP(string start, string end, vector<string>& words) {
    unordered_set<string> st(words.begin(), words.end());
    queue<string> q;
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;

    q.push(start);
    st.erase(start);
    mpp[start] = 1;

    while (!q.empty()){
        string word = q.front();
        q.pop();
        if(word == end) break;
        int steps = mpp[word];

        for(int i=0;i<word.length();i++){
            char org = word[i];

            for(char ch='a';ch<='z';ch++){
                word[i] = ch;
                if(st.count(word)){
                    q.push(word);
                    mpp[word] = steps+1;
                    st.erase(word);
                }

            }
            word[i] = org;
        }


    }

    vector<string> sequence;
    sequence.push_back(end);

    dfs(end, start, mpp, ans, sequence);
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

    vector<vector<string>> ans = wordLadder2_OP(start, end, words);

    cout << "All shortest transformation sequences:\n";

    for (const auto& sequence : ans) {
        for (const string& word : sequence) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
