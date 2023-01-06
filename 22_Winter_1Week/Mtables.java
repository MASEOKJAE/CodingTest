// BAEKJOON
// https://www.acmicpc.net/problem/2739

import java.util.Scanner;

public class Mtables {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = 0;

        num = sc.nextInt();
        for(int i=0; i<9; i++) {
            int result = num*(i+1);
            System.out.println(num + " * " + (i+1) + " = " +  result);
        }
    }
}
