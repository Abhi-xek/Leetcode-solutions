class Solution {
public:
    // int operation(int a, int b, string i){
    //     if(i == "+") return a+b;
    //     if(i == "-") return b-a;
    //     if(i == "*") return long(a)*long(b);
    //     if(i == "/") return b/a;

    //     return -1;
    // }

    int evalRPN(vector<string>& tokens) {
        int result = 0;
        stack<int>st;

        unordered_map<string, function<int(int, int)>>m{
            {"+", [](int a , int b){return a+b;}}, 
            {"-", [](int a, int b){return b-a;}},
            {"*", [](int a, int b){return long(a)*long(b);}},
            {"/", [](int a, int b){return b/a;}}
        };

        

        for(auto i : tokens){
            if(i =="+" ||i =="-" ||i == "*" ||i == "/" ){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(m[i](a,b));
            }
            else{
                st.push(stoi(i));
            }
        }

        return st.top();
    }
};