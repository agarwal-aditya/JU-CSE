#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

class array{
	int size;
	int *a;
    
    bool in_range(int i)const{
        return (i>=0 && i < size);
    }
public:
	//Default Constructor.
	array(int i_size = 0, int value = 0){
        if(i_size){
            this->size = i_size;
            a = new int[size];
			int i;
			for( i = 0; i < i_size; i++)
				a[i] = value;
		}
		else{
			a = NULL;
		}
        
	}
	
	//Copy Constructor
	array (const array &);
	//Construct object from a C-type Array of Integers.
	array (int *, int);
	
	//Destructor
	~array();
	
    array operator +(const array &);
    array& operator =(const array &);
    int& operator[](int);
    
    int get_size(void)const{ return size;};
    int get_element(int i)const{
        if( in_range(i) ){
            return a[i];
        }
        else{
            printf("Invalid Array element access tried.\n");
            throw "Invalid Array element access tried.\n";
        }
    }
    void display(void);

};


array::array(const array & a2){
    int i;
	size = a2.size;
    a = new int[size];
 //   a = (int*)malloc(size*sizeof(int));
	for(i=0;i<size;i++)
		a[i] = a2.get_element(i); 
	
}

array::array(int *a2, int n){
	size = n;
    int i;
    a = new int[n];
	//a = (int*)malloc(size*sizeof(int));
	for(i=0;i<size;i++)
		a[i] = a2[i]; 

}

array::~array(){
	if(a != NULL){
		delete [] a;
	}

}

/*
Add the elements of one array with that of another array. Then ask the user if he wants to store the array.
*/
array array::operator+(const array& a2){
    int n1 = (*this).size, n2 = a2.size;
    int i, n = (n1>n2)?n1:n2;
    int lesser_index = n1+ n2 - n;
    array temp(n);
    for( i =  0; i < lesser_index; i ++){
        temp.a[i] = this->a[i] + a2.a[i];
    }
    if(lesser_index == n2){
        while( i < n1 ){
            temp.a[i] = this->a[i];
            i++;
        }
    }
    else{
        while( i < n2 ){
            temp.a[i] = a2.a[i];
            i++;
        }
    }
    return temp;
}

/*
Assignment operator overloading
*/
array& array::operator=(const array & a2){
    int i;
    if(size != a2.size){
        delete[]a;
        a = new int[a2.size];
        size = a2.size;
    }
    for(i = 0 ; i <a2.size; i++){
        this->a[i] = a2.a[i];
    }
    return *this;
}

/*
Return ith element. using overloaded function.
*/
int& array::operator[] (int index){
    if( in_range(index) ){
        return a[index];
    }
    else{
        throw "Invalid Array element access tried.\n";
    }
}

/*
Display the entire array stored inside the object.
*/
void array::display(void){
    int i;
    std::cout<< "Array :\n\t";
    for(i=0;i<size ;i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

/*
Print choices for switch_case.
*/
void print_options(void);

int main(void){
    array *arr;
    arr = new array[10];
    int index = 0, switch_case, switch_case_1;
    bool flag = true;
    print_options();
    while(flag){
        std::cout<<"\nChoose from the given options :\t";
        std::cin>>switch_case;
        switch(switch_case){
            case 0:
                flag = false;
                break;
            case 1:
                std::cout<<"\t1: To enter the size of array you want to declare, and the value for initialization(optional).\n";
                std::cout<<" Array object may be declared for a specific size and a value for initializing all the elements.\n" << " If no initialising value is providd explicitly, it is to be assumed as a 0.\n";
                std::cout<<"\t2: To declare and initialise with another object.\n";
                std::cout<<"\t3: To assign one array object with another C type array(a = b).\n";
                std::cout<<"\nChoose from the given options :\t";
                
                std::cin>>switch_case_1;
                
                switch(switch_case_1){
                    case 1:
                        int a[2], i, l;
                        char string[100], s2[100];
                        std::cout << "Enter the size, and the value for initialization(optional).\n";
                        std::cin.ignore(10, '\n');
                        std::cin.getline(string, 100 );
                        i = 0;
                        l = strlen(string);
                        while(i<l){
                            if(string[i] != ' ')
                                i++;
                            else
                                break;
                        }
                        if(i != l){
                            strncpy(s2,string,i);
                            strcpy(string, string+i);
                            a[0] = atoi(s2);
                            a[1] = atoi(string);
                        }
                        else{
                            a[0] = atoi(string);
                            a[1] = 0;
                        }
                        
                        arr[index] = array ( a[0], a[1]);
                        arr[index].display();
                        std::cout << "\n\tI.D. Number of array is: " << index << "\n";
                        index += 1;
                        
                        break;
                        
                    case 2:
                        std::cout << "Enter the I.D. Number of the array object you want to initialise a new array object with.\n";
                        std::cin >> i;
                        if(i < index){
                            arr[index] = array(arr[i]);
                            std::cout << "\n\tI.D. Number of array is: " << index << "\n";
                            index += 1;
                        }
                        else
                            std::cout<< "ID Error:Accessing unallocated array object.\n";
                        break;
                        
                    case 3:
                        std::cout << "Enter the size of the C-type array you want to initialise a new array object with.\n";
                        std::cin >> l;
                        int *a1;
                        a1 = new int[l];
                        std::cout << "Enter the values of the C-type array of size : " << l << ", separated by a space.\n";
                        for(i=0;i<l;i++)
                            std::cin >> a1[i];
                        arr[index] = array(a1, l);
                        std::cout << "\n\tI.D. Number of array is: " << index << "\n";
                        index += 1;
                        delete [] a1;
                        
                        break;
                        
                    default:
                        printf("Invalid value entered. Bye!\n");
                        return 0;
                }
                
                
                break;
                
            case 2:
            	char ch;
                int i1, i2;
                std::cout << "Enter the I.D. Numbers of the array objects you want to add.\n";
                std::cin >> i1 >> i2;
                if(i1 >= 0 && i1 < index && i2 >= 0 && i2 < index){
                    array temp = arr[i1] + arr[i2];
                    temp.display();
                    std::cout << "Do you want to store this array?(Y/N)\t";
                    std::cin >> ch;
                    if(ch == 'Y' || ch == 'y'){
                        arr[index] = temp;
                        std::cout << "\n\tI.D. Number of array is: " << index << "\n";
                        index += 1;
                    }
                }
                
                break;
                
            case 3:
                std::cout << "Finding the ith element in an object having ID No X...Enter the query STRICTLY in this format : X[i]\n";
                scanf("%d[%d]", &i1, &i2);
                std::cout << "Element requested is :  " << i1 <<"[" << i2 << "] = " << arr[i1][i2] << "\n";
                break;
                
            case 4:
                int y;
                std::cout << "To multiply the ith element in an object having ID No X with an integer Y (X[i]*Y)...Enter the query STRICTLY in this format : X i Y\n";
                std::cin >> i1 >> i2 >> y;
                std::cout << y << " * " << i1 << "[" << i2 << "] = " << y * arr[i1][i2] << "\n";
                std::cout << i1 << "[" << i2 << "] * " << y << " = " << arr[i1][i2] * y << "\n";
                break;
                
            case 6:
                std::cout << "Enter the I.D. Number of the array objects you want to display.\n";
                std::cin >> i1;
                if(i1 < index)
                    arr[i1].display();
                else
                    std::cout<< "ID Error:Accessing unallocated array object.\n";
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
    std::cout<<"\t1: Initialise Array.\n";
    std::cout<<"\t2: Add 2 array objects.\n";
    std::cout<<"\t3: Return element using a[i] of an array.\n";
    std::cout<<"\t4: Multiply element using * operator.\n";
    std::cout<<"\t6: Display an array object.\n";
    std::cout<<"\t9: Show the option menu again.\n";
}
