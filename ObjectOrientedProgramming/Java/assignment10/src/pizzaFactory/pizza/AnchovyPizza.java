package pizzaFactory.pizza;

import pizzaFactory.AbstractPizzaFactory;

/**
 * Created by adityaagarwal on 10/04/16.
 */
public class AnchovyPizza extends Pizza {
    private AbstractPizzaFactory ingredientFactory;

    public AnchovyPizza(AbstractPizzaFactory factory){
        ingredientFactory = factory;
    }

    public void prepare(){
        System.out.println("Preparing " + name);
        dough = ingredientFactory.createDough();
        sauce = ingredientFactory.createSauce();
        cheese = ingredientFactory.createCheese();
        anchovy = ingredientFactory.createAnchovy();
    }

}
