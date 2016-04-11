package pizzaFactory.pizzastore;

import pizzaFactory.AbstractPizzaFactory;
import pizzaFactory.MilanPizzaFactory;
import pizzaFactory.pizza.*;

import java.util.Scanner;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class MilanPizzaStore extends PizzaStore {

    protected Pizza createPizza (String type){
        Pizza pizza = null;
        AbstractPizzaFactory factory = new MilanPizzaFactory();

        if(type.equals("Cheese")){

            pizza = new CheesePizza(factory);
            pizza.setName("Milan Style Cheese Pizza");

        } else if(type.equals("Veg")){

            pizza = new VegPizza(factory);
            pizza.setName("Milan Style Veg Pizza");

        } else if(type.equals("Anchovy")){

            pizza = new AnchovyPizza(factory);
            pizza.setName("Milan Style Anchovy Pizza");

        } else if (type.equals("Mega Non Veg Pizza")){

            pizza = new MegaNonVegPizza(factory);
            pizza.setName("Milan Style Mega-Non-Veg Pizza");

        }

        return pizza;

    }

    @Override
    public String selectPizza() {
        String choice = new String("null");
        Scanner sc = new Scanner(System.in);
        System.out.println("\tMILAN PIZZA STORE MENU :");
        System.out.println("\t< 1 >\tMilan Style Cheese Pizza");
        System.out.println("\t< 2 >\tMilan Style Veg Pizza");
        System.out.println("\t< 3 >\tMilan Style Anchovy Pizza");
        System.out.println("\t< 4 >\tMilan Style Mega-Non-Veg Pizza");

        System.out.print("Enter your choice : \t");
        int i =  sc.nextInt();

        switch (i){
            case 1:
                choice = new String("Cheese");
                break;
            case 2:
                choice = new String("Veg");
                break;
            case 3:
                choice = new String("Anchovy");
                break;
            case 4:
                choice = new String("Mega Non Veg Pizza");
                break;
            default:
                System.out.println("ERROR! INCORRECT OPTION CHOSEN!");
        }

        return choice;
    }
}
