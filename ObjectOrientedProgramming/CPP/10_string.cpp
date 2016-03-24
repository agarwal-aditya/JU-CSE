#include <iostream>
#include <cstring>
#include <cstdio>

class string{
    int length;
    char *s;
    
public:
    string(int = 1);
    string(string &);
    string(char*);
    ~string();
    
    inline int ret_length(void){
        return length;
    }
    inline char* ret_str(void){
        return s;
    }
    
    void set_str(void){
        std::cin.ignore(2, '\n');
        std::cin.getline(s, length + 1 );
    }
    
    
    string operator + ( const string& );
    string& operator = ( const string& );
    
    bool operator > ( string& );
    bool operator < ( string& );
    bool operator >= ( string& );
    bool operator <= ( string& );
    bool operator == ( string& );
    bool operator != ( string& );
};


string::string(int n){
    if(n <= 1){
        length = 0;
        s = new char[1];
        s[0] = '\0';
    }
    else{
        length = n;
        s = new char[n+1];
        s[0] = '\0';
    }
}

string::string(string &a){
    length = a.length;
    int i;
    if(length == 0)
        delete []s;
    
    s = new char[length+1];
    for(i=0;i<length;i++){
        this -> s[i] = a.s[i];
    }
    s[i] = '\0';
}

string::string(char *a){
    length = strlen(a);
    int i;
    s = new char[length+1];
    for(i=0;i<length;i++){
        s[i] = a[i];
    }
    s[i] = '\0';
}

string::~string(){
    if(s)
        delete[] s;
}

string& string::operator = (const string &a){
    if(length < a.length){
        delete [] s;
        s = new char[a.length + 1];
        length = a.length;
    }
    else{
        length = a.length;
    }
    int i;
    for( i = 0; i < length; i++){
        s[i] = a.s[i];
    }
    s[i] = '\0';
    return (*this);
}

string string::operator + (const string& a){
    string temp;
    int i, j, k;
    temp.length = length + a.length;
    temp.s = new char[length + 1];
    k = strlen(s);
    for( i = 0; i < k; i++){
        temp.s[i] = s[i];
    }
    for(j = 0 ; j < a.length; j++)
        temp.s[i++] = a.s[j];
    temp.s[i] = '\0';
    return temp;
}

bool string::operator > (string& a2){
    if( strcmp(s, a2.s) > 0 )
        return true;
    else
        return false;
}

bool string::operator < (string& a2){
    if( strcmp(s, a2.s) < 0 )
        return true;
    else
        return false;
}

bool string::operator == (string& a2){
    if( !strcmp(s, a2.s) )
        return true;
    else
        return false;
}

bool string::operator <= (string& a2){
    if( strcmp(s, a2.s) <= 0 )
        return true;
    else
        return false;
}

bool string::operator >= (string& a2){
    if( strcmp(s, a2.s) >= 0 )
        return true;
    else
        return false;
}

bool string::operator != (string& a2){
    return (!(*this == a2));
}

void print_options(void);

int main(void){
    string *st;
    st = new string[100];
    string *s_temp;
    int index = 0, switch_case, switch_case_1;
    int i;
    bool flag = true;
    print_options();
    while(flag){
        std::cout << "\nChoose from the given options :\t";
        std::cin >> switch_case;
        switch(switch_case){
            case 0:
                flag = false;
                break;
            case 1:
                std::cout << "\t1: To enter the length of string you want to declare and initialize henceforth.\n";
                std::cout << "\t2: To declare and initialise with another object.\n";
                std::cout << "\t3: To assign one string object with another C type string(a = b).\n";
                std::cout << "\nChoose from the given options :\t";
                
                std::cin >> switch_case_1;
                
                switch(switch_case_1){
                    case 1:
                    {
                        std::cout << "Enter the size, and the value for initialization(optional).\n";
                        std::cin >> i;
                        string temp(i);
                        std::cout << "Enter the contents of the string. Length initialized = " << i << '\n';
                        temp.set_str();
                        st[index] = temp;
                        std::cout << "\n\tI.D. Number of string is: " << index << "\n";
                        index += 1;
                        
                        break;
                    }
                    case 2:
                    {
                        std::cout << "Enter the I.D. Number of the string object you want to initialise a new string object with.\n";
                        std::cin >> i;
                        if(i < index){
                            st[index] = st[i];
                            std::cout << "\n\tI.D. Number of string is: " << index << "\n";
                            index += 1;
                        }
                        else{
                            std::cout<< "ID Error:Accessing unallocated string object.\n";
                        }
                        break;
                    }
                    case 3:
                        std::cout << "Enter the C-type string you want to initialise a new string object with.\n";
                        char *t;
                        t = new char[101];
                        std::cin >> t;
                        s_temp = new string(t);
                        st[index] = *s_temp;
                        delete s_temp;
                        std::cout << "\n\tI.D. Number of string is: " << index << "\n";
                        index += 1;
                        delete [] t;
                        
                        break;
                        
                    default:
                        printf("Invalid value entered. Bye!\n");
                        return 0;
                }
                
                
                break;
                
            case 2:
                int i1, i2;
                char ch;
                std::cout << "Enter the I.D. Numbers of the string objects you want to concatenate.\n";
                std::cin >> i1 >> i2;
                if(i1 >= 0 && i1 < index && i2 >= 0 && i2 < index){
                    string temp;
                    temp = (st[i1] + st[i2]);                        //?Possible CE
                    std::cout << temp.ret_str() << '\n';
                    std::cout << "Do you want to store this string?(Y/N)\t";
                    std::cin >> ch;
                    if(ch == 'Y' || ch == 'y'){
                        st[index] = temp;
                        std::cout << "\n\tI.D. Number of string is: " << index << "\n";
                        index += 1;
                    }
                }
                
                break;
                
            case 3:
                char *t;
                t = new char[5];
                std::cout << "Enter the type of comparison you want to do.\n";
                std::cout << "'==' or '!=' or '>=' or '<=' or '<' or '>'.\tAll symbols have usual meanings.\n";
                std::cin >> t;
                if(!strcmp(t, "==")){
                    std::cout << "Enter the I.D. Numbers of the string objects you want to compare.\n";
                    std::cin >> i1 >> i2;
                    if(i1 >= 0 && i1 < index && i2 >= 0 && i2 < index)
                        std::cout << (st[i1] == st[i2]);
                    else
                        std::cout<< "ID Error:Accessing unallocated string objects.\n";
                }
                
                else if(!strcmp(t, "!=")){
                    std::cout << "Enter the I.D. Numbers of the string objects you want to compare.\n";
                    std::cin >> i1 >> i2;
                    if(i1 >= 0 && i1 < index && i2 >= 0 && i2 < index)
                        std::cout << (st[i1] != st[i2]);
                    else
                        std::cout<< "ID Error:Accessing unallocated string objects.\n";
                }
                
                else if(!strcmp(t, ">=")){
                    std::cout << "Enter the I.D. Numbers of the string objects you want to compare.\n";
                    std::cin >> i1 >> i2;
                    if(i1 >= 0 && i1 < index && i2 >= 0 && i2 < index)
                        std::cout << (st[i1] >= st[i2]);
                    else
                        std::cout<< "ID Error:Accessing unallocated string objects.\n";
                }
                
                else if(!strcmp(t, "<=")){
                    std::cout << "Enter the I.D. Numbers of the string objects you want to compare.\n";
                    std::cin >> i1 >> i2;
                    if(i1 >= 0 && i1 < index && i2 >= 0 && i2 < index)
                        std::cout << (st[i1] <= st[i2]);
                    else
                        std::cout<< "ID Error:Accessing unallocated string objects.\n";
                }
                
                else if(!strcmp(t, "<")){
                    std::cout << "Enter the I.D. Numbers of the string objects you want to compare.\n";
                    std::cin >> i1 >> i2;
                    if(i1 >= 0 && i1 < index && i2 >= 0 && i2 < index)
                        std::cout << (st[i1] < st[i2]);
                    else
                        std::cout<< "ID Error:Accessing unallocated string objects.\n";
                }
                
                else {
                    std::cout << "Enter the I.D. Numbers of the string objects you want to compare.\n";
                    std::cin >> i1 >> i2;
                    if(i1 >= 0 && i1 < index && i2 >= 0 && i2 < index)
                        std::cout << (st[i1] > st[i2]);
                    else
                        std::cout<< "ID Error:Accessing unallocated string objects.\n";
                }
                
                break;
            
            case 4:
                std::cout << "Enter the I.D. Number of the string objects you want to display.\n";
                std::cin >> i;
                if(i < index)
                    std::cout << st[i].ret_length() << "\n";
                else
                    std::cout<< "ID Error:Accessing unallocated string object.\n";
                break;
                
            case 6:
                std::cout << "Enter the I.D. Number of the string objects you want to display.\n";
                std::cin >> i;
                if(i < index)
                    std::cout << st[i].ret_str() << "\n";
                else
                    std::cout<< "ID Error:Accessing unallocated string object.\n";
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

    return 0;
}

void print_options(void){
    std::cout<<"Enter:\n";
    std::cout<<"\t0: Exit.\n";
    std::cout<<"\t1: Initialise string object.\n";
    std::cout<<"\t2: Concatenate 2 string objects.\n";
    std::cout<<"\t3: Compare 2 string objects.\n";
    std::cout<<"\t4: See the length of a string object.\n";
    std::cout<<"\t6: Display a string object.\n";
    std::cout<<"\t9: Show the option menu again.\n";
}
