#include <iostream>
#include <string>

using namespace std;

// 내림차순으로 나무 자라는 날짜 sort
void sorting(int loop, int tOrigin[], int tUpdate[]) {
    int count = 0;
    while(true) {
        int max = 0, m_index = 0;
        for(int i=0; i<loop; i++) {
            if(max < tOrigin[i]) {
                max = tOrigin[i];
                m_index = i;
            }
        }
        tUpdate[count] = max;
        tOrigin[m_index] = 0;
        count++;
        if(count == loop)
            break;
    }
}

// 나무가 다 자라는 날짜
void inviteDay(int loop, int tUpdate[], int &day) {
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
    int tType[tNum], tSort[tNum];

    for(int i=0; i<tNum; i++)
        cin >> tType[i];

    sorting(tNum, tType, tSort);
    inviteDay(tNum, tSort, dDay);

    // 이장님 초대는 나무가 다 자란 다음날
    dDay++;

    // 결과 출력
    cout << dDay << endl;
}
