#include <iostream>
#include <string>

using namespace std;

int main() {
    int callNum = 0; // 전화를 한 횟수
    cin >> callNum; // 전화 횟수 입력

    int callTime[callNum]; // 전화 횟수마다의 통화 시간량
    int yBill = 0, mBill = 0; // 영식 요금, 민식 요금

    for(int i=0; i<callNum; i++)
        cin >> callTime[i]; // 통화 시간량 입략
    
    // 영식 요금제
    for(int i=0; i<callNum; i++) {
        int temp = callTime[i];
        while(temp > 0) {
            if(temp < 30) {
                yBill += 10;
                temp -= 29;
            }
            else {
                yBill += 20;
                temp -= 59;
            }
        }
    }

    // 민식 요금제
    for(int i=0; i<callNum; i++) {
        int temp = callTime[i];
        while(temp > 0) {
            if(temp < 60) {
                mBill += 15;
                temp -= 59;
            }
            else {
                mBill += 30;
                temp -= 119;
            }
        }
    }

    // 결과 출력
    if(yBill < mBill)
        cout << "Y " << yBill << endl;
    else if(yBill > mBill)
        cout << "M " << mBill << endl;
    else
        cout << "Y M " << yBill << endl;        
 }
