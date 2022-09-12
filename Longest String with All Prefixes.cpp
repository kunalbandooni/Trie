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
    
    bool isEnd(){
        return flag;
    }
    
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    
    void insert(string word){
        Node* temp = root;
        for(int i=0;i<word.length();i++){
            if(!temp->containsKey(word[i])){
                temp->put(word[i], new Node());
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }
    
    bool checkIfPrefixExists(string word){
        Node* temp = root;
        for(int i=0;i<word.length();i++){
            if(temp->containsKey(word[i])){
                temp = temp->get(word[i]);
                if(temp->isEnd() == false)
                    return false;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    Trie trie;
    for(auto i:a)
        trie.insert(i);

    string longest = "";
    for(auto i:a){
        if(trie.checkIfPrefixExists(i)){
            if(longest.size() < i.size())
                longest = i;
            else if(longest.size() == i.size() and longest > i)
                longest = i;
        }
    }
    if(longest == "")    return "None";
    return longest;
}
int main(){
    // Do whatever you want to do...
    return 0;
}