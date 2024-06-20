#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str;
    cin >> str;
    stack<char> s;

    int ans = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            s.push(str[i]);
        } else { // str[i] == ')' 인 경우
            if (str[i - 1] == '(') { // 레이저를 쏘는 경우
                s.pop();
                ans += s.size();
            } else { // str[i - 1]이 ')'인 경우, 막대의 끝
                s.pop();
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}