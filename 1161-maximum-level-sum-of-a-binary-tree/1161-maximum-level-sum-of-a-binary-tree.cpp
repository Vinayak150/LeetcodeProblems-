class Solution {
public:
    void dfs(TreeNode* node, int level, vector<long long>& levelSum) {
       
        if (node == nullptr) return;

        
        if (level > (int)levelSum.size()) {
            levelSum.push_back(0);
        }

       
        levelSum[level - 1] += node->val;

        
        dfs(node->left, level + 1, levelSum);

       
        dfs(node->right, level + 1, levelSum);
    }

    int maxLevelSum(TreeNode* root) {
        vector<long long> levelSum;

       
        dfs(root, 1, levelSum);

        
        long long bestSum = levelSum[0];
        int bestLevel = 1;

        for (int i = 1; i < (int)levelSum.size(); i++) {
            if (levelSum[i] > bestSum) {
                bestSum = levelSum[i];
                bestLevel = i + 1;
            }
        }

        return bestLevel;
    }
};