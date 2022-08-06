#include <iostream>
#include <string>

using namespace std;

// 최소 공배수를 계산해주는 함수
int cal(int info[]) {
    int result = 1;
    if(info[0] == 1 || info[1] == 1) // 두 수 중 어느 하나가 1일 경우
        result = info[0] * info[1];
    else { // 두 수 중 어느 값도 1이 아닐 경우
        int temp = 0; // 두 수끼리 나누고 나온 나머지 값
        int div = 2; // 최초 공약수 시도 값
        int one = 0, two = 0; // 두 수 각각 공약수로 나누고 나온 나머지 값
        if(info[0] < info[1]) { // info[1]이 클 경우
            temp = info[1]%info[0];
            if(temp == 0) // info[1]이 info[0]으로 나눠질 때
                result = info[1];
            else { // info들이 info[0]보다 작은 수들로 나눠질 때
                while(div < info[0]) {
                    one = info[0]%div;
                    two = info[1]%div;
                    if(one == 0 && two == 0) { // 두 수가 나눠 떨어짐
                        info[0] /= div; // info[0]을 div에 나눠진 값으로 변경
                        info[1] /= div; // info[1]을 div에 나눠진 값으로 변경
                        result *= div;
                    }
                    else // 이 div로 더 이상 두 수가 나누어 지지 않음
                        div++; // 다음 div로 비교를 위해 1 증가
                }
                result *= (info[0]*info[1]); // result = (나눈 값들의 곱) * (최대로 나눠 떨어지고 나온 값)
            }
        }
        else { // info[0]이 클 경우
            temp = info[0]%info[1];
            if(temp == 0)  // info[0]이 info[1]으로 나눠질 때
                result = info[0];
            else { // info들이 info[1]보다 작은 수들로 나눠질 때
                while(div < info[1]) {
                    one = info[0]%div;
                    two = info[1]%div;
                    if(one == 0 && two == 0) { // 두 수가 나눠 떨어짐
                        info[0] /= div; // info[0]을 div에 나눠진 값으로 변경
                        info[1] /= div; // info[1]을 div에 나눠진 값으로 변경
                        result *= div; 
                    }
                    else // 이 div로 더 이상 두 수가 나누어 지지 않음
                        div++; // 다음 div로 비교를 위해 1 증가
                }
                result *= (info[0]*info[1]); // result = (나눈 값들의 곱) * (최대로 나눠 떨어지고 나온 값)
            }
        }
    }
    return result;
}

int main() {
    int input = 0; // 알고 싶은 최소공배수 개수
    cin >> input;
    int lCM[input]; // 최소 공배수를 담는 변수(Least Common Multiple)

    for(int i=0; i<input; i++) {
        int num[2]; // 최소 공배수를 구하기 위한 두 수
        cin >> num[0] >> num[1];
        lCM[i] = cal(num); // 최소 공배수를 담음
    }
    // 결과 출력
    for(int i=0; i<input; i++)
        cout << lCM[i] << "\n";
}
