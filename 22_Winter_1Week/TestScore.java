// BAEKJOON
// https://www.acmicpc.net/problem/9498

import java.util.Scanner;

public class TestScore {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int score = 0;
        char grade;

        while(true) {
            score = sc.nextInt();
            if(score >= 0 && score <= 100)
                break;
        }

        if(score >= 90)
            grade = 'A';
        else if(score >= 80)
            grade = 'B';
        else if(score >= 70)
            grade = 'C';
        else if(score >= 60)
            grade = 'D';
        else
            grade = 'F';

        System.out.println(grade);
    }
}
