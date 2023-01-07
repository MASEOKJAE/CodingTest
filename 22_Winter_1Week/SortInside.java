// BAEKJOON
// https://www.acmicpc.net/problem/1427

import java.util.Scanner;

public class Main {
    public int numDigits(int num) {
        int digit = 0, divisor = 10;

        while(num != 0) {
            num /= divisor;
            digit++;
        }

        return digit;
    }
    public int[] makeSort(int a[]) {
        int repeat = a.length;

        // bubble sort
        for(int i=1; i<repeat; i++) {
            for(int j=0; j<repeat-i; j++) {
                if(a[j] < a[j+1]) {
                    int temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }

        return a;
    }
    public int[] makeArray(int num, int digit) {
        int result[] = new int[digit];
        int divisior = (int)Math.pow(10, digit-1);

        for(int i=0; i<digit; i++) {
            int temp = 0;           // num의 현재 가장 큰 자리수의 값
            temp = num/divisior;
            result[i] = temp;

            num -= temp*divisior;
            divisior = divisior/10;
        }
        result = makeSort(result);
        return result;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = 0, digit = 0;
        Main si = new Main();

        num = sc.nextInt();
        digit = si.numDigits(num);
        int[] array = si.makeArray(num, digit);

        for(int i=0; i<array.length; i++)
            System.out.print(array[i]);
    }
}
