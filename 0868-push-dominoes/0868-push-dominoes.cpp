class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<char> charArray(dominoes.begin(), dominoes.end());
        int index = 0 ;
        while(index<dominoes.size()){
            if(dominoes[index]== 'L'){
                // make all previous . character in char array as L 
                for (int i = index - 1; i >= 0 && charArray[i] == '.'; i--) {
                     charArray[i] = 'L';
                }
                index++;

            }
            else if (charArray[index] == 'R') {
                // Look ahead to find next 'L' or end
                int j = index + 1;
                while (j < dominoes.size() && charArray[j] == '.') j++;
                if (j < dominoes.size() && charArray[j] == 'L') {
                    // R...L
                    int left = index + 1, right = j - 1;
                    while (left < right) {
                        charArray[left++] = 'R';
                        charArray[right--] = 'L';
                    }
                    index = j + 1;
                } else {
                    // R.... or R at end
                    for (int k = index + 1; k < j; k++) {
                        charArray[k] = 'R';
                    }
                    index = j;
                }
            }
            else {
                index++;
            }
        }
        return string(charArray.begin(), charArray.end());
    }
};