import java.util.Scanner;

public class Questao2 {
	public static void main(String[] args) {
		int tamanho;
		String metodo;
		Scanner ler = new Scanner(System.in);
		
		System.out.println("Selecione o metodo: S para substitutivo e R para retroativo");
		
		metodo = ler.next();
		//System.out.println(metodo.compareTo("S"));
		if(0 != metodo.compareTo("S") && 0 != metodo.compareTo("R")) {
			System.out.println("Entrada invalida, tente novamente");
		}
		else {
			System.out.println("Quantas linhas/iconitas existem no sistema ?");
			
			tamanho = ler.nextInt();
			
			double[] variaveis = new double[tamanho];
			double[] resultados = new double[tamanho];
			double[][] multiplicadores = new double[tamanho][];
			int []quantidadeMultiplicadores = new int[tamanho];
			
			if(0 == metodo.compareTo("S")) {
				for (int i = 0; i < tamanho; i++) {
					multiplicadores[i] = new double[i+1];
					quantidadeMultiplicadores[i] = i+1;
				}
				for (int i = 0; i < tamanho;i++) {
					for(int j = 0; j < quantidadeMultiplicadores[i]; j++) {
						System.out.println("Digite o valor do multiplicadores " + i + " " + j);
						multiplicadores[i][j] = ler.nextDouble();
					}
					System.out.println("Digite o resultado " + i);
					resultados[i] = ler.nextDouble();
				}
				for (int i = 0; i < tamanho ;i++) {
					variaveis[i] = resultados[i];
					for(int j = 0; j <= i - 1 ; j++) {
						if(i != 0) {
							variaveis[i] -= (variaveis[j] * multiplicadores[i][j]);
						}
					}
					variaveis[i] = variaveis[i] / multiplicadores[i][i];
				}
			}
			else if(0 == metodo.compareTo("R")) {
				for (int i = tamanho-1; i >= 0; i--) {
					multiplicadores[i] = new double[i+1];
					quantidadeMultiplicadores[i] = i+1; 
				}
				for (int i = tamanho -1; i >= 0; i--) {
					for(int j = quantidadeMultiplicadores[i]-1; j >= 0; j--) {
						System.out.println("Digite o valor do multiplicadores " + i + " " + j);
						multiplicadores[i][j] = ler.nextDouble();
					}
					System.out.println("Digite o resultado " + i);
					resultados[i] = ler.nextDouble();
				}

				for (int i = 0; i < tamanho; i++) {
					variaveis[i] = resultados[i];
					for(int j = quantidadeMultiplicadores[i]-1; j >= 0; j--) {
						if(j != quantidadeMultiplicadores[i]-1) {
							variaveis[i] -= (variaveis[j] * multiplicadores[i][j]);
						}
					}
					variaveis[i] = variaveis[i] / multiplicadores[i][i];
				}
			}
			for(int i = 0; i < tamanho; i++) {
				System.out.println("variavel " + i + " vale : " + variaveis[i]);
			}	
		}
	}
}
			