abstract class Shop {
    private String name;
    private double price;
    private double birthdayDiscount = 0.15;
    private double cardDiscount = 0.1;

    public Shop(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    public double calculateDiscount(boolean isBirthday, boolean hasCard) {
        double discount = 0;
        if (isBirthday) {
            discount += birthdayDiscount;
        }
        if (hasCard) {
            discount += cardDiscount;
        }
        return price * (1 - discount);
    }
}

class Lipstick extends Shop {
    public Lipstick() {
        super("Помада", 1000);
    }

    
    public double calculateDiscount(boolean isBirthday, boolean hasCard) {
        return super.calculateDiscount(isBirthday, hasCard);
    }
}

class FaceCream extends Shop {
    public FaceCream() {
        super("Крем для лица", 890);
    }

    
    public double calculateDiscount(boolean isBirthday, boolean hasCard) {
        return super.calculateDiscount(isBirthday, hasCard);
    }
}

class Perfume extends Shop {
    public Perfume() {
        super("Духи", 4860);
    }

    
    public double calculateDiscount(boolean isBirthday, boolean hasCard) {
        return super.calculateDiscount(isBirthday, hasCard);
    }
}

public class Shop1 {
    public static void main(String[] args) {
        Shop lipstick = new Lipstick();
        Shop faceCream = new FaceCream();
        Shop perfume = new Perfume();

        int birthday = 15;
        boolean hasCard = true;

        System.out.println("С учетом всех скидок:");
        System.out.println(lipstick.getName() + ": " + lipstick.calculateDiscount(birthday == 15, hasCard) + " рублей");
        System.out.println(faceCream.getName() + ": " + faceCream.calculateDiscount(birthday == 15, hasCard) + " рублей");
        System.out.println(perfume.getName() + ": " + perfume.calculateDiscount(birthday == 15, hasCard) + " рублей");
    }
}

