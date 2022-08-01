#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 나무가 다 자라는 날짜
void inviteDay(int loop, vector<int> tUpdate, int &day) {
    for(int i=0; i<loop; i++) {
        if(i == 0) // 자라는 날짜값 초기화
            day = tUpdate[i] + (i+1); // i+1을 해주는 이유는 loop가 0부터 시작하기 떄문에
        else {
            int temp = tUpdate[i] + (i+1); // (나무가 다 자라는 날짜) + (현재 최초 심은 날짜로부터 지난 날짜)
            if(day < temp) // 만약, 현재 자라는 날짜보다 temp가 더 클 경우
                day = temp;
        }
    }
}

int main() {
    int tNum = 0, dDay = 0;
    cin >> tNum;
    vector<int> tType;

    for(int i=0; i<tNum; i++) {
        int temp = 0;
        cin >> temp;
        tType.push_back(temp);
    }

    // 내림차순으로 나무 자라는 날짜 sort
    sort(tType.rbegin(), tType.rend());

    inviteDay(tNum, tType, dDay);

    // 이장님 초대는 나무가 다 자란 다음날
    dDay++;
    
    // 결과 출력
    cout << dDay << endl;
}
