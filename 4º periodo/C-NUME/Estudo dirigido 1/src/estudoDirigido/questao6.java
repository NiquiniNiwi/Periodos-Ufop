package estudoDirigido;
import java.util.Scanner;
import java.lang.*;


public class questao6 {
	public static void main(String[] args) {
		int n;
		Scanner ler = new Scanner(System.in);
		
		n = ler.nextInt();
		
		double maior = 0;
		double atual;
		int linhaMaior;
		double[][] A = new double[n][n];
		double[][] U = new double[n][n];
		double[][] L = new double[n][n];
		double[] auxTroca = new double[n];
		double[][] m = new double [n][n];
		
		for (int i = 0; i < n;i++) {
			for(int j = 0; j < n; j++) {
				A[i][j] = ler.nextDouble();
				U[i][j] = A[i][j];
			}
		}	
		for (int k = 0; k < n - 1; k++) {
			linhaMaior = k;
			maior = U[k][k];
			for(int r = k+1; r <= n-1;r++) {
				atual = U[r][k];
				if(maior < Math.abs(atual)) {
					maior = Math.abs(atual);
					linhaMaior = r;
				}
			}
			if(linhaMaior != k) {
				auxTroca = U[k];
				System.out.println(U[k][k]);
				U[k] = U[linhaMaior];
				System.out.println(U[k][k]);
				U[linhaMaior] = auxTroca;
			}
			for(int i = k+1; i <= n-1; i++) {
				m[i][k] = -(U[i][k]/U[k][k]);
				for(int j = k+1; j <= n-1; j++) {
					L[i][j-1] = m[i][k];
					U[i][j] = U[i][j] + (m[i][k]*U[k][j]);
				}
			}
		}
		System.out.println("A:");
		for (int i = 0; i < n;i++) {
			for(int j = 0; j < n; j++) {
				System.out.printf("%.4f	",A[i][j]);
			}
			System.out.println(" ");
		}
		System.out.println("L:");
		for (int i = 0; i < n;i++) {
			for(int j = 0; j < n; j++) {
				if(j == i) {
					L[i][j] =1;
				}
				else if(j > i) {
					L[i][j] = 0;
				}
				System.out.printf("%.4f	",L[i][j]);
			}
			System.out.println(" ");
		}
		System.out.println("U:");
		for (int i = 0; i < n;i++) {
			for(int j = 0; j < n; j++) {
				if(j < i) {
					U[i][j] = 0;
				}
				System.out.printf("%.4f	",U[i][j]);
			}
			System.out.println(" ");
		}
	}
}
