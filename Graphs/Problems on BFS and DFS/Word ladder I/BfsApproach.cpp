#include <bits/stdc++.h>
using namespace std;

int wordLadder_1(string beginWord, string endWord, vector<string>& wordList) {

    // If endWord is not present, transformation is impossible.
    unordered_set<string> words(wordList.begin(), wordList.end());

    if (words.find(endWord) == words.end()) {
        return 0;
    }

    queue<pair<string, int>> q;

    q.push({beginWord, 1});
    words.erase(beginWord);

    while (!q.empty()) {

        string str = q.front().first;
        int level = q.front().second;
        q.pop();

        if (str == endWord) {
            return level;
        }

        for (int i = 0; i < str.length(); i++) {

            string temp = str;

            for (char ch = 'a'; ch <= 'z'; ch++) {

                if (ch == str[i]) continue;

                temp[i] = ch;

                if (words.find(temp) != words.end()) {
                    q.push({temp, level + 1});
                    words.erase(temp);
                }
            }
        }
    }

    return 0;
}

int main() {

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {
        "hot",
        "dot",
        "dog",
        "lot",
        "log",
        "cog"
    };

    int ans = wordLadder_1(beginWord, endWord, wordList);

    cout << "Shortest transformation length: " << ans << endl;

    return 0;
}
