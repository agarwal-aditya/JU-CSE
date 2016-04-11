package student.view;

import student.Student;
import student.controller.StudentController;
import student.model.IncorrectMarksException;
import student.model.StudentModel;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.border.EtchedBorder;
import javax.swing.border.TitledBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Created by adityaagarwal on 06/04/16.
 */
public class StudentView {

    public void inflateView(StudentModel temp){
        JPanel panelForButtons = new JPanel( new GridLayout(5, 1, 40, 10) );

        PanelType1  name = new PanelType1("Name   :", 31),
                    course = new PanelType1("Course :", 10);

        JButton confirm = new JButton("CONFIRM");

        confirm.setToolTipText("You can also press Enter to confirm.");

        panelForButtons.add(name);
        panelForButtons.add(course);
        panelForButtons.add(confirm);

        JFrame addStudentFrame = new JFrame("ADD STUDENT DETAILS");

        addStudentFrame.getRootPane().setDefaultButton(confirm);

        addStudentFrame.add(panelForButtons);
        addStudentFrame.pack();
        addStudentFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        addStudentFrame.setVisible(true);

        confirm.addActionListener(new ActionListener() {
                                      @Override
                                      public void actionPerformed(ActionEvent e) {
                                          temp.setName(name.textField.getText());
                                          temp.setCourse(course.textField.getText());
                                          if(name.textField.getText().equals("") || name.textField.getText().substring(0,1).equals(" ")
                                                  || course.textField.getText().equals("") || course.textField.getText().substring(0,1).equals(" ") ){
                                              System.out.println("INVALID ENTRY. YOU NEED TO ENTER SOMETHING. THEN ONLY WILL IT BE ACCEPTED");
                                              StudentModel.decreaseNumberOfStudents();
                                              addStudentFrame.dispose();
                                              return;
                                          }

                                          addStudentFrame.dispose();
                                          (new StudentView()).showRollAndAdmissionDate(temp);
                                      }
                                  }
        );

    }

    private void initialisePersonalDetails(JPanel panel, StudentModel temp){

        PanelType1  name   = new PanelType1("Name   :", 31),
                course = new PanelType1("Course :", 10),
                roll   = new PanelType1("Roll      :", 10),
                admissionDate = new PanelType1("Admission Date :", 15);

        name.textField.setEditable(false);
        name.textField.setText( temp.getName() );

        course.textField.setEditable(false);
        course.textField.setText( temp.getCourse() );

        roll.textField.setEditable(false);
        roll.textField.setText( temp.getRoll() );

        admissionDate.textField.setEditable(false);
        admissionDate.textField.setText( temp.getAdmissionDate() );

        panel.add(name);
        panel.add(course);
        panel.add(roll);
        panel.add(admissionDate);

    }

    private void showRollAndAdmissionDate(StudentModel temp){
        JPanel panelForButtons = new JPanel( new GridLayout(4, 1, 40, 10) );

        this.initialisePersonalDetails(panelForButtons, temp);

        panelForButtons.setBorder(new EmptyBorder(5,5,10,5));


        JFrame showFinalStudentDetails = new JFrame("Details of " + temp.getRoll());
        showFinalStudentDetails.add(panelForButtons);
        showFinalStudentDetails.pack();
        showFinalStudentDetails.setVisible(true);
        showFinalStudentDetails.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
    }

    public void askForRoll(StudentModel[] student, int choice){

        PanelType1 roll = new PanelType1("Enter the roll no : ", 10);
        roll.setVisible(true);
        JButton confirm = new JButton("CONFIRM");
        confirm.setToolTipText("You can also press Enter to confirm.");

        JPanel container = new JPanel(new GridLayout(2,1,10,10));
        container.setBorder(new EmptyBorder(20,25,25,25));

        JFrame forRoll = new JFrame("Add a Student's Marks");
        forRoll.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        forRoll.getRootPane().setDefaultButton(confirm);

        container.add(roll);
        container.add(confirm);

        forRoll.add(container);
        forRoll.pack();
        forRoll.setVisible(true);

        confirm.addActionListener(
                new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        if(roll.textField.getText().equals("") || roll.textField.getText().substring(0,1).equals(" ") ) {
                            System.out.println("INVALID ENTRY. YOU NEED TO ENTER SOMETHING. THEN ONLY WILL IT BE ACCEPTED");
                            forRoll.dispose();
                            return;
                        }
                        if(choice == Student.SET_MARKS_OPTION)
                            (new StudentController()).setMarks(roll.textField, student);
                        else if(choice == Student.GENERATE_MARKSHEET)
                            (new StudentController()).generateMarkSheet(roll.textField, student);
                        forRoll.dispose();
                    }

                }
        );

    }

    public void addMarks(StudentModel student){

        StudentModel s = new StudentModel(student);

        JPanel panelForMarks = new JPanel( new GridLayout(7, 1, 40, 10) );

        PanelType1  subject[] = new PanelType1[StudentModel.subjects()];

        for(int i = 0; i < StudentModel.subjects(); i++) {
            subject[i] = new PanelType1("Subject #30" + (i + 1), 3);
            subject[i].setLayout( new FlowLayout(FlowLayout.CENTER) );
            panelForMarks.add(subject[i]);
        }

        JButton confirm = new JButton("CONFIRM");
        confirm.setToolTipText("You can also press Enter to confirm.");

        panelForMarks.add(confirm);

        JFrame addStudentMarksFrame = new JFrame("Marks for " + s.getName());

        addStudentMarksFrame.getRootPane().setDefaultButton(confirm);

        addStudentMarksFrame.add(panelForMarks);
        addStudentMarksFrame.setSize(350,400);
        addStudentMarksFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        addStudentMarksFrame.setVisible(true);

        confirm.addActionListener(
                new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        boolean flag = true;
                        for(int i = 0; i < StudentModel.subjects(); i++) {
                            try {
                                s.setMarks(i, Integer.parseInt(subject[i].textField.getText()) );
                            } catch(IncorrectMarksException e1) {
                                JOptionPane.showMessageDialog(addStudentMarksFrame, e1, "Incorrect Marks Exception", JOptionPane.ERROR_MESSAGE);
                                flag = false;
                            }

                        }
                        if(flag){
                            for(int i = 0; i < StudentModel.subjects(); i++) {
                                try {
                                    student.setMarks(i, s.getMarks(i));
                                } catch (IncorrectMarksException e1) {
                                    e1.printStackTrace();
                                }
                            }
                            addStudentMarksFrame.dispose();
                        }
                        
                    }
                }
        );

    }

    public void displayMarkSheet(StudentModel student){

        JPanel  panelForMarks = new JPanel( new GridLayout(0, 3, 40, 10) ),
                panelForPersonalDetails = new JPanel(new GridLayout(4,1,40,10)),
                superPanel = new JPanel(new GridLayout(2,1,5,5));

        PanelType1  subject[] = new PanelType1[StudentModel.subjects()],
                    cgpa = new PanelType1("CGPA : ", 5);

        this.initialisePersonalDetails(panelForPersonalDetails, student);

        panelForPersonalDetails.setBorder( new TitledBorder( new EtchedBorder(EtchedBorder.RAISED), "Student Details" ) );
        panelForMarks.setBorder( new TitledBorder( new EtchedBorder(EtchedBorder.RAISED), "Marks" ) );

        for(int i = 0; i < StudentModel.subjects(); i++) {
            subject[i] = new PanelType1("Subject #30" + (i + 1), 3);
            subject[i].setLayout( new FlowLayout(FlowLayout.CENTER) );
            subject[i].textField.setText(String.valueOf(student.getMarks(i)));
            subject[i].textField.setEditable(false);

            //subject[i].setBorder(new LineBorder(Color.black, 1));

            panelForMarks.add(new JLabel(" "));
            panelForMarks.add(subject[i]);
            panelForMarks.add(new JLabel(" "));
        }

        cgpa.textField.setText(String.valueOf(student.getGrade()));
        cgpa.textField.setEditable(false);

        panelForMarks.add(cgpa);
        panelForMarks.add(new JLabel(" "));
        panelForMarks.add(new JLabel(" "));

        JFrame markSheetFrame = new JFrame("MARK SHEET");

        superPanel.add(panelForPersonalDetails);
        superPanel.add(panelForMarks);
        superPanel.setBorder(new EmptyBorder(15,20,20,20));

        markSheetFrame.add(superPanel);

        markSheetFrame.pack();
        markSheetFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        markSheetFrame.setVisible(true);

    }

    public void displayNumberOfStudents(JFrame mainFrame){
        JOptionPane.showMessageDialog(mainFrame, "Number of Students Admitted : " + StudentModel.getNumberOfStudents(), "INFORMATION", JOptionPane.INFORMATION_MESSAGE);
    }

}

class PanelType1 extends JPanel{
    JTextField textField;
    private JLabel label;

    /*
    PanelType1(){
        super(new FlowLayout(FlowLayout.LEFT));
        textField = new JTextField(10);
        label = new JLabel("default");
        add(label);
        add(textField);
    }
    */

    PanelType1(String labelName, int fieldWidth ){
        super(new FlowLayout(FlowLayout.LEFT));
        textField = new JTextField(fieldWidth);
        label = new JLabel(labelName);
        add(label);
        add(textField);
    }

}
