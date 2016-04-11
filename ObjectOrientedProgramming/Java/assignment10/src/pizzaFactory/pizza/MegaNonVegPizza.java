package pizzaFactory.pizza;

import pizzaFactory.AbstractPizzaFactory;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class MegaNonVegPizza extends Pizza {
    private AbstractPizzaFactory ingredientFactory;

    public MegaNonVegPizza(AbstractPizzaFactory factory){
        ingredientFactory = factory;
    }

    public void prepare(){
        System.out.println("Preparing " + name);
        dough = ingredientFactory.createDough();
        sauce = ingredientFactory.createSauce();
        cheese = ingredientFactory.createCheese();

        if(ingredientFactory.createAnchovy() != null)
            anchovy = ingredientFactory.createAnchovy();

        if(ingredientFactory.createPepperoni() != null)
            pepperoni = ingredientFactory.createPepperoni();

        if(ingredientFactory.createSausage() != null)
            sausage = ingredientFactory.createSausage();

    }
}
