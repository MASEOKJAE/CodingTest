#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    int temp[10], count = 0;
    vector<int> answer;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i]%divisor == 0) { // 나누어 떨어질 경우
            // temp[count] = arr[i];
            answer.push_back(arr[i]);
            count++; // 나누어 떨어지는 개수 카운트
        }
    }
    
    int divArr[count]; // 오름차순으로 정렬한 내용을 담음
    if(count == 0) // 나누어 떨어진 것이 없을 경우
        answer.push_back(-1);
    else // 나누어 떨어진 것이 존재할 경우
        sort(answer.begin(), answer.end()); // 오름차순으로 정렬
    return answer;
}
