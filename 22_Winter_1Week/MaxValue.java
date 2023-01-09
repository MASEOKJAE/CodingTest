// BAEKJOON
// https://www.acmicpc.net/problem/2566
// 행렬 출력할 때, (0, 0) 안나오게 주의할 것

import java.util.Scanner;

public class MaxValue {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int row = 1, col = 1, max = 0;

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                int temp = sc.nextInt();
                if(temp > max) {
                    max = temp;
                    row = i + 1;
                    col = j + 1;
                }
            }
        }
        System.out.println(max);
        System.out.println(row + " " + col);
    }
}
