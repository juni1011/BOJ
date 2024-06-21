#include <iostream>
#include <stack>

using namespace std;

int main() {
    int arr[1000000] = { 0 }; // 받은 값들을 저장하기 위한 배열
    int ans[1000000] = { 0 }; // 정답을 저장하기 위한 배열
    stack<int> s;

    int N;
    cin >> N;

    for (int i = 0 ; i < N; i++) {
        cin >> arr[i];
    }

    // 스택을 사용하여 각 원소의 최댓값 찾기
    for (int i = 0; i < N; i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) { // 스택이 비어있지 않고 현재 원소보다 큰 원소가 스택에 존재
            ans[s.top()] = arr[i]; // 해당 원소의 최댓값을 ans 배열에 저장하고 스택에서 제거
            s.pop();
        }
        s.push(i);
    }

    // 스택에 남아있는 원소들의 최댓값을 -1로 설정
    while (!s.empty()) {
        ans[s.top()] = -1;
        s.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}