package pizzaFactory;

import pizzaFactory.ingredients.anchovy.Anchovy;
import pizzaFactory.ingredients.anchovy.VinegarMarinadedAnchovy;
import pizzaFactory.ingredients.cheese.Cheese;
import pizzaFactory.ingredients.cheese.ParmigianoCheese;
import pizzaFactory.ingredients.dough.Dough;
import pizzaFactory.ingredients.dough.ThinCrustDough;
import pizzaFactory.ingredients.pepperoni.Pepperoni;
import pizzaFactory.ingredients.pepperoni.SlicedPepperoni;
import pizzaFactory.ingredients.sauce.ArrabiataSauce;
import pizzaFactory.ingredients.sauce.Sauce;
import pizzaFactory.ingredients.sausage.FreshSmokedSausage;
import pizzaFactory.ingredients.sausage.Sausage;
import pizzaFactory.ingredients.vegetables.*;

/**
 * Created by adityaagarwal on 09/04/16.
 */
public class RomePizzaFactory implements AbstractPizzaFactory{

    public Dough createDough(){
        return new ThinCrustDough();
    }

    public Sauce createSauce(){
        return new ArrabiataSauce();
    }

    public Cheese createCheese(){
        return new ParmigianoCheese();
    }

    public Vegetables[] createVegetables(){
        Vegetables[] veggies = {  new Onion(),
                                new Tomato(),
                                new BlackOlives(),
                                new Capsicum(),
                                new EggPlant(),
                                new Garlic()  };
        return veggies;
    }

    public Anchovy createAnchovy(){
        return new VinegarMarinadedAnchovy();
    }

    public Pepperoni createPepperoni(){
        return new SlicedPepperoni();
    }

    @Override
    public Sausage createSausage() {
        return new FreshSmokedSausage();
    }
}
