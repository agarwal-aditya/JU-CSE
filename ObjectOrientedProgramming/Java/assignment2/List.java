package assignment2;

import java.util.*;
import java.io.*;

public class List{
    
    private static void printOptions(){
        System.out.print("\nOptions available:\n");
        System.out.print("\t0 : Exit.\n");
        System.out.print("\t1 : Add New Item.\n");
        System.out.print("\t2 : Issue item based on unique Item Code.\n");
        System.out.print("\t3 : Receive item based on unique Item Code.\n");
        System.out.print("\t5 : View Details of an item based on unique Item Code.\n");
        System.out.print("\t6 : Print Details of all Items in databse.\n");
        System.out.print("\t7 : Change Rate of an item based on unique Item Code.\n");
        System.out.print("\t8 : Find items having cost greater than a user input amount.\n");
        System.out.print("\t9 : Display Options Menu again.\n");

    }
    
    public static void main(String args[]){
        int switchCase;
        boolean flag = true;
        ItemList list = new ItemList();
        Scanner scanInput = new Scanner(System.in);
        printOptions();
        while(flag){
            System.out.print("\nChoose from the given options :\t");
            switchCase = scanInput.nextInt();
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
                case 7:
                    list.changeItemRate();
                    break;
                case 8:
                    list.itemsCostingMore();
                    break;
                case 9:
                    printOptions();
                    break;
                default:
                    System.out.print("Invalid value entered. Bye!\n");
                    flag = false;
                    break;
                    
            }
        }
    }
}