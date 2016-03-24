#include <iostream>
#define LIB_BASE_DEF 1
#include <cstring>

// Generalised Base Class for Student and Faculty.

class Member_Library{

protected:
	char mem_name[31];
	char mem_uid[26];
    Member_Library(){
        strcpy(mem_uid, "");
        strcpy(mem_name, "");
    }
	
public :
	void set_name(const char * inp_name){
		strcpy(mem_name, inp_name);
	}
	
	virtual void set_uid(void) = 0;
	
    char *get_uid(void){
		return mem_uid;
	}
	
	char *get_name(void){
		return mem_name;
	}
	
    //set when reading from file
    void set_uid(char *id){
        strcpy(mem_uid, id);
    }

	
};


// Generalised Base Class for Book and Journal.
class Article_Library{

protected:
	char art_name[31];
	char art_uid[26];
	unsigned int qty_in_stock;
	unsigned int total_qty;
    
    //Protected Constructor Default for Articles. Intitates everything to 0 or "".
	Article_Library(){
        strcpy(art_uid, "");
        strcpy(art_name, "");
        qty_in_stock = total_qty = 0;
    }
	
public :

	void set_name(const char * inp_name){
		strcpy(art_name, inp_name);
	}
	
	virtual void set_uid(void) = 0;
	
    //Uid set when reading from file
    void set_uid(char *id){
std::cout << "in art_class : id recd = " << id <<"\n";
        strcpy(art_uid, id);
    }
    
	char *get_uid(void){
		return art_uid;
	}
	
	char *get_name(void){
		return art_name;
	}
    
    // Total Qty has to be greater than or equal to 1.
    int set_total_qty(unsigned int j){
       // if(j > 0){
            total_qty = j;
            return 1;
       /* }
        else{
            std::cout << "Incorrect quantity entered.";
            return 0;
        }*/
    }
    
    int get_total_qty(void){
        return total_qty;
    }
    
    int get_qty_in_stock(void){
        return qty_in_stock;
    }
    
    int set_qty_in_stock( int j){
       // if(j >= 0 && j <= total_qty){
            qty_in_stock = j;
            return 1;
        /*}
        else{
            std::cout << "Incorrect quantity entered.";
            return 0;
        }*/
    }
    
};