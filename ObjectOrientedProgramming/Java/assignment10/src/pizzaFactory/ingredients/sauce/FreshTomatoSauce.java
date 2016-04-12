package pizzaFactory.ingredients.sauce;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class FreshTomatoSauce implements Sauce  {
    public FreshTomatoSauce(){
        System.out.println("Adding fresh tomato sauce...");
    }

    public String toString(){
        return "Fresh tomato";
    }
}
