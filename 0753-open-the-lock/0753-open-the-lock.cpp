class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>keysFound;
        queue<pair<string,int>>q;
        if(find(deadends.begin(), deadends.end(), "0000") == deadends.end()){
            q.push({"0000",0});
            keysFound.insert("0000");
        }
        
        while(!q.empty()){
            string currentLock = q.front().first;
            int currentSteps = q.front().second;
            q.pop();
            if(currentLock == target){
                return currentSteps;
            }
            for(int i=0;i<4;i++){
                // each position can be done as +1 and -1 !
                //first +1
                char temp = currentLock[i];
                currentLock[i] = (currentLock[i] -'0' + 1) % 10 + '0';
                if(keysFound.find(currentLock)==keysFound.end() && find(deadends.begin(), deadends.end(), currentLock) == deadends.end()){
                    q.push({currentLock,currentSteps+1});
                    keysFound.insert(currentLock);
                }
                currentLock[i] = temp;

                // now doing -1
                char temp1 = currentLock[i];
                currentLock[i] = ((currentLock[i] - '0') - 1 + 10) % 10 + '0';
                if(keysFound.find(currentLock)==keysFound.end() && find(deadends.begin(), deadends.end(), currentLock) == deadends.end()){
                    q.push({currentLock,currentSteps+1});
                    keysFound.insert(currentLock);
                }
                currentLock[i] = temp1;
            }
        }
        return -1;
    }
};