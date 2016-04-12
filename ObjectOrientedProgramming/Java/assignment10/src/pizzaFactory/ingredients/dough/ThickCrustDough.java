package pizzaFactory.ingredients.dough;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class ThickCrustDough implements Dough {
    public ThickCrustDough(){
        System.out.println("Tossing thick crust dough...");
    }

    public String toString(){
        return "Thick crust";
    }
}
