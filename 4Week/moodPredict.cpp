#include <iostream>
#include <string>
#include <math.h>

using namespace std;

// 
class Good {
    float good;
    float bad;
    float tempGood;
public:
    Good();
    void gCal(int judge, float data1, float data2);
    void setGood(float data);
    void setBad(float data);
    void setTemp(float data);
    float getGood();
    float getBad();
    float getTemp();
};

Good::Good() {
    good = 0;
    bad = 0;
    tempGood = 0;
}

void Good::gCal(int judge, float data1, float data2) {
    float result = 0;

    if(judge == 0) { // 0일 경우 현재 기분 good
        setTemp(result); // tempGood을 0으로 초기화
        result = (getGood()*data1 + getBad()*data2); // 기분이 좋을 확률 총합
        setTemp(result); // tempGood을 확률값으로 저장
    }
    else if(judge == 1) { // 1일 경우 현재 기분 bad
        result = (getGood()*data1 + getBad()*data2); // 기분이 나쁠 확률 총합
        setGood(getTemp());
        setBad(result);
    }
}

void Good::setGood(float data) {
    good = data;
}

void Good::setBad(float data) {
    bad = data;
}

void Good::setTemp(float data) {
    tempGood = data;
}

float Good::getGood() {
    return good;
}

float Good::getBad() {
    return bad;
}

float Good::getTemp() {
    return tempGood;
}

// 오늘 기분이 나쁠 때
class Bad {
    float good;
    float bad;
    float tempGood;
public:
    Bad();
    void bCal(int judge, float data1, float data2);
    void setGood(float data);
    void setBad(float data);
    void setTemp(float data);
    float getGood();
    float getBad();
    float getTemp();
};

Bad::Bad() {
    good = 0;
    bad = 0;
    tempGood = 0;
}

void Bad::bCal(int judge, float data1, float data2) {
   float result = 0;

    if(judge == 0) { // 0일 경우 현재 기분 good
        setTemp(result); // tempGood을 0으로 초기화
        result = (getGood()*data1 + getBad()*data2); // 기분이 좋을 확률 총합
        setTemp(result); // tempGood을 확률값으로 저장
    }
    else if(judge == 1) { // 1일 경우 현재 기분 bad
        result = (getGood()*data1 + getBad()*data2); // 기분이 나쁠 확률 총합
        setGood(getTemp());
        setBad(result);
    }
}

void Bad::setGood(float data) {
    good = data;
}
void Bad::setBad(float data) {
    bad = data;
}

void Bad::setTemp(float data) {
    tempGood = data;
}

float Bad::getGood() {
    return good;
}

float Bad::getBad() {
    return bad;
}

float Bad::getTemp() {
    return tempGood;
}

int main() {
    int when, feeling; // 지금부터 며칠 뒤, 현재 기분
    cin >> when >> feeling;

    float gogo, gobad, badgo, badbad; // 좋은날 좋은날, 좋은날 나쁜날, 나쁜날 좋은날, 나쁜날 나쁜날
    cin >> gogo >> gobad >> badgo >> badbad;

    // constructor. class 구조체 선언
    Good good;
    Bad bad;

    if(feeling == 0) { // 오늘 기분이 좋을 때
        // 오늘 기분에 따른 최초 확률 기입
        good.setGood(gogo);
        good.setBad(gobad);
        cout << "최초 good -> " << good.getGood() << "\n";
        // 선택한 날짜의 기분의 확률을 구하는 과정
        for(int i=0; i<when-1; i++) {
            cout << i+1 << "번째 good\n";
            good.gCal(0, gogo, badgo); // 기분이 좋을 확률
            good.gCal(1, gobad, badbad); // 기분이 나쁠 확률
        }
        // 결과 출력
        cout << round(good.getGood()*10)/10*1000 << endl;
        cout << round(good.getBad()*10)/10*1000 << endl;
    }
    else if(feeling == 1) { // 오늘 기분이 나쁠 때
        // 오늘 기분에 따른 최초 확률 기입
        bad.setGood(badgo);
        bad.setBad(badbad);
         cout << "최초 good -> " << bad.getGood() << "\n";
        // 선택한 날짜의 기분의 확률을 구하는 과정
        for(int i=0; i<when-1; i++) {
            cout << bad.getGood() << endl;
            bad.bCal(0, gogo, badgo); // 기분이 좋을 확률
            cout << bad.getGood() << endl;
            bad.bCal(1, gobad, badbad); // 기분이 나쁠 확률
        }
        // 결과 출력
        cout << round(bad.getGood()*10)/10*1000 << endl;
        cout << round(bad.getBad()*10)/10*1000 << endl;
    }
}
