package assignment7;

import java.util.*;
import java.io.*;
import java.lang.*;
import java.text.*;

public class ListDirectory{
    
    private static void sortName(String path){
        File file = new File(path);
        
        File[] fileList = file.listFiles();
        
        Arrays.sort(fileList);
        
        System.out.println("Files in\t" + path + "\tlisted according to Name :\n");
        
        print(fileList);
        
    }
    
    private static void sortModified(String path){
        File file = new File(path);
        
        File[] fileList = file.listFiles();
        
        Arrays.sort(fileList, new Comparator<File>(){
            
            public int compare(File object1, File object2){
                int result = ((Long)object1.lastModified()).compareTo( (Long)object2.lastModified() );
                return -result;
            }
        });
        
        System.out.println("Files in\t" + path + "\tlisted according to Date Modified (most recent to least) :\n");
        
        print(fileList);
    }
    
    private static void sortSize(String path){
        File file = new File(path);
        
        File[] fileList = file.listFiles();
        
        Arrays.sort(fileList, new Comparator<File>(){
            
            public int compare(File object1, File object2){
                int result = ((Long)object1.length()).compareTo( (Long)object2.length() );
                return -result;
            }
        });
        
        System.out.println("Files in\t" + path + "\tlisted in decreasing order of size :\n");
        
        print(fileList);
        
    }
    
    private static void print (File[] fileList){
        
        SimpleDateFormat dateFormat = new SimpleDateFormat("dd-MM-YYYY, HH:mm");
        
        System.out.println(String.format("%-100s\t%-10s\t%-10s", "Name", "Size", "Last Modified" ));
        
        for(File fileName : fileList){
            long size = fileName.length();
            int sizeUnit = 0;
            while(size / 1024 != 0){
                size /= 1024;
                sizeUnit ++;
            }
            String fileSize = "";
            if(sizeUnit == 0){
                fileSize = size + " B";
            }
            else if(sizeUnit == 1){
                fileSize = size + " KB";
            }
            else if(sizeUnit == 2){
                fileSize = size + " MB";
            }
            else if(sizeUnit == 3){
                fileSize = size + " GB";
            }
            else if(sizeUnit == 4){
                fileSize = size + " TB";
            }
            
            
            System.out.println(String.format("%-100s\t%-10s\t%-10s", fileName.getName(), fileSize, dateFormat.format(fileName.lastModified()) ) );
        }
        
        System.out.println("\n");
        
    }
    
    public static void main(String args[]){
        
        String path = args[0];
        if(args.length > 2){
            System.out.println("ERROR : Cant have more than one modifier!");
        }
        else if (args.length == 2){
            
            if( (args[1].equals("-s") ) ){
                sortSize(path);
            }
            else if( (args[1].equals("-d") ) ){
                sortModified(path);
            }
        }
        else{
            sortName(path);
        }
    }

}