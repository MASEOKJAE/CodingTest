#include <iostream>
#include <string>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int temp = x;
    int sum = 0;
    
    if(x < 1 || x > 10000) // x가 제한 범위 미준수
        answer = false;
    else { // x가 제한 범위 준수
        while(temp > 0) { // temp가 0 이상이면 반복
            if(temp < 100) {
                sum += temp/10; // 십의 자리 수 추출
                sum += temp%10; // 일의 자리 수 추출
                temp -= temp; // 반복문을 종료하는 조건
            }
            else if(temp < 1000) {
                int hun = temp/100; // 백의 자리 수 추출
                sum += hun;
                temp -= 100*hun;
            }
            else if(temp < 10000) {
                int tho = temp/1000; // 천의 자리 수 추출
                sum += tho;
                temp -= 1000*tho;
            }
            else {
                sum += temp/10000; // 만의 자리 수 추출
                temp -= 10000;
            }
        }
        // x가 하샤드 수인지 판별
        if(x%sum == 0)
            answer = true;
        else
            answer = false;
    }
    
    return answer;
}
