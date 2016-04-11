package pizzaFactory;

import pizzaFactory.ingredients.anchovy.Anchovy;
import pizzaFactory.ingredients.cheese.Cheese;
import pizzaFactory.ingredients.cheese.MozzarellaCheese;
import pizzaFactory.ingredients.dough.Dough;
import pizzaFactory.ingredients.dough.ThickCrustDough;
import pizzaFactory.ingredients.pepperoni.Pepperoni;
import pizzaFactory.ingredients.pepperoni.SlicedPepperoni;
import pizzaFactory.ingredients.sauce.MarinaraSauce;
import pizzaFactory.ingredients.sauce.Sauce;
import pizzaFactory.ingredients.sausage.FreshSmokedSausage;
import pizzaFactory.ingredients.sausage.Sausage;
import pizzaFactory.ingredients.vegetables.*;


public class NaplesPizzaFactory implements AbstractPizzaFactory {

    public Dough createDough() {
        return new ThickCrustDough();
    }

    public Sauce createSauce(){
        return new MarinaraSauce();
    }

    public Cheese createCheese(){
        return new MozzarellaCheese();
    }

    public Vegetables[] createVegetables(){
        Vegetables[] veggies = {  new Jalapeno(),
                new Tomato(),
                new Onion(),
                new Capsicum()  };
        return veggies;
    }

    public Anchovy createAnchovy(){
        return null;
    }

    public Pepperoni createPepperoni(){
        return new SlicedPepperoni();
    }

    @Override
    public Sausage createSausage() {
        return new FreshSmokedSausage();
    }
}
