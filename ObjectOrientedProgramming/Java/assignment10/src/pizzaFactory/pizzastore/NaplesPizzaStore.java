package pizzaFactory.pizzastore;

import pizzaFactory.AbstractPizzaFactory;
import pizzaFactory.NaplesPizzaFactory;
import pizzaFactory.pizza.*;

import java.util.Scanner;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class NaplesPizzaStore extends PizzaStore {

    protected Pizza createPizza (String type){
        Pizza pizza = null;
        AbstractPizzaFactory factory = new NaplesPizzaFactory();

        if(type.equals("Cheese")){

            pizza = new CheesePizza(factory);
            pizza.setName("Naples Style Cheese Pizza");

        } else if(type.equals("Veg")){

            pizza = new VegPizza(factory);
            pizza.setName("Naples Style Veg Pizza");

        } else if(type.equals("Pepperoni")){

            pizza = new PepperoniPizza(factory);
            pizza.setName("Naples Style Pepperoni Pizza");

        } else if (type.equals("Mega Non Veg Pizza")){

            pizza = new MegaNonVegPizza(factory);
            pizza.setName("Naples Style Mega-Non-Veg Pizza");

        }

        return pizza;

    }

    @Override
    public String selectPizza() {
        String choice = new String("null");
        Scanner sc = new Scanner(System.in);
        System.out.println("\tNAPLES PIZZA STORE MENU :");
        System.out.println("\t< 1 >\tNaples Style Cheese Pizza");
        System.out.println("\t< 2 >\tNaples Style Veg Pizza");
        System.out.println("\t< 3 >\tNaples Style Pepperoni Pizza");
        System.out.println("\t< 4 >\tNaples Style Mega-Non-Veg Pizza");

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
                choice = new String("Pepperoni");
                break;
            case 4:
                choice = new String("Mega Non Veg Pizza");
                break;
            default:
                System.out.println("ERROR! INCORRECT OPTION CHOSEN!");
        }

        if(choice == null ){
            System.out.println("lolololol");
        }
        return choice;
    }
}
