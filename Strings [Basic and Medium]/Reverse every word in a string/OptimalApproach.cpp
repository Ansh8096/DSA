#include <bits/stdc++.h>
using namespace std;
class revere{
public:
    string reverseWords(string &s)
    {

        int n = s.length();
        string ans = "";
        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++)
        {
            string word = "";
            while (i < n && s[i] != ' ')
            {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());
            if (word.length() > 0)
            {
                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};
int main()
{

    string s;
    getline(cin, s); // this will take the entire line as our string..
    revere ren;
    cout << ren.reverseWords(s);
    return 0;
}
