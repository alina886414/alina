class  Avto {
	int kpass;
	int vfuel;
	double rash;
	String type;

	void range() {
		System.out.println("Автомобиль проедет " + vfuel/rash*100 + "km. на полном баке");

	}
}
class Obj1 {
	public static void main(String args[]) {
		Avto nissan = new Avto();
		Avto ford = new Avto();
		Avto bmw =  new Avto();
		nissan.kpass = 7;
		ford.kpass = 5;
		bmw.kpass = 2;
		nissan.type = "минивэн" ;
	        ford.type = "седан";
	        bmw.type = "кабриолет";
		nissan.vfuel = 50;
		ford.vfuel = 40;
		bmw.vfuel = 20;
		nissan.rash = 12.5;
		ford.rash = 10.2;
		bmw.rash = 18.5;
		System.out.println("Информация об автомобиле \"Ниссан\"");
		System.out.println("Колличество пассажиров: " + nissan.kpass);
		System.out.println("емкость топлива бака: " + nissan.vfuel);
		System.out.println("Тип кузова" + nissan.type);
		nissan.range();
	}
}
