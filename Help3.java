class Help {
	    public static void main (String args[]) 
		          throws java.io.IOException {
		
		char choice,ignore;
		
    		for(;;) {

		do {
			System.out.println("Справочная система");
			System.out.println(" 1. if");
			System.out.println(" 2. switch");
			System.out.println(" 3. for");
      			System.out.println(" 4. while");
			System.out.println(" 5. do-while");
      			System.out.println(" 6. break");
      			System.out.println(" 7. continue\n");
			System.out.println("q - выход из программы");
      			System.out.println("выберите подраздел: ");
			
			choice = (char) System.in.read();
				do {
					ignore = (char) System.in.read();
				}  while (ignore != '\n');
			} while (choice < '1' | choice > '5' & choice != 'q');
			
			if(choice == 'q') break;

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
				case '3':
					System.out.println("Цикл for:\n ");
            				System.out.println("for(инициализация; условие; интерация");
            				System.out.println("операторы");
					break;
				case '4':
					System.out.println("цикл whule:\n ");
         				System.out.println("while(условие) операторы; ");
					break;
				case '5':
					System.out.println("цикл do-while:\n");
          				System.out.println("do {");
          				System.out.println("операторы; ");
					System.out.println("} while(условие); ");
          				break;
        			case '6':
					System.out.println("Инструкция break:\n ");
          				System.out.println("break; или break метка; ");
          				break;
        			case '7':
					System.out.println("инструкция continue:\n ");
          				System.out.println("continue; или continue метка; ");
					break;
			}
      		System.out.println();
      }
   }		
}
