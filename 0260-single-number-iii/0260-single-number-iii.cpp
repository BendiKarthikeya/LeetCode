class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xors=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            xors^=nums[i];
        }
        int a=-1;
        for(int i=0;i<32;i++){
            if(((xors>>i)&1)==1){
                a=i;
                break;
            }
        }
        int b=0,c=0;
        for(int i=0;i<n;i++){
            if(((nums[i]>>a)&1)==1){
                b^=nums[i];
            }
            else{
                c^=nums[i];
            }
        }
        return {b,c};
    }
};