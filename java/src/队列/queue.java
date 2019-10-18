package 队列;
import java.util.*;
//银行排队
public class queue {

	public static void main(String[] args) {
		Queue<String> queue = new LinkedList<String>();
		int timeA = 0,timeB = 0,timeC = 0;
		int coutA = 0,coutB = 0,coutC = 0;
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		for (int i = 0; i < n; i++) {
			queue.offer(scanner.next());
		}
		for (int i = 0; i < n; i++) {
			String a = (String) ((LinkedList<String>) queue).pop();
			if (a.equals("A")) {
				timeA += scanner.nextInt();
				coutA++;
			}else if (a.equals("B")) {
				timeB += scanner.nextInt();
				coutB++;
			}else {
				timeC += scanner.nextInt();
				coutC++;
			}
		}
		coutA = timeA/coutA;
		coutB = timeB/coutB;
		coutC = timeC/coutC;
		System.out.println(coutA+"\n"+coutB+"\n"+coutC);
	}
}
