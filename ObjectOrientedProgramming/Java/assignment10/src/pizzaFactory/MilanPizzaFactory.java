package pizzaFactory;

import pizzaFactory.ingredients.anchovy.Anchovy;
import pizzaFactory.ingredients.anchovy.FreshAnchovy;
import pizzaFactory.ingredients.cheese.BelPaeseCheese;
import pizzaFactory.ingredients.cheese.Cheese;
import pizzaFactory.ingredients.dough.Dough;
import pizzaFactory.ingredients.dough.PanTossedDough;
import pizzaFactory.ingredients.pepperoni.Pepperoni;
import pizzaFactory.ingredients.sauce.FreshTomatoSauce;
import pizzaFactory.ingredients.sauce.Sauce;
import pizzaFactory.ingredients.sausage.CookedSausage;
import pizzaFactory.ingredients.sausage.Sausage;
import pizzaFactory.ingredients.vegetables.*;

/**
 * Created by adityaagarwal on 09/04/16.
 */
public class MilanPizzaFactory implements AbstractPizzaFactory {

    public Dough createDough() {
        return new PanTossedDough();
    }

    public Sauce createSauce(){
        return new FreshTomatoSauce();
    }

    public Cheese createCheese(){
        return new BelPaeseCheese();
    }

    public Vegetables[] createVegetables(){
        Vegetables[] veggies = {  new Spinach(),
                                new Tomato(),
                                new BlackOlives(),
                                new Capsicum(),
                                new Mushroom()  };
        return veggies;
    }

    public Anchovy createAnchovy(){
        return new FreshAnchovy();
    }

    public Pepperoni createPepperoni(){
        return null;
    }

    @Override
    public Sausage createSausage() {
        return new CookedSausage();
    }
}
