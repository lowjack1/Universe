import java.util.*;
import java.lang.*;
import java.io.*;

class MooreVoting
{
	public static void main (String[] args) throws java.lang.Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int arr[] = new int[n];
		for(int i = 0; i < n; i++)
			arr[i]=Integer.parseInt(br.readLine());
		int majority = majorityElement(arr);
		if(majority>-1)
			System.out.println("Majority Element: "+majority);
		else
			System.out.println("No majority element");
	}
	
	private static int majorityElement(int[] arr) {
		int majority = -1;
		int counter = 0;
		int length = arr.length;
		int index = 0;
		while (index < length) {
			if (counter == 0) {
				majority = arr[index];
				counter++;
			} else if (majority == arr[index]) {
				counter++;
			} else {
				counter--;
			}
			index++;
		}

		if (counter == 0) {
			// No majority element found
			return -1;
		}

		index = -1;
		counter = 0;
		while (++index < length) {
			if (majority == arr[index]) {
				counter++;
			}
		}

		if (counter > length / 2)
			return majority;

		return -1;
	}
}
