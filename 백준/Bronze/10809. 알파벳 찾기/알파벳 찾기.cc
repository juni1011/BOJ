#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string exps;
    cin >> exps;

    vector<int> v(26, -1);
    for (int i = 0; i < exps.length(); i++) {
        if (v[exps[i] - 'a'] == -1)
            v[exps[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; i++) {
        cout << v[i] << " ";
    }

    return 0;
}