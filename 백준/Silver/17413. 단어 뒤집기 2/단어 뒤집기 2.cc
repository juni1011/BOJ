#include <iostream>
#include <stack>
#include <string>

using namespace std;

void print(stack <char>& s) {
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {
    string str;
    getline(cin, str);

    bool tag = false;
    stack<char> s;

    for (char ch : str) {
        if (ch == '<') {
            print(s);
            cout << ch;
            tag = true;
        } else if (ch == '>') {
            cout << ch;
            tag = false;
        } else {
            if (tag) {
                cout << ch;
            } else {
                if (ch == ' ') {
                    print(s);
                    cout << ch;
                } else {
                    s.push(ch);
                }
            }
        }
    }

    print(s);

    return 0;
}