package pizzaFactory.pizzastore;

import pizzaFactory.AbstractPizzaFactory;
import pizzaFactory.RomePizzaFactory;
import pizzaFactory.pizza.*;

import java.util.Scanner;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class RomePizzaStore extends PizzaStore {

    protected Pizza createPizza (String type){
        Pizza pizza = null;
        AbstractPizzaFactory factory = new RomePizzaFactory();

        if(type.equals("Cheese")){

            pizza = new CheesePizza(factory);
            pizza.setName("Rome Style Cheese Pizza");

        } else if(type.equals("Veg")){

            pizza = new VegPizza(factory);
            pizza.setName("Rome Style Veg Pizza");

        } else if(type.equals("Anchovy")){

            pizza = new AnchovyPizza(factory);
            pizza.setName("Rome Style Anchovy Pizza");

        } else if(type.equals("Pepperoni")){

            pizza = new PepperoniPizza(factory);
            pizza.setName("Rome Style Pepperoni Pizza");

        } else if (type.equals("Mega Non Veg Pizza")){

            pizza = new MegaNonVegPizza(factory);
            pizza.setName("Rome Style Mega-Non-Veg Pizza");

        }

        return pizza;

    }

    @Override
    public String selectPizza() {
        String choice = new String("null");
        Scanner sc = new Scanner(System.in);
        System.out.println("\tROME PIZZA STORE MENU :");
        System.out.println("\t< 1 >\tRome Style Cheese Pizza");
        System.out.println("\t< 2 >\tRome Style Veg Pizza");
        System.out.println("\t< 3 >\tRome Style Pepperoni Pizza");
        System.out.println("\t< 4 >\tRome Style Mega-Non-Veg Pizza");

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
            case 5:
                choice = new String("Anchovy");
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
