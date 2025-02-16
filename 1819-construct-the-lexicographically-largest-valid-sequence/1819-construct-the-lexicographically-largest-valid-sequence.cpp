class Solution 
{
public:
    vector<int> constructDistancedSequence(int n) 
    {
        // Step 1: Initialize structures
        vector<int> result(2 * n - 1, -1); // Final sequence array
        vector<bool> used(n + 1, false); // To track used numbers

        // Step 2: Start the recursive backtracking function
        solve(0, n, result, used);

        return result;
    }

private:
    bool solve(int i, int n, vector<int>& result, vector<bool>& used) 
    {
        // Step 3: If we've reached the end, return true
        if (i >= result.size())
        {
            return true;
        } 

        // Step 4: If the position is occupied, move to the next index
        if (result[i] != -1)
        {
            return solve(i + 1, n, result, used);
        } 

        // Step 5: Try placing numbers from `n` to `1`
        for (int num = n; num >= 1; num--)
        {
            if (used[num])
            {
                continue; // Skip if already used
            } 

            // Step 6: Mark the number as used and place it
            used[num] = true;
            result[i] = num;

            if (num == 1 || (i + num < result.size() && result[i + num] == -1))
            {
                if (num > 1)
                {
                    result[i + num] = num;
                } 

                // Step 7: Continue solving recursively
                if (solve(i + 1, n, result, used))
                {
                    return true;
                } 

                // Step 8: Backtrack if solution is not found
                if (num > 1)
                {
                    result[i + num] = -1;
                } 
            }

            // Step 9: Backtrack and try another number
            used[num] = false;
            result[i] = -1;
        }

        return false;
    }
};