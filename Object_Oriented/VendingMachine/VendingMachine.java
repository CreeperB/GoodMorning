import java.util.ArrayList;

public class VendingMachine{
    /*
        A: Coca Cola, unit price US $1.65
        B: Minute Maid Orange Juice, unit price US $3.50
        C: Evian Mineral Water, unit price US $2.80
        D: M&M's Chocolate, unit price US $1.50
        E: Hershey's Chocolate Bar, unit price US $1.85
        F: Oreo Cookies, unit price US $1.00
        G: Doritos Tortilla Chips, unit price US $3.25
        H: Pringles Potato Chips, unit price US $3.40
     */
    protected ArrayList<Product> shoppingCart;
    public final static Product COCA_COLA = new Product("Coca Cola", 1.65);
    public final static Product ORANGE_JUICE = new Product("Minute Maid Orange Juice", 3.50);
    public final static Product EVIAN_MINERAL_WATER = new Product("Evian Mineral Water", 2.80);
    public final static Product MMS_CHOCOLATE = new Product("M&M's Chocolate", 1.50);
    public final static Product HERSHEY_CHOCOLATE_BAR = new Product("Hershey's Chocolate Bar", 1.85);
    public final static Product OREO_COOKIES = new Product("Oreo Cookies", 1.00);
    public final static Product DORITOS_TORTILLA_CHIPS = new Product("Doritos Tortilla Chips", 3.25);
    public final static Product PRINGLES_POTATO_CHIPS = new Product("Pringles Potato Chips", 3.40);
    

    public VendingMachine(){
        shoppingCart = new ArrayList<Product>();
    }

    public void select(Product product){
        shoppingCart.add(product);
    }

    public void show(){
        System.out.println("Shopping Cart:");
        for(Product item: shoppingCart){
            System.out.println(item.getProdcutName());
        }
    }

    public static class Product{
        protected String productName;
        protected double price;
        public Product(String name, double price){
            this.productName = name;
            this.price = price;
        }

        public String getProdcutName(){
            return productName;
        }
        public double getPrice(){
            return price;
        }
    }

    public double getTotalPrice(){
        double totalPrice = 0;
        for(Product item: shoppingCart){
            totalPrice += item.getPrice();
        }
        return totalPrice;
    }
}