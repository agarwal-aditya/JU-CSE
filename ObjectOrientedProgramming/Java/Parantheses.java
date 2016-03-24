// Parantheses checker.

import java.util.*;
import java.io.*;

public class Parantheses{
	
	public static void main(String args[]) throws IOException{
		Scanner scanInput = new Scanner(System.in);
		String str;
		Stack paranStack = new Stack();
		char ch;
		Character chPopped;
		boolean isCorrect = true;
		
		System.out.println("Enter a string of parantheses expression : ");
		str = scanInput.nextLine();
		int i, sLen = str.length();
		for(i = 0; i < sLen; i++){
			ch = str.charAt(i);
			if(ch == '(' || ch == '[' || ch == '{' ){
				paranStack.push(ch);
			}
			else if(ch == ')'){
				chPopped = (Character)paranStack.peek();
				if((char)chPopped == '(' ){
					paranStack.pop();
				}
				else{
					isCorrect = false;
					break;
				}
			}
			else if( ch == ']' ){
				chPopped = (Character)paranStack.peek();
				if((char)chPopped == '['){
					paranStack.pop();
				}
				else{
					isCorrect = false;
					break;
				}
			}
			else if( ch == '}' ){
				chPopped = (Character)paranStack.peek();
				if((char)chPopped == '{'){
					paranStack.pop();
				}
				else{
					isCorrect = false;
					break;
				}
			}
	//If char peeked is not compatible with current bracket type. break and set isCorrect flag to false.
			if (!isCorrect){
				break;
			}
		}
	
	//If the parantheses sequence is correct, the stack will be empty and boolean flag will also be true.
		if( paranStack.empty() && isCorrect){
			System.out.println("True.");
		}
		else{
			System.out.println("False.");
		}
		
	
	}
}
