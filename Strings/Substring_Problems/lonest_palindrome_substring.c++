#include <bits/stdc++.h>
using namespace std;

// Solution class to find the longest palindromic substring
class Solution {
private:
    // Helper function to expand around a given center
    pair<int,int> expandAroundCenter(const string &s, int left, int right) {
        // Expand while the characters at left and right are equal
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the start and end indices of the palindrome
        return {left + 1, right - 1};
    }

public:
    // Function to return the longest palindromic substring
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0, end = 0;

        // Iterate over each character as center
        for (int i = 0; i < n; i++) {
            // Odd-length palindrome
            auto odd = expandAroundCenter(s, i, i);
            // Even-length palindrome
            auto even = expandAroundCenter(s, i, i + 1);

            // Choose the longer palindrome
            if (odd.second - odd.first > end - start) {
                start = odd.first;
                end = odd.second;
            }
            if (even.second - even.first > end - start) {
                start = even.first;
                end = even.second;
            }
        }

        // Extract and return the substring
        return s.substr(start, end - start + 1);
    }
};

// Driver code
int main() {
    Solution sol;
    string s = "babad";
    cout << sol.longestPalindrome(s) << endl; // Output: "bab" or "aba"
    return 0;
}


// best with expansiona round center approach

class Solution {
public:
    bool solve(string &s, int i , int j){
        if(i>=j){
            return true;
        }

        if(s[i]==s[j]){
             return solve(s,i+1,j-1);
        }

        return false;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        
        int maxLen= INT_MIN;
        int sp=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)==true){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        sp=i;
                    }
                }
            }
        }

        return s.substr(sp,maxLen);
    }
};


//brute force approach with recursion simply checking all the substrings and checking if they are palindrome or not and then returning the longest one


class Solution {
public:

int t[1001][1001];
    bool solve(string &s, int i , int j){
        if(i>=j){
            return 1;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }

        if(s[i]==s[j]){
             return t[i][j]=solve(s,i+1,j-1);
        }

        return t[i][j]=0;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        memset(t,-1,sizeof(t));
        int maxLen= INT_MIN;
        int sp=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)==true){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        sp=i;
                    }
                }
            }
        }

        return s.substr(sp,maxLen);
    }
};


// dp approach with memoization to optimize the brute force solution by storing previously computed results in a 2D array `t`. This reduces redundant calculations and improves efficiency when checking for palindromic substrings.