package ir.ac.kntu;
   

import java.util.Scanner;

/**
 * PalindromDetector checks if the input string(just letters) is making a palindrom or not 
 * 
 * @author amir 
 * @0.2
 */


public class PalindromDetector {
      public static void main(String[] args){
            System.out.print("enter your input data (first line is the number of lines you want to enter): \n");
            Scanner scanner=new Scanner(System.in);
            int numOfLines=scanner.nextInt();
            String [] stringLines=new String[numOfLines+1];
            String outPut="";
            int counter=0;

            //reading inputs:
            while (scanner.hasNext()){
                stringLines[counter]=scanner.nextLine();
                counter++;
            } 

            //implementing the operation:
            for (int j=1; j<numOfLines+1;j++){
                stringLines[j]=stringLines[j].toLowerCase();
                stringLines[j]=findLetters(stringLines[j]);
                outPut=outPut + isPalindrom(stringLines[j])+ " ";
            }
            
            scanner.close();
            System.out.print(outPut);
        }
        
      public static String findLetters(String line){
            String letters="";
            for (int k=0 ;k<line.length() ; k++){
                if (line.charAt(k) >= 'a' && line.charAt(k) <= 'z') {
                    letters+=line.charAt(k);
                }
                if (line.charAt(k)>='0' && line.charAt(k)<= '9') {
                    letters+=line.charAt(k);
                }

            }

            return letters;
        }
       
      public static String isPalindrom(String s){
          int a=2;
          int len=s.length();
          for (int i=0 ; i<len/2 ; i++){
              if (s.charAt(i)!= s.charAt(len-i-1)){
                  return "N";
                  
                }
              
              
            }
          return "Y";
        }
}
