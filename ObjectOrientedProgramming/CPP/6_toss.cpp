#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

class last_three_tosses{
	int i;
	unsigned int number_of_tosses;
	bool arr[3];
	
	void increase_index(void){
		i++;
		i %= 3;
	}
	
public:
	last_three_tosses(){
		i = 0;
		number_of_tosses = 0;
		for(int i = 0; i <= 2; i++){
			arr[i] = false;
		}
		srand(time(NULL));
	}
	
	//Increase the variable storing count of tosses taken place
	void increase_count(void){
		number_of_tosses ++ ;
	}
	
	//Returns the number of coin tosses done till that moment.
	unsigned int get_count(void){
		return number_of_tosses;
	}
	
	/*
	toss function which stores result of coin toss in an array of size 3, using circular array concept.
	Then call is made to increase toss count function.
	*/
	void toss(void){
		int temp;
		temp = rand()%2;
		// 0 corresponds for tails and 1 for heads
		if(temp == 0){
			arr[i] = false;
			std::cout << "tails" << "\n";
		}
		else{
			arr[i] = true;
			std::cout << "heads" << "\n";
		}
		increase_index();
	}
	
	/*
	Function checks whether last 3 tosses have been heads or not.
	Returns bool. 1 if last 3 tosses are heads, else returns false.
	*/
	bool check_result(void){
		//std::cout <<" arr[0] = " << arr[0] <<" arr[1] = " <<  arr[1] << " arr[2] = " <<  arr[2] << " \n";
		return(arr[0] && arr[1] && arr[2]);
	}
};



int main(void){
	last_three_tosses run1;
	while( !run1.check_result() ){
		run1.toss();
		run1.increase_count();
	}
	std::cout<<"It took " << run1.get_count()  << " flips to get 3 conscecutive heads.\n"; 
	return 0;
}
