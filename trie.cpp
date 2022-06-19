#include "bits/stdc++.h"
using namespace std;

class trieNode {
public:
    trieNode* children[26];
    bool endOfWord;
    
    trieNode () {
        endOfWord = false;
        for (int i=0; i<26; i++) 
            children[i] = NULL;
    }
    
};

class Trie {
private:
    trieNode* root;
public:
    Trie() {
        root = new trieNode();
    }
    
    void insert(string word) {
        trieNode* curr = root;
        for (int i=0; i<word.length(); i++) {
            int k = word[i]-'a';
            if (curr->children[k] == NULL) {
                curr->children[k] = new trieNode();
            }
            curr = curr->children[k];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        trieNode* curr = root;
        for (int i=0; i<word.length(); i++) {
            int k = word[i]-'a';
            if (curr->children[k] == NULL)
                return false;
            curr = curr->children[k];
        }

        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        trieNode* curr = root;
        for (int i=0; i<prefix.length(); i++) {
            int k = prefix[i]-'a';
            if (curr->children[k] == NULL)
                return false;
            curr = curr->children[k];
        }

        return true;
    }
};

int main () {

}