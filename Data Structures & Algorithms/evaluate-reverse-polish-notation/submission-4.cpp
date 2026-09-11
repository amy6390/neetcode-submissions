class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (int i = 0; i < tokens.size(); i++) {
            string c = tokens[i];
            if (c != "+" && c != "-" && c != "*" && c != "/") {
                stk.push(stoi(c));
            } 
            else {
                int first_num = stk.top();
                stk.pop();
                int second_num = stk.top();
                stk.pop();
                 
                if (c == "+") {
                    int res = first_num + second_num;
                    stk.push(res);
                }
                else if (c == "-") {
                    int res = second_num - first_num;
                    stk.push(res);
                }
                else if (c == "*") {
                    int res = first_num * second_num;
                    stk.push(res);
                }
                else if (c == "/") {
                    int res = second_num / first_num;
                    stk.push(res);
                }
            }
        }

        int res = (!stk.empty() ? stk.top() : 0);
        return res;
    }
};
