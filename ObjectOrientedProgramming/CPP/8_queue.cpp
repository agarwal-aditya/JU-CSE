#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ctime>
#include "header_file_for_student_class.hpp"

struct node{
	student data;
	node *next;
};

class priority_queue_batch{
	node *p_queue;
	int number_of_students;
    
    void set_marks(node *n){
        std::cout << "To enter CGPA directly and set marks accordingly, enter 1.\n";
        std::cout << "Else marks will have to be entered individually to calculate CGPA\n";
        int option;
        std::cin >> option;
        if(option == 1){
            (n->data).set_cgpa_unscrupulously();
        }
        else{
            (n->data).set_marks();
        }
    }
	
public:
	priority_queue_batch(){
		p_queue = NULL;
		number_of_students = 0;
	}
	
	~priority_queue_batch(){
        	node * t;
        	while(p_queue != NULL){
        		t = p_queue;
            		p_queue = p_queue-> next;
            		delete t;
        	}
	}
	
	//this function is called when a new student is to be admitted.
    	node* admit_new_student(void){
    		node* new_student;
    		new_student = new node;
    		
            	( new_student -> data ).set_admission_date() ;
            	( new_student -> data ).set_name() ;
        	( new_student -> data ).generate_roll(number_of_students);
            	( new_student -> next ) = NULL;
            	set_marks( new_student );
            	printf("\nRoll for the student is: %s\n", (new_student -> data).return_roll() );
            	number_of_students++;
            
            	return new_student;
    	}
    
    bool is_empty(void){
        return (number_of_students == 0);
    }
    
    int get_size(void){
        return number_of_students;
    }
    
    void enqueue(void){
        node *n, *curr, *prev;
        n = admit_new_student();
        double n_cgpa = (n ->data).get_cgpa();
        curr = p_queue;
        if( curr == NULL)
    		p_queue = n;
    		
    	else if( (curr->data).get_cgpa() < n_cgpa ){
            n -> next = p_queue;
            p_queue = n;
        }
       // std::cout << "5\n";
        
        else{
        	int flag = 1;
        	while(curr->next != NULL){
            		prev = curr;
            		curr = curr -> next;
            		if( (curr->data).get_cgpa() < n_cgpa ){
                		n -> next = curr;
                		flag = 0;
                		prev -> next = n;
                		break;
            		}
        	}
        	if(flag){
                	curr -> next = n;
                	n -> next = NULL;
        	}
        }
    }
    
    student dequeue(void){
        if(p_queue != NULL){
            student temp;
            temp = (p_queue->data);
            node *t = p_queue;
            p_queue = p_queue -> next;
            t->next = NULL;
            delete t;
            number_of_students--;
            return temp;
        }
        else{
            printf("QUEUE IS EMPTY! ERROR!\n");
            student s;
            return s;
        }
    }
    
    void print_all(void){
        int index = 0;
        node *t = p_queue;
        printf("Sl. No\t|\t\tName\t\t\t|\tRoll\t|\tCGPA\t|\n");
        printf("____________________________________________________________________________\n");
        while(t!= NULL){
            printf("%3d\t| %-31s\t|\t%s\t|\t%.2lf\t|\n", index++, (t->data).get_name(), (t->data).return_roll(), (t->data).get_cgpa() );
            (t -> data).print_marks();
            t = t -> next;
        }
    }
    
};

void print_choice(void);

int main(void){
    priority_queue_batch queue;
    int switchCase;
    bool flag = true;
    
    print_choice();
    
    while(flag){
        printf("\nChoose from the given options :\t");
        std::cin >> switchCase;
        switch(switchCase){
            case 0:
                flag = false;
                break;
            case 1:
                queue.enqueue();
                break;
            case 2:
                if(queue.is_empty())
                    std::cout << "Queue is empty.\n";
                else
                    std::cout << "Queue is not empty.\n";
                break;
            case 3:
                std::cout << "Current Size : " << queue.get_size() << "\n";
                break;
            case 4:
            {
                student s = queue.dequeue();
                if(strcmp(s.get_name(), "") ){
                    printf("\tStudent Dequeue successful.\n");
                    printf("\tStudent Name: %s\n", s.get_name());
                    printf("\tStudent Roll: %s\n", s.return_roll());
                    printf("\tStudent CGPA: %lf\n", s.get_cgpa());
                    printf("\t___X___\t___X___\t___X___\n");
                }
            }
                break;
            case 6:
                queue.print_all();
                break;
            case 9:
                print_choice();
                break;
            default:
                printf("Invalid value entered. Bye!\n");
                flag = false;
                break;
        }
    }
	return 0;
}

void print_choice(void){
    std::cout << "Enter :\n";
    std::cout << "\t0 -> Exit.\n";
    std::cout << "\t1 -> Enqueue new student.\n";
    std::cout << "\t2 -> Check if queue is empty.\n";
    std::cout << "\t3 -> Print current size of priority queue.\n";
    std::cout << "\t4 -> Dequeue the first student from the queue.\n";
    std::cout << "\t6 -> Print details of all students in the queue.\n";
    std::cout << "\t9 -> Print choice list again.\n";
    
}
