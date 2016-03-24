#include <iostream>
#include <cstdio>

class toll_tax {
	unsigned int vehicleCrossedCount, carCrossedCount, bikeCrossedCount, heavyVehicleCrossedCount, govServantCrossedCount, otherCategoryCount;
	unsigned long int amountCollected;
	int rateCar;
	int rateBike;
	int rateHeavyVehicle;
	int rateGovServant;

	public:
	
	//default constructor
	toll_tax(){
		vehicleCrossedCount = amountCollected = carCrossedCount = 0;
		otherCategoryCount = bikeCrossedCount = heavyVehicleCrossedCount = govServantCrossedCount = 0;
	}
	
	//constructor with car rate. all other vehicle rates in relation to car rate.
	toll_tax(int rate){
		vehicleCrossedCount = amountCollected = carCrossedCount = 0;
		otherCategoryCount = bikeCrossedCount = heavyVehicleCrossedCount = govServantCrossedCount = 0;
		rateCar = rate;
		rateBike = (int)(rate * 0.80);
		rateHeavyVehicle = (int)(rate * 2.0);
		rateGovServant = (int)(rate * 0.25);
	}

        //receive toll based on type of car crossing plaza.
	void receive_toll(int type){
		vehicleCrossedCount ++;
		switch(type){
			case 1:
			        carCrossedCount++;
				amountCollected += rateCar;
				break;
			case 2:
			        bikeCrossedCount++;
				amountCollected += rateBike;
				break;
			case 3:
			        heavyVehicleCrossedCount++;
				amountCollected += rateHeavyVehicle;
				break;
			case 4:
			        govServantCrossedCount++;
				amountCollected += rateGovServant;
				break;
			default:
			        otherCategoryCount++;
				amountCollected += rateCar;
				break;
		
		}
		
	}

        //display vehicles crossed both in total(for all vehicle types) and individually.
	void display_no_of_cars_crossed(void){
		printf("Total number of vehicles crossing the toll plaza is: %u\n\n", vehicleCrossedCount);
		printf("Type\t\tNo.\n");
		printf("Cars\t\t%u\n", carCrossedCount);
		printf("Bikes\t\t%u\n", bikeCrossedCount);
		printf("Heavy Vehicles\t%u\n", heavyVehicleCrossedCount);
		printf("Gov. Servant\t%u\n", govServantCrossedCount);
		printf("Others\t\t%u\n", otherCategoryCount);
	}
	
	//display toll rates for each vehicle type.
	void display_toll_rates(void){
	        printf("Toll Rates are:\n");
		printf("Cars\t\tRs.%d\n", rateCar);
		printf("Bikes\t\tRs.%d\n", rateBike);
		printf("Heavy Vehicles\tRs.%d\n", rateHeavyVehicle);
		printf("Gov. Servant\tRs.%d\n", rateGovServant);
		printf("Others\t\tRs.%d\n", rateCar);
	}
	
	//display total amount of toll collected.
	void display_amount_of_toll_collected(void){
		printf("Total Amount of toll collected at the toll plaza is: Rs. %lu\n", amountCollected); 
	}
	
	//set all counts and amount of toll collected to 0.
	void reset_cars_and_toll_count(void){
		vehicleCrossedCount = amountCollected = carCrossedCount = 0;
		otherCategoryCount = bikeCrossedCount = heavyVehicleCrossedCount = govServantCrossedCount = 0;
	}
	
	//reset toll rate for all vehicle types.
	void reset_toll_rate(void){
	        display_no_of_cars_crossed();
	        display_amount_of_toll_collected();
	        printf("Enter toll tax amount for a single car.\n");
	        scanf("%d", &rateCar); 
	        rateBike = (int)(rateCar * 0.80);
		rateHeavyVehicle = (int)(rateCar * 2.0);
		rateGovServant = (int)(rateCar * 0.25); 
		display_toll_rates();
	}

};


//helper function to select which vehicle to add toll for.
//returns int. based on pre defined code.
int car_type(void){
        int choice;
        printf("\n\tEnter the code corresponding to the following type:\n");
        printf("Cars - 1\n");
	printf("Bikes - 2\n");
	printf("Heavy Vehicles - 3\n");
	printf("Gov. Servant - 4\n");
	printf("Others - 5 (or any other unassigned integer)\n");
	scanf("%d", &choice);
	return choice;
}

int main(void){
        int tollCar, switchCase;
        bool flag = true;
        printf("Enter toll tax amount for a single car.\n");
	scanf("%d", &tollCar);
        toll_tax plaza_1(tollCar);
        
        printf("\nOptions available:\n");
	printf("\t0 : Exit.\n");
	printf("\t1 : Receive Toll.\n");
	printf("\t2 : View No. of Cars Crossing the Toll Plaza.\n");
	printf("\t3 : View Amount of Toll Collected at the Toll Plaza.\n");
	printf("\t7 : View Toll Rates.\n");
	printf("\t8 : Reset Cars and Toll Count.\n");
	printf("\t9 : Reset Toll Rates.\n");
	
	
	while(flag){
        printf("\nChoose from the given options :\t");
        scanf("%d", &switchCase);
		switch(switchCase){
			case 0:
				flag = false;
				break;
			case 1:
				plaza_1.receive_toll( car_type() );
				break;
			case 2:
				plaza_1.display_no_of_cars_crossed();
				break;
			case 3:
				plaza_1.display_amount_of_toll_collected();
				break;
			case 7:
				plaza_1.display_toll_rates();
				break;
			case 8:
				plaza_1.reset_cars_and_toll_count();
				break;
		        case 9:
				plaza_1.reset_toll_rate();
				break;
                        default:
                                printf("Invalid value entered. Bye!\n");
                                flag = false;
                                break;

		}
	}
        
	return 0;
}
