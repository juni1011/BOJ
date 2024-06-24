#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string exps, ans; // 입력을 받을 string과 결과를 저장할 string
    cin >> exps;

    stack<char> st;
    for (char exp : exps) {
        if (exp >= 'A' && exp <= 'Z') {
            cout << exp;
        } else if (exp == '(') {
            st.push('(');
        } else if (exp == '*' || exp == '/') {
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                cout << st.top();
                st.pop();
            }

            st.push(exp);
        } else if (exp == '+' || exp == '-') {
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }

            st.push(exp);
        } else if (exp == ')') {
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }

            st.pop();
        } 
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}
