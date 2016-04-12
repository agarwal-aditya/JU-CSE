package pizzaFactory.ingredients.sauce;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class MarinaraSauce implements Sauce {
    public MarinaraSauce(){
        System.out.println("Adding Marinara sauce...");
    }

    public String toString(){
        return "Marinara";
    }
}
