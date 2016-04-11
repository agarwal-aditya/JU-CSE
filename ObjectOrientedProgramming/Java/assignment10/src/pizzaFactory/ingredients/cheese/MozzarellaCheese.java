package pizzaFactory.ingredients.cheese;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class MozzarellaCheese implements Cheese  {
    public MozzarellaCheese(){
        System.out.println("Adding Mozzarella cheese...");
    }

    public String toString(){
        return "Mozzarella ";
    }
}
