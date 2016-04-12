package pizzaFactory.ingredients.dough;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class PanTossedDough implements Dough {
    public PanTossedDough(){
        System.out.println("Preparing Pan-Tossed dough...");
    }

    public String toString(){
        return "Pan-tossed";
    }
}
