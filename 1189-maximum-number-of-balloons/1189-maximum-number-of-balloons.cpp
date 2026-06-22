class Solution {
public:
    int maxNumberOfBalloons(string text) {

        vector<int> freq(26, 0);

        // Count frequencies
        for(char ch : text) {
            freq[ch - 'a']++;
        }

        int answer = 0;

        // Keep forming balloons while possible
        while(
            freq['b' - 'a'] >= 1 &&
            freq['a' - 'a'] >= 1 &&
            freq['l' - 'a'] >= 2 &&
            freq['o' - 'a'] >= 2 &&
            freq['n' - 'a'] >= 1
        ) {

            freq['b' - 'a']--;
            freq['a' - 'a']--;
            freq['l' - 'a'] -= 2;
            freq['o' - 'a'] -= 2;
            freq['n' - 'a']--;

            answer++;
        }

        return answer;
    }
};