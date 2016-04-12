package pizzaFactory.pizza;

import pizzaFactory.AbstractPizzaFactory;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class PepperoniPizza extends Pizza  {
    private AbstractPizzaFactory ingredientFactory;

    public PepperoniPizza(AbstractPizzaFactory factory){
        ingredientFactory = factory;
    }

    public void prepare(){
        System.out.println("Preparing " + name);
        dough = ingredientFactory.createDough();
        sauce = ingredientFactory.createSauce();
        cheese = ingredientFactory.createCheese();
        pepperoni = ingredientFactory.createPepperoni();
    }
}
