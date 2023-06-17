struct Node{
    Node *ref[26];
    bool last = false;

    bool refExists(char ch){
        return (ref[ch-'a'] != NULL);
    }

    void put(char ch){
        ref[ch-'a'] = new Node();
    }

    Node* get(char ch){
        return ref[ch-'a'];
    }

};

class Trie {
private: Node *root;
public:


    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *node = root;

        for(int i=0;i<word.size();i++){
            // if word already exist go to its ref
            // else insert and go to its ref
            // in both case we have to go to ref, 
            // so if word dosent exist add it to trie and go to ref

            if(!node->refExists(word[i])){
                node->put(word[i]);
            }
            node = node->get(word[i]);
        }
        node->last = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->refExists(word[i])) return false;
            node = node->get(word[i]);
        }
        return (node->last);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.size(); i++){
            if(!node->refExists(prefix[i])) return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};