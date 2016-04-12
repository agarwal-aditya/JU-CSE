package pizzaFactory;

import pizzaFactory.ingredients.anchovy.Anchovy;
import pizzaFactory.ingredients.cheese.Cheese;
import pizzaFactory.ingredients.dough.Dough;
import pizzaFactory.ingredients.pepperoni.Pepperoni;
import pizzaFactory.ingredients.sauce.Sauce;
import pizzaFactory.ingredients.sausage.Sausage;
import pizzaFactory.ingredients.vegetables.Vegetables;

/**
 * Created by adityaagarwal on 09/04/16.
 */
public interface AbstractPizzaFactory {

    public Dough createDough();
    public Sauce createSauce();
    public Cheese createCheese();
    public Vegetables[] createVegetables();
    public Anchovy createAnchovy();
    public Pepperoni createPepperoni();
    public Sausage createSausage();

}

