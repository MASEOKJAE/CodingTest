// BAEKJOON
// https://www.acmicpc.net/problem/1978

import java.util.Scanner;

public class prime {
    public static int primeChecker(int temp) {
        int result = 0, cal = 0, checker = 0;

        if(temp < 2)
            result = 0;
        else if(temp == 2)
            result = 1;
        else {
            for(int i=2; i<temp; i++) {
                cal = temp%i;
                if(cal == 0) {
                    result = 0;
                    break;
                } else
                    result = 1;
            }
        }
        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = 0, temp = 0, prime = 0;

        
        num = sc.nextInt();
        
        for(int i=0; i<num; i++) {
            temp = sc.nextInt();
            if(primeChecker(temp) == 1)
                prime++;
        }
        System.out.println(prime);
    }
}
