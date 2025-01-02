class Solution {
    public boolean isVowel(char ch){
        return ch == 'a' || ch == 'e' ||  ch == 'i' || ch == 'o' || ch == 'u';
    }
    public int[] vowelStrings(String[] words, int[][] queries) {
        int n = words.length, len = queries.length;
        int vowelCount[] = new int[n];
        int res[] = new int[len];
        int count = 0;
        for(int i=0; i<n; i++){
            if(isVowel(words[i].charAt(0)) && isVowel(words[i].charAt(words[i].length()-1))) count++;
            vowelCount[i] = count;
        }
        for(int i=0; i<len; i++){
            int countInRange = vowelCount[queries[i][1]];
            if(queries[i][0]-1>=0) countInRange -= vowelCount[queries[i][0]-1];
            if(countInRange>0) res[i] = countInRange;
        }
        return res;
    }
}