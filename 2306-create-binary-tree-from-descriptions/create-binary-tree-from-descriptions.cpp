/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, int> parent, child;
        for (int i = 0; i < descriptions.size(); i++) {
    if (mp.find(descriptions[i][0]) == mp.end()) {
                TreeNode* create = new TreeNode(descriptions[i][0]);
                mp[descriptions[i][0]] = create;
            }

            if (mp.find(descriptions[i][1]) == mp.end()) {
                TreeNode* create = new TreeNode(descriptions[i][1]);
                mp[descriptions[i][1]] = create;
            }

            if (descriptions[i][2]) {
                mp[descriptions[i][0]]->left = mp[descriptions[i][1]];
            } else {
                mp[descriptions[i][0]]->right = mp[descriptions[i][1]];
            }

      
            parent[descriptions[i][0]]++;
            child[descriptions[i][1]]++;
        }


        TreeNode* ans = nullptr;

        for (auto it : mp) {
            if (parent.find(it.first) != parent.end() &&
                child.find(it.first) == child.end()) {
                ans = it.second;
                break;
            }
        }

        return ans;
    }
};