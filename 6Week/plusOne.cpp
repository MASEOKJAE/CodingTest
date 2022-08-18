class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size(); // digits size
        vector<int> result;  // 결과를 담는 변수
        
        digits[size-1] += 1; // 일의 자리 수 + 1
      
        // 모든 자리 수 변화 점검 후, result에 담기
        for(int i=size-1; i>=0; i--) {
            // 더한 값이 다음 자리 수에 영향
            if(digits[i] == 10) {
                result.push_back(0);  // 9일 경우에만 영향이 있기에, 우선 0을 push
                if(i-1 >= 0)          // 지금 자리보다 앞 자리에 값이 있을 경우
                    digits[i-1] += 1;
                else                  // 값이 없을 경우
                    result.push_back(1);
            }
            // 더한 값이 다음 자리 수에 영향 x
            else
                result.push_back(digits[i]);
        }
        // 배열의 끝부터 push를 해서 값이 반대로 저장되어 있기 때문에 결과값 reverse
        reverse(result.begin(), result.end());
        
        // 결과 값 return
        return result;
    }
};
