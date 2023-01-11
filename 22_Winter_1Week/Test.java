// BAEKJOON
// https://www.acmicpc.net/problem/15596

import java.util.Scanner;

public class Test {
    long sum(int[] a) {
        long ans = 0;
        for(int i=0; i<a.length; i++)
            ans += a[i];
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Test test = new Test();

        int num = sc.nextInt();
        int[] array = new int[num];

        for(int i=0; i<num; i++)
            array[i] = sc.nextInt();

        long answer = test.sum(array);
        System.out.println(answer);
    }
}
