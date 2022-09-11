#include <stdio.h>
#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	HANDLE lib;
	double  (*tambah) (double, double),
			(*kurang) (double, double),
			(*kali) (double, double),
			(*bagi) (double, double);
	int (*bagi_integer) (int, int),
		(*sisabagi) (int, int);
	
	lib = LoadLibrary("aritmetika.dll");
	
	if (lib > (void*) HINSTANCE_ERROR) {
		tambah = (double(*) (double, double))
				GetProcAddress(lib, "tambah");
		kurang = (double(*) (double, double))
				GetProcAddress(lib, "kurang");
		kali = (double(*) (double, double))
				GetProcAddress(lib, "kali");
		bagi = (double(*) (double, double))
				GetProcAddress(lib, "bagi");
		bagi_integer = (int(*) (int, int))
				GetProcAddress(lib, "bagi_integer");
		sisabagi = (int(*) (int, int))
				GetProcAddress(lib, "sisabagi");
				
		double a = 10.25;
		double b = 0.25;
		int c = 20;
		int d = 3;
		
		printf("%.2lf + %.2lf = %.2lf\n", a, b, tambah (a, b));
		printf("%.2lf - %.2lf = %.2lf\n", a, b, kurang (a, b));
		printf("%.2lf * %.2lf = %.2lf\n", a, b, kali (a, b));
		printf("%.2lf / %.2lf = %.2lf\n", a, b, bagi (a, b));	
		printf("%d / %d = %d\n", c, d, bagi_integer (c, d));	
		printf("%d %% %d = %d\n", c, d, sisabagi (c, d));		
	} 	else {
		printf("\"aritmetika.dll\" gagal diakses.");
	}
	return 0;
}
