#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to insert element at bottom
    void insertAtBottom(stack<int> &st, int x) {
        if (st.empty()) {
            st.push(x);
            return;
        }
        int top = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(top);
    }

    // Function to reverse stack recursively
    void reverseStack(stack<int> &st) {
        if (st.empty()) return;

        int top = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, top);
    }
};

// ---------------- Main for Testing ----------------
int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    Solution sol;
    sol.reverseStack(st);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    // Output: 1 2 3 4 (reversed order)
}