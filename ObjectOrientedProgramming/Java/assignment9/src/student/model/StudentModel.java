package student.model;

import student.controller.StudentController;
import student.view.StudentView;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * Created by adityaagarwal on 06/04/16.
 */
public class StudentModel {

    private static int numberOfStudents = 0;

    public static int getNumberOfStudents(){
        return numberOfStudents;
    }
    public static void decreaseNumberOfStudents(){ numberOfStudents--; }

    StudentController modelController;
    StudentView modelView;

    public static boolean isRollUnique(String rollInput){
        int rollInt = Integer.parseInt(rollInput.substring(5));
        return (rollInt <= numberOfStudents && rollInt > 0);
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

    public StudentModel() {
        name = "";
        roll = "";
        course = "";
        admissionDate = "";

        intRoll = -1;

        marks = new int[numberOfSubjects];

        for (int i = 0; i < numberOfSubjects; i++){
            marks[i] = 0;
        }

        modelView = new StudentView();
        modelController = new StudentController();
    }

    public StudentModel(StudentModel model){
        name = new String(model.getName());
        roll = new String(model.getRoll());
        course = new String(model.getCourse());
        admissionDate = new String(model.getAdmissionDate());

        intRoll = model.getIntegerRoll();

        marks = new int[numberOfSubjects];

        for(int i = 0; i < numberOfSubjects; i++){
            marks[i] = model.getMarks(i);
        }
    }


    public String getName(){
        return name;
    }

    public String getRoll(){
        return roll;
    }

    public String getCourse() { return course; }

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

    public int getIntegerRoll(){ return intRoll; }

    public double getGrade(){
        int total = 0;
        for (int i = 0; i < numberOfSubjects; i ++){
            total += marks[i];
        }
        return (total/numberOfSubjects/10.0);
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
            if(subjectMark < 0)
                throw new IncorrectMarksException(true);
            else if(subjectMark > 100)
                throw new IncorrectMarksException(false);

            marks[index] = subjectMark;

        } catch(ArrayIndexOutOfBoundsException e){
            System.out.println(e);
        }

    }




}