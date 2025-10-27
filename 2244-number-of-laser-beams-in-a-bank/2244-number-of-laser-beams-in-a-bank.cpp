class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int ans = 0;
        for(int i =0;i<bank.size();i++){
            // check for the devices in current row
            int currentRow =0;
            for(int j = 0; j<bank[0].size();j++){
                if(bank[i][j]== '1'){    
                    currentRow++;
                }
            }
            if(currentRow>0){
                ans = ans + (currentRow*prev);
                prev = currentRow;
            }
        }
        return ans;
    }
};