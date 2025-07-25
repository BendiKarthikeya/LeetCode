class Solution {
public:
    struct TrieNode {
        TrieNode* children[2];
        TrieNode() {
            children[0] = nullptr;
            children[1] = nullptr;
        }
    };
    
    void insert(TrieNode* root, int num) {
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (root->children[bit] == nullptr) {
                root->children[bit] = new TrieNode();
            }
            root = root->children[bit];
        }
    }
    
    int getMaxXor(TrieNode* root, int num) {
        int maxXor = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;
            if (root->children[opposite] != nullptr) {
                maxXor |= (1 << i);
                root = root->children[opposite];
            } else {
                root = root->children[bit];
            }
        }
        return maxXor;
    }

    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        int maxResult = 0;

        insert(root, nums[0]);

        for (int i = 1; i < nums.size(); ++i) {
            maxResult = max(maxResult, getMaxXor(root, nums[i]));
            insert(root, nums[i]);
        }

        return maxResult;
    }
};
