#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N); // 입력 받은 값들 저장
    vector<int> cnt(1000000, 0); // 빈도 저장
    vector<int> ans(N, -1); // 정답을 받는 배열

    stack<int> s;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    for (int i = 0; i < N; i++) {
        while (!s.empty() && cnt[arr[s.top()]] < cnt[arr[i]]) {
            ans[s.top()] = arr[i];
            s.pop();
        }

        s.push(i);
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}