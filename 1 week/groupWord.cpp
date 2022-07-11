#include <iostream>
#include <string>

using namespace std;

// 이전에 등장했던 단어였는지 판단해주는 함수
int judge(char previous[], char compare, int count) {
    int result = 0;

    // 이전에 등장했던 단어들이 담겨 있는 'previous' 변수를 현재 상태 단어 'compare'과 비교
    for(int i=0; i<count; i++) {
        if(previous[i] == compare)
            result = 1; // 이전에 등장했던 단어가 또 다시 등장할 경우
    }
    return result;
}

int main() {
    int kind = 0, check = 0, // 문장 종류 개수
    wordCount = 0, group = 0; // 단어가 새로 등장할 때마다 count를 한다, group 문장의 개수
    char tempWord, prevWord[100] = ""; // 비교를 위해 잠시 문자를 저장하는 변수

    cin >> kind;
    string sentence[kind];
    int length[kind]; // 각 문장들의 길이

    for(int i=0; i<kind; i++) {
        cin >> sentence[i];
        length[i] = sentence[i].length();
        tempWord = sentence[i][0]; // 문장에서 가장 최초의 단어로 초기화
        wordCount++;
        for(int j=0; j<=length[i]; j++) {
            if(tempWord != sentence[i][j]) {
                if(judge(prevWord, tempWord, wordCount) == 1) {
                    check = 1; // check에 1이 담기면 이 문장은 그룹이 아님
                    break;
                }
                else { // 문장이 아직 그룹 문장 성격을 갖고 있음
                    prevWord[wordCount-1] = tempWord;
                    tempWord = sentence[i][j];
                    wordCount++;
                }
            }
        }
        // 새로운 문장의 그룹 여부를 판별하기 전 다시 초기화 해주는 작업
        for(int k=0; k<wordCount; k++)
            prevWord[k] = '\0';
        wordCount = 0;
        // 만약 check가 0이면 group 문장인 것이고, 아니면 그룹 문장이 아니다.
        if(check == 0)
            group++;
        else
            check = 0;
    }

    // 최종 그룹 문장 개수 출력
    cout << group << "\n";
}
