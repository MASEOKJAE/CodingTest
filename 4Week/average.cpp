#include <iostream>
#include <string>

using namespace std;

class Calculate {
    int overAvg;

public:
    Calculate();
    void setData(int price);
    int getData();
    int average(int sum, int num);
    float percent(int sum, int num, int score[]);

};

// constructor
Calculate::Calculate() {
    overAvg = 0;
}

// data 저장
void Calculate::setData(int price) {
    overAvg = price;
}

// data return
int Calculate::getData() {
    return overAvg;
}

// 평균 계산
int Calculate::average(int sum, int num) {
    int avg = sum/num;

    return avg;
}

// 각 case percent 계산, 파라미터: (총합, 점수 개수, 점수들)
float Calculate::percent(int sum, int num, int score[]) {
    setData(0); // 0으로 초기화
    float per = 0; // 해당 case percentage
    int avg = average(sum, num);
    int temp = 0;

    // 평균 넘는 학생들의 수 체크
    for(int i=0; i<num; i++) {
        if(score[i] > avg)
            temp++;
    }
    setData(temp); // 평균 넘는 학생 수 저장
    per = (getData()*1.0/num)*100; // 평균 넘는 percent 계산

    return per;
}

int main() {
    int testCase = 0; // 몇 가지 case를 진행할 것인지?
    cin >> testCase; // case 가지 수 입력
    int num[testCase]; // 각 case에 들어갈 인원 수
    float result[testCase];

    Calculate cal;

    for(int i=0; i<testCase; i++) {
        int sum = 0; // 각 case의 점수들 총합
        cin >> num[i]; // 각 case의 개수 입력
        int score[num[i]]; // 각 case의 점수들
        for(int j=0; j<num[i]; j++) {// 점수 입력
            cin >> score[j];
            sum += score[j];
        }
        result[i] = cal.percent(sum, num[i], score);
    }

    // 결과 출력
    for(int k=0; k<testCase; k++)
        printf("%.3f%%\n", result[k]);
}
