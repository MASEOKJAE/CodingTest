#include <iostream>
#include <string>

using namespace std;

int main() {
    string str; // 초기 문자열
    cin >> str;
    int strLen = str.length();
    string suffix[strLen], sort[strLen]; // suffix 내용을 담음, suffix에서 알파벳 순으로 sort
    
    // suffix로 담아서 정리
    for(int i=0; i<strLen; i++)
        suffix[i] = str.substr(i, strLen);

    string min = suffix[0];
    int min_index = 0;
    
    for(int i=0; i<strLen; i++) {
        string min = "~"; // 아스키 코드에서 가장 큰 10진수 값
        for(int j=0; j<strLen; j++) {
            if(suffix[j] != sort[0]) { // 발견되지 않은 문자열만 지나갈 수 있도록
                if(min > suffix[j]) { // min값보다 작은 문자열이 존재할 경우
                    min = suffix[j];
                    min_index = j;
                }
            }
        }
        sort[i] = min; // sort 배열에 가장 작은 문자열 입력
        suffix[min_index] = sort[0]; // 가장 작은 문자열이 발견된 위치를 sort[0]으로 초기화
    }
    
    // 결과 출력
    for(int i=0; i<strLen; i++)
        cout << sort[i] << endl;
}
