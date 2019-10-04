package classes;

public class Fibonacci {
	
	
	
	public static void start(int num) {
		
		int x =1;
		int y = 1;
		
		System.out.println("Sequência Fibonacci com " + num + " elementos:");
		
		for (int i = 0; i <= num; i++) {
			
			x = y - x ;
			
			y = x + y;
			
			System.out.print(x + " ");	
			
		}
		
		
	}
	
	

}
