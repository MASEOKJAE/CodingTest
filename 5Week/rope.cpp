#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// rope 조합 중 최대 무게 조합을 알아내는 함수
int maxJudge(int loop, vector<int> rData, vector<int> &cData) {
    sort(rData.begin(), rData.end()); // rope 오름차순 정렬

    for(int i=1; i<=loop; i++) {
        int max = rData.back(); // 가장 마지막 값 return(가장 큰 값)
        rData.pop_back(); // 가장 마지막 값 pop(가장 큰 값)
        max *= i; // rope 개수만큼 곱
        cData.push_back(max); // cData에 최대 증량 push
    }
    sort(cData.begin(), cData.end()); // cData data 오름차순 정렬

    return cData.back(); // cData에서 가장 큰 값 return
}

int main() {
    int num = 0, maxWei = 0; // rope 개수
    cin >> num; // rope 개수 입력
    vector<int> rope, comb; // rope 종류, 조합 종류
    
    for(int i=0; i<num; i++) {
        int temp;
        cin >> temp;
        rope.push_back(temp);
    }
    maxWei = maxJudge(num, rope, comb);
    // 결과 출력
    cout << maxWei << endl;
}
