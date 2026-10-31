
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.length();
        int m = s2.length();

        if (n > m) return false;

        int freq[26] = {0};

        for (char c : s1) {
            freq[c - 'a']++;
        }

        int i = 0;
        int count = 0;

        for (int j = 0; j < m; j++) {

            int idx = s2[j] - 'a';

            // Add the incoming character
            if (freq[idx] > 0) {
                count++;
            }

            freq[idx]--;

            // Maintain window size
            if (j - i + 1 > n) {

                int left = s2[i] - 'a';

                freq[left]++;

                if (freq[left] > 0) {
                    count--;
                }

                i++;
            }

            // Check for permutation
            if (j - i + 1 == n && count == n) {
                return true;
            }
        }

        return false;
    }
};
