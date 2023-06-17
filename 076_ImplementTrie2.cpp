#include <bits/stdc++.h> 

class Node{
    public:

    Node* reference[26];
    int count;
    int endWith;

    Node(){
        count = 0;
        endWith = 0;
    }

    bool doesExist(char ch){
        return (reference[ch-'a']!=NULL);
    }

    void put(char ch){
        reference[ch-'a'] = new Node();
    }

    Node* get(char ch){
        return reference[ch-'a'];
    }


};

class Trie{
    private:
        Node *root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node *node = root;
        for(int i = 0; i < word.size();i++){
            if(!node->doesExist(word[i])){
                node->put(word[i]);
            }
            node = node->get(word[i]);
            node->count++;
        }
        node->endWith++;

    }

    int countWordsEqualTo(string &word){
        Node *node = root;
        for(int i = 0; i < word.size();i++){
            if(!node->doesExist(word[i])) return 0;
            node = node->get(word[i]);
        }
        return node->endWith;
    }

    int countWordsStartingWith(string &word){
        Node *node = root;
        for(int i = 0; i < word.size();i++){
            if(!node->doesExist(word[i])) return 0;
            node = node->get(word[i]);
        }
        return node->count;
    }

    void erase(string &word){
        Node *node = root;
        for(int i = 0; i < word.size();i++){
            if(node->doesExist(word[i])){
                node = node->get(word[i]);
                node->count--;
            }else{
                return;
            }
        }
        node->endWith--;
    }
};
