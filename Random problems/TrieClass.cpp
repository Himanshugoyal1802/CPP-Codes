#include<bits/stdc++.h>
#include"TrieNode.h"
#include<string>
using namespace std;
class Trie{
    TrieNode* root;

    public:
    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(string word){
        insertWord(root , word);
    }
    void removeWord(string word){
        removeWord(root,word);
    }
    bool search(string word) {
        return search(root,word);
    }

    private:

    bool search(TrieNode* root, string word){
        if(word.size()==0){
            // if(root->isTerminal == true){
            //     return true;
            // }
            // else{
            //     return false;
            // }
            return true;
        }
        
        int index = word[0]-'a';
        TrieNode * child;
        if(root->children[index] != NULL){
            child = root->children[index];
            bool ans = search(child,word.substr(1));
            if(ans == false){
                return ans;
            }
        }
        else{
            return false;
        }
        return true;
    }

    void removeWord(TrieNode * root, string word){
        if(word.size() == 0){
            root->isTerminal = false;
            return;
        }

        TrieNode * child;
        int index = word[0]-'a';
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return;
        }

        removeWord(child,word.substr(1));

        if(child->isTerminal == false){
            for(int i=0; i<26; i++){
                if(child->children[i] != NULL){
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }

    }

    void insertWord(TrieNode* root, string word){
        if(word.size()==0){
            root->isTerminal = true;
            return;
        }

        int index = word[0]-'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertWord(child,word.substr(1));
    }
};

int main(){
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout<<t.search("and")<<endl;
    t.removeWord("and");
    cout<<t.search("and")<<endl;
    cout<<t.search("are")<<endl;
}