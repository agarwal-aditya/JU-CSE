#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctime>

#define MAX_STUDENTS 99

class student{
    char roll[26];
    char name[31];
    char course[10];
    char admission_date_time[25];
    int marks[5];
    time_t time_of_admission;
    int admission_day, admission_month, admission_year;
public:
    student(){
        admission_day = admission_month = admission_year = -1;
        strcpy(roll, "");
        strcpy(name, "");
        strcpy(course, "");
        strcpy(admission_date_time, "");
        marks[0] = marks[1] = marks[2] = marks[3] = marks[4] = -1;
    }

    //Set Name of a Student.
    void set_name(void){
        int temp;
        printf("Enter Name:\t");
        std::cin.ignore(32767, '\n');
        scanf("%[^\n]", name);
        std::cin.ignore(32767, '\n');
        printf("\n\tName entered by you is : %s\n", name);
        printf("\tEnter 1 to confirm, 0 to enter again.\t");
        scanf("%d", &temp);
        if(!temp){
            set_name();
        }
    }

    //Return the ptr to array storing name of the student
    char* get_name(void){
        return (char*)name;
    }

    //Set the curse code of the student
    void set_course(void){
        int temp;
        printf("Enter 3 or 4 letter code for your course:\t");
        std::cin.ignore(32767, '\n');
        scanf("%s", course);
        printf("\n\tCourse entered by you is : %s\n", course);
        printf("\tEnter 1 to confirm, 0 to enter again.\t");
        std::cin.ignore(32767, '\n');
        scanf("%d", &temp);
        if(!temp || strlen(course) > 4 ){
            std::cout<<"\nCourse code more than 4 letters. Enter Again.\n";
            set_course();
        }
    }

    //Return the ptr to array storing course code of the student
    char* get_course(void){
        return (char*)course;
    }

    //Set the admission date and time using system time.
    void set_admission_date(void){
        time(&time_of_admission);

        struct tm * timeinfo;
        timeinfo = localtime(&time_of_admission);

        strftime ( admission_date_time, 25, "%d/%m/%Y %X",  timeinfo);
        //printf("\tTime : %s\n", admission_date_time);

        admission_day = (admission_date_time[0] - '0')*10 + (admission_date_time[1] - '0');
        admission_month =(admission_date_time[3] - '0')*10 + (admission_date_time[4] - '0');
        admission_year = (admission_date_time[6] - '0')*1000 + (admission_date_time[7] - '0')*100 + (admission_date_time[8] - '0')*10 + (admission_date_time[9] - '0');

       // printf("%2d - %2d - %4d\n", admission_day, admission_month, admission_year);
    }

    //Return the ptr to char array storing admission date and time details of the student
    char* get_admission_date(void){
        return (char*)admission_date_time;
    }

    //Generates Roll Number of Student using coder-defined algorithm. (Year of Admission/No_ofStudent_Admitted)
    //Argument: int ; telling how many students have currently enrolled.
    void generate_roll(int number_of_students){
        number_of_students++;
        char temp[5];
        strncpy(temp, admission_date_time + 6, 4);
        temp[4] = '\0';
        strcat(roll, temp );
        strcpy(temp, "/");
        strcat(roll, temp);
        strcpy(temp, "");
        temp[0] = (char)(number_of_students/10 +'0');
        temp[1] = (char)(number_of_students%10 + '0');
        temp[2] = '\0';
        strcat(roll, temp);
    }

    //Return the ptr to char array storing roll of the student
    char* return_roll(void){
        return (char*)roll;
    }
    
    // Set the marks of the student.
    void set_marks(void){
        int temp;
        printf("Enter the marks of each subject one by one.\n");
        for(int i = 0; i < 5; i++){
            printf("\tEnter marks for subject #30%d :\t", i+1);
            scanf("%d", &temp);
            while(temp <0 || temp > 100){
                printf("No negative marks or extra marks for good handwriting. Try Again!\n");
                scanf("%d", &temp);
            }
            marks[i] = temp;
        }
    }
    
    //return marks of subject at int:index of the marks array.
    int get_marks(int index){
        return marks[index];
    }
};

class batch{

private:
    student st[100];
    int number_of_students;

    //Private helper function to check if roll entered by user exists or not.
    // Returns index at which it's present or -1 if roll does not exist.
    int roll_exists(char *roll){
        int i;
        for( i = 0; i < number_of_students; i++){
                //printf("%d %s %s %d\n", i, roll, st[i].return_roll(), strcmp(roll, st[i].return_roll() ) );
            if( strcmp(roll, st[i].return_roll() ) == 0 )
                return i;
        }
        return -1;
    }

    //Private helper function to Print Marksheet of student.
    void print_marksheet(int index){
        printf("_______________________________________________________________________________________________\n");
        printf("%35sMARKSHEET\n", "" );
        printf("_______________________________________________________________________________________________\n");
        printf("Name: %s\n", st[index].get_name());
        printf("Course: %s\n", st[index].get_course());
        printf("Roll: %s\n", st[index].return_roll());
        printf("_______________________________________________________________________________________________\n");
        printf("Subject Code\t|\tMarks Obtained\t|\tFull Marks\t|\n");
        printf("_______________________________________________________________________________________________\n");
        for(int i = 0; i < 5; i++){
            printf("    30%d\t\t|\t%10d\t|\t%10d\t|\n", i+1, st[index].get_marks(i), 100);
        }
        printf("_______________________________________________________________________________________________\n\n");
    }

    //Private Helper Function to Enter Roll of student by user for a query.
    int enter_roll(void){
        char roll_t[26];
        std::cout<<"Enter the roll number:\t";
        std::cin>>roll_t;
        return roll_exists(roll_t);
    }

public:
    batch(){
        number_of_students = 0;
    }

    //Prints no. of students enrolled.
    void get_no_of_students_admitted(void){
        printf("Number of Total Students Admitted is: %d\n", number_of_students);
    }

    //this function is called when a new student is to be admitted.
    void admit_new_student(void){
        if(number_of_students == MAX_STUDENTS)
            printf("Student Capacity Reached.Error!\n");
        else{
            st[number_of_students].set_admission_date();
            st[number_of_students].set_name();
            st[number_of_students].set_course();
            st[number_of_students].generate_roll(number_of_students);
            printf("\nRoll for the student is: %s\n", st[number_of_students].return_roll() );
            number_of_students++;
        }
    }

    /*Generates marksheet of a student,
     if user entered roll does not exist then error is generated.
     if marks are entered then it is asked whether marks are to be entered again else, user is asked to enter marks first.
     */
    int generate_marksheet(void){
        int index = enter_roll();

        if( index  != -1 ){
            if(st[index].get_marks(4) == -1){
                st[index].set_marks();
            }
            else{
                std::cout<<"Marks already exist."<<"\n";
                print_marksheet(index);
                std::cout<<"Do you want to change the marks?"<<"\n"<<"Press 1 if yes, else press any other integer\n";
                int temp;
                std::cin>>temp;
                if(temp == 1)
                    st[index].set_marks();
                else
                    return 0;
            }
        }
        else{
            std::cout<<"\tRoll Doesn't Exist. Try Again."<<"\n";
            return -1;
        }

        print_marksheet(index);
        return 1;
    }

    /*
     Returns details of admission if user entered roll exists.
     */
    void get_admission_date_details(void){
        int index = enter_roll();
        if( index != -1){
            printf("Date and Time of Admission of Student having Roll : %s is\n%s\n", st[index].return_roll(), st[index].get_admission_date() );
        }
        else{
            printf("Roll Number Entered is not in database. Try Again!\n");
        }
    }

};

int main(void){
    bool flag = true;
    int switchCase;

    batch bcse18;

    printf("\nOptions available:\n");
    printf("\t0 : Exit.\n");
    printf("\t1 : Add New Student.\n");
    printf("\t2 : Generate Marksheet and/or Set Marks.\n");
    printf("\t3 : Print Number of Students Admitted.\n");
    printf("\t4 : Print Details Related to Admission Date of a Student.\n");


    while(flag){
        printf("\nChoose from the given options :\t");
        scanf("%d", &switchCase);
        switch(switchCase){
            case 0:
                flag = false;
                break;
            case 1:
                bcse18.admit_new_student();
                break;
            case 2:
                bcse18.generate_marksheet();
                break;
            case 3:
                bcse18.get_no_of_students_admitted();
                break;
            case 4:
                bcse18.get_admission_date_details();
                break;
            default:
                printf("Invalid value entered. Bye!\n");
                flag = false;
                break;

        }
    }



    return 0;
}
