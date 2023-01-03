// BAEKJOON
// https://www.acmicpc.net/problem/1330

import java.util.Scanner;

public class Compare {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num1 = 0, num2 = 0;
        String result = "";

        num1 = sc.nextInt();
        num2 = sc.nextInt();

        if(num1 > num2)
            result = ">";
        else if(num1 < num2)
            result = "<";
        else
            result = "==";

        System.out.println(result);
    }
}
