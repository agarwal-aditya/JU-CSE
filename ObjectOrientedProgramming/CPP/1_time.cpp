#include <cstdio>
#include <iostream>
#include <cstring>

// class stores time in 24 hour format always.
// Depending upon query, takes inout or outputs time wither in 12/24 hour format.

class time_time{
	private:

	int hour, min, sec;

    /*
     private helper function rationalises the minutes and hours value after call to increase the time by minutes.
    */
	void time_rationalise(void){
		while(min >= 60){
			hour += 1;
			min -= 60;
		}
		while( hour >= 24)
			hour -= 24;
	}
	
    /*
     private helper function validates the hours, minutes and seconds values after they are input.
     argument : boolean parameter to tell whether function has been called by the 24_hr_input method or 12_hr_input method
     returns: integer to help in continuous validations of the input until the input corresponds to the range of permissible values.
    */
	int validate_input( bool is_24_hr_format ){
		int temp;
		if( is_24_hr_format ){
			while( (hour >= 24 || hour < 0) || (min >= 60 || min < 0) || (sec >= 60 || sec < 0) ){
				if( (hour >= 24 || hour < 0) ){
					printf("Please enter hours in the correct range(0-23).\nEnter hour again or if you want to start afresh enter -1.\n");
					scanf("%d", &temp);
					if(temp == -1)
						return 1;
					else
						hour = temp;
				}
				else if( (min >= 60 || min < 0) ){
					printf("Please enter minutes in the correct range(0-59).\nEnter minutes again or if you want to start afresh enter -1.\n");
					scanf("%2d", &temp);
					if(temp == -1)
						return 1;
					else
						min = temp;
				}
				else{
					printf("Please enter seconds in the correct range(0-59).\nEnter seconds again or if you want to start afresh enter -1.\n");
					scanf("%2d", &temp);
					if(temp == -1)
						return 1;
					else
						sec = temp;
				}
			}
			return 0;
		}
		else{
			char s[4] = "";
			while( (hour >= 24|| hour < 0) || (min >= 60 || min < 0) || (sec >= 60 || sec < 0) ){
				if( (hour >= 24 || hour < 0) ){
					printf("Please enter hours in the correct range(0-11).\nEnter hour again with am/pm (eg. 10 AM) \tor if you want to start afresh enter -1.\n");
					scanf("%2d %2s", &temp, s);
					if(temp == -1)
						return 1;
					else{
						if(!strcmp(s,"am") || !strcmp(s,"AM") || !strcmp(s,"Am") || !strcmp(s,"aM") )
							hour = temp;
						else if (!strcmp(s,"pm") || !strcmp(s,"PM") || !strcmp(s,"Pm") || !strcmp(s,"pM") )
							hour = temp + 12;
					}
				}
				else if( (min >= 60 || min < 0) ){
					printf("Please enter minutes in the correct range(0-59).\nEnter minutes again or if you want to start afresh enter -1.\n");
					scanf("%2d", &temp);
					if(temp == -1)
						return 1;
					else
						min = temp;
				}
				else{
					printf("Please enter seconds in the correct range(0-59).\nEnter seconds again or if you want to start afresh enter -1.\n");
					scanf("%2d", &temp);
					if(temp == -1)
						return 1;
					else
						sec = temp;
				}
			}
			return 0;
		}
		return 0;
	}
	
	public:

    /*
     public function to input time in 24 hr format.
     */
	void input_time_24hr_format(void){
		do{
			printf("\nEnter hr min seconds in the 'hh:mm:ss' format.\n");
			scanf("%d:%d:%d", &hour, &min, &sec);
		}while( validate_input( true ) );
	
	}
    
    /*
     public function to input time in 12 hr format.
     NOTE: eccentric values for the string may result in unruly behaviour.
     */
	void input_time_12hr_format(void){
		char string[10] = "";
		do{
			printf("\nEnter hr min seconds in the 'hh:mm:ss am/pm' format.\n");
			scanf("%d:%d:%d %s", &hour, &min, &sec, string);
			if ( !strcmp(string, "pm") || !strcmp(string, "PM") ){
				hour += 12;
				if(hour == 24){
					hour -= 12;
				}
			}
			else if ( !strcmp(string, "am") || !strcmp(string, "AM") ){
				if( hour == 12 ){
					hour = 0;
				} 
			}
		}while( validate_input( false ) );
	}
	
    
    /*
     public function to input time in format specified by the argument is_24_hr.
     prints time stored in object in 24 hr frmat if boolean is24HrForat is true.
        else prints time in 12 hr format.
     */
	void print_time( bool is24HrFormat ){
		if( is24HrFormat ){
			printf("Time : %02d:%02d:%02d\n", hour, min, sec);
		}
		else{
			if(hour > 12 && hour < 24){
				hour -= 12;
				printf("Time : %02d:%02d:%02d PM\n", hour, min, sec);
				hour += 12;
			}
			else if(hour == 12){
				printf("Time : %02d:%02d:%02d PM\n", hour, min, sec);
			}
			else if(hour == 24){
				printf("Time : %02d:%02d:%02d AM\n", 0, min, sec);
			}
			else {
				printf("Time : %02d:%02d:%02d AM\n", hour, min, sec);
			}
		}
	
	}

    /*
     public function to add minutes to the current time stored in the object.
     */
	void add_time(void){
		int minutes_to_add;
		printf("Enter the minutes you want to add to '%02d:%02d:%02d' .\n", hour, min, sec);
		scanf("%d", &minutes_to_add);
		min += minutes_to_add;
		time_rationalise();
	}
};

int main(void){
	time_time t;
	int option;
	bool flag = true;
	printf("Options available:\n");
	printf("\t0 : Exit.\n");
	printf("\t1 : Enter time in 12 hour format.\n");
	printf("\t2 : Enter time in 24 hour format.\n");
	printf("\t3 : Print time in 12 hour format.\n");
	printf("\t4 : Print time in 24 hour format.\n");
	printf("\t5 : Add minutes to time.\n");

	while(flag){
        printf("Choose from the given options :\t");
        scanf("%d", &option);
		switch(option){
			case 0:
				flag = false;
				break;
			case 1:
				t.input_time_12hr_format();
				break;
			case 2:
				t.input_time_24hr_format();
				break;
			case 3:
				t.print_time( false );
				break;
			case 4:
				t.print_time( true );
				break;
			case 5:
				t.add_time();
				break;
            default:
                printf("Invalid value entered. Bye!\n");
                flag = false;
                break;

		}
	}
	return 0;
}
