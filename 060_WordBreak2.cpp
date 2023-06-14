#include <bits/stdc++.h>

void sol(int idx, string temp, vector<string>& ans, string& s, vector<string>& dict, int n) {
    if (idx == n) {
        ans.push_back(temp);
        return;
    }

    for (auto x : dict) {
        int i = idx;
        int j = 0;
        int n2 = x.size();
        while ((i < n) && (j < n2) && (i < s.size()) && (s[i] == x[j])) {
            i++;
            j++;
        }

        if (j == n2) {
            sol(i, temp + x + " ", ans, s, dict, n);
        }
    }
}

vector<string> wordBreak(string& s, vector<string>& dictionary) {
    vector<string> ans;
    sol(0, "", ans, s, dictionary, s.size());
    return ans;
}
