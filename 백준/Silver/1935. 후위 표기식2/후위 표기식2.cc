#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    string exps;
    cin >> N >> exps;

    vector<int> v(N);
    stack<double> st;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (char exp : exps) {
        if (exp >= 'A' && exp <= 'Z') {
            st.push(v[exp - 'A']);
        }
        else {
            if (!st.empty()) {
                double tmp = st.top();
                st.pop();

                if (exp == '+') {
                    tmp = st.top() + tmp;
                } else if (exp == '-') {
                    tmp = st.top() - tmp;
                } else if (exp == '*') {
                    tmp = st.top() * tmp;
                } else if (exp == '/') {
                    tmp = st.top() / tmp;
                }

                st.pop();
                st.push(tmp);
            }
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << st.top() << '\n';

    return 0;
}