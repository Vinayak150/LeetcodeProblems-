#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        // Create a stack to store opening brackets
        stack<char> st;

        // Traverse each character of string
        for (int i = 0; i < s.length(); i++) {
            
            char c = s[i];

            // If character is an opening bracket,
            // push it into stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                // If closing bracket appears
                // and stack is empty -> invalid
                if (st.empty()) {
                    return false;
                }

                // Get top element of stack
                char topElement = st.top();
                st.pop();  // remove it

                // Check if types match
                if (c == ')' && topElement != '(') return false;
                if (c == '}' && topElement != '{') return false;
                if (c == ']' && topElement != '[') return false;
            }
        }

        // If stack is empty -> all brackets matched
        // If not empty -> some opening brackets left
        return st.empty();
    }
};
