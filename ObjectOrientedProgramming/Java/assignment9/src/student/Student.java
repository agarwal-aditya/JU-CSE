package student;

import student.controller.StudentController;
import student.model.StudentModel;
import student.view.StudentView;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

/**
 * Created by adityaagarwal on 06/04/16.
 */
public class Student {

    private static final int studentStrength = 100;
    public static final int SET_MARKS_OPTION = 1;
    public static final int GENERATE_MARKSHEET = 2;

    StudentController controller;
    StudentView view;
    StudentModel[] student;

    private JFrame mainFrame;
    private JButton addStudent,
                    setMarksStudent,
                    generateMarksheet,
                    displayNumberOfAdmittedStudents,
                    exit;

    private Student(){

        controller = new StudentController();
        view = new StudentView();
        student = new StudentModel[studentStrength];

        mainFrame = new JFrame("STUDENT MVC");

        buildComponent(mainFrame);
        registerButtons();
    }


    private void buildComponent(JFrame mainFrame){
        JPanel panelForButtons = new JPanel(new GridLayout(5, 1, 40, 30));
        addStudent = new JButton("ADD A NEW STUDENT");
        addStudent.setMnemonic(KeyEvent.VK_A);
        panelForButtons.add(addStudent);

        setMarksStudent = new JButton("SET MARKS OF A STUDENT");
        setMarksStudent.setMnemonic(KeyEvent.VK_S);
        panelForButtons.add(setMarksStudent);

        generateMarksheet = new JButton("GENERATE A STUDENT'S MARK SHEET");
        generateMarksheet.setMnemonic(KeyEvent.VK_M);
        panelForButtons.add(generateMarksheet);

        displayNumberOfAdmittedStudents = new JButton("DISPLAY NUMBER OF ADMITTED STUDENTS");
        displayNumberOfAdmittedStudents.setMnemonic(KeyEvent.VK_N);
        panelForButtons.add(displayNumberOfAdmittedStudents);

        exit = new JButton("EXIT");
        exit.setMnemonic(KeyEvent.VK_E);
        panelForButtons.add(exit);

        panelForButtons.setBorder(new EmptyBorder(50,80,50,80));

        mainFrame.getRootPane().setDefaultButton(addStudent);
        mainFrame.add(panelForButtons);
        mainFrame.setSize(500, 500);
        mainFrame.setVisible(true);
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private void registerButtons(){
        addStudent.addActionListener( new MyActionListener() );
        setMarksStudent.addActionListener( new MyActionListener() );
        generateMarksheet.addActionListener( new MyActionListener() );
        displayNumberOfAdmittedStudents.addActionListener( new MyActionListener() );
        exit.addActionListener( new MyActionListener() );
    }

    public static void main(String[] args) {

        Student studentMVC = new Student();


    }

    private class MyActionListener implements ActionListener {

        public void actionPerformed(ActionEvent e) {
            if (e.getSource() == addStudent){

                int i = StudentModel.getNumberOfStudents();
                if(i > 0 && (student[i-1].getName().equals("") || student[i-1].getCourse().equals("")) ){
                    StudentModel.decreaseNumberOfStudents();
                }
                student[i] = new StudentModel();
                controller.addNewStudentDetails(student[i]);

            }

            else if (e.getSource() == setMarksStudent) {

                int i = StudentModel.getNumberOfStudents();
                if (i > 0 && (student[i-1].getName().equals("") ||
                        student[i-1].getName().substring(0, 1).equals(" ") ||
                        student[i-1].getCourse().equals("") ||
                        student[i-1].getCourse().substring(0, 1).equals(" ")) ){

                    StudentModel.decreaseNumberOfStudents();
                }
                view.askForRoll(student, SET_MARKS_OPTION);

            }

            else if (e.getSource() == generateMarksheet) {
                int i = StudentModel.getNumberOfStudents();
                if (i > 0 && (student[i-1].getName().equals("") ||
                        student[i-1].getName().substring(0, 1).equals(" ") ||
                        student[i-1].getCourse().equals("") ||
                        student[i-1].getCourse().substring(0, 1).equals(" ")) ){

                    StudentModel.decreaseNumberOfStudents();
                }
                view.askForRoll(student, GENERATE_MARKSHEET);


            }

            else if (e.getSource() == displayNumberOfAdmittedStudents) {
                view.displayNumberOfStudents(mainFrame);
            }

            else if (e.getSource() == exit) {
                System.exit(0);
            }
        }
    }


}
