class Solution {
public:
    string reverseParentheses(string s) {
        deque<string> dq;
        dq.push_back("");

        for (auto i : s) {
            if (i == '(') {
                dq.push_back("");
            } else if (i == ')') {
                auto lt = dq.back();
                dq.pop_back();
                reverse(lt.begin(), lt.end());
                dq.back() += lt;
            } else {
                dq.back() += i;
            }
        }

        return dq.back();
    }
};
