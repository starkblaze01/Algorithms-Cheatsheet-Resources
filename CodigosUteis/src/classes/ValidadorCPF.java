package classes;

public class ValidadorCPF {

	private static int[] cpfVetor = new int[11];

	public static void start(String cpf) {

		String msgErro = "O CPF " + cpf + " é inválido";
		String msgSucesso = "O CPF " + cpf + " é válido";

		if (validadorCPF(cpf)) {

			passarParaVetor(cpf);

			if (verificarPrimeiroDigito() && verificarSegundoDigito()) {

				System.out.println(msgSucesso);

			} else {

				System.out.println(msgErro);

			}

		} else {

			System.out.println(msgErro);

		}
	}

	private static boolean validadorCPF(String cpf) {

		if (!(cpf.length() == 11)) {

			return false;

		} else {

			return true;

		}
	}

	private static void passarParaVetor(String cpf) {

		int inicio = 0;
		int fim = 1;

		for (int i = 0; i < cpfVetor.length; i++) {

			cpfVetor[i] = Integer.parseInt((String) cpf.substring(inicio, fim));

			++inicio;
			++fim;
		}

	}

	private static boolean verificarSegundoDigito() {

		int[] cpfPeso = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2 };

		int soma = 0;
		int valor;

		for (int i = 0; i < cpfVetor.length - 1; i++) {

			valor = cpfVetor[i];

			valor *= cpfPeso[i];

			soma += valor;

		}

		soma %= 11;

		soma = 11 - soma;

		if (soma == cpfVetor[10]) {
			return true;
		} else {
			return false;
		}

	}

	private static boolean verificarPrimeiroDigito() {

		int[] cpfPeso = { 10, 9, 8, 7, 6, 5, 4, 3, 2 };

		int soma = 0;
		int valor;

		for (int i = 0; i < cpfVetor.length - 2; i++) {

			valor = cpfVetor[i];

			valor *= cpfPeso[i];

			soma += valor;

		}

		soma %= 11;

		soma = 11 - soma;

		if (soma == cpfVetor[9]) {

			return true;

		} else {

			return false;
		}

	}

}