package assignment1;

import java.io.*;
import java.text.*;
import java.util.*;

public class StudentMain {

    private static void display_options(){
        System.out.println("-------------------------------------------------------");
        System.out.println("\t\tOPTIONS");
        System.out.println("-------------------------------------------------------");
        System.out.println("\t<0> Exit.\n");
        System.out.println("\t<1> Admit new student.\n");
        System.out.println("\t<2> Set marks for a student.\n");
        System.out.println("\t<3> Generate marksheet.\n");
        System.out.println("\t<4> Display number of admitted students.\n");
        System.out.println("\t<5> Display the course/batch & dept. of a particular student.\n");
        System.out.println("\t<6> Sort students in a department according to score.\n");
        System.out.println("\t<7> Remove a student.\n");
        System.out.println("\t<9> Reprint options menu.");
    }
    
    private static int returnRoll(Scanner scanInput){
        System.out.println("Enter Roll Number of student." );
        String rollEntered = scanInput.nextLine();
        if(Batch.isRollUnique(rollEntered)){
            int roll = Integer.parseInt(rollEntered.substring(5));
            return roll;
        }
        else{
            System.out.println("Roll Number of student does not exist. Try Again!" );
            return -1;
        }
    }
    
    private static int returnRoll(String rollEntered){
        if(Batch.isRollUnique(rollEntered)){
            int roll = Integer.parseInt(rollEntered.substring(5));
            return roll;
        }
        else{
            System.out.println("Roll Number of student does not exist." );
            return -1;
        }
    }
    
    
    private static void setMarksForStudent(ArrayList<Batch> batch, int roll, Scanner scanInput){
        Batch b = new Batch();
        for(int i = 0; i < batch.size(); i++){
            if( batch.get(i).getIntegerRoll() == roll ){
                b = batch.get(i);
                break;
            }
        }
        
        for (int i = 0; i < Batch.subjects(); i ++){
            System.out.print("Enter marks for subjects #30" + (i+1) + " :\t" );
            try {
                b.setMarks(i, Integer.parseInt(scanInput.nextLine()) );
            } catch(IncorrectMarksException e) {
                System.out.println(e);
                i--;
            }
        }
    }
    
    

    
    
    public static void main(String args[]){
        Scanner scanInput = new Scanner(System.in);
        int choice;
        int CapacityOfSchool = 100;
        ArrayList<Batch> batch = new ArrayList<Batch>(CapacityOfSchool);
        display_options();
        
        do{
            System.out.print("\nEnter a suitable choice:\t");
            choice = scanInput.nextInt();
            scanInput.nextLine();
            switch(choice){
                case 0:
                    break;
                case 1:
                {
                    int i = batch.size();
                    Batch student = new Batch();
                    System.out.print("Enter Name:\t");
                    String str = scanInput.nextLine();
                    student.setName(str);
                    
                    System.out.print("Enter Course:\t");
                    str = scanInput.nextLine();
                    student.setCourse(str);
                    
                    System.out.print("Enter Department Code/Number:\t");
                    int depCode = scanInput.nextInt();
                    student.setDepartmentCode(depCode);
                    
                    student.setAdmissionDate();
                    student.setRoll();
                    student.setIntegerRoll( returnRoll( student.getRoll() ) );
                    System.out.println("Roll Number for " + student.getName() + " is : " + student.getRoll() );
                    
                    batch.add(student);
                    
                    break;
                }
                
                case 2:
                {
                    System.out.print("To set marks for student : ");
                    int roll = returnRoll(scanInput);
                    if(roll != -1){
                        setMarksForStudent(batch, roll, scanInput);
                    }
                    break;
                }
                
               case 3:
                {
                    Batch b = new Batch();
                    System.out.print("To generate marksheet for student : ");
                    int roll = returnRoll(scanInput);
                    if(roll != -1){
                        for(int i = 0; i < batch.size(); i++){
                            if( batch.get(i).getIntegerRoll() == roll ){
                                b = batch.get(i);
                                break;
                            }
                        }
                        b.generateMarkSheet();
                    }
                    break;
                }
         
                case 4:
                    System.out.println(Batch.getNumberOfStudents() + " student(s) have taken admission.");
                    break;
         
                case 5:
                {
                    Batch b = new Batch();
                    System.out.print("To display course/batch & department of a student : ");
                    int roll = returnRoll(scanInput);
                    if(roll != -1){
                        for(int i = 0; i < batch.size(); i++){
                            if( batch.get(i).getIntegerRoll() == roll ){
                                b = batch.get(i);
                                break;
                            }
                        }
                        System.out.println(b.getName() + " having roll " + b.getRoll()+ " is admitted in " + b.getCourse() + " course.");
                        System.out.println("Its department code is : " + b.getDepartmentCode() );
                    }
                    break;
                }
        
                case 6:
                {
                	class CustomComparator implements Comparator<Batch> {
                        public int compare(Batch object1, Batch object2) {
                            return (- ( ((Double)object1.getGrade()).compareTo((Double)object2.getGrade()) ) );
                        }
                    }
                
                	ArrayList<Batch> specificDept = new ArrayList<Batch>();
                	System.out.print("Enter Department Code/Number:");
                    	int depCode = (new Scanner(System.in)).nextInt();
                    	int n = 0;
                    	for(int i = 0; i < batch.size(); i++){
                    		if( batch.get(i).getDepartmentCode() == depCode ){
                    			specificDept.add(batch.get(i));
                    			n++;
                    		}
                    	}
                    	if(n != 0){
                    		Collections.sort(specificDept, new CustomComparator());
                    	
                    		for(int i = 0; i < n; i++){
                    			System.out.println(specificDept.get(i).getName() + "\t" + specificDept.get(i).getGrade()) ;
                    		}
                    		
                    	}
                	break;
                }

                case 7:
                {
                    Batch b = new Batch();
                    System.out.print("To Remove Student from Roll : ");
                    int roll = returnRoll(scanInput);
                    if(roll != -1){
                        System.out.println("size = " + batch.size());
                        System.out.println("Memory free before .gc() call = " + Runtime.getRuntime().freeMemory() + " Bytes" );
                        
                        for(int i = 0; i < batch.size(); i++){
                            if( batch.get(i).getIntegerRoll() == roll ){
                                batch.remove(i);
                                break;
                            }
                        }
                        System.gc();
                        System.out.println("size = " + batch.size());
                        System.out.println("Memory free after .gc() call = " + Runtime.getRuntime().freeMemory() + " Bytes");
                    }
                	break;
                }	
                
                case 9:
                    display_options();
                    break;
                    
                default:
                    System.out.println("Incorrect option chosen. Exiting. Bye!");
                    choice = 0;
                    break;
            }
            
        }while(choice != 0);
        
    }
}