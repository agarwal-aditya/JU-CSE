package pizzaFactory;

import pizzaFactory.pizzastore.MilanPizzaStore;
import pizzaFactory.pizzastore.NaplesPizzaStore;
import pizzaFactory.pizzastore.PizzaStore;
import pizzaFactory.pizzastore.RomePizzaStore;

import java.util.Scanner;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class Main {

    public static PizzaStore choosePizzaStore(){
        Scanner sc = new Scanner(System.in);
        System.out.println("\tOPTIONS");
        System.out.println("Choose Pizza Store : ");
        System.out.println("\t< 1 >\tMilan Pizza Store");
        System.out.println("\t< 2 >\tNaples Pizza Store");
        System.out.println("\t< 3 >\tRome Pizza Store");

        System.out.print("Enter your choice : \t");
        int i =  sc.nextInt();

        switch (i){
            case 1:
                return new MilanPizzaStore();
            case 2:
                return new NaplesPizzaStore();
            case 3:
                return new RomePizzaStore();
            default:
                System.out.println("ERROR! INCORRECT OPTION CHOSEN. TRY AGAIN!");
        }
        return null;
    }


    public static void main(String[] args) {

        PizzaStore myStore = choosePizzaStore();
        System.out.println( "\nOrder details:\n------------------\n" +
                myStore.orderPizza( myStore.selectPizza(), myStore.selectSize() ) );
        System.out.println("");
        System.out.println("Enjoy your pizza! :-)");
    }
}
