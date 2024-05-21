class Help {
	public static void main (String args[]) 
		throws java.io.IOException {
		
		char choice;

		System.out.println("Справочная система");
		System.out.println(" 1. if");
		System.out.println(" 2. switch");
		System.out.println("выберите подраздел: ");
		choice = (char) System.in.read();

		System.out.println("\n");
	
		switch (choice) {
			case '1':
				System.out.println("Operator if:\n");
				System.out.println("if(условие)операторы; ");
				System.out.println("else операторы");
				break;
			case '2':
				System.out.println("Operator switch:\n");
                                System.out.println("switch(условие) { ");
                                System.out.println("	case constanta");
				System.out.println("	последовательность операторов");
                                System.out.println("	break; ");
                                System.out.println("  ...");
                                System.out.println(" } ");
				break;
			default:
				System.out.print("неверный номер подраздела");
		}

	} 

}
