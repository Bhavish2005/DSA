/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int>parent;
        unordered_map<int,TreeNode*>node;
        int n=descriptions.size();
        parent.reserve(n);
        node.reserve(n);
        int root=-1;
        for(auto d:descriptions){
            int par=d[0];
            int child=d[1];
            bool isleft=d[2];
            if(node.count(par)==0)
            {
                node[par]=new TreeNode(par);
                if(parent.count(par)==0)
                root=par;
            }
            if(node.count(child)==0){
                node[child]=new TreeNode(child);
            }
            parent[child]=par;
            if(isleft)
            node[par]->left=node[child];
            else
            node[par]->right=node[child];
        }
        while(parent.count(root))
            root=parent[root];        

            return node[root];
    }
};
