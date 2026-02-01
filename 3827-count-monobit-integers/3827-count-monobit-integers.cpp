class Solution {
public:
    int countMonobit(int n) {
        int count = 0;
        for(int x = 0; x <= n;x++){
            if(x==0){
                count++;
                continue;
            }
            int temp = x;
            int lastbit = temp & 1;
            bool isMonobit = true;
            while(temp>0){
                int cur = temp & 1;
                if(cur != lastbit){
                    isMonobit = false;
                    break;
                }
                temp >>= 1;
            }
            if(isMonobit){
                count++;
            }

        }
        return count;
        
    }
};