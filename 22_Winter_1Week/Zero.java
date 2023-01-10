// BAEKJOON
// https://www.acmicpc.net/problem/10773
// total 계산 할 때, 한번 더 생각하기

import java.util.Scanner;
import java.util.Stack;

public class Zero {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> money = new Stack<Integer>();

        int num = sc.nextInt();
        for(int i=0; i<num; i++) {
            int temp = sc.nextInt();
            if(temp == 0)
                money.pop();
            else
                money.push(temp);
        }
        int total = 0, rSize = money.size();;
        for(int i=0; i<rSize; i++)
            total += money.pop();
        
        System.out.println(total);
    }
}
