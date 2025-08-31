class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> us;
        for(int i=0;i<friends.size();i++){
            us.insert(friends[i]);
        }
        vector<int> arr;
        for(int i=0;i<order.size();i++){
            if(us.find(order[i])!=us.end()){
                arr.push_back(order[i]);
            }
        }
        return arr;
    }
};