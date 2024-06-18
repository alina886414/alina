abstract class Shop {
    private String name;
    private double price;

 Shop (String name, double price) {
        this.name = name;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public abstract double calculateDiscount();
}

class Lipstick extends Shop {
    public Lipstick() {
        super("Помада", 1000);
    }
    public double calculateDiscount(boolean isBirthday, boolean hasCard) {
        double discount = 0;
    if (isBirthday) {
        discount += birthdayDiscount;
    }
    if (hasCard) {
        discount += cardDiscount;
    }
    return price - (price * discount);
    }
}
    
    public double calculateDiscount() {
        return getPrice() * 0.15;
    }
}

class FaceCream extends Shop {
    public FaceCream() {
        super("Крем для лица", 890);
    }
    public double calculateDiscount(boolean isBirthday, boolean hasCard) {
        double discount = 0;
    if (isBirthday) {
        discount += birthdayDiscount;
    }
    if (hasCard) {
        discount += cardDiscount;
    }
    return price - (price * discount);
    }
}
   
    public double calculateDiscount() {
        return getPrice() * 0.15;
    }
}

class Perfume extends Shop {
    public Perfume() {
        super("Духи", 4860);
    }
    public double calculateDiscount(boolean isBirthday, boolean hasCard) {
        double discount = 0;
    if (isBirthday) {
        discount += birthdayDiscount;
    }
    if (hasCard) {
        discount += cardDiscount;
    }
    return price - (price * discount);
    }
}
    
    public double calculateDiscount() {
        return getPrice() * 0.15;
    }
}

public class Shop1 {
    public static void main(String[] args) {
        Shop lipstick = new Lipstick();
        Shop faceCream = new FaceCream();
        Shop perfume = new Perfume();

        System.out.println("Помада:");
        System.out.println("Цена: " + lipstick.getPrice() + " руб.");
        System.out.println("Скидка 15%: " + lipstick.calculateDiscount() + " руб.");

        System.out.println("\nКрем для лица:");
        System.out.println("Цена: " + faceCream.getPrice() + " руб.");
        System.out.println("Скидка 15%: " + faceCream.calculateDiscount() + " руб.");

        System.out.println("\nДухи:");
        System.out.println("Цена: " + perfume.getPrice() + " руб.");
        System.out.println("Скидка 15%: " + perfume.calculateDiscount() + " руб.");
    }
}
