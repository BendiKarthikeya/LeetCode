class FreqStack {
public:
    FreqStack() {   
    }
    unordered_map<int,int> um1;
    unordered_map<int,vector<int>> um2;

    int maxF=0;
    
    void push(int val) {
        um1[val]++;
        maxF=max(maxF,um1[val]);
        int f=um1[val];
        um2[f].push_back(val);
    }
    
    int pop() {
        if(maxF==0) return -1;
        int ele = um2[maxF].back();
        um2[maxF].pop_back();
        if(um2[maxF].size()==0){
            um2.erase(maxF);
            maxF--;
        }
        um1[ele]--;
        return ele;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */