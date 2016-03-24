#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>

#define MAX_ITEMS 100
#define ITEM_CODE_LENGTH 15
#define ITEM_NAME_LENGTH 31

class item_class{
        char item_code[ITEM_CODE_LENGTH];
        char item_name[ITEM_NAME_LENGTH];
        float rate;
        unsigned long quantity;
        
public:
        item_class(){
                strcpy( item_code, "");
                strcpy( item_name, "");
                rate = 0.0;
                quantity = 0;
        } 
    
    /*
     Fetch the item code from the object. const so that it cant be changed here.
     */
        char* getItemCode(void) const{
                return (char*)item_code;
        }
    
    /*
     Fetch the item name from the object.
     */
        char* getItemName(void) const{
                return (char*)item_name;
        }
    
    /*
     Fetch the item rate from the object.
     */
        float getItemRate(void){
                return rate;
        } 
    
    /*
     Fetch the item qty in stock from the object.
     */
        unsigned long getItemQuantity(void) const{
                return quantity;
        }
    
    /*
     Set the item code for the object.
     */
        void setItemCode(char *code){
                strcpy(item_code, code);
        }    
    
    /*
     Set the item name for the object.
     */
        void setItemName(char *name){
                strcpy(item_name, name);
        }
    
    /*
     Set the item rate for the object.
     */
        void setItemRate(void){
            scanf("%f", &rate);
            while(rate < 0){
                printf("Rate cannot be negative! \nEnter again.\n");
                scanf("%f", &rate);
            }
        } 
    
    /*
     Set the item qty for the object.
     */
        void setItemQuantity(long temp){
                while(temp < 0){
                        printf("Quantity cannot be negative! \nEnter again.\n");
                        scanf("%ld", &temp);
                }
                quantity = temp;
        }
        
        
        
};


class item_list{
    item_class item[MAX_ITEMS];
    int numberOfUniqueItems;
    char tempCode[ITEM_CODE_LENGTH];
    char tempName[ITEM_NAME_LENGTH];
    
    /*
     Private function to check whether code entered by the user exists in database or not.
     input: param: code: ptr to char array, pointing to user entered code.
     returns index at which item is present in databse. else returns -1 if it DNE.
     */
    int doesCodeExist(char *code){
        for( int i = 0; i < numberOfUniqueItems; i++){
            if(!strcmp(item[i].getItemCode(), tempCode) )
                return i;
        }
        return -1;
    }
    
    /*
     Private function to add new item if code entered by the user  doesnt exist.
     Helper function for addNewItem();
     */
    void addCodeForNewItem(void){
        scanf("%s", tempCode);
        while( doesCodeExist(tempCode) != -1){
            printf("That code already exists for another item. Enter a different code.\n");
            scanf("%s", tempCode);
        }
        item[numberOfUniqueItems].setItemCode(tempCode);
    }
    
    /*
     Private function to add name for item.
     Helper function for addNewItem();
     */
    void addNameForNewItem(void){
        do{
            std::cin.ignore(32767, '\n');
            gets(tempName);
            printf("The item name entered is : %s\n", tempName);
            printf("\tIf you want to continue press 0.\n");
            printf("\tIf you want to enter again press any non zero integer.\n");
            scanf("%s", tempCode);
        }while( strcmp(tempCode, "0") != 0 );
        
        item[numberOfUniqueItems].setItemName(tempName);
    }
    
public:
    item_list(){
        numberOfUniqueItems = 0;
        strcpy(tempCode, "");
        strcpy(tempName, "");
    }
    
    /*
     Public function to add new item.
     Sets code, name, rate, qty, along with necessary input validations.
     */
    void addNewItem(void){
        printf("Enter the code for new item you want to add.\n");
        addCodeForNewItem();
        
        
        printf("Enter the name for new item you want to add.\n");
        addNameForNewItem();
        
        printf("Enter Rate per unit of item name: %s, having code: %s\n", item[numberOfUniqueItems].getItemName(), item[numberOfUniqueItems].getItemCode());
        item[numberOfUniqueItems].setItemRate();
        
        printf("Enter Quantity in Stock of item name: %s, having code: %s\n", item[numberOfUniqueItems].getItemName(), item[numberOfUniqueItems].getItemCode());
        
        
        long temp;
        scanf("%ld", &temp);
        item[numberOfUniqueItems].setItemQuantity(temp);
        
        numberOfUniqueItems++;
    }
    
    /*
     Public function to print details of all items in database.
     */
    void printAllItemsDetails(void){
        if(!numberOfUniqueItems)
            printf("No Items in Database!\n");
        else{
            printf("Code\t\tName\t\t\t\tRate\t\tQty\n");
            printf("_____________________________________________________________________________\n");
            for( int i = 0; i < numberOfUniqueItems; i++){
                printf("%-15s\t%-30s\t%-15.2f\t%lu\n", item[i].getItemCode(), item[i].getItemName(), item[i].getItemRate(), item[i].getItemQuantity()  );
            }
            printf("_____________________________________________________________________________\n");
        }
    }
    
    /*
     Public function to print details of item (if it exists) whose code is entered by user.
     */
    void printSpecificItemDetails(void){
        if(!numberOfUniqueItems)
            printf("No Items in Database!\n");
        else{
            int index;
            printf("Enter the code for item you want to see details.\n");
            scanf("%s", tempCode);
            if( (index = doesCodeExist(tempCode)) == -1){
                printf("No item with such code exists in database!\n");
            }
            else{
                printf("Item Name: %s\n", item[index].getItemName() );
                printf("Item Code: %s\n", item[index].getItemCode() );
                printf("Item Rate: %.2f\n", item[index].getItemRate() );
                printf("Item Quantity: %lu\n", item[index].getItemQuantity() );
            }
        }
    }
    
    /*
     Public function to change rate of item (if it exists) whose code is entered by user.
     */
    void changeItemRate(void){
        printf("Enter the code for item you want to change rate.\n");
        scanf("%s", tempCode);
        int itemIndex = doesCodeExist(tempCode);
        if(itemIndex == -1){
            printf("Item Does Not Exist. Try Again!\n");
        }
        else{
            printf( "Enter Rate per unit of item name: %s, having code: %s\n", item[itemIndex].getItemName(), item[itemIndex].getItemCode());
            printf( "Current Rate is: %.2f\n", item[itemIndex].getItemRate() );
            
            item[itemIndex].setItemRate();
        }
    }
    
    /*
     Public function to issue item (if it exists) whose code is entered by user.
     */
    void issueItem(void){
        printf("Enter the code for item you want to issue.\n");
        scanf("%s", tempCode);
        int itemIndex = doesCodeExist(tempCode);
        if(itemIndex == -1){
            printf("Item Does Not Exist. Can't be issued!\n");
        }
        else{
            long qtyToIssue;
            
            printf( "Current stock of item name: %s, having code: %s is: \n\t%lu\n", item[itemIndex].getItemName(), item[itemIndex].getItemCode(), item[itemIndex].getItemQuantity() );
            printf("Enter the quantity for the above mentioned item you want to issue.\n");
            scanf("%ld", &qtyToIssue);
            while(qtyToIssue<0 || qtyToIssue > item[itemIndex].getItemQuantity()){
                printf("Incorrect Quantity Entered. Enter the quantity of stock to issue again.\n");
                scanf("%ld", &qtyToIssue);
            }
            qtyToIssue = item[itemIndex].getItemQuantity() - qtyToIssue;
            item[itemIndex].setItemQuantity(qtyToIssue);
        }
    }
    
    /*
     Public function to receive item (if it exists) whose code is entered by user.
     */
    void receiveItem(void){
        printf("Enter the code for item you want to receive.\n");
        scanf("%s", tempCode);
        int itemIndex = doesCodeExist(tempCode);
        if(itemIndex == -1){
            printf("Item Does Not Exist. Please Create New Item First to receive additional stock!\n");
        }
        else{
            long qtyToReceive;
            
            printf( "Current stock of item name: %s, having code: %s is: \n\t%lu\n", item[itemIndex].getItemName(), item[itemIndex].getItemCode(), item[itemIndex].getItemQuantity() );
            printf("Enter the quantity for the above mentioned item you received.\n");
            scanf("%ld", &qtyToReceive);
            while(qtyToReceive<0){
                printf("Incorrect Quantity Entered. Enter the quantity of stock received again.\n");
                scanf("%ld", &qtyToReceive);
            }
            qtyToReceive += item[itemIndex].getItemQuantity();
            item[itemIndex].setItemQuantity(qtyToReceive);
        }
    }

};

int main(void){
    
    int switchCase;
    bool flag = true;
  
    item_list list;
    
    printf("\nOptions available:\n");
    printf("\t0 : Exit.\n");
    printf("\t1 : Add New Item.\n");
    printf("\t2 : Issue item based on unique Item Code.\n");
    printf("\t3 : Receive item based on unique Item Code.\n");
    printf("\t5 : View Details of an item based on unique Item Code.\n");
    printf("\t6 : Print Details of all Items in databse.\n");
    printf("\t8 : Change Rate of an item based on unique Item Code.\n");
    
    while(flag){
        printf("\nChoose from the given options :\t");
        scanf("%d", &switchCase);
        switch(switchCase){
            case 0:
                flag = false;
                break;
            case 1:
                list.addNewItem();
                break;
            case 2:
                list.issueItem();
                break;
            case 3:
                list.receiveItem();
                break;
            case 5:
                list.printSpecificItemDetails();
                break;
            case 6:
                list.printAllItemsDetails();
                break;
            case 8:
                list.changeItemRate();
                break;
            default:
                printf("Invalid value entered. Bye!\n");
                flag = false;
                break;
                
        }
    }

    return 0;
}