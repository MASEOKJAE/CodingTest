// BECKJOON
// https://www.acmicpc.net/source/53732197

import java.util.Scanner;

public class Main {
    private int loc; // stack location
    private char[] ch = new char[50];


    public Main() {
        setLoc(0);
    }


    public int getLoc() {
        return loc;
    }

    public char getCh() {
        return ch[getLoc()];
    }

    public void setLoc(int num) {
        this.loc = num;
    }

    public void setCh(char v) {
        ch[getLoc()] = v;
    }

    public void push(char v) {
        int num = getLoc();
        num++;
        setCh(v);
        setLoc(num);
    }

    public void pop() {
        int num = getLoc();
        num--;
        char v = getCh();
        setLoc(num);
    }

    boolean stackEmpty() {
        if(getLoc() == 0)
            return true;
        else
            return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Main stack = new Main();
        int num = 0;
        num = sc.nextInt();
        String[] ans = new String[num];

        for(int i=0; i<num; i++) {
            String str = sc.next();
            stack.setLoc(0);
            int err = 0;
            for(int j=0; j<str.length(); j++) {
                char temp = str.charAt(j);
                if(temp == '(')
                    stack.push(temp);
                else {
                    if(stack.stackEmpty()) {
                        ans[i] = "NO";
                        err = 1;
                        break;
                    }
                    else
                        stack.pop();
                }
            }
            if(stack.stackEmpty() && err == 0)
                ans[i] = "YES";
            else
                ans[i] = "NO";
        }

        for(int i=0; i<num; i++)
            System.out.println(ans[i]);
    }
}
