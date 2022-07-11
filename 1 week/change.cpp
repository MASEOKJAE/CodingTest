#include <iostream>
#include <string>

using namespace std;

int main() {
    int test = 0, check = 0, // testcase의 개수, testcase 순서
    kind[4] = {25, 10, 5, 1}, tempChange = 0; // 동전의 종류, 나머지 값
    cin >> test;
    int cent[test]; // 환전이 필요한 cent들을 담는 변수


    for(int i=0; i<test; i++) {
        int temp = 0;
        cin >> cent[i];
        }

    for(int i=0; i<test; i++) {
        while(true) {
            int kindCount = 0;
            if(check == 0) {
                kindCount = cent[i]/kind[check];
                tempChange = cent[i]%kind[check]; // 최초 나머지 값 저장
            }
            else {
                kindCount = tempChange/kind[check]; // 동전 종류별 환전에 필요한 개수
                tempChange = tempChange%kind[check]; // 나머지 값 저장
            }
            
            cout << kindCount << " ";
            if(check == 3)
                break;
            check++;
        }
        check = 0;
        cout << "\n";
    }
}
