#ifndef SUBJECTS
#define SUBJECTS 3
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ctime>
#endif


class student{
    char roll[26];
    char name[31];
    char admission_date_time[25];
    int marks[SUBJECTS];
    double cgpa;
    time_t time_of_admission;
    int admission_day, admission_month, admission_year;
    
    //Private function to compute cgpa. Called in set_marks(void) public function.
    void compute_cgpa(void){
    	int total = 0;
    	for(int i = 0; i < SUBJECTS; i++)
    		total += marks[i];
    	cgpa = total/10.0/SUBJECTS;
    }
    
public:
    student(){
        admission_day = admission_month = admission_year = -1;
        strcpy(roll, "");
        strcpy(name, "");
        strcpy(admission_date_time, "");
        for(int i = 0; i < SUBJECTS; i++)
        	marks[i] = -1;
        cgpa = 0;
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
        printf("There are %d subjects. Enter the marks of each subject one by one.\n", SUBJECTS);
        for(int i = 0; i < SUBJECTS; i++){
            printf("\tEnter marks for subject #30%d :\t", i+1);
            scanf("%d", &temp);
            while(temp <0 || temp > 100){
                printf("No negative marks or extra marks for good handwriting. Try Again!\n");
                scanf("%d", &temp);
            }
            marks[i] = temp;
        }
        
        compute_cgpa();
        printf("CGPA is : %.2lf\n", cgpa);
    }
    
    //return marks of subject at int:index of the marks array.
    void print_marks(void){
        printf("\t\t\t\t\t\t\t\t\tMarks :\n");
        for(int i = 0; i < SUBJECTS; i++){
            printf("\t\t\t\t\t\t\t\t\tSubject No: 30%d : %d/100\n", i+1, marks[i]);
        }
        printf("\n");
    }
    
    //Function to return the cgpa computed AFTER the marks have been entered.
    double get_cgpa(void){
    	return cgpa;
    }
    
    void set_cgpa_unscrupulously(void){
    	printf("Enter the CGPA you want for the student %s having roll: %s.\n", name, roll);
    	scanf("%lf", &cgpa);
    	while (cgpa < 0.0 || cgpa > 10.0 ){
    		printf("CGPA has to lie in between 0.0 and 10.0.\n\tEnter CGPA Again!");
    		scanf("%lf", &cgpa);	
    	}
    	int mark_individual = cgpa * 10.0;
    	for(int i = 0; i < SUBJECTS; i++){
    		marks[i] = mark_individual;	
    	}	
    }
    
};
