#include<iostream>
#include<windows.h>
using namespace std;

int main() {
	HINSTANCE lib;
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
		
		cout << a << " + " << b << " = " << tambah (a, b) << endl;
		cout << a << " - " << b << " = " << kurang (a, b) << endl;
		cout << a << " * " << b << " = " << kali (a, b) << endl;
		cout << a << " / " << b << " = " << bagi (a, b) << endl;
		cout << a << " / " << b << " = " << bagi_integer (c, d) << endl;
		cout << a << " % " << b << " = " << sisabagi (c, d) << endl;
	} else {
		cout << "\"aritmetika.dll\" gagal diakses.";
	}
	return 0;
}
