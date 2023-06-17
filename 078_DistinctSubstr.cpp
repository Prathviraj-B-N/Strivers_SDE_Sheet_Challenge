#include <bits/stdc++.h> 

// T: O(n^2 * log(m)) m is set
// S: O(n ^ 3)

void addToSet(string s, unordered_set<string> &st){
    st.insert(s);
}

int distinctSubstring(string &word) {
    unordered_set<string> st;
    for(int i = 0; i < word.size(); i++){
        for(int j = i; j < word.size(); j++){
            addToSet(word.substr(i,j-i+1),st);
        }
    }

    return (int)st.size();
}

// Optimise space complexity with trie
// duplicate substrings will not take extra space
// for each substring trverse from root
// treat each substr as new string

#include <bits/stdc++.h> 
struct Trie{
    public:
    Trie *reference[26];

    bool doesExist(char ch){
        return (reference[ch-'a'] != NULL);
    }

    void put(char ch){
        reference[ch-'a'] = new Trie();
    }

    Trie* get(char ch){
        return reference[ch-'a'];
    }

};

int distinctSubstring(string &word) {
    int count = 0;
    Trie *root = new Trie();

    for(int i = 0; i < word.size(); i++){
        Trie *node = root;
        for(int j = i; j < word.size(); j++){
            if(!node->doesExist(word[j])){
                node->put(word[j]);
                count++;
            }
            node = node->get(word[j]);
        }
    }

    return count;
}


