class MyHashMap {
public:
    int n = 10000;
    vector<vector<pair<int,int>>> arr;

    MyHashMap() {
        arr.resize(n);
    }
    int sumOfdigits(int key){
        int sum=0;
        while(key>0){
            sum+=key%10;
            key=key/10;
        }
        return sum;
    }
    int hashFunction(int key){
        return sumOfdigits(key)%n;
    }
    
    void put(int key, int value) {
        int ind=hashFunction(key);
        for(auto &p : arr[ind]){
            if(p.first == key){
               p.second = value;
                return; 
            } 
        }
        arr[ind].push_back({key,value});
    }
    
    int get(int key) {
        int ind =hashFunction(key);
        for(auto &p : arr[ind]){
            if(p.first == key){
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int ind =hashFunction(key);
        for(int i = 0; i < arr[ind].size(); i++){
            if(arr[ind][i].first==key){
                arr[ind].erase(arr[ind].begin()+i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */