import java.util.*;

class Tea {
    private int name;
    private char size;
    private int ice;
    private int topping;

    Tea(int name, char size, int ice, int topping) {
        this.name = name;
        this.size = size;
        this.ice = ice;
        this.topping = topping;
    }

    public String getName() {
        if (this.name == 0) {
            return "Milk Tea";
        }
        if (this.name == 1) {
            return "Fruit Tea";
        }
        return "Nah";
    }

    public char getSize() {
        return this.size;
    }

    public String getIce() {
        if (this.ice == 0) {
            return "no";
        }
        if (this.ice == 1) {
            return "half";
        }
        if (this.ice == 2) {
            return "regular";
        }
        return "Nah";
    }

    public String getTopping() {
        if (this.topping == 0) {
            return "no";
        }
        if (this.topping == 1) {
            return "fruit";
        }
        if (this.topping == 2) {
            return "bubble";
        }
        return "Nah";
    }

    public int calcCost() {
        int cost = 0;
        if (this.name == 0) {
            if (this.size == 's') {
                cost += 40;
            } else if (this.size == 'm') {
                cost += 50;
            } else if (this.size == 'l') {
                cost += 60;
            }
        }
        if (this.name == 1) {
            if (this.size == 's') {
                cost += 60;
            } else if (this.size == 'm') {
                cost += 80;
            } else if (this.size == 'l') {
                cost += 90;
            }
        }
        if (this.topping == 1) {
            cost += 10;
        } else if (this.topping == 2) {
            cost += 20;
        }
        return cost;
    }

    String orderDescription() {
        return "Name: " + getName() + " Size: " + getSize() + " Ice: " + getIce() + " Topping: " + getTopping()
                + " Cost: " + calcCost();
    }
}

public class WishTea {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Please input your order:");
        System.out.print("Number of orders:");
        ArrayList<Tea> orders = new ArrayList<Tea>();
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.print("Drink(0 for milk tea, 1 for fruit tea):");
            int name = sc.nextInt();
            System.out.print("Size(l, m, s):");
            char size = sc.next().charAt(0);
            System.out.print("Ice(0 for free, 1 for half, 2 for regular):");
            int ice = sc.nextInt();
            System.out.print("Topping(0 for none, 1 for bubble, 2 for fruit):");
            int topping = sc.nextInt();
            orders.add(new Tea(name, size, ice, topping));
        }
        sc.close();
        orders.forEach((order) -> {
            System.out.println(order.orderDescription());
        });
    }
}