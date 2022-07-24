import java.util.Scanner;

public class CharSum {
	private static int result;
	private static char[] alp = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 
			'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	
	
	public CharSum() {
		result = 0;
	}
	
	// 존재하는 알파벳을 check 해주는 함수
	public int judge(String now) {
		int confirm = 27;
		
		for(int i=0; i<26; i++) {
			if(now.equals(String.valueOf(alp[i]))) // 어떤 알파벳인지 체크
				confirm = i; // 해당 알파벳 위치 저장
		}
		return confirm;
	}
	
	// 존재하지 않는 알파벳의 아스키 값 총합 산출
	public static int solve(int info[]) {
		result = 0;
		
		for(int i=0; i<26; i++) {
			if(info[i] != 1) // 알파벳이 존재하지 않을 경우
				result += alp[i];
		}
		
		return result;
	}

	public static void main(String[] args) {
		Scanner keyboard = new Scanner(System.in);
		
		CharSum sum = new CharSum(); // 구조체 선언 
		
		int num = 0; // 알고 싶은 종류 개수
		
		num = keyboard.nextInt();
		int[] result = new int[num]; // 결과를 담는 변수
		String[] str = new String[num]; // 문자열을 담을 변수 
		
		for(int i=0; i<num; i++) {
			int[] check = new int[26]; // 존재하는 알파벳은 1로 변경
			str[i] = keyboard.next(); // 문자열 입력 
			String spliter[] = str[i].split(""); // 문자열에 존재하는 알파벳 하나씩 분리 
			for(int j=0; j<spliter.length; j++) {
				String temp = spliter[j].toUpperCase(); // 소문자가 입력되어도 대문자로 변경
				int alpNum = sum.judge(temp);
				if(alpNum < 26) // 26 미만일 경우 알파벳 존재
					check[alpNum] = 1; // 존재하는 알파벳 위치 1로 변경
			}
			result[i] = solve(check);
		}
		// 결과 출력
		for(int i=0; i<num; i++)
			System.out.println(result[i]);
	}
}
