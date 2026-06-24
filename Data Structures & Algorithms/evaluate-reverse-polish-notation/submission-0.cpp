class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                st.push(stoi(tokens[i]));
            } else {
                int second = st.top();
                st.pop();

                int first = st.top();
                st.pop();

                if (tokens[i] == "+")
                    st.push(first + second);
                else if (tokens[i] == "-")
                    st.push(first - second);
                else if (tokens[i] == "*")
                    st.push(first * second);
                else
                    st.push(first / second);
            }
        }
        return st.top();
    }
};
