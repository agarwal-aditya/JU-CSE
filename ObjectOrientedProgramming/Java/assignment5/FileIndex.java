package assignment5;

import java.io.*;
import java.util.*;

public class FileIndex {
    
    	private File filePath;
    
	private HashMap < String, ArrayList<Integer> > hash;
    
	
	private FileIndex(String path) throws Exception {
        
	filePath = new File(path);
        
        hash = new HashMap <String, ArrayList<Integer>>();
        
	}
    
	private void indexTheFile() throws IOException, FileNotFoundException {
        	int lineNumber = 1;
        
		Scanner sc = new Scanner(filePath);
        
		String line;
        
		StringTokenizer token;
        
		while(sc.hasNext()) {
            		line = sc.nextLine();
            		
            		System.out.println(line);
			
			token = new StringTokenizer(line, " +=-,./?~:;~`]}[{|><_!@#$%^&*(\"')\\");
			while(token.hasMoreTokens()) {
				String str = token.nextToken().toLowerCase();
				ArrayList<Integer> list = hash.get(str);
                if(list != null){
					list.add(lineNumber);
                }
				else {
					list = new ArrayList<Integer>();
					list.add(lineNumber);
					hash.put(str, list);
				}
                		
			}
			lineNumber++;
		}
	}
	
	private void displayResults() {
		Set<String> set = hash.keySet();
		Iterator iter = set.iterator();
		while(iter.hasNext()) {
			String key = (String)iter.next();
			ArrayList<Integer> list = hash.get(key);
			System.out.print(key + " :\t");
            for(int i : list){
				System.out.print(i + " ");
            }
			System.out.println();
		}
	}
    
    public static void main(String args[]) {
        try {
        
            FileIndex file = new FileIndex(args[0]);
            file.indexTheFile();
            file.displayResults();
        }
        catch(Exception e) {
            System.out.println(e);
        }
    }
}
