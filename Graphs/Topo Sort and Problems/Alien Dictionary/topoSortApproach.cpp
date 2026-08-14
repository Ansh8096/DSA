#include <bits/stdc++.h>
using namespace std;
int comparingWords(string s1, string s2){
    int i = 0, j = 0;
    while (i< s1.length() && j < s2.length()){
        if(s1[i] != s2[j]) return i;
        i++; j++;
    }
    
    // edge cases...
    if(s1.length() <= s2.length()) return -1;
    else return -2;
}
string findOrderForAlienDictionary(vector<string> &words) {
    unordered_set<char> st;
    for(auto word: words){
        for(char ch: word){
            st.insert(ch);
        }
    }


    int n = st.size();
    vector<int> indegree(26, 0);

    // it is necessary to use set because we can encounter multiple edges between same nodes.
    unordered_map<int, unordered_set<int>> adj;

    for(int i=0;i<words.size()-1;i++){
        int idx = comparingWords(words[i], words[i+1]);
        if(idx == -1) continue;
        if(idx == -2) return "";

        int u = words[i][idx] - 'a';
        int v = words[i+1][idx] - 'a';

        // the insert() -> It returns a pair<iterator, bool>
        // where 'iterator' pointing to inserted element and 'bool' contains result of insertion...
        if(adj[u].insert(v).second) indegree[v]++; // we should only increase the indegree after successful insertion, beacuse there can be multiple edges...
    }

    // applying the topo sort...
    queue<int> q;

    for(int i=0;i<indegree.size();i++){
        if(indegree[i] == 0 && st.find(i + 'a') != st.end()) q.push(i);
    }

    string order = "";
    while (!q.empty()){
        int node = q.front();
        q.pop();
        char ch = node + 'a';
        order += ch;

        if(adj.find(node) != adj.end()){
            for(int itt: adj[node]){
                indegree[itt] -= 1;
                if(indegree[itt] == 0) q.push(itt);
            }
        }
    }
    
    // edge case for cyclic dependency...
    if(order.length() != n) return "";
    return order;
}
int main() {

    vector<vector<string>> testCases = {
        {"wrt", "wrf", "er", "ett", "rftt"},
        {"z", "x"},
        {"z", "x", "z"},
        {"abc", "ab"},
        {"baa", "abcd", "abca", "cab", "cad"}
    };

    for (auto &words : testCases) {
        cout << "Words: ";
        for (auto &word : words) {
            cout << word << " ";
        }

        string ans = findOrderForAlienDictionary(words);

        cout << "\nOrder: " << ans << "\n";
        cout << "-------------------------\n";
    }

    return 0;
}
