#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool check[201][201][201];
struct kind {
    int a;
    int b;
    int c;
};

void judge(int water[], queue<kind> q, vector<int> &result) {
    while(!q.empty()) {
        kind now = q.front(); // queue에 가장 먼저 들어 간 값 반환
        q.pop(); // 가장 먼저 들어간 값 pop

        if(check[now.a][now.b][now.c])
            continue;
        check[now.a][now.b][now.c] = true;

        // a가 0일 때, c의 양을 확인, 결과를 
        if(now.a == 0)
            result.push_back(now.c);
        
        // c물통 -> b물통
        if(now.c + now.b > water[1])
            q.push({now.a, water[1], now.b+now.c - water[1]});
        else
            q.push({now.a, now.b+now.c, 0});

        // c물통 -> a물통
        if(now.c + now.a > water[0])
            q.push({water[0], now.b, now.a+now.c - water[0]});
        else
            q.push({now.a+now.c, now.b, 0});
            
        // b물통 -> c물통
        if(now.b + now.c > water[2])
            q.push({now.a, now.b+now.c - water[2], water[2]});
        else
            q.push({now.a, 0, now.b+now.c});

        // b물통 -> a물통
        if(now.b + now.a > water[0])
            q.push({water[0], now.b+now.a - water[0], now.c});
        else
            q.push({now.a+now.b, 0, now.c});

        // a물통 -> c물통
        if(now.a + now.c > water[2])
            q.push({now.a+now.c - water[2], now.b, water[2]});
        else
            q.push({0, now.b, now.a+now.c});

        // a물통 -> b물통
        if(now.a + now.b > water[1])
            q.push({now.a+now.b - water[1], water[1], now.c});
        else
            q.push({0, now.b+now.a, now.c});
    }
}

int main() {
    int bottle[3] = {}; // 3가지의 물통 종류
    vector<int> cNum; // 해당 조건에서 C 물통에 담길 수 있는 물의 양

     for(int i=0; i<3; i++)
        cin >> bottle[i];

    queue<kind> q; // 물통 queue 생성
    q.push({0, 0, bottle[2]}); // 최초 queue에 기입

    judge(bottle, q, cNum); // c물통의 종류를 구해주는 함수

    sort(cNum.begin(), cNum.end()); // cNum 오름차순으로 정렬
    
    // 결과 
    for(int i=0; i<cNum.size(); i++)
        cout << cNum[i] << " ";
}
