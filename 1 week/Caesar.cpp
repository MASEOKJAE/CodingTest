#include <iostream>
#include <string>

using namespace std;

int main() {
    char alp[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char password[] = {'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C'};
    string caesar, origin; // 카이사르 암호를 담는 변수, 해독한 단어를 담는 변수
    int length = 0;

    cin >> caesar;
    length = caesar.length();

    for(int i=0; i<length; i++) {
        for(int j=0; j<26; j++) {
            if(password[j] == caesar[i])
                cout << alp[j];
        }
    }
    cout << "\n";
}
