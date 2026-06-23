class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        string actualCode = "";
        bool isComment = false;

        for (int i = 0; i < source.size(); i++) {
            string codeLine = source[i];

            for (int j = 0; j < codeLine.size(); j++) {

                if (!isComment && j + 1 < codeLine.size() && codeLine[j] == '/' && codeLine[j + 1] == '/') {
                    break;
                }
                else if (!isComment && j + 1 < codeLine.size() && codeLine[j] == '/' && codeLine[j + 1] == '*') {
                    isComment = true;
                    j++;
                }
                else if (isComment && j + 1 < codeLine.size() && codeLine[j] == '*' && codeLine[j + 1] == '/') {
                    isComment = false;
                    j++;
                }
                else if (!isComment) {
                    actualCode += codeLine[j];
                }
            }

            if (!isComment && actualCode.size() != 0) {
                ans.push_back(actualCode);
                actualCode = "";
            }
        }
        return ans;
    }
};