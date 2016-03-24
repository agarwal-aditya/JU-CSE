#include "lib_class_def.hpp"

#include <ctime>

#include <sstream>

#include <iomanip>

/*
 Struct stores book id issued. date of issue and return date in ddmmyyyy format in(int).
 Also stores time of return set to 00:00:00 od return_date. To calculate late return fine.
 */
struct issue_details{
    char book_uid[26];
    int issue_date, return_date;
    time_t r_date_in_time_t;
};

// Start of Student Class Declaration.
/*
 Inherits:  name[], uid[]
 set_name(), get_name(), get_uid().
 */
class Student_Library : public Member_Library{

private:
    static unsigned int number_of_students;
    bool is_issued[2];
    issue_details card[2];
    
    double calculate_fine(time_t date_returned, time_t return_date){
        double fine_per_day = 1;
        
        double diff_seconds = difftime(date_returned, return_date);
        diff_seconds /= (24*60*60);
        int days_late = int(diff_seconds);
        
        return days_late * fine_per_day;
        
    }
    
    
public:
    //Public Constructor Default for Student. Intitates everything to 0 or "".
    Student_Library(){
        for (int i = 0; i < 2; i++) {
            is_issued[i] = false;
            strcpy(card[i].book_uid, "");
            card[i].issue_date = card[i].return_date = 0;
            card[i].r_date_in_time_t = 0;
        }
    }
    
    static unsigned int ret_tot_students(){
        return number_of_students;
    }
    static void set_tot_students(int i){
         number_of_students = i;
    }
    
    /*
     Function to return state of is_issued_array
     Takes in index as param &* returns boolean.
     */
    bool ret_issued(int i){
        return is_issued[i];
    }
    
    //Return book id in card index i
    char *ret_issue_book_uid(int i){
        return card[i].book_uid;
    }
    
    //Return issue date in card index i
    int ret_issue_date(int i){
        return card[i].issue_date;
    }
    
    //Return return date in card index i
    int ret_return_date(int i){
        return card[i].return_date;
    }
    
    //Return return date in time_t in card index i
    time_t ret_r_date_in_time_t(int i){
        return card[i].r_date_in_time_t;
    }
    
    //File reading - set object methods.
    
    void set_issued(int i, bool x){
        is_issued[i] = x;
    }
    
    void set_uid( char* a){
        strcpy( mem_uid, a );
    }
    
    
    void set_book_uid(int i, std::string &s){
        strcpy( card[i].book_uid ,s.c_str() );
    }
    
    void set_issue_date (int i, std::string &s){
        std::stringstream a;
        a << s;
        a >> card[i].issue_date;
    }
    
    void set_return_date (int i, std::string &s){
        std::stringstream a;
        a << s;
        a >> card[i].return_date;
    }
    
    void set_r_date_in_time_t(int i, std::string &s){
        std::stringstream a;
        a << s;
        a >> card[i].r_date_in_time_t;
    }
    
    
    
    

    //Set UID of Student as : "ST/xxxxxxxxxx" where x is an integer, telling the no. of students when this student is added.
    void set_uid(void){
        char temp[26] = "";
        strcpy(temp, "ST/");
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(6);
        ss << ++number_of_students;
        strcpy(mem_uid, temp);
        ss >> temp;
        strcat(mem_uid, temp);
        ss.str("");
        ss.clear();
        std::cout << "UID of Student : " << mem_name << " is : " << mem_uid << '\n' ;
    }
    
    /*
     Book ID passed to the function after validations issues to the student. Card number is the number used by student against which book will be issued.
     Returns : 1 - if succesful after which book from stock is decreased.
                0 - if book issue fails because of not valid credentials of the student. ( payment due - or card in use)
     Card No : Can be 0 or 1.
     */
    int issue_book(char *book_id, int card_no){
        if(card_no != 1 && card_no != 0)
            return 0;
        
        //To calculate Date of Issue and Date of Return.
        time_t right_now;
        struct tm *t_i;
        
        time(&right_now);
        t_i = localtime(&right_now);
        
        char temp[10];
        
        strftime( temp, 10, "%d%m%Y", t_i );
        int curr_time = atoi(temp);
        
        
        if (is_issued[card_no] == true) {
            if (curr_time <= card[card_no].return_date) {
                std::cout << " Card in Use for book #: " << card[card_no].book_uid << '\n';
                return 0;
            }
            else{
                std::cout << " Book returned late. Fine due : Rs. " << std::setprecision(2) << calculate_fine(curr_time, card[card_no].r_date_in_time_t) << ".\n";
                std::cout << "Card will be reutned only afer that" << "\n";
                return 0;
            }
            
        }
        is_issued[card_no] = true;
        strcpy(card[card_no].book_uid, book_id);
        card[card_no].issue_date = curr_time;
        
        unsigned long long x = 15*24*60*60;
        right_now += x;
        
        t_i = localtime(&right_now);
        
        strcpy(temp,"");
        
        strftime( temp, 10, "%d%m%Y", t_i );
        card[card_no].return_date = atoi(temp);
        
        t_i->tm_hour = 0;
        t_i->tm_min = 0;
        t_i->tm_sec = 0;
        
        card[card_no].r_date_in_time_t = mktime(t_i);
        
        return 1;
    }
    
    /*
     Book ID passed to the function after validations frees card to the student. Card number is the number used by student, which is to be returned.
     Returns : 1 - if succesful after which book from stock is increased.
     0 - if card return fails because of not valid credentials of the student. ( card not in use )
     Card No : Can be 0 or 1.
     */
    int return_book(char *book_id, int card_no){
        if(card_no != 1 && card_no != 0)
            return 0;
        if (is_issued[card_no] == false) {
            std::cout << " Card not in Use.\n";
            return 0;
        }
        
        //To calculate Date of Return.
        time_t right_now;
        struct tm *t_i;
        
        time(&right_now);
        t_i = localtime(&right_now);
        
        char temp[10];
        
        strftime( temp, 10, "%d%m%Y", t_i );
        int date_returned = atoi(temp);
        
        if(is_issued[card_no] && !strcmp(card[card_no].book_uid, book_id ) ){
            if ( card[card_no].return_date <= date_returned ) {
                std::cout << " Book return successful. Card returned.\n";
                is_issued[card_no] = false;
                return 1;
            }
            else{
                std::cout << " Book returned late. Fine due : Rs. " << std::setprecision(2) << calculate_fine(right_now, card[card_no].r_date_in_time_t) << ".\n";
                std::cout << "Card will be reutned only afer that" << "\n";
                return 1;
            }
        }
        return 0;
    }
    
    
};

unsigned int Student_Library::number_of_students = 0;

                                // End of Student Class Declaration.




struct issue_details_journal{
    char journal_uid[26];
    int issue_date, return_date;
};


                                                                    // Start of Faculty Class Decalration.
/*
 Inherits:  name[], uid[]
 set_name(), get_name(), get_uid().
 */
class Faculty_Library : public Member_Library{
    
private:
    static unsigned int number_of_faculties;
    bool is_issued[10], is_issued_journal[10];
    issue_details card[10];
    issue_details_journal card_journal[10];
    
public:
    //Public Constructor Default for Faculty. Intitates everything to 0 or "".
    Faculty_Library(){
        for (int i = 0; i < 10; i++) {
            is_issued[i] = is_issued_journal[i] = false;
            strcpy(card[i].book_uid, "");
            strcpy(card_journal[10].journal_uid ,"");
            card[i].issue_date = card[i].return_date = 0;
            card[i].r_date_in_time_t = 0;
            card_journal[i].issue_date = card_journal[i].return_date = 0;
        }
    }
    
    static unsigned int ret_tot_faculty(){
        return number_of_faculties;
    }
    static void set_tot_faculty(int i){
        number_of_faculties = i;
    }
    
    
    /*
     Function to return state of is_issued_array
     Takes in index as param &* returns boolean.
     */
    bool ret_issued(int i){
        return is_issued[i];
    }
    
    //Return book id in card index i
    char *ret_issue_book_uid(int i){
        return card[i].book_uid;
    }
    
    //Return issue date in card index i
    int ret_issue_date(int i){
        return card[i].issue_date;
    }
    
    //Return return date in card index i
    int ret_return_date(int i){
        return card[i].return_date;
    }
    
    //Return return date in time_t in card index i
    time_t ret_r_date_in_time_t(int i){
        return card[i].r_date_in_time_t;
    }
    
    /*
     Function to return state of is_issued_journal array
     Takes in index as param &* returns boolean.
     */
    bool ret_issued_journal(int i){
        return is_issued_journal[i];
    }
    
    //Return journal id in card index i
    char *ret_issue_journal_uid(int i){
        return card_journal[i].journal_uid;
    }
    
    //Return journal issue date in card index i
    int ret_issue_date_journal(int i){
        return card_journal[i].issue_date;
    }
    
    //Return journal return date in card index i
    int ret_return_date_journal(int i){
        return card_journal[i].return_date;
    }
    
    //File reading - set object methods.
    
    void set_issued(int i, bool x){
        is_issued[i] = x;
    }
    
    void set_uid( char* a){
        strcpy( mem_uid, a );
    }
    
    void set_book_uid(int i, std::string &s){
        strcpy( card[i].book_uid ,s.c_str() );
    }
    
    void set_issue_date (int i, std::string &s){
        std::stringstream a;
        a << s;
        a >> card[i].issue_date;
    }
    
    void set_return_date (int i, std::string &s){
        std::stringstream a;
        a << s;
        a >> card[i].return_date;
    }
    
    void set_r_date_in_time_t(int i, std::string &s){
        std::stringstream a;
        a << s;
        a >> card[i].r_date_in_time_t;
    }


    void set_issued_journal(int i, bool x){
        is_issued_journal[i] = x;
    }
    
    void set_journal_uid(int i, std::string &s){
        strcpy( card_journal[i].journal_uid ,s.c_str() );
    }
    
    void set_issue_date_journal (int i, std::string &s){
        std::stringstream a;
        a << s;
        a >> card_journal[i].issue_date;
    }
    
    void set_return_date_journal (int i, std::string &s){
        std::stringstream a;
        a << s;
        a >> card_journal[i].return_date;
    }
    
    //Set UID of Student as : "FA/xxxxxxxxxx" where x is an integer, telling the no. of students when this student is added.
    void set_uid(void){
        char temp[26] = "";
        strcpy(temp, "FA/");
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(6);
        ss << ++number_of_faculties;
        strcpy(mem_uid, temp);
        ss >> temp;
        ss.str("");
        ss.clear();
        strcat(mem_uid, temp);
        std::cout << "UID of Faculty : " << mem_name << " is : " << mem_uid << '\n' ;
    }
    
    /*
     Book ID passed to the function after validations issues to the faculty. Card number is the number used by faculty against which book will be issued.
     Returns : 1 - if succesful after which book from stock is decreased.
     0 - if book issue fails because of not valid credentials of the faculty. (card in use)
     Card No : Can be 0 - 9 .
     */
    int issue_book(char *book_id, int card_no){
        if(card_no < 0 || card_no > 9)
            return 0;
        
        
        if (is_issued[card_no] == true) {
            std::cout << " Card in Use for book #: " << card[card_no].book_uid << '\n';
            return 0;
        }
        
        //To calculate Date of Issue and Date of Return.
        time_t right_now;
        struct tm *t_i;
        
        time(&right_now);
        t_i = localtime(&right_now);
        
        char temp[10];
        
        strftime( temp, 10, "%d%m%Y", t_i );
        int curr_time = atoi(temp);
        
        
        is_issued[card_no] = true;
        strcpy(card[card_no].book_uid, book_id);
        card[card_no].issue_date = curr_time;
        
        unsigned long long x = 15*24*60*60;
        right_now += x;
        
        t_i = localtime(&right_now);
        
        strcpy(temp,"");
        
        strftime( temp, 10, "%d%m%Y", t_i );
        card[card_no].return_date = atoi(temp);
        
        t_i->tm_hour = 0;
        t_i->tm_min = 0;
        t_i->tm_sec = 0;
        
        card[card_no].r_date_in_time_t = mktime(t_i);
        
        return 1;
    }
    
    /*
     Book ID passed to the function after validations frees card to the faculty. Card number is the number used by faculty, which is to be returned.
     Returns : 1 - if succesful after which book from stock is increased.
     0 - if card return fails because of not valid credentials of the faculty. ( card not in use )
     Card No : Can be 0 - 9.
     */
    int return_book(char *book_id, int card_no){
        if(card_no < 0 || card_no > 9)
            return 0;
        if (is_issued[card_no] == false) {
            std::cout << " Card not in Use.\n";
            return 0;
        }
        
        if(is_issued[card_no] && !strcmp(card[card_no].book_uid, book_id ) ){
            std::cout << " Book return successful. Card returned.\n";
            is_issued[card_no] = false;
            return 1;
        }
        return 0;
    }
    
    /*
     Journal ID passed to the function after validations issues to the faculty. Journal Card number is the number used by faculty against which Journal will be issued.
     Returns : 1 - if succesful after which Journal from stock is decreased.
     0 - if Journal issue fails because of not valid credentials of the faculty. (card in use)
     Journal Card No : Can be 0 - 9 .
     */
    int issue_journal(char *journal_id, int card_no){
        if(card_no < 0 || card_no > 9)
            return 0;
        
        
        if (is_issued_journal[card_no] == true) {
            std::cout << " Card in Use for book #: " << card_journal[card_no].journal_uid << '\n';
            return 0;
        }
        
        //To calculate Date of Issue and Date of Return.
        time_t right_now;
        struct tm *t_i;
        
        time(&right_now);
        t_i = localtime(&right_now);
        
        char temp[10];
        
        strftime( temp, 10, "%d%m%Y", t_i );
        int curr_time = atoi(temp);
        
        
        is_issued_journal[card_no] = true;
        strcpy(card_journal[card_no].journal_uid, journal_id);
        card_journal[card_no].issue_date = curr_time;
        
        unsigned long long x = 15*24*60*60;
        right_now += x;
        
        t_i = localtime(&right_now);
        
        strcpy(temp,"");
        
        strftime( temp, 10, "%d%m%Y", t_i );
        card_journal[card_no].return_date = atoi(temp);
        
        return 1;
    }
    
    /*
     Journal ID passed to the function after validations frees card to the faculty. Journal Card number is the number used by faculty, which is to be returned.
     Returns : 1 - if succesful after which Journal from stock is increased.
     0 - if card return fails because of not valid credentials of the faculty. ( card not in use )
     Journal Card No : Can be 0 - 9.
     */
    int return_journal(char *journal_id, int card_no){
        if(card_no < 0 || card_no > 9)
            return 0;
        if (is_issued_journal[card_no] == false) {
            std::cout << " Card not in Use.\n";
            return 0;
        }
        
        if(is_issued_journal[card_no] && !strcmp(card_journal[card_no].journal_uid, journal_id ) ){
            std::cout << " Journal return successful. Card returned.\n";
            is_issued_journal[card_no] = false;
            return 1;
        }
        return 0;
    }
    
};

unsigned int Faculty_Library::number_of_faculties = 0;

// End of Faculty Class Declaration.