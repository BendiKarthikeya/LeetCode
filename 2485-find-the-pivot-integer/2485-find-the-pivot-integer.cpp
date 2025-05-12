class Solution {
public:
    int pivotInteger(int n) {
        vector<int> preArr(n+1);
        vector<int> suffArr(n+1);

        int sum1=0,sum2=0;
        for(int i=1;i<=n;i++){
            sum1+=i;
            sum2+=n-i+1;
            preArr[i]=sum1;
            suffArr[n-i+1]=sum2;
        }
        for(int i=1;i<=n;i++){
            if(preArr[i]==suffArr[i]){
                return i;
            }
        }
        return -1;
    }
};