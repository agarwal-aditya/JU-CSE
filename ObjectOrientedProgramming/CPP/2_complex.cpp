#include <cstdio>

class complex{
        private:int real, imaginary; 
        
        public:      
                complex(){
                        real = 0;
                        imaginary = 0;             
                }
                
                void input(void){
                        printf("Enter the complex number in the following format(2 3i) or (2 -3i)\n");
                        scanf("%d %di", &real, &imaginary);
                }
                
                
                //Print complex number depending upon values of real and imaginary parts.
                void print(void){
                        if (!imaginary){
                                printf("%d\n",real);
                        }
                        else if( !real){
                                printf("%di\n",imaginary);
                        }
                        else{
                                printf("%d%+di\n", real, imaginary);
                        }           
                }
                
                //Add 2 different complex objects and store result in the object ( c = a + b )
                void add (complex a, complex b){
                        real = a.real + b.real;
                        imaginary = a.imaginary + b.imaginary;
                        printf("\tAfter addition result is : \t");
                        print();
                }
                
                //Add 2 complex objects and store result in the object ( b = a + b )
                void add (complex a){
                        real += a.real;
                        imaginary += a.imaginary;
                        printf("\tAfter addition result is : \t");
                        print();
                }
                
                //Subtract 2 different complex objects and store result in the object ( c = a - b )
                void subtract (complex a, complex b){
                        real = a.real - b.real;
                        imaginary = a.imaginary - b.imaginary;
                        printf("\tAfter subtraction result is : \t");
                        print();
                }
                
                //Subtract 2 complex objects and store result in the object ( b = a - b )
                void subtract (complex a){
                        real -= a.real;
                        imaginary -= a.imaginary;
                        printf("\tAfter subtraction result is : \t");
                        print();
                }
                
                
};

int main(void){
        complex a, b, c, d;
        a.input();
        b.input();
        c.add(a,b);
        d.subtract(a,b);    
        printf("Printing value of 1st no. for cross check with subsequent computations.\t");    
        a.print();
        c.subtract(b);
        d.add(b);
        
        return 0;
}
