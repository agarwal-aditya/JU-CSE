package pizzaFactory.pizzastore;

import pizzaFactory.pizza.Pizza;

import java.util.Scanner;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public abstract class PizzaStore  {



    public Pizza orderPizza(String type, int size){
        Pizza pizza;

        pizza = createPizza(type);

        pizza.prepare();
        pizza.bake();
        pizza.cut(size);
        pizza.box();

        return pizza;
    }

    abstract protected Pizza createPizza(String type);

    abstract public String selectPizza();

    public int selectSize(){
        Scanner sc = new Scanner(System.in);
        int i;
        System.out.println("\nSelect the size of your pizza :");
        System.out.println("\t< 1 >\tPersonal Pizza (serves 1)");
        System.out.println("\t< 2 >\tMedium Pizza (serves 2)");
        System.out.println("\t< 4 >\tFamily Pizza (serves 4)");

        i =  sc.nextInt();
        if(i != 1 && i != 2 && i != 4){
            System.out.println("Incorrect size chosen, defaulting to personal pizza.");
            i = 1;
        }
        return i;
    }

}
