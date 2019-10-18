package ´®;
import java.util.*;

public class run {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i = 0; i < t; i++)
		{
			String mStr = sc.next();
			String mode = sc.next();
			String newStr = sc.next();
			int[] next = new int[mode.length()];
			getNext(mode, next);
			int index = kmp(mStr, mode, next, 0);
			mStr.replace(mode, newStr);
			System.out.println(mStr);
//			for(int j = 0; j < next.length; j++)
//			{
//				System.out.print(next[j] + " ");
//			}
//			System.out.println();
//			System.out.println(kmp(mStr, mode, next, 0)+1);
		}

	}
	static void getNext(String s, int[] next)
	{
		int j = -1, k = 0;
		next[0] = -1;
		while(k < s.length() - 1)
		{
			if(j == -1 || s.charAt(k) == s.charAt(j))
			{
				j++;
				k++;
				next[k] = j;
			}
			else
			{
				j = next[j];
			}
		}
	}
	static int kmp(String p, String s, int[] next, int pos)
	{
		int i = pos, j = -1;
		while(i < p.length() && j < s.length())
		{
			if(j == -1 || p.charAt(i) == s.charAt(j))
			{
				i++;
				j++;
			}
			else
			{
				j = next[j];
			}
		}
		if(j == s.length())
		{
			return i - j;
		}
		else
		{
			return -1;
		}
	}
}
