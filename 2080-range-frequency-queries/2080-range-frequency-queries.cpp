class RangeFreqQuery {
    struct Node {
        unordered_map<int, int> frequency;
    };

    vector<Node> segmentTree;
    int size;

private:
    void mergeFrequencies(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        for (const auto& entry : segmentTree[leftChild].frequency) {
        segmentTree[index].frequency[entry.first] += entry.second;
        }

        for (const auto& entry : segmentTree[rightChild].frequency) {
        segmentTree[index].frequency[entry.first] += entry.second;
        }
        }

    void buildTree(int index, int low, int high, vector<int>& arr) {
        if (low == high) {
            segmentTree[index].frequency[arr[low]] = 1;
            return;
        }
        int mid = (low + high) / 2;
        buildTree(2 * index + 1, low, mid, arr);
        buildTree(2 * index + 2, mid + 1, high, arr);
        mergeFrequencies(index);
    }

    int queryFrequency(int index, int low, int high, int l, int r, int value) {
        if (r < low || high < l) { 
            return 0;
        }
        if (l <= low && high <= r) {
            return segmentTree[index].frequency[value];
        }
        int mid = (low + high) / 2;
        int left = queryFrequency(2 * index + 1, low, mid, l, r, value);
        int right = queryFrequency(2 * index + 2, mid + 1, high, l, r, value);
        return left + right;
    }

public:
    RangeFreqQuery(vector<int>& arr) {
        size = arr.size();
        segmentTree.resize(4 * size + 1);
        buildTree(0, 0, size - 1, arr);
    }

    int query(int left, int right, int value) {
        return queryFrequency(0, 0, size - 1, left, right, value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */