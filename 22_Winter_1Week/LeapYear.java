// BECKJOON
// https://www.acmicpc.net/problem/2753

import java.util.Scanner;

public class LeapYear {
    public static int leap(int year) {
        int answer = 0;
        int check1 = 0, check2 = 0, check3 = 0;

        check1 = year%4;
        check2 = year%100;
        check3 = year%400;

        if((check1 == 0 && check2 != 0) || check3 == 0)
            answer = 1;

        return answer;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int year = 0, result = 0;
        year = sc.nextInt();

        result = leap(year);

        System.out.println(result);
    }
}
