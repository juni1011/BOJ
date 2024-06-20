#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    queue<int> qu;

    for (int i = 1; i <= N; i++) {
        qu.push(i);
    }

    cout << '<';
    while (qu.size() > 1) {
        for (int i = 1; i < K; i++) {
            int tmp = qu.front();
            qu.pop();
            qu.push(tmp);
        }
        cout << qu.front() << ", ";
        qu.pop();

    }
    cout << qu.front() << ">\n";

    return 0;
}