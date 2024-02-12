class Solution {
public:
    int operation(int a, int b, string i){
        if(i == "+") return a+b;
        if(i == "-") return b-a;
        if(i == "*") return long(a)*long(b);
        if(i == "/") return b/a;

        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        int result = 0;
        stack<int>st;

        for(auto i : tokens){
            if(i =="+" ||i =="-" ||i == "*" ||i == "/" ){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(operation(a, b, i));
            }
            else{
                st.push(stoi(i));
            }
        }

        return st.top();
    }
};