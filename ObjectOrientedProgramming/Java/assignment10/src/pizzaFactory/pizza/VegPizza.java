package pizzaFactory.pizza;

import pizzaFactory.AbstractPizzaFactory;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class VegPizza extends Pizza {
    private AbstractPizzaFactory ingredientFactory;

    public VegPizza(AbstractPizzaFactory factory){
        ingredientFactory = factory;
    }

    public void prepare(){
        System.out.println("Preparing " + name);
        dough = ingredientFactory.createDough();
        sauce = ingredientFactory.createSauce();
        cheese = ingredientFactory.createCheese();
        veggies = ingredientFactory.createVegetables();
    }
}
