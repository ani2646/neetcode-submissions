/*class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> hash;
        
        int i = 0;
        int j = 0;
        int maxf = 0;
        int length = 0;
        
        while (j < s.size()) {
            
            hash[s[j]]++;
            maxf = max(maxf, hash[s[j]]);

            while ((j - i + 1) - maxf > k) {
                hash[s[i]]--;
                i++;
            }

            length = max(length, j - i + 1);
            j++;
        }

        return length;
    }
};*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> hash;
        
        int i = 0;
        int j = 0;
        int maxf = 0;
        int length = 0;
        
        while (j < s.size()) {
            
            // Expand window
            hash[s[j]]++;
            maxf = max(maxf, hash[s[j]]);
            
            // If window invalid → shrink
            if ((j - i + 1) - maxf > k) {
                hash[s[i]]--;
                i++;
            }
            
                // Window valid → update answer
                length = max(length, j - i + 1);
                j++;
            
        }
        
        return length;
    }
};


