//Quote of the Day

import java.util.*;
import java.io.*;
import java.text.*;

public class QuoteOfTheDay{

	private static String[] quotes = {
		"Either you run the day or the day runs you.",
		"Good, better, best. Never let it rest. 'Til your good is better and your better is best.\n\t-Jim Rohn",
		"When you reach the end of your rope, tie a knot in it and hang on.\n\t-St. Jerome",
		"Accept the challenges so that you can feel the exhilaration of victory.\n\t-Franklin D. Roosevelt",
		"Life is 10% what happens to you and 90% how you react to it.\n\t-Charles R. Swindoll",
		"In order to succeed, we must first believe that we can.\n\t-Nikos Kazantzakis",
		"What you do today can improve all your tomorrows.\n\t-Ralph Marston",
            	"If oppurtunity doesn't knock, build a door.\n\t-Milton Burle",
            	"It is always the simple that produces the marvellousn\n\t-Amelia Barr",
            	"Only a life lived for others is a life worthwhile.\n\t-Albert Einstein",
            	"A life spent making mistakes is not only more honorable, but more useful than a life spent doing nothing.\n\t-G. B. Shaw",
            	"Either you do it perfect, or you don't do it at all.\n\t-Elon Musk"
	};
	
	public static void main(String args[]){
        
		Date today = new Date();
		DateFormat hr = new SimpleDateFormat("H");
		DateFormat min = new SimpleDateFormat("m");
		DateFormat sec = new SimpleDateFormat("s");
		DateFormat millisec = new SimpleDateFormat("S");
		int numberOfQuoutes = quotes.length;
		long currentTime =  today.getTime();
		long extraMilliSec = 0;
		int temp;
		String st = hr.format(today);
		temp = Integer.parseInt(st);
		extraMilliSec = (long)temp *60*60*1000;
		
		st = min.format(today);
		temp = Integer.parseInt(st);
		extraMilliSec += (long)temp *60*1000;
		
		st = sec.format(today);
		temp = Integer.parseInt(st);
		extraMilliSec += (long)temp *1000;
		
		st = millisec.format(today);
		temp = Integer.parseInt(st);
		extraMilliSec += (long)temp;
		
		currentTime -= extraMilliSec;
		
		Random seed = new Random(currentTime);
		
		int index = seed.nextInt(numberOfQuoutes);
		System.out.println("Quote of the Day :");
		System.out.println(quotes[index]);
	}
}