//#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include "lib_mem_class.hpp"
#include "lib_art_class.hpp"

void print_options(void);
void admin_action( char *, int&, int&, int&, int& );
std::string  make_rec( Student_Library &, int& );
std::string  make_rec( Faculty_Library &, int& );
std::string  make_rec( Book_Library &, int& );
std::string  make_rec( Journal_Library &, int& );

Student_Library  make_obj_s (int , char*, int );
Faculty_Library  make_obj_f (int , char*, int );
Book_Library     make_obj_b (int , char*, int );
Journal_Library  make_obj_j (int , char*, int );

void  update_file_s ( Student_Library &, int, int );
void  update_file_f ( Faculty_Library &, int, int  );
void  update_file_b ( Book_Library &, int, int );
void  update_file_j ( Journal_Library &, int, int );

void log_tx(char *, char * , int , int , bool );

int main(void){
    
    int size_of_student_rec = 0;
    int size_of_faculty_rec = 0;
    int size_of_book_rec = 0;
    int size_of_journal_rec = 0;
    {    std::ifstream f;
        f.open("Student Details", std::ios::binary);
        if(f){
            int lines_per_rec = 5;
            std::string tmp;
            f.seekg(0, std::ios::beg);
            for(int i = 0; i < lines_per_rec ; i ++)
                std::getline(f, tmp);
            size_of_student_rec = f.tellg();
            f.seekg(0, std::ios::end);
            Student_Library::set_tot_students( f.tellg()/size_of_student_rec );
        }
        f.close();
    
        f.open("Faculty Details", std::ios::binary);
        if(f){
            int lines_per_rec = 23;
            std::string tmp;
            f.seekg(0, std::ios::beg);
            for(int i = 0; i < lines_per_rec ; i ++)
                std::getline(f, tmp);
            size_of_faculty_rec = f.tellg();
            f.seekg(0, std::ios::end);
            Faculty_Library::set_tot_faculty( f.tellg()/size_of_faculty_rec );
        }
        f.close();
    
        f.open("Book Details", std::ios::binary);
        if(f){
            int lines_per_rec = 2;
            std::string tmp;
            f.seekg(0, std::ios::beg);
            for(int i = 0; i < lines_per_rec ; i ++)
                std::getline(f, tmp);
            size_of_book_rec = f.tellg();
            f.seekg(0, std::ios::end);
            Book_Library::set_tot_books( f.tellg()/ size_of_book_rec );
        }
        f.close();
    
        f.open("Journal Details", std::ios::binary);
        if(f){
            int lines_per_rec = 2;
            std::string tmp;
            f.seekg(0, std::ios::beg);
            for(int i = 0; i < lines_per_rec ; i ++)
                std::getline(f, tmp);
            size_of_journal_rec = f.tellg();
            f.seekg(0, std::ios::end);
            Journal_Library::set_tot_journals( f.tellg()/size_of_journal_rec );
        }
        f.close();
    }
    
    // End of calculating size of records.
    
    int switchCase;
    bool flag = true;
    char password[10] = "abc";
    print_options();
    
    while(flag){
        
        std::cout << size_of_student_rec << " "<< size_of_faculty_rec << " " << size_of_book_rec << " " << size_of_journal_rec;
        
        printf("\nChoose from the given options :\t");
        std::cin >> switchCase;
        switch(switchCase){
            case 0:
                flag = false;
                break;
                
            case 1:
                
                admin_action(password, size_of_student_rec, size_of_faculty_rec, size_of_book_rec, size_of_journal_rec);
                std::cout << "\n";
                print_options();
                break;
                
            case 2:
            {
                Student_Library student;
                char x[26], id_entered[26];
                std::cout << "Enter uid of student:\t";
                std::cin >> id_entered;
                strcpy ( x, id_entered + 3 );
                int i_id_s = atoi(x), i_id_b;
                if( i_id_s > Student_Library::ret_tot_students() ){
                    std::cout << "Incorrect Id Entered. Try Again! \n";
                    break;
                }
                student = make_obj_s(i_id_s, id_entered ,size_of_student_rec);
                int choice;
                std::cout << "Enter 1 to issue book to student, 2 to return book to library from student.";
                std::cin >> choice;
                
                char book_id[30];
                int card_no;
                
                std::cout << "Enter the book id : ";
                std::cin >> book_id;
                strcpy ( x, book_id + 2 );
                i_id_b = atoi(x);
                if( i_id_b > Book_Library::ret_tot_books() ){
                    std::cout << "Incorrect Id Entered. Try Again! \n";
                    break;
                }
                
                std::cout << "Enter the card number you want to use : ";
                std::cin >> card_no;
                
                Book_Library book_concerned = make_obj_b(i_id_b, book_id ,size_of_book_rec);
    std::cout << "s id passed : " << i_id_s << " bid : " << i_id_b << "\n";
                if(choice == 1){
                    if(! book_concerned.get_qty_in_stock() ){
                        std::cout << "Book desired is   -  Out of Stock  -  . Try Again Later. \n";
                        break;
                    }
                    
                    if(student.issue_book(book_id, card_no) ){
                        book_concerned.set_qty_in_stock( book_concerned.get_qty_in_stock() - 1 );
                        std::cout << "\n\t BOOK ISSUE TO STUDENT : SUCCESSFUL!\n\n";
                        
                    std::cout << "s id passed : " << i_id_s << " bid : " << i_id_b << "\n";
                        
                        update_file_s(student, size_of_student_rec, i_id_s);
                        update_file_b(book_concerned, size_of_book_rec, i_id_b);
                        log_tx(book_id, id_entered, 1, 1, true);
                        
                    }
                    else{
                        std::cout << "\n\t BOOK ISSUE TO STUDENT : UNSUCCESSFUL!\n\n";
                    }
                }
                else if(choice == 2){
                    if(student.return_book(book_id, card_no) ){
                        book_concerned.set_qty_in_stock( book_concerned.get_qty_in_stock() + 1 );
                        std::cout << "\n\t BOOK RETURN BY STUDENT : SUCCESSFUL!\n\n";
                        
                        update_file_s(student, size_of_student_rec, i_id_s);
                        update_file_b(book_concerned, size_of_book_rec, i_id_b);
                        log_tx(book_id, id_entered, 1, 1, false);
                        
                    }
                    else{
                        std::cout << "\n\t BOOK RETURN BY STUDENT : UNSUCCESSFUL!\n\n";
                    }

                }
                else{
                    std::cout << "Incorrect input. Try Again! \n";
                }
            }
                break;
                
            case 3:
            {
                Faculty_Library faculty;
                char x[26], id_entered[26];
                std::cout << "Enter uid of faculty:\t";
                std::cin >> id_entered;
                strcpy ( x, id_entered + 3 );
                int i_id_f = atoi(x), i_id_bj;
    std::cout << "ID = " << i_id_f << "\n";
                if( i_id_f > Faculty_Library::ret_tot_faculty() ){
                    std::cout << "Incorrect Id Entered. Try Again! \n";
                    break;
                }
    std::cout << "ID in string = " << id_entered << "\n";
                faculty = make_obj_f(i_id_f, id_entered ,size_of_faculty_rec);
                int choice, c2;
                std::cout << "Enter 1 to issue/return book to/from faculty, 2 to issue/return journal to/from faculty: \t";
                std::cin >> choice;
                
                if(choice == 1){
                    
                    std::cout << "\nEnter 3 to issue book to faculty, 4 to return book to faculty: \t";
                    std::cin >> c2;
                    char book_id[30];
                    int card_no;
                    
                    std::cout << "Enter the book id : ";
                    std::cin >> book_id;
                    strcpy ( x, book_id + 2 );
                    i_id_bj = atoi(x);
                    if( i_id_bj > Book_Library::ret_tot_books() ){
                        std::cout << "Incorrect Id Entered. Try Again! \n";
                        break;
                    }
                    std::cout << "Enter the card number you want to use : ";
                    std::cin >> card_no;
                    
                    Book_Library book_concerned = make_obj_b(i_id_bj, book_id ,size_of_book_rec);
  std::cout << "s id passed : " << i_id_f << " bid : " << i_id_bj << "\n";
                    if(c2 == 3){
                        if(! book_concerned.get_qty_in_stock() ){
                            std::cout << "Book desired is   -  Out of Stock  -  . Try Again Later. \n";
                            break;
                        }
                        
                        if(faculty.issue_book(book_id, card_no) ){
    std::cout << "s id passed : " << i_id_f << " bid : " << i_id_bj << "\n";
                            book_concerned.set_qty_in_stock( book_concerned.get_qty_in_stock() - 1 );
                            std::cout << "\n\t BOOK ISSUE TO FACULTY : SUCCESSFUL!\n\n";
                            update_file_f(faculty, size_of_faculty_rec, i_id_f);
                            update_file_b(book_concerned, size_of_book_rec, i_id_bj);
                            log_tx(book_id, id_entered, 2, 1, true);
                            
                        }
                        else{
                            std::cout << "\n\t BOOK ISSUE TO FACULTY : UNSUCCESSFUL!\n\n";
                        }
                    }
                    else if(c2 == 4){
                        if(faculty.return_book(book_id, card_no) ){
                            book_concerned.set_qty_in_stock( book_concerned.get_qty_in_stock() + 1 );
                            std::cout << "\n\t BOOK RETURN BY FACULTY : SUCCESSFUL!\n\n";
                            
                            update_file_f(faculty, size_of_faculty_rec, i_id_f);
                            update_file_b(book_concerned, size_of_book_rec, i_id_bj);
                            log_tx(book_id, id_entered, 2, 1, false);
                            
                        }
                        else{
                            std::cout << "\n\t BOOK RETURN BY FACULTY : UNSUCCESSFUL!\n\n";
                        }
                        
                    }
                    else{
                        std::cout << "Incorrect input. Try Again! \n";
                    }
                    
                }
                else if(choice == 2){

                    std::cout << "\nEnter 3 to issue journal to faculty, 4 to return journal to faculty: \t";
                    std::cin >> c2;
                    char j_id[30];
                    int card_no_j;
                    
                    std::cout << "Enter the journal id : ";
                    std::cin >> j_id;
                    strcpy ( x, j_id + 2 );
                    i_id_bj = atoi(x);
                    if( i_id_bj > Journal_Library::ret_tot_journals() ){
                        std::cout << "Incorrect Id Entered. Try Again! \n";
                        break;
                    }
                    std::cout << "Enter the card number you want to use : ";
                    std::cin >> card_no_j;
                    
                    Journal_Library j_concerned = make_obj_j(i_id_bj, j_id , size_of_journal_rec);
                    
                    if(c2 == 3){
                        if(! j_concerned.get_qty_in_stock() ){
                            std::cout << "Journal desired is   -  Out of Stock  -  . Try Again Later. \n";
                            break;
                        }
                        
                        if(faculty.issue_journal(j_id, card_no_j) ){
                            j_concerned.set_qty_in_stock( j_concerned.get_qty_in_stock() - 1 );
                            std::cout << "\n\t JOURNAL ISSUE TO FACULTY : SUCCESSFUL!\n\n";
       std::cout << "s id passed : " << i_id_f << " bid : " << i_id_bj << "\n";                      
                            update_file_f(faculty, size_of_faculty_rec, i_id_f);
                            update_file_j(j_concerned, size_of_journal_rec, i_id_bj);
                            log_tx(j_id, id_entered, 2, 2, true);
                            
                        }
                        else{
                            std::cout << "\n\t JOURNAL ISSUE TO FACULTY : UNSUCCESSFUL!\n\n";
                        }
                    }
                    else if(c2 == 4){
                        if(faculty.return_journal(j_id, card_no_j) ){
                            j_concerned.set_qty_in_stock( j_concerned.get_qty_in_stock() + 1 );
                            std::cout << "\n\t JOURNAL RETURN BY FACULTY : SUCCESSFUL!\n\n";
                            
                            update_file_f(faculty, size_of_faculty_rec, i_id_f);
                            update_file_j(j_concerned, size_of_journal_rec, i_id_bj);
                            log_tx(j_id, id_entered, 2, 2, false);
                            
                        }
                        else{
                            std::cout << "\n\t JOURNAL RETURN BY FACULTY : UNSUCCESSFUL!\n\n";
                        }
                        
                    }
                    else{
                        std::cout << "Incorrect input. Try Again! \n";
                    }

                }
                else{
                    std::cout << "Incorrect input. Try Again! \n";
                }
                
            }
                break;
                
            case 9:
                print_options();
                break;
                
            default:
                printf("Invalid value entered. Bye!\n");
                flag = false;
                break;
        }
    }

    
    
}

/*
 art_id will tell id of book/journal.
 mem_id - uid of studfent/faculty
 mem_t - type: 1 for student, 2 for faculty.
 art_t - type : 1 for book, 2 for journal.
 in_out : bool - true if book is issued(out) false for return(in)
 
 Storing in Log File.txt.
 */
void log_tx(char *art_id, char * mem_id, int mem_t, int art_t, bool in_out){
    std::stringstream str;
    std::fstream log_file ("Log File.txt", std::ios::out | std::ios::binary | std::ios::ate );
    
    time_t right_now;
    struct tm *t_i;
    
    time(&right_now);
    t_i = localtime(&right_now);
    
    char temp[25];
    
    strftime( temp, 25, "%d-%m-%Y %X", t_i );
    
    str << temp << ";\t";
    
    if (mem_t == 1) {
        str << "Student " << mem_id << "; Book "  << art_id << "; ";
        if(in_out)
            str << "Issued ( OUT )\n";
        else
            str << "Returned ( OUT )\n";
    }
    else{
        str << "Faculty " << mem_id << "; ";
        if(art_t == 1)
            str << "Book "  << art_id << "; ";
        else
            str << "Journal "  << art_id << "; ";
        if(in_out)
            str << "Issued ( OUT )\n";
        else
            str << "Returned ( OUT )\n";
    }
    str << "\n";
    std::string s1;
    s1 = str.str();
    log_file << s1;
//    log_file.write(str, sizeof(str));
    log_file.close();
    
}

// All the different functions which an admin can do.
void admin_action( char * password, int& size_of_student_rec, int& size_of_faculty_rec, int& size_of_book_rec, int& size_of_journal_rec ){
    char temp[10];
    std::cout << "Enter Password to continue:\t";
    std::cin >> temp;
    if(strcmp(password, temp) ){
        std::cout << "Incorrect Password Try Again\n";
        return;
    }
    int switchCase;
    std::cout << "\t1 : Add new student details.\n";
    std::cout << "\t2 : Add new faculty details.\n";
    std::cout << "\t3 : Add new book details.\n";
    std::cout << "\t4 : Add new journal details.\n";
    std::cout << "\t5 : Change Password.\n";
    std::cin >> switchCase;
    switch(switchCase){
        case 1:
        {
            Student_Library temp_s;
            std::fstream f_student("Student Details",std::ios::app | std::ios::binary );    // std::ios::ate | 
            char *input_buf;
            int i;
            input_buf = new char[31];
            while(true){
                std::cout << "Enter Name :\t";
                std::cin.ignore(2, '\n');
                std::cin.getline(input_buf, 31);
                std::cout << "\n\tName entered by you is : " << input_buf << "\n";
                std::cout << "\tEnter 1 to confirm, 0 to enter again.\t";
                std::cin >> i;
                if(i == 1)
                    break;
            }
            temp_s.set_name(input_buf);
            temp_s.set_uid();
            
            std::string rec = make_rec(temp_s, size_of_student_rec);
            //f_student << rec;
            f_student.write( rec.c_str() , size_of_student_rec );
            
            f_student.close();
        }
            break;
        
        case 2:
        {
            Faculty_Library temp_f;
            std::fstream f_faculty("Faculty Details",  std::ios::app | std::ios::binary );  //std::ios::ate |
            char *input_buf;
            int i;
            input_buf = new char[31];
            while(true){
                std::cout << "Enter Name :\t";
                std::cin.ignore(2, '\n');
                std::cin.getline(input_buf, 31);
                std::cout << "\n\tName entered by you is : " << input_buf << "\n";
                std::cout << "\tEnter 1 to confirm, 0 to enter again.\t";
                std::cin >> i;
                if(i == 1)
                    break;
            }
            temp_f.set_name(input_buf);
            temp_f.set_uid();
            
            std::string rec = make_rec(temp_f, size_of_faculty_rec);
            //f_faculty << rec;
            f_faculty.write( rec.c_str() , size_of_faculty_rec );
            
            f_faculty.close();
        }
            break;
            
        case 3:
        {
            Book_Library temp_b;
            std::fstream f_book("Book Details", std::ios::app | std::ios::binary ); //std::ios::ate |
            char *input_buf;
            int i;
            input_buf = new char[31];
            while(true){
                std::cout << "Enter Book Name :\t";
                std::cin.ignore(2, '\n');
                std::cin.getline(input_buf, 31);
                std::cout << "\n\tBook Name entered by you is : " << input_buf << "\n";
                std::cout << "\tEnter 1 to confirm, 0 to enter again.\t";
                std::cin >> i;
                if(i == 1)
                    break;
            }
            temp_b.set_name(input_buf);
            while(true){
                std::cout << "\nEnter Total qty of " << temp_b.get_name() << " purchased :\t";
                std::cin >> i;
                if( temp_b.set_total_qty(i) )
                    break;
            }
            while(true){
                std::cout << "\nEnter qty of " << temp_b.get_name() << " in stock :\t";
                std::cin >> i;
                if( temp_b.set_qty_in_stock(i) )
                    break;
            }
            
            temp_b.set_uid();
            
            std::string rec = make_rec(temp_b, size_of_book_rec);
            std::cout << rec;
            f_book << rec;
            //f_book.write( rec , size_of_book_rec );
            
            f_book.close();
        }
            break;
            
        case 4:
        {
            Journal_Library temp_j;
            std::fstream f_journal("Journal Details",  std::ios::app | std::ios::binary );  //std::ios::ate |
            char *input_buf;
            int i;
            input_buf = new char[31];
            while(true){
                std::cout << "Enter Journal Name :\t";
                std::cin.ignore(2, '\n');
                std::cin.getline(input_buf, 31);
                std::cout << "\n\tJournal Name entered by you is : " << input_buf << "\n";
                std::cout << "\tEnter 1 to confirm, 0 to enter again.\t";
                std::cin >> i;
                if(i == 1)
                    break;
            }
            temp_j.set_name(input_buf);
            
            while(true){
                std::cout << "\nEnter the date of publish of " << temp_j.get_name() << " :\t";
                std::cin >> i;
                if( temp_j.set_date_of_publish(i) )
                    break;
            }
            while(true){
                std::cout << "\nEnter the volume of " << temp_j.get_name() << " :\t";
                std::cin >> i;
                if( temp_j.set_volume(i) >= 0)
                    break;
            }
            
            while(true){
                std::cout << "\nEnter Total qty of " << temp_j.get_name() << " purchased :\t";
                std::cin >> i;
                if( temp_j.set_total_qty(i) )
                    break;
            }
            while(true){
                std::cout << "\nEnter qty of " << temp_j.get_name() << " in stock :\t";
                std::cin >> i;
                if( temp_j.set_qty_in_stock(i) )
                    break;
            }
            
            temp_j.set_uid();
            
            std::string rec = make_rec(temp_j, size_of_journal_rec);
            f_journal << rec;
            //f_journal.write( rec , size_of_journal_rec );
            
            f_journal.close();
        }
            break;
            
        case 5 :
        {
            char temp[10], temp1[10];
            std::cout << "Enter New Password:\t";
            std::cin >> temp;
            std::cout << "Enter Password Again:\t";
            std::cin >> temp1;
            if( !strcmp(temp, temp1) )
               strcpy(password, temp);
            else
               std::cout << "Passwords Do Not Match. Try Again!\n";
            
        }
            break;
            
        default:
            std:: cout << "No values match! Try Again\n";
    }
           
}

/*
 Make record of the updated Student object and place in file. at its position.
 */
void update_file_s (Student_Library & student, int size_of_student_rec, int i_id_s){
    
std::cout << "id_s received : "<< i_id_s << "\n";
    std::fstream fs("Student Details",  std::ios::binary | std::ios::ate); //std::ios::app |
    std::string s = make_rec (student, size_of_student_rec );
    fs.seekp((i_id_s-1) * size_of_student_rec , std::ios::beg );
    fs << s;
    fs.close();
}

/*
 Make record of the updated Book object and place in file. at its position.
 */
void update_file_b (Book_Library & book_concerned, int size_of_book_rec, int i_id_b){
std::cout << "id_b received : "<< i_id_b << "\n";
    std::fstream fb("Book Details",  std::ios::binary | std::ios::ate); //std::ios::app |
    std::string b = make_rec (book_concerned, size_of_book_rec  );
    fb.seekp( (i_id_b - 1 ) * size_of_book_rec , std::ios::beg );
    fb << b;
    fb.close();
}

/*
 Make record of the updated Faculty object and place in file. at its position.
 */
void update_file_f (Faculty_Library & faculty, int size_of_faculty_rec, int i_id_f){
std::cout << "id_F received : "<< i_id_f << "\n";
    std::fstream ff("Faculty Details", std::ios::binary | std::ios::ate);   // std::ios::app |
    std::string f = make_rec ( faculty , size_of_faculty_rec  );
    ff.seekp( (i_id_f - 1 ) * size_of_faculty_rec , std::ios::beg );
    ff << f;
    ff.close();
}

/*
 Make record of the updated Journal object and place in file. at its position.
 */
void update_file_j (Journal_Library & j_concerned, int size_of_journal_rec, int i_id_j){
    std::fstream fj("Journal Details",  std::ios::binary | std::ios::ate);  //std::ios::app |
    std::string j = make_rec (j_concerned, size_of_journal_rec  );
    fj.seekp( (i_id_j - 1 ) * size_of_journal_rec , std::ios::beg );
    fj << j;
    fj.close();
}



/*
 Make student record on reading from file.
 return student object.
 */

Student_Library  make_obj_s (int id, char* s_id, int size){
    int k = id;
    
    std::ifstream f_s("Student Details", std::ios::binary | std::ios::in);
    f_s.seekg( (k-1)*size, std::ios::beg );
    
    std::stringstream ss;
    std::string st1, line;

    char tmp[35];
    
    Student_Library student;
    
    std::getline(f_s, line);
    ss << line;
    ss >> st1;
    ss >> st1;
    ss >> st1;
    strcpy( tmp , st1.c_str() );
    
    ss.clear();
    ss.str("");
    
//    std::cout << "s_id = " << s_id <<"\n";
    
    if( strcmp(tmp, s_id)){
        std::cout << "No such member registered.";
    }
    else{
        student.set_uid(s_id);
        std::getline(f_s, line);
        ss << line;
        ss >> st1;
        ss >> st1;
        st1 = "";
        ss >> st1;
        while(!ss.eof()){
            line = "";
            ss >> line;
                                                            //std::cout << "\t\t- " << line << " "<< ss.eof() << "\n";
            st1 += " ";
            st1 += line;
        }
        st1.erase(st1.end()-1);
        
        strcpy( tmp , st1.c_str() );
        student.set_name(tmp);
        
        for (int i = 0; i < 2; i++) {
            
            ss.str("");
            ss.clear();
            
            std::getline(f_s, line);
            ss << line;
            ss >> st1;
            ss >> st1;
            ss >> st1;
            if( st1 == "false"){
                student.set_issued(i, false);
                getline(ss, st1);
                st1 = "";
            }
            else{
                student.set_issued(i, true);
                ss >> st1;
                student.set_book_uid(i, st1);
                ss >> st1;
                student.set_issue_date(i, st1);
                ss >> st1;
                student.set_return_date(i, st1);
                ss >> st1;
                student.set_r_date_in_time_t(i, st1);
            }
 //   std::cout << "\nasd " << i  << " " << student.ret_issued(i) << " " << student.ret_issue_book_uid(i) << " " << student.ret_issue_date(i) << " " << student.ret_return_date(i) << " " << student.ret_r_date_in_time_t(i) << "\n"  ;
        }
    }
    f_s.close();
    return student;
}

/*
 Make book record on reading from file.
 return book object.
 */

Book_Library  make_obj_b (int id, char* s_id, int size){
    int k = id;

    std::ifstream f_b("Book Details", std::ios::binary | std::ios::in);
    f_b.seekg( (k-1)*size, std::ios::beg );
    
    std::stringstream ss;
    std::string st1, line;
    char tmp1[35];
    unsigned int t_i;
    Book_Library book;
    
    std::getline(f_b, line);
    ss << line;
    ss >> st1;
std::cout << "ss = " << ss.str() << "\n";
    strcpy( tmp1 , st1.c_str() );
    
    std::cout << "s_id = " << s_id <<"\n";
    std::cout << "tmp1 = " << tmp1 <<"\n";
    if( strcmp(tmp1, s_id)){
        std:: cout << "No such book in inventory.";
    }
    else{
        book.Article_Library::set_uid(tmp1);
        std::cout << "ID B = " <<book.get_uid() << "\n" ;
        ss >> t_i;
        std::cout << "T_I = " << t_i << "\n";
        book.set_qty_in_stock(t_i);
        std::cout << "T_I = " << t_i << "\n";
        ss >> t_i;
        book.set_total_qty(t_i);
        
        std::getline(ss, st1);
        strcpy( tmp1 , st1.c_str() );
        book.set_name(tmp1);
        
    }
    std::cout << "\nasd " << " " << book.get_uid() << " " << book.get_name()  << " " << book.get_qty_in_stock()  << " "  << book.get_total_qty() << "\n";
    
    f_b.close();
    return book;
}

/*
 Make journal record on reading from file.
 return journal object.
 */

Journal_Library  make_obj_j (int id, char* s_id, int size){
    int k = id;
    std::ifstream f_j("Journal Details", std::ios::binary | std::ios::in);
    f_j.seekg( (k-1)*size, std::ios::beg );
    std::stringstream ss;
    std::string st1;
    char tmp[35];
    unsigned int t_i;
    Journal_Library journal;
    ss << f_j;
    ss >> st1;
    strcpy( tmp , st1.c_str() );
    
    if( strcmp(tmp, s_id)){
        std:: cout << "No such member registered.";
    }
    else{
        journal.Article_Library::set_uid(tmp);
        ss << f_j;
        ss >> t_i;
        journal.set_date_of_publish(t_i);
        ss << f_j;
        ss >> t_i;
        journal.set_volume(t_i);
        ss << f_j;
        ss >> t_i;
        journal.set_qty_in_stock(t_i);
        ss << f_j;
        ss >> t_i;
        journal.set_total_qty(t_i);
        ss.str("");
        std::getline(ss, st1);
        strcpy( tmp , st1.c_str() );
        journal.set_name(tmp);
    }
    f_j.close();
    return journal;
    
}


/*
 Make journal record on reading from file.
 return journal object.
 */

Faculty_Library  make_obj_f (int id, char* s_id, int size){
    
    char id_in_s[26];
    strcpy(id_in_s, s_id);
    
    int k = id;
    std::fstream f_f("Faculty Details", std::ios::binary | std::ios::in );
    f_f.seekg( (k-1)*size, std::ios::beg );
    
    std::string line;
    
    std::getline(f_f, line);
    
    std::stringstream ss;
    std::string st1;
    
    char tmp[35];
    unsigned int t_i;
    
    Faculty_Library faculty;
    
    ss << line;
    ss >> st1;
    ss >> st1;
    ss >> st1;
    strcpy( tmp , st1.c_str() );
    
    ss.clear();
    ss.str("");
    
    if( strcmp(tmp, id_in_s)){
        std:: cout << "No such member registered.\n";
    }
    else{
        faculty.set_uid(tmp);
                                                                    //std::cout << "\t- " << ss.str() <<"\n";
        std::getline(f_f, line);
                                                                    //std::cout << "line = " << line << "\n";
        ss << line;
        ss >> st1;
        ss >> st1;
        st1 = "";
        ss >> st1;
                                                                //std::cout << "\t- " << st1 << "\n";
        while(!ss.eof()){
            line = "";
            ss >> line;
                                                //std::cout << "\t\t- " << line << " "<< ss.eof() << "\n";
            st1 += " ";
            st1 += line;
        }
        st1.erase(st1.end()-1);
                                                //std::cout << "\t- " << st1 << ".\n";
                                                //std::cout << "tellg = " << f_f.tellg() << "\n";
        strcpy( tmp , st1.c_str() );
        faculty.set_name(tmp);
        
        for (int i = 0; i < 10; i++) {
            
            ss.str("");
            ss.clear();
            
            std::getline(f_f, line);
            ss << line;
            ss >> st1;
            ss >> st1;
            ss >> st1;
            if( st1 == "false"){
                faculty.set_issued(i, false);
                getline(ss, st1);
                st1 = "";
            }
            else{
                faculty.set_issued(i, true);
                ss >> st1;
                faculty.set_book_uid(i, st1);
                ss >> st1;
                faculty.set_issue_date(i, st1);
                ss >> st1;
                faculty.set_return_date(i, st1);
                ss >> st1;
                faculty.set_r_date_in_time_t(i, st1);
            }
//            std::cout << "\nasd " << i  << " " << faculty.ret_issued(i) << " " << faculty.ret_issue_book_uid(i) << " " << faculty.ret_issue_date(i) << " " << faculty.ret_return_date(i) << " " << faculty.ret_r_date_in_time_t(i) << "\n"  ;
        }
        
        for (int i = 0; i < 10; i++) {
            
            ss.str("");
            ss.clear();

            std::getline(f_f, line);
            ss << line;
            ss >> st1;
            ss >> st1;
            ss >> st1;
            if( st1 == "false"){
                faculty.set_issued_journal(i, false);
                getline(ss, st1);
                st1 = "";
            }
            else{
                faculty.set_issued_journal(i, true);
                ss >> st1;
                faculty.set_journal_uid(i, st1);
                ss >> st1;
                faculty.set_issue_date_journal(i, st1);
                ss >> st1;
                faculty.set_return_date_journal(i, st1);
            }
 //           std::cout << "\njjjasd " << i  << " " << faculty.ret_issued_journal(i) << " " << faculty.ret_issue_journal_uid(i) << " " << faculty.ret_issue_date_journal(i) << " " << faculty.ret_return_date_journal(i) << "\n";
        }
        
    }
 //   std::cout << "tellg = " << f_f.tellg() << "\n";
    f_f.close();
    return faculty;
}


/*
 Reference of string object created passed. Size of book record also passed.
 Object in the format :
 "Book_UID qty_in_stock total_qty Name
 
 "
 */
std::string make_rec( Book_Library & book , int& size ){
    std::stringstream s;
    s << std::setw(15) << std::left << book.get_uid() << " ";
    s << std::setw(10) << std::left << book.get_qty_in_stock() << " ";
    s << std::setw(10) << std::left << book.get_total_qty() << " ";
    s << std::setw(31) << std::left << book.get_name() << "\n\n";
    
    s.clear();
    if(s.tellp() != size && s.tellp() > 0)
        size = s.tellp();
    std::string s1;
    s1 = s.str();
    return s1;
}


/*
 Reference of string object created passed. Size of journal record also passed.
 Object in the format :
 "Journal_UID date_of_publish vol._no. qty_in_stock total_qty Name
 
 "
 */
std::string make_rec( Journal_Library & journal , int& size ){
    std::stringstream s;
    s << std::setw(15) << std::left << journal.get_uid() << " ";
    s << std::setw(10) << std::left << journal.get_date_of_publish() << " ";
    s << std::setw(4) << std::left << journal.get_volume() << " ";
    s << std::setw(10) << std::left << journal.get_qty_in_stock() << " ";
    s << std::setw(10) << std::left << journal.get_total_qty() << " ";
    s << std::setw(31) << std::left << journal.get_name() << "\n\n";
    
    s.clear();
    if(s.tellp() != size && s.tellp() > 0)
        size = s.tellp();
    std::string s1;
    s1 = s.str();
    return s1;
}


/*
 Reference of string object created passed. Size of student record also passed.
 Object in the format :
 "S_UID :
 Name :
    Card 0 bool book_uid issue_date ret_date ret_date_in_time_t
    Card 1 bool book_uid issue_date ret_date ret_date_in_time_t
 
 "
 */
std::string make_rec( Student_Library & student, int& size ){
    std::stringstream s;
    s << "S_UID : " << student.get_uid() << "\n";
    s << "Name : " << std::left << std::setw(31) << student.get_name() << "\n";
    s.clear();
    for(int i = 0; i < 2; i++){
        s << "\tCard " << std::setw(2) << i << " " << std::boolalpha << student.ret_issued(i) << " " ;
        s << std::left << std::setw(20) << student.ret_issue_book_uid(i) << " " ;
        s << std::left << std::setw(8) << student.ret_issue_date(i) << " " ;
        s << std::left << std::setw(8) << student.ret_return_date(i) << " " ;
        s.clear();
        s << student.ret_r_date_in_time_t(i) << "\n" ;
        
    }
    s << "\n";
    if(s.tellp() != size && s.tellp() > 0)
        size = s.tellp();
    std::string s1;
    s1 = s.str();
    return s1;
}


/*
 Reference of string object created passed. Size of faculty record also passed.
 Object in the format :
 "F_UID :
 Name :
    Card 0 bool book_uid issue_date ret_date ret_date_in_time_t
        .
    Card 9 bool book_uid issue_date ret_date ret_date_in_time_t
        Journal_Card 0 bool j_uid issue_date ret_date
            .
        Journal_Card 9 bool j_uid issue_date ret_date
 
"
 */
std::string make_rec( Faculty_Library & faculty, int& size ){
    std::stringstream s;
    s << "F_UID : " << faculty.get_uid() << "\n";
    s << "Name : " << std::left << std::setw(31) << faculty.get_name() << "\n";
    s.clear();
    for(int i = 0; i < 10; i++){
        s << "\tCard " << std::setw(2) << i << " " << std::boolalpha << faculty.ret_issued(i) << " " ;
        s << std::setw(20) << std::left << faculty.ret_issue_book_uid(i) << " " ;
        s << std::setw(8) << std::left << faculty.ret_issue_date(i) << " " ;
        s << std::setw(8) << std::left << faculty.ret_return_date(i) << " " ;
        s.clear();
        s << faculty.ret_r_date_in_time_t(i) << "\n" ;
        
    }
    
    for(int i = 0; i < 10; i++){
        s << "\t\tJournal_Card "  << std::setw(2) << i << "  " << std::boolalpha << faculty.ret_issued_journal(i) << " " ;
        s << std::setw(20)  << std::left << faculty.ret_issue_journal_uid(i) << " " ;
        s << std::setw(8) << std::left << faculty.ret_issue_date_journal(i) << " " ;
        s << std::setw(8) << std::left << faculty.ret_return_date_journal(i) << "\n" ;
        s.clear();
    }
    
    s << "\n";
    if(s.tellp() != size && s.tellp() > 0)
        size = s.tellp();
    std::string s1;
    s1 = s.str();
    return s1;
}


void print_options(void){
    std::cout << "________________________________________________________________________\n" ;
    std::cout << "                              MENU\n" ;
    std::cout << "________________________________________________________________________\n\n" ;
    std::cout << "\t[0] : Exit\n\n" ;
    std::cout << "\t[1] : Administrative Access (password required)\n\n" ;
    std::cout << "\t[2] : Student Related Tx.\n\n" ;
    std::cout << "\t[3] : Faculty Related Tx.\n\n" ;
    std::cout << "\t[9] : Print Options Again\n\n" ;
    std::cout << "________________________________________________________________________\n" ;
}