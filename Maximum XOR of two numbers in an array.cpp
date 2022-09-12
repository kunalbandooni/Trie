#include<bits/stdc++.h>
using namespace std;
//#include<set>
struct Node{
    Node* links[2];
    
    bool containsKey(int bit){
        return (links[bit] != NULL);
    }
    
    Node* get(int bit){
        return links[bit];
    }
    
    void put(int bit, Node* temp){
        links[bit] = temp;
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* temp = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(!temp->containsKey(bit)){
                temp->put(bit, new Node());
            }
            temp = temp->get(bit);
        }
    }
    int getMax(int num){
        Node* temp = root;
        int maxnum = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(temp->containsKey(1 - bit)){
                maxnum = maxnum | (1<<i);
                temp = temp->get(1-bit);
            }
            else{
                temp = temp->get(bit);
            }
        }
        return maxnum;
    }
};
int maximumXor(vector<int> A){
    Trie trie;
    for(auto &i:A)
        trie.insert(i);
    
    int ans = 0;
    
    for(auto i:A)
        ans = max(ans, trie.getMax(i));
    
    return ans;
    
    /*
    // We have a faster approach... using Trie
    // So, commenting this..
    int maxi = 0, mask = 0;
    
    for(int i=31; i>=0; i--){
        mask = mask | (1<<i);
        set<int> hash;
        for(int i:A)
            hash.insert(i & mask);
        
        int temp = maxi | (1<<i);
        for(auto j:hash)
            if(hash.find(temp ^ j)!=hash.end()){
                maxi = temp;
                break;
            }
    }*/
    
    /*
    // n*n approach
    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++)
            maxi = max(maxi, A[i]^A[j]);
    }*/
    
    //return maxi;
}
int main(){
    // Do whatever you want... :D

    return 0;
}