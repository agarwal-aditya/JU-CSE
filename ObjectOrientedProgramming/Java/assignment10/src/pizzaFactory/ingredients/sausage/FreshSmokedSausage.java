package pizzaFactory.ingredients.sausage;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class FreshSmokedSausage implements Sausage {
    public FreshSmokedSausage(){
        System.out.println("Adding fresh smoked sausage...");
    }

    public String toString(){
        return "Fresh smoked sausage ";
    }
}
