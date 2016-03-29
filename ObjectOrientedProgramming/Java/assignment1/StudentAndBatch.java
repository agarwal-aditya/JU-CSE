package assignment1;

import java.io.*;
import java.text.*;
import java.util.*;


class Student{
    
    private static int numberOfStudents = 0;
    
    public static int getNumberOfStudents(){
        return numberOfStudents;
    }
    
    public static boolean isRollUnique(String rollInput){
        int rollInt = Integer.parseInt(rollInput.substring(5));
        return (rollInt <= numberOfStudents);
    }
    
    private int intRoll;
    
    private String  name,
                    roll,
                    course,
                    admissionDate;

    private static final int numberOfSubjects = 5;
    
    public static int subjects(){
        return numberOfSubjects;
    }
    
    private int[] marks;
    
    public Student(){
        name = "";
        roll = "";
        course = "";
        admissionDate = "";
        intRoll = -1;
        marks = new int[numberOfSubjects];
        for(int subject_mark : marks)
            subject_mark = 0;
    }
    
    public String getName(){
        return name;
    }
    
    public String getRoll(){
        return roll;
    }
    
    public String getCourse(){
        return course;
    }
    
    public String getAdmissionDate(){
        return admissionDate;
    }
    
    public int getMarks( int index ){
        try{
            int temp =  marks[index];
        } catch(ArrayIndexOutOfBoundsException e){
            System.out.println(e + "\n\tTry Again!\n\n");
        }
        return marks[index];
    }
    
    public int getIntegerRoll(){
        return intRoll;
    }
    
    public void setIntegerRoll(int i){
        intRoll = i;
    }
    
    public void setName(String inputName){
        name = new String(inputName);
    }
    
    public void setCourse(String inputCourse){
        course = new String (inputCourse);
    }
    
    public void setAdmissionDate( ){
        Date rightNow = new Date();
        DateFormat dateFormat = new SimpleDateFormat("dd-MM-Y HH:mm:ss");
        admissionDate = new String( dateFormat.format(rightNow) );
    }
    
    public void setRoll( ){
        String temp = admissionDate.substring(6, 10);
        temp = temp + "/" + (++numberOfStudents);
        roll = new String(temp);
    }
    
    public void setMarks( int index, int subjectMark ) throws IncorrectMarksException{
        
        try{
            if(subjectMark < 0 || subjectMark > 100)
                throw new IncorrectMarksException();
            
            marks[index] = subjectMark;
            
        } catch(ArrayIndexOutOfBoundsException e){
            System.out.println(e + "\n\tTry Again!\n");
        }
        
    }

}

class Batch extends Student{
	private int department;
	
	public Batch(){
		super();
		department = -1;
	}
	
	public int getDepartmentCode(){
        	return department;
    	}
    	
    	public void setDepartmentCode(int i){
    		department = i;
    	}
    	
    	public double getGrade(){
    		int total = 0;
    		for (int i = 0; i < this.subjects(); i ++){
            		total += this.getMarks(i);
        	}
        	return (total/this.subjects()/10.0);
    	}
    	
    	public void generateMarkSheet(){
        System.out.println("-------------------------------------------------------------------------");
        System.out.println("\t\tMARKSHEET");
        System.out.println("-------------------------------------------------------------------------");
        System.out.println("Name : " + this.getName());
        System.out.println("Course/Batch : " + this.getCourse() + "\t\tAdmission Date : " + this.getAdmissionDate() );
        System.out.println("Roll : " + this.getRoll() + "\t\tDepartment Code : " + department);
        System.out.println("CGPA : " + getGrade() );
        System.out.println("-------------------------------------------------------------------------");
        for (int i = 0; i < this.subjects(); i ++){
            System.out.println("Subject #30" + (i+1) + " :\t " + this.getMarks(i) + " / 100" );
        }
        System.out.println("\n-------------------------------------------------------------------------");
    }
    	
    	

}