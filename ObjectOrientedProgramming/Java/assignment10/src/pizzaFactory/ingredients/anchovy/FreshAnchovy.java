package pizzaFactory.ingredients.anchovy;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class FreshAnchovy implements Anchovy {

    public FreshAnchovy(){
        System.out.println("Adding fresh anchovy...");
    }

    public String toString(){
        return "Fresh anchovy";
    }
}
