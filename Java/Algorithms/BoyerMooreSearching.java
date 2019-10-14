/* Java Program for Boyer Moore String Matching Algorithm */

import java.util.*;
import java.lang.*;
import java.io.*;

class BoyerMooreSearching
{
	static int NO_OF_CHARS = 256; 
    static int badchar[] = new int[256]; 
     //The preprocessing done in constructor
     BoyerMooreSearching( char []str) 
     { 
      int i, size = str.length;
      for (i = 0; i < NO_OF_CHARS; i++) 
           badchar[i] = -1; 
      for (i = 0; i < size; i++) 
           badchar[(int) str[i]] = i; 
     } 
  
     void search( char txt[],  char pat[]) 
     { 
      int m = pat.length, n = txt.length, s = 0;
      while(s <= (n - m)) 
      { 
          int j = m-1; 
          while(j >= 0 && pat[j] == txt[s+j]) j--; 
          if (j < 0) 
          { 
              System.out.println("Patterns found at " + s); 
              s += (s+m < n)? m-badchar[txt[s+m]] : 1; 
          } 
          else
              s += Math.max(1, j - badchar[txt[s+j]]); 
      } 
     } 
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		char[] txt =  br.readLine().toCharArray();
		char[] pat = br. readLine().toCharArray();
		BoyerMooreSearching obj = new BoyerMooreSearching(pat);
		obj.search(txt, pat);
	}
}

  