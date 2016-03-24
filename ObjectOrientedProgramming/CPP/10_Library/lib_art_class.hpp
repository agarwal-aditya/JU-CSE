
#ifndef LIB_BASE_DEF
#include "lib_class_def.hpp"
#endif

#include <sstream>

#include <iomanip>


//Class for Book in Library.
/*
 Inherits:  name[], uid[], qty_in_stock, total_qty
 set_name(), get_name(), get_uid(), set&get for qties.
 */
class Book_Library : public Article_Library{
private:
	// Number of unique books
	static unsigned int number_of_books;

public:
    //Public Constructor Default for Book. Intitates everything to 0 or "" (through base class constructor).
	Book_Library(){
	}
    
    static unsigned int ret_tot_books(){
        return number_of_books;
    }
    static void set_tot_books(int i){
        number_of_books = i;
    }
    
    
	
    //Sets UID of each book as : "B-xxxxxxxxxx" where x is an integer, telling unique no. of books.
	void set_uid(void){
		char temp[26] = "";
		strcpy(temp, "B-");
        std::stringstream ss;
        ss << std::setw(8) << std::setfill('0') << ++number_of_books;
		strcpy(art_uid, temp);
		ss >> temp;
        ss.clear();
		strcat(art_uid, temp);

		std::cout << "UID of Book Name : " << art_name << " is : " << art_uid << '\n' ;
	}

};

//Initialising Static Member Variable.
unsigned int Book_Library::number_of_books = 0;









// Class for Journal in Library Library.
/*
 Inherits:  name[], uid[], qty_in_stock, total_qty
            set_name(), get_name(), get_uid(), set&get for qties.
 */
class Journal_Library : public Article_Library{
    
private:
	// Number of unique journals
	static unsigned int number_of_journals;
	
	//date stored in ddmmyyyy format.
	unsigned int date_of_publish;	
	int volume_no;

public:
    //Public Constructor Default for journal. Intitates everything to 0 or "".
	Journal_Library(){
		date_of_publish = 19011970;	// 19-Jan-1970
		volume_no = 0;
	}
    
    static unsigned int ret_tot_journals(){
        return number_of_journals;
    }
    static void set_tot_journals(int i){
        number_of_journals = i;
    }
    
    
	
    //Sets UID of each book as : "J-xxxxxxxxxx" where x is an integer, telling unique no. of journals.
	void set_uid(void){
		char temp[26] = "";
		strcpy(temp, "J-");
        std::stringstream ss;
        ss << std::setw(8) << std::setfill('0') << ++number_of_journals;
		strcpy(art_uid, temp);
		ss >> temp;
        ss.clear();
		strcat(art_uid, temp);

		std::cout << "UID of Journal Name : " << art_name << " is : " << art_uid << '\n' ;
	}

    // Sets Volume no. Parameter n, to set volume no.
	int set_volume(int n){
        if(n >= 0){
            volume_no = n;
            return 1;
        }
        return 0;
        
	}

    // Returns volume no. ( an int)
	int get_volume(void){
		return volume_no;
	}

    // Sets date of pulishing after neccesary validations and returns 1. Else prints error message and returns 0 and no setting of date happens.
	int set_date_of_publish(int date){
		int flag = 0;
		int d = date/1000000;
		int m = (date/10000)%100;
		int y = date % 10000;
		if(d <= 0 ||  d > 31){
			if( m < 1 || m > 12)
				flag = 1;
			else if( m == 2 && y % 4 == 0 && d > 30)
				flag = 1;
			else if( m == 2 && d > 29)
				flag = 1;
			else if ( ( m == 4 || m == 6 || m == 9 || m == 11) && d > 30 )
				flag = 1;

		}
		if(!flag){
			date_of_publish = date;
            return 1;
		}
		else{
			std::cout << "Incorrect Date Entered.";
            return 0;
		}
	}

    // Returns int: date_of_publish - ddmmYYYY format.
    unsigned int get_date_of_publish(void){
		return date_of_publish;
	}
	

};

//Initialising Static Member Variable.
unsigned int Journal_Library::number_of_journals = 0;