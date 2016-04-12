package student.controller;

import student.model.StudentModel;
import student.view.StudentView;

import javax.swing.*;

/**
 * Created by adityaagarwal on 06/04/16.
 */
public class StudentController {

    private StudentView addDetailsView,
                        setStudentMarksView;

    public StudentController(){
        addDetailsView = new StudentView();
        setStudentMarksView = new StudentView();
    }

    public void addNewStudentDetails(StudentModel temp){

        addDetailsView.inflateView(temp);
        temp.setAdmissionDate();
        temp.setRoll();
        temp.setIntegerRoll( returnStudentRoll(temp.getRoll()) );

    }

    private int returnStudentRoll(String rollEntered){
        if(StudentModel.isRollUnique(rollEntered)){
            return Integer.parseInt(rollEntered.substring(5));
        }
        else{
            System.out.println("Roll Number of student does not exist." );
            return -1;
        }
    }

    public void setMarks(JTextField tf, StudentModel[] student ){

        int roll = returnStudentRoll(tf.getText());
        if(roll != -1){
            setStudentMarksView.addMarks(student[roll-1]);
        }

    }

    public void generateMarkSheet(JTextField tf, StudentModel[] student){

        int roll = returnStudentRoll(tf.getText());
        if(roll != -1){
            setStudentMarksView.displayMarkSheet(student[roll-1]);
        }
    }

}