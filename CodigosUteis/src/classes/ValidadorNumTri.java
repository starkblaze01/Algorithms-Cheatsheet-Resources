package classes;

public class ValidadorNumTri {

	public static void start(int num) {

		int num1 = 1;
		int num2;

		System.out.println("Números multiplicados em série:");

		for (int i = 1; num1 < num; i++) {

			num2 = i+1;

			num1 *= num2;

			System.out.print(" | " + num2 + " | ");

			if (num1 == num) {
				System.out.println("\n" + num + " é um número triangular :)");
				break;
			}

		}

		if (num1 != num) {
			System.out.println("\n" + num + " não é um número triangular :(");
		}

	}

	//código para ver se determinado número inteiro é triangular
	// 24 = 1 X 2 X 3 X 4
	// 720 + 1 X 2 X 3 X 4 X 5 X 6



}
