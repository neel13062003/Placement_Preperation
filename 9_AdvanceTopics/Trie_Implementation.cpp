#include <bits/stdc++.h>
using namespace std;

class TrieNode{
    public: 
        char data;
        TrieNode *children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode *root;
        Trie(){
            root = new TrieNode('\0'); //starts with null character
        }
        
        void insertUtil(TrieNode *root, string word){
            //base case
            if(word.length() == 0) {
                root->isTerminal = true;
                return;
            }
            
            //assumption word in CAPS
            int index = word[0] - 'A';
            TrieNode* child;

            //present 
            if(root->children[index] != NULL) {
                child = root->children[index];
            }
            //absent
            else {
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            //Recursion
            insertUtil(child, word.substr(1));
        }

        bool searchUtil(TrieNode* root, string word){
            //base case
            if(word.length() == 0) {
                return root->isTerminal;
            }
            
            //assumption word in CAPS
            int index = word[0] - 'A';
            TrieNode* child; 

            //present 
            if(root->children[index] != NULL) {
                child = root->children[index];
            }
            //absent
            else {
                return false;  
            }

            //recursion
            return searchUtil(child, word.substr(1));
        }

        bool startsWithUtil(TrieNode* root, string prefix) {
            // base case
            if (prefix.length() == 0) {
                return true;
            }

            // assumption word in CAPS
            int index = prefix[0] - 'A';
            TrieNode* child;

            // present
            if (root->children[index] != NULL) {
                child = root->children[index];
            }
            // absent
            else {
                return false;
            }

            // recursion
            return startsWithUtil(child, prefix.substr(1));
        }

        // void removeUtil(TrieNode* root, string word, int depth = 0) {
        //     if (depth == word.length()) {
        //         root->isTerminal = false;
        //         return;
        //     }

        //     int index = word[depth] - 'A';
        //     TrieNode* child = root->children[index];

        //     if (child == NULL)
        //         return;

        //     removeUtil(child, word, depth + 1);

        //     if (child->isTerminal == false) {
        //         for (int i = 0; i < 26; i++) {
        //             if (child->children[i] != NULL) {
        //                 return;
        //             }
        //         }
        //         delete child;
        //         root->children[index] = NULL;
        //     }
        // }
        void removeUtil(TrieNode *root,String word){  // But in this case we are not saving space and uncomment part we are saving space also
             //base case
            if(word.length() == 0) {
                root->isTerminal  = false;
                return;
            }
            
            //assumption word in CAPS
            int index = word[0] - 'A';
            TrieNode* child; 

            //present 
            if(root->children[index] != NULL) {
                child = root->children[index];
            }
            //absent
            else {
                return false;  
            }

            //recursion
            return searchUtil(child, word.substr(1));
        }
      
        bool searchWord(string word){
            return searchUtil(root, word);
        }
        void insertWord(string word){
             insertUtil(root, word);
        }
        void removeWord(string word) {
            removeUtil(root, word);
        }
        bool startsWith(string prefix) {
            return startsWithUtil(root, prefix);
        }
};

int main(){
    Trie *t = new Trie();
    t->insertWord("abcd");
    t->insertWord("abce");
    t->insertWord("plok");

    cout << "Is Present or Not: " << t->searchWord("abcd") << endl;
    t->removeWord("abcd");
    cout << "Is Present or Not: " << t->searchWord("abcd") << endl;

    cout << "Is Starts with or Not: " << t->startsWith("ab") << endl;

    return 0;
}
