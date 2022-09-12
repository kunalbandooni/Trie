#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    
    Node* get(char ch){
        return links[ch - 'a'];
    }
    
    void put(char ch, Node* temp){
        links[ch - 'a'] = temp;
    }
    
    void setEnd(){
        flag = true;
    }
};

class Trie{
    Node* root;
    
    // each time a new node is created,
    //     we get another substring
    int count_of_substring;
    
    public:
    Trie(){
        root = new Node();
        count_of_substring = 0;
    }
    
    int get_count(){
        return count_of_substring;
    }
    
    void insert(string word){
        Node* temp = root;
        for(int i=0;i<word.length();i++){
            if(!temp->containsKey(word[i])){
                temp->put(word[i], new Node());
                count_of_substring++;
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }
};

int distinctSubstring(string &word) {
    int n = word.length();
    Trie trie;
    for(int i=0;i<n;i++){
        string s="";
        for(int j=i;j<n;j++){
            s = s + word[j];
            trie.insert(s);
        }
    }
    return trie.get_count();
}

int main(){

    // Do whatever you want to...
    return 0;
}