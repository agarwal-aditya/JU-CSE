package pizzaFactory.ingredients.sausage;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class CookedSausage implements Sausage {
    public CookedSausage(){
        System.out.println("Adding cooked sausage...");
    }

    public String toString(){
        return "Cooked sausage";
    }
}
