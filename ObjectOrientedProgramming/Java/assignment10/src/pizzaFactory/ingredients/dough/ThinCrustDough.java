package pizzaFactory.ingredients.dough;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class ThinCrustDough implements Dough {
    public ThinCrustDough(){
        System.out.println("Tossing thin crust dough...");
    }

    public String toString(){
        return "Thin crust";
    }
}
