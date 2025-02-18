class Solution {
private:
    // Valid function to check if the current digit is valid given ch either I or D.
    bool valid(char ch, int prev, int curr){
        if(ch == 'I') return curr > prev;
        else return curr < prev;
    }

    // Helper function that recursively builds the ans.
    bool helper(string &ans, string &pattern, vector<bool> &visited, int prev, int idx){
        // Base case: We already built the ans.
        if(idx == pattern.size()) return true;
        // Traversing through all the digits.
        for(int i = 1 ; i <= 9 ; i++){
            // Checking if the current digit is visited or not.
            if(!visited[i]){
                // newIdx and truth are computed based on the first digit.
                int  newIdx = (ans == "") ? idx : (idx + 1);
                bool truth  = (ans == "") ? true : valid(pattern[idx], prev, i);
                if(truth){
                    // Adding the current digit to the answer.
                    ans.push_back(i+'0');
                    visited[i] = true;
                    // Recurssion calls.
                    if(helper(ans, pattern, visited, i, newIdx)) return true;
                    // Backtracking
                    visited[i] = false;
                    ans.pop_back();
                }
            }
        }
        return false;
    }
public:
    string smallestNumber(string pattern) {
        // Intuition
        // The idea in here is really very simple. What we will do is we will use the simple Back tracking algorithm for finding the smallestNumber. We will have visited vector which keeps the track of the digits of numbers visited till now. Then based on the idx and I and D then we will continue doing everything. Based on the answer.
        // Variables for storing the answer.
        string ans;
        vector<bool> visited(10, false);
        helper(ans, pattern, visited, -1, 0);
        // Returning the answer.
        return ans;
    }
};