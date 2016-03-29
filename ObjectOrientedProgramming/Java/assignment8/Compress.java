package assignment8;

import java.util.zip.*;
import java.util.*;
import java.io.*;
import java.lang.*;

public class Compress{
	
	
	private static void gzipFile(String sourcePath) throws IOException{
		
        final int BUFFER_SIZE = 1024;
        
		byte[] buffer = new byte[BUFFER_SIZE];

		String filePath = "/Users/adityaagarwal/Documents/Aditya/Yr2/OOP Lab/Java";		//"/home/user/Aditya/Java/zip8.gzip"
        
        ZipEntry testEntry = new ZipEntry (sourcePath);
        if ( testEntry.isDirectory() ){
            System.out.println("ERROR : Can't compress Folder. Try again with a file.\n");
            return;
        }
        
        System.out.println("Starting to gzip...");
        
        String destPath = sourcePath.substring(0, sourcePath.indexOf('.')) + ".gzip";
        
        FileInputStream sourceFile = null;
        
        try{
            
            sourceFile = new FileInputStream(sourcePath);
            
        } catch(FileNotFoundException e) {
            System.out.println(e);
        }
        
        
		FileOutputStream destFile = new FileOutputStream(destPath);
        GZIPOutputStream gzipOut = new GZIPOutputStream(destFile, BUFFER_SIZE);
		
		int length = 0;
	
		while( ( length = sourceFile.read(buffer) ) > 0 ){
			gzipOut.write(buffer, 0, length);
		}
        
        gzipOut.finish();
		gzipOut.close();
        sourceFile.close();
        destFile.close();
        
         System.out.println("Done.");
	
	}

	private static void zipDirectory(String sourceDirectoryPath) throws IOException{
        
        final int BUFFER_SIZE = 1024;
        
        byte[] buffer = new byte[BUFFER_SIZE];
        
        String destPath = sourceDirectoryPath + ".zip" ;
        
        BufferedInputStream bufferedInput = null;
        FileOutputStream destFile = new FileOutputStream(destPath);
        ZipOutputStream zipOut = new ZipOutputStream ( new BufferedOutputStream( destFile )  );
        ZipEntry newZip;
        
        System.out.println("Starting zip process...\n");
        
        File file = new File (sourceDirectoryPath);
        
        String[] filesList = file.list();
        if (file.list() == null){
            System.out.println("ERROR: Mentioned path is not a directory.");
            return;
        }
        
        File[] filesListFileFormat = file.listFiles();
        
        for(int i = 0; i < filesList.length; i++ ){
            String path = sourceDirectoryPath + "/" + filesList[i];
            System.out.println("Compressing : " + path);
            
            //System.out.println("Compressing : " + filesList[i]);
            
            newZip = new ZipEntry(filesList[i]);
            
            if( filesListFileFormat[i].isDirectory() ){
                String subDirDestPath = destPath + "/" + filesList[i];
            //    zipSubDirectory(path, subDirDestPath, newZip);
            }
            else{
                
                zipOut.putNextEntry(newZip);
                
                FileInputStream fileInput = null;
                
                try{
                    fileInput = new FileInputStream( path );
                } catch(FileNotFoundException e) {
                    System.out.println(e);
                }
                
                bufferedInput = new BufferedInputStream( fileInput, BUFFER_SIZE );
               
                int length = 0;
                
                while( ( length = bufferedInput.read(buffer) ) > 0 ){
                    zipOut.write(buffer, 0, length);
                }
                
                fileInput.close();
                bufferedInput.close();
                zipOut.closeEntry();
            }
        }
        zipOut.finish();
        zipOut.close();
        System.out.println("Done.");
        
	}
    
    private static void printOptions(){
        System.out.println("-------------------------------------------------------");
        System.out.println("\t\tOPTIONS");
        System.out.println("-------------------------------------------------------");
        System.out.println("\t<0> Exit.\n");
        System.out.println("\t<1> Compress a file in GZIP Format.\n");
        System.out.println("\t<2> Compress a directory in ZIP Format.\n");
    }
	
	public static void main(String args[]){
        int choice;
        String path;
        printOptions();
        Scanner input = new Scanner(System.in);
        System.out.print("\nEnter a suitable choice:\t");
        choice = input.nextInt();
        input.nextLine();
        switch(choice){
            case 0:
                System.out.println("Exiting the program.");
                break;
            
            case 1:
                System.out.println("Enter the path of the file.");
                path = input.nextLine();
                try{
                    gzipFile(path);
                } catch (IOException e){
                    System.out.println(e);
                    System.out.println("\tTry again!");
                }
                    
                break;
                
            case 2:
                System.out.println("Enter the path of the folder/directory.");
                path = input.nextLine();
                try{
                    zipDirectory(path);
                } catch (IOException e){
                    System.out.println(e);
                    System.out.println("\tTry again!");
                }
                break;
            
            default:
                System.out.println("Incorrect option chosen. Try again!");
                break;
        }
        
        
	}

}
