package xmas2023;
import java.io.*;
import java.util.*;

public class xmas2023 {

	public static void main(String[] args) throws FileNotFoundException {
		//day1();
		day2();

}
	static void day1() throws FileNotFoundException {File input = new File("input.txt");
	Scanner scan = new Scanner(input);
	int sum=0; 
	while(scan.hasNextLine()) {
		int summand1=0; 
		String s = scan.nextLine();
		int len = s.length();
		char x; 
		boolean first = true; 
		int firstint =0;;
		int lastint=0;
		for(int i = 0; i<len; i++) {
			x = s.charAt(i);
			if(Character.isDigit(x)) {
				int digit = Character.getNumericValue(x);
				lastint = digit;
				if(first) {
					first=false;
					firstint = digit;
				}
			}
			else {
				if(len-i>2&&s.substring(i,i+ 3).contains("one")) {
					lastint=1;
					if(first) {
						first=false;
						firstint = 1;
					}
					
				}
				if( len-i>2&&s.substring(i, i+3).contains("two")) {
					lastint=2;
					if(first) {
						first=false;
						firstint = 2;
					}
					
				}	if(len-i>4&&s.substring(i, i+5).contains("three")) {
					lastint=3;
					if(first) {
						first=false;
						firstint = 3;
					}
					
				}
				if(len-i>3&&s.substring(i, i+4).contains("four")) {
					lastint=4;
					if(first) {
						first=false;
						firstint = 4;
					}
					
				}
				if(len-i>3 &&s.substring(i,i+ 4).contains("five")) {
					lastint=5;
					if(first) {
						first=false;
						firstint = 5;
					}
					
				}
				if(len-i>2&&s.substring(i, i+3).contains("six")) {
					lastint=6;
					if(first) {
						first=false;
						firstint = 6;
					}
					
				}
				if(len-i>4&&s.substring(i, i+5).contains("seven")) {
					lastint=7;
					if(first) {
						first=false;
						firstint = 7;
					}
					
				}
				if(len-i>4&&s.substring(i,i+ 5).contains("eight")) {
					lastint=8;
					if(first) {
						first=false;
						firstint = 8;
					}
					
				}
				if(len-i>3&&s.substring(i, i+4).contains("nine")) {
					lastint=9;
					if(first) {
						first=false;
						firstint = 9;
					}
					
				}
			}//it is a a letter
			
		}
		summand1= 10*firstint+lastint;
		sum+= summand1;
		
	}
	System.out.println(sum);

}
	static void day2() {
	return;
	
	}
}
