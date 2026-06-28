class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        for(int i=0;i<secret.size();i++){
            if(secret[i] == guess[i]){
                bulls++;
                secret.erase(secret.begin()+ i);
                guess.erase(guess.begin()+ i);
                i--;

            }
        }
        cout<<secret<<" "<<guess;
        int cows = 0;
        //  now we just need to count the same digits in secret and guess!
        vector<int>count1(10,0);
        vector<int>count2(10,0);
        for (char c : secret) {
            count1[c - '0']++;
        }

        for (char c : guess) {
            count2[c - '0']++;
        }
        for(int i=0;i<10;i++){
            cows+= min(count1[i],count2[i]);
        }
        string ans = to_string(bulls)+ "A" + to_string(cows) + "B" ;
        return ans;

    }
};