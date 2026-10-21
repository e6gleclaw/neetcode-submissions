/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node* ,Node*>mp; // OG node->clone node
        if(node==NULL)return NULL;
        queue<Node*>q;
        q.push(node);
        Node* head=new Node(1);
        mp[node]=head;
        while(!q.empty()){
            Node* cur=q.front();
            Node* cl=mp[cur];
            q.pop();
            for(auto ele:cur->neighbors){
                if(mp.find(ele)==mp.end()){
                    Node* n=new Node(ele->val);
                    mp[ele]=n;
                    cl->neighbors.push_back(n);
                    q.push(ele);
                }
                else{
                    cl->neighbors.push_back(mp[ele]);
                }
            }
        }
        return head;
    }
};
