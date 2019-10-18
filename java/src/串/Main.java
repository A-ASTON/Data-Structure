package ´®;
import java.util.*;

public class Main {
	public String mainStr;
	public int size;
	public int[] GetNext(String p, int[] next)
	{
		int j = -1, k = 0;
		next[0] = -1;
		while(k < p.length())
		{
			if(j == -1 || p.charAt(k) == p.charAt(j))
			{
				next[k++] = ++j; 
			}
			else
			{
				j = next[j];
			}
		}
		return next;
	}
	public int KmpFind(String p, int[] next, int pos)
	{
		int i = -1, j = pos;
		while(i < p.length() && j < size)
		{
			if(i == -1 || p.charAt(i) == mainStr.charAt(j))
			{
				i++;
				j++;
			}
			else
			{
				i = next[i];
			}
		}
		if(i == p.length()) return j - i;
		else return -1;
	}
}
