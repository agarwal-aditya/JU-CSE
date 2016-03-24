import java.io.*;
import java.text.*;
import java.util.*;

class IncorrectMarksException extends Exception {

    public IncorrectMarksException(){
        System.out.println("No negative marks or extra marks for good handriting!\nTry again.\n\n");
    }

}

class Student{
    
    private static int numberOfStudents = 0;
    
    public static int getnumberOfStudents(){
        return numberOfStudents;
    }
    
    public static boolean isRollUnique(String rollInput){
        int rollInt = Integer.parseInt(rollInput.substring(5));
        return (rollInt <= numberOfStudents);
    }
    
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
    
    public void generateMarkSheet(){
        System.out.println("-------------------------------------------------------------------------");
        System.out.println("\t\tMARKSHEET");
        System.out.println("-------------------------------------------------------------------------");
        System.out.println("Name : " + name);
        System.out.println("Course/Batch : " + course + "\t\tAdmission Date : " + admissionDate);
        System.out.println("Roll : " + roll);
        System.out.println("-------------------------------------------------------------------------");
        for (int i = 0; i < numberOfSubjects; i ++){
            System.out.println("Subject #30" + (i+1) + " :\t " + marks[i] + " / 100" );
        }
        System.out.println("\n-------------------------------------------------------------------------");
    }
    
}

class A1_Student {

    private static void display_options(){
        System.out.println("-------------------------------------------------------");
        System.out.println("\t\tOPTIONS");
        System.out.println("-------------------------------------------------------");
        System.out.println("\t<0> Exit.\n");
        System.out.println("\t<1> Admit new student.\n");
        System.out.println("\t<2> Set marks for a student.\n");
        System.out.println("\t<3> Generate marksheet.\n");
        System.out.println("\t<4> Display number of admitted students.\n");
        System.out.println("\t<5> Display the course/batch of a particular student.\n");
        System.out.println("\t<9> Reprint options menu.");
    }
    
    private static int returnRoll(Scanner scanInput){
        System.out.println("Enter Roll Number of student." );
        String rollEntered = scanInput.nextLine();
        if(Student.isRollUnique(rollEntered)){
            int roll = Integer.parseInt(rollEntered.substring(5));
            return roll;
        }
        else{
            System.out.println("Roll Number of student does not exist. Try Again!" );
            return -1;
        }
    }
    
    private static void setMarksForStudent(Student student , Scanner scanInput){
        for (int i = 0; i < Student.subjects(); i ++){
            System.out.print("Enter marks for subjects #30" + (i+1) + " \t" );
            try {
                student.setMarks(i, Integer.parseInt(scanInput.nextLine()) );
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
        Student[] st = new Student[CapacityOfSchool];
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
                    int i = Student.getnumberOfStudents();
                    st[i] = new Student();
                    System.out.print("Enter Name:\t");
                    String str = scanInput.nextLine();
                    (st[i]).setName(str);
                    
                    System.out.print("Enter Course:\t");
                    str = scanInput.nextLine();
                    st[i].setCourse(str);
                    
                    st[i].setAdmissionDate();
                    st[i].setRoll();
                
                    System.out.println("Roll Number for " + st[i].getName() + " is : " + st[i].getRoll() );
                    
                    break;
                }
                case 2:
                {
                    System.out.print("To set marks for student : ");
                    int roll = returnRoll(scanInput);
                    if(roll != -1)
                        setMarksForStudent(st[roll-1], scanInput);
                    break;
                }
                case 3:
                {
                    System.out.print("To generate marksheet for student : ");
                    int roll = returnRoll(scanInput);
                    if(roll != -1)
                        st[roll-1].generateMarkSheet();
                    break;
                }
                case 4:
                    System.out.println(Student.getnumberOfStudents() + " student(s) have taken admission.");
                    break;
                case 5:
                {
                    System.out.print("To display course/batch of a student : ");
                    int roll = returnRoll(scanInput);
                    if(roll != -1)
                        System.out.println(st[roll-1].getName() + " having roll " + st[roll-1].getRoll()+ " is admitted in " + st[roll-1].getCourse() + " course.");
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