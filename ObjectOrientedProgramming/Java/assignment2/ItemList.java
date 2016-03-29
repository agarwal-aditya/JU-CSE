package assignment2;

import java.util.Scanner;
import java.util.*;
import java.io.*;

class ItemClass{
    private String itemCode,
                    itemName;
    private double rate;
    private long quantity;

    

    public ItemClass(){
        itemCode = new String();
        itemName = new String();
        rate = 0.0;
        quantity = 0;
    }
    
    public String getItemCode(){
        return itemCode;
    }

    public String getItemName() {
        return itemName;
    }

    public double getItemRate(){
        return rate;
    }
    
    public long getItemQuantity() {
        return quantity;
    }
    
    public void setItemCode(String code){
        itemCode = new String(code);
    }
    
    public void setItemName(String name){
        itemName = new String(name);
    }
    
    public void setItemRate(){
        Scanner sc = new Scanner(System.in);
        rate = sc.nextDouble();
        while(rate < 0){
            System.out.println("Rate cannot be negative! \nEnter again.");
            rate = sc.nextDouble();
        }
    }
    
    public void setItemQuantity(long temp){
        Scanner sc = new Scanner(System.in);
        while(temp < 0){
            System.out.println("Quantity cannot be negative! \nEnter again.");
            temp = sc.nextLong();
        }
        quantity = temp;
    }
    
}


class ItemList{
    private static final int MAX_ITEMS = 100;
    
    private ItemClass[] item;
    private int numberOfUniqueItems;
    private String tempCode;
    private String tempName;
    
    /*
     Private function to check whether code entered by the user exists in database or not.
     input: param: code: ptr to char array, pointing to user entered code.
     returns index at which item is present in databse. else returns -1 if it DNE.
     */
    private int doesCodeExist(String code){
        for( int i = 0; i < numberOfUniqueItems; i++){
            if( item[i].getItemCode().equals(code) )
                return i;
        }
        return -1;
    }
    
    /*
     Private function to add new item if code entered by the user  doesnt exist.
     Helper function for addNewItem();
     */
    private void addCodeForNewItem(){
        Scanner sc = new Scanner(System.in);
        tempCode = sc.nextLine();
        while( doesCodeExist(tempCode) != -1){
            System.out.println("That code already exists for another item. Enter a different code.");
            tempCode = sc.nextLine();
        }
        item[numberOfUniqueItems] = new ItemClass();
        item[numberOfUniqueItems].setItemCode(tempCode);
    }
    
    /*
     Private function to add name for item.
     Helper function for addNewItem();
     */
    private void addNameForNewItem(){
        int j = 1;
        while( j != 0 ){
            Scanner sc = new Scanner(System.in);
            tempName = sc.nextLine();
            System.out.println("The item name entered is : " +  tempName);
            System.out.println("\tIf you want to continue press 0.");
            System.out.println("\tIf you want to enter again press any non zero integer.");
            j = sc.nextInt();
        }
        
        item[numberOfUniqueItems].setItemName(tempName);
    }
    

   public ItemList(){
       super();
       item = new ItemClass[100];
       numberOfUniqueItems = 0;
       tempCode = new String();
       tempName = new String();
    }
    
    /*
     Public function to add new item.
     Sets code, name, rate, qty, along with necessary input validations.
     */
    public void addNewItem(){
        System.out.println("Enter the code for new item you want to add.");
        addCodeForNewItem();
        
        
        System.out.println("Enter the name for new item you want to add.");
        addNameForNewItem();
        
        System.out.println("Enter Rate per unit of item name: " + item[numberOfUniqueItems].getItemName() +  ", having code: "+ item[numberOfUniqueItems].getItemCode() );
        item[numberOfUniqueItems].setItemRate();
        
        System.out.println("Enter Quantity in Stock of item name: "+ item[numberOfUniqueItems].getItemName() + ", having code: " + item[numberOfUniqueItems].getItemCode() );
        
        long temp;
        Scanner sc = new Scanner(System.in);
        temp = sc.nextLong();
        item[numberOfUniqueItems].setItemQuantity(temp);
        
        numberOfUniqueItems++;
    }
    
    /*
     Public function to print details of all items in database.
     */
    public void printAllItemsDetails(){
        if(numberOfUniqueItems == 0)
            System.out.println("No Items in Database!");
        else{
            System.out.println("Code\t\tName\t\t\t\tRate\t\tQty");
            System.out.println("_____________________________________________________________________________");
            for( int i = 0; i < numberOfUniqueItems; i++){
                System.out.println(String.format("%-15s\t%-30s\t%-15s\t%s", item[i].getItemCode(), item[i].getItemName(), item[i].getItemRate(), item[i].getItemQuantity() ) );
            }
            System.out.println("_____________________________________________________________________________");
        }
    }
    
    /*
     Public function to print details of item (if it exists) whose code is entered by user.
     */
    public void printSpecificItemDetails(){
        if(numberOfUniqueItems == 0)
            System.out.println("No Items in Database!");
        else{
            int index;
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the code for item you want to see details.");
            tempCode = sc.nextLine();
            if( (index = doesCodeExist(tempCode)) == -1){
                System.out.println("No item with such code exists in database!");
            }
            else{
                System.out.println("Item Name: " + item[index].getItemName() );
                System.out.println("Item Code: " + item[index].getItemCode() );
                System.out.println("Item Rate: Rs. " + item[index].getItemRate() );
                System.out.println("Item Quantity: " + item[index].getItemQuantity() );
            }
        }
    }
    
    /*
     Public function to change rate of item (if it exists) whose code is entered by user.
     */
    public void changeItemRate(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the code for item you want to change rate.");
        tempCode = sc.nextLine();
        int itemIndex = doesCodeExist(tempCode);
        if(itemIndex == -1){
            System.out.println("Item Does Not Exist. Try Again!");
        }
        else{
            System.out.println( "Enter Rate per unit of item name: " + item[itemIndex].getItemName() + " having code: " + item[itemIndex].getItemCode() );
            System.out.println( "Current Rate is: Rs. " + item[itemIndex].getItemRate() );
            
            item[itemIndex].setItemRate();
        }
    }
    
    /*
     Public function to issue item (if it exists) whose code is entered by user.
     */
    public void issueItem(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the code for item you want to issue.");
        tempCode = sc.nextLine();
        int itemIndex = doesCodeExist(tempCode);
        if(itemIndex == -1){
            System.out.println("Item Does Not Exist. Can't be issued!");
        }
        else{
            long qtyToIssue;
            
            System.out.println( "Current stock of item name: " + item[itemIndex].getItemName() + ", having code: " + item[itemIndex].getItemCode()+ " is: \n\t" + item[itemIndex].getItemQuantity() );
            System.out.println("Enter the quantity for the above mentioned item you want to issue.");
            qtyToIssue = sc.nextLong();
            while(qtyToIssue < 0 || qtyToIssue > item[itemIndex].getItemQuantity() ){
                System.out.println("Incorrect Quantity Entered. Enter the quantity of stock to issue again.");
                qtyToIssue = sc.nextLong();
            }
            qtyToIssue = item[itemIndex].getItemQuantity() - qtyToIssue;
            item[itemIndex].setItemQuantity(qtyToIssue);
        }
    }
    
    /*
     Public function to receive item (if it exists) whose code is entered by user.
     */
    public void receiveItem(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the code for item you want to receive.");
        tempCode = sc.nextLine();
        int itemIndex = doesCodeExist(tempCode);
        if(itemIndex == -1){
            System.out.println("Item Does Not Exist. Please Create New Item First to receive additional stock!");
        }
        else{
            long qtyToReceive;
            
            System.out.println( "Current stock of item name: " + item[itemIndex].getItemName() + ", having code: " + item[itemIndex].getItemCode()+ " is: \n\t" + item[itemIndex].getItemQuantity() );
            System.out.println("Enter the quantity for the above mentioned item you received.");
            qtyToReceive = sc.nextLong();
            while(qtyToReceive<0){
                System.out.println("Incorrect Quantity Entered. Enter the quantity of stock received again.");
                qtyToReceive = sc.nextLong();
            }
            qtyToReceive += item[itemIndex].getItemQuantity();
            item[itemIndex].setItemQuantity(qtyToReceive);
        }
    }
    
    public void itemsCostingMore(){
        double cost;
        int num = 0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the cost you want to compare items with.");
        cost  = sc.nextDouble();
        if(numberOfUniqueItems == 0)
            System.out.println("No Items in Database!");
        else{
            System.out.println("Items having cost greater than or equal to : Rs. " + cost + "\n");
            System.out.println("Code\t\tName\t\t\t\tRate\t\tQty");
            System.out.println("_____________________________________________________________________________");
            for( int i = 0; i < numberOfUniqueItems; i++){
                if( item[i].getItemRate() < cost ){
                    continue;
                }
                else{
                    num ++;
                    System.out.println(String.format("%-15s\t%-30s\t%-15s\t%s", item[i].getItemCode(), item[i].getItemName(), item[i].getItemRate(), item[i].getItemQuantity() ) );
                }
            }
            System.out.println("_____________________________________________________________________________");
            System.out.println(num + " entry(ies) matched query.");
            System.out.println("_____________________________________________________________________________");
        }
        
    }
    
}
