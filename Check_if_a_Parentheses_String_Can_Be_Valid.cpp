#include <bits/stdc++.h>
using namespace std;

// This is a speed-up block that disables synchronization between C and C++ I/O, improving performance in competitive programming.
auto speedUP = []()
{
    ios::sync_with_stdio(false); // Disables synchronization between C and C++ I/O streams
    cin.tie(0);                  // Unties cin from cout to prevent unnecessary flushes
    cout.tie(0);                 // Ensures cout won't be flushed unnecessarily
    return 'c';                  // Returns a dummy value (not used)
}();

class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        int n = s.length(); // Length of the parentheses string
        if (n % 2 != 0)     // If the length is odd, it is impossible to balance parentheses
            return false;

        int open = 0; // Counter for open parentheses '('

        // First pass: Left to right
        for (int i = 0; i < n; i++)
        {
            if (locked[i] == '1') // If the character is locked
            {
                if (s[i] == '(') // If the locked character is '(', increment open parentheses counter
                    open++;
                else // If the locked character is ')', decrement open parentheses counter
                    open--;
            }
            else        // If the character is unlocked
                open++; // Treat it as an open parenthesis to balance the string (optimally)

            if (open < 0) // If the number of open parentheses becomes negative, it's invalid
                return false;
        }

        int close = 0; // Counter for close parentheses ')'

        // Second pass: Right to left
        for (int i = n - 1; i > 0; i--) // We iterate in reverse order
        {
            if (locked[i] == '1') // If the character is locked
            {
                if (s[i] == ')') // If the locked character is ')', increment close parentheses counter
                    close++;
                else // If the locked character is '(', decrement close parentheses counter
                    close--;
            }
            else         // If the character is unlocked
                close++; // Treat it as a close parenthesis to balance the string (optimally)

            if (close < 0) // If the number of close parentheses becomes negative, it's invalid
                return false;
        }

        return true; // Return true if the string can be made valid
    }
};

class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        int n = s.length(); // Get the length of the string
        // If the length of the string is odd, it's impossible to form valid parentheses
        if (n % 2 != 0)
            return false;

        stack<int> open;     // Stack to store the indices of '(' characters
        stack<int> unlocked; // Stack to store the indices of unlocked characters (where locked[i] == '0')

        // Traverse through the string
        for (int i = 0; i < n; i++)
        {
            if (locked[i] == '0')
            {
                // If the current character is unlocked, push its index to the unlocked stack
                unlocked.push(i);
            }
            else if (s[i] == '(')
            {
                // If the current character is '(' and locked, push it to the open stack
                open.push(i);
            }
            else if (s[i] == ')')
            {
                // If the current character is ')', check if it can be paired with '('
                if (!open.empty())
                {
                    // If there is an open bracket available, pop the top of the open stack
                    open.pop();
                }
                else if (!unlocked.empty())
                {
                    // If there is no open bracket but there's an unlocked character, pop the unlocked stack
                    unlocked.pop();
                }
                else
                {
                    // If there's no valid pair (either '(' or unlocked), return false
                    return false;
                }
            }
        }

        // After processing, try to match the remaining open parentheses with unlocked positions
        while (!open.empty() && !unlocked.empty() && open.top() < unlocked.top())
        {
            open.pop();     // Pop the open stack if it can be matched with an unlocked position
            unlocked.pop(); // Pop the unlocked stack to complete the pairing
        }

        // If there are any unmatched open parentheses left, return false
        if (!open.empty())
            return false;

        // If all open parentheses are matched successfully, return true
        return true;
    }
};

int main()
{

    return 0;
}