package pizzaFactory.pizza;

import pizzaFactory.ingredients.anchovy.Anchovy;
import pizzaFactory.ingredients.cheese.Cheese;
import pizzaFactory.ingredients.dough.Dough;
import pizzaFactory.ingredients.pepperoni.Pepperoni;
import pizzaFactory.ingredients.sauce.Sauce;
import pizzaFactory.ingredients.sausage.Sausage;
import pizzaFactory.ingredients.vegetables.Vegetables;

import java.util.HashMap;

/**
 * Created by adityaagarwal on 09/04/16.
 */
public abstract class Pizza {
    protected String name;
    protected Dough dough;
    protected Sauce sauce;
    protected Vegetables veggies[];
    protected Cheese cheese;
    protected Pepperoni pepperoni;
    protected Anchovy anchovy;
    protected Sausage sausage;
    protected int sizePizza;

    final static int PERSONAL_PIZZA = 1;
    final static int MEDIUM_PIZZA = 2;
    final static int FAMILY_PIZZA = 4;

    static private HashMap<Integer, String> sizeMap = new HashMap<Integer, String>();
    static {
        sizeMap.put(1, "Personal");
        sizeMap.put(2, "Medium");
        sizeMap.put(3, "Family");
    }

    public abstract void prepare();

    public void bake(){
        System.out.println("Bake for 14 minutes at 350 degF");
    }

    public void cut(int size){
        sizePizza = size;
        if(size == FAMILY_PIZZA)
            System.out.println("Cut the pizza into 8 diagonal slices.");
        else if(size == MEDIUM_PIZZA)
            System.out.println("Cut the pizza into 6 diagonal slices.");
        else if(size == PERSONAL_PIZZA)
            System.out.println("Cut the pizza into 4 diagonal slices.");
        else
            System.out.println("INVALID SIZE. THERE'S NO PIZZA OF SUCH A SIZE!!");
    }

    public void box(){
        System.out.println("Place the pizza in a KeepMyPizzaHotBox of appropriate size.");
    }

    public void setName(String nameEntered){
        name = nameEntered;
    }

    public String toString(){
        StringBuilder details = new StringBuilder(50);
        details.append("Name : " + name + "\n");
        details.append("Size : " + sizeMap.get(sizePizza) + "\n");
        details.append("Dough : " + dough + "\n");
        details.append("Sauce : " + sauce + "\n");
        details.append("Cheese : " + cheese + "\n");
        details.append("Toppings : \n\t");

        if(veggies != null)
            for (Vegetables veg: veggies) {
                details.append(veg + "\n\t");
            }
        if(pepperoni != null){
            details.append(pepperoni + "\n\t");
        }
        if(anchovy != null){
            details.append(anchovy + "\n\t");
        }
        if(sausage != null){
            details.append(sausage + "\n\t");
        }
        details.append("\n");

        return details.toString();
    }

}
