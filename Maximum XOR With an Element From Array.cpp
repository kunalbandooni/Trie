#include<bits/stdc++.h>
using namespace std;

#include<algorithm>
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

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
    sort(arr.begin(), arr.end());
    vector<pair<int, pair<int,int>>> oq;
    int q = queries.size();
    for(int i=0;i<q;i++)
        oq.push_back({queries[i][1], {queries[i][0], i}});
    sort(oq.begin(), oq.end());
    vector<int> ans(q,0);
    int n = arr.size();
    
    Trie trie;
    int ind = 0;
    for(int i = 0;i<q;i++){
        int ai = oq[i].first;
        int xi = oq[i].second.first;
        int qind = oq[i].second.second;
        while(ind < n and arr[ind]<=ai){
            trie.insert(arr[ind]);
            ind++;
        }
        if(ind == 0)    ans[qind] = -1;
        else    ans[qind] = trie.getMax(xi);
    }
    
    return ans;
}

int main(){
    // Your choice... :)
    return 0;
}