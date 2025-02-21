class Solution
{
public:
    // Step 1: Define the backtracking function
    void backtrack(int n, string curr, vector<string>& happyStrings)
    {  
        // Step 2: If the current string reaches length 'n', store it and return
        if (curr.size() == n)
        {  
            happyStrings.push_back(curr);
            return;
        }

        // Step 3: Iterate over possible characters ('a', 'b', 'c')
        for (char ch : {'a', 'b', 'c'})
        {  
            // Step 4: Ensure the new character is different from the last one
            if (curr.empty() || curr.back() != ch)
            {  
                // Step 5: Recursively generate the next character
                backtrack(n, curr + ch, happyStrings);  
            }
        }
    }

    // Step 6: Main function to generate happy strings
    string getHappyString(int n, int k)
    {
        vector<string> happyStrings; 
        backtrack(n, "", happyStrings); // Step 7: Start backtracking from an empty string

        // Step 8: Return k-th happy string if it exists, else return ""
        return (k > happyStrings.size()) ? "" : happyStrings[k - 1];  
    }
};