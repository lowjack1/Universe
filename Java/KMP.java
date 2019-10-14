import java.util.*;
import java.lang.*;
import java.io.*;

class KMP
{
	static int lps[];
	void KMPSearch(String pat, String txt) 
    { 
        int M = pat.length(), N = txt.length(), j = 0, i = 0;
        while (i < N) { 
            if (pat.charAt(j) == txt.charAt(i)) { 
                j++; 
                i++; 
            } 
            if (j == M) { 
                System.out.println("Found pattern "
                                   + "at index " + (i - j)); 
                j = lps[j - 1]; 
            } 
  
            else if (i < N && pat.charAt(j) != txt.charAt(i)) { 
                if (j != 0) 
                    j = lps[j - 1]; 
                else
                    i = i + 1; 
            } 
        } 
    } 
  
    KMP(String pat) 
    { 
		lps = new int[pat.length()];
        int len = 0, i = 1; 
        lps[0] = 0;
  
        while (i < pat.length()) { 
            if (pat.charAt(i) == pat.charAt(len)) { 
                len++; 
                lps[i] = len; 
                i++; 
            } 
            else 
            { 
                if (len != 0)  len = lps[len - 1]; 
                else
                { 
                    lps[i] = len; 
                    i++; 
                } 
            } 
        }} 
  
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String txt = br.readLine(); 
        String pat = br.readLine(); 
        new KMP(pat).KMPSearch(pat, txt); 
	}
}
