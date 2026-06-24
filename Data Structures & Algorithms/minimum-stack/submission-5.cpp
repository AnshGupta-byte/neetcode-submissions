#include <bits/stdc++.h>
using namespace std;

class MinStack {
   public:
    stack<long long> st;
    long long mini;

    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
            return;
        }

        if (val >= mini) {
            st.push(val);
        } else {
            st.push(2LL * val - mini);
            mini = val;
        }
    }

    void pop() {
        if (st.empty()) return;

        long long t = st.top();
        st.pop();

        if (t < mini) {
            mini = 2LL * mini - t;
        }
    }

    int top() {
        long long t = st.top();
        if (t < mini) return mini;
        return t;
    }

    int getMin() { return mini; }
};