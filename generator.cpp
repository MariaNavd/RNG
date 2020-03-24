#include <iostream>
#include <cmath>
#include <fstream>

const int N = 1000;

double disp(double arr[], int size, double e) {
	double dis = 0;
	for (int i = 0; i < size; i++) {
		dis += (arr[i] - e) * (arr[i] - e);
	}
	return dis / size;
}

double xi(int arr[], int size) {
	double xi = 0;
	for (int i = 0; i < size; i++) {
		xi = xi + (arr[i] - 0.1 * N) * (arr[i] - 0.1 * N) / (0.1 * N);
	}
	return xi;
}

int main(void) {
	using namespace std;
	double num[N];
	int k, q, n, x0, x, p[10] = { 0 };
	double r0, r, sum = 0, e, d, sigma, xi_2 = 0;
	cout << "Enter r0: ";
	cin >> r0;
	x0 = (int)r0;
	cout << "Enter q: ";
	cin >> q;
	k = 5 + 8 * q;
	cout << "Enter n: ";
	cin >> n;

	ofstream  out;
	out.open("gist.txt");
	for (int i = 0; i < N; i++) {
		x = int(k * x0) % int(pow(2, n));
		cout << x;
		r = double(x) / pow(2, n);
		num[i] = r;
		sum += r;
		out << i +1 << ": " << r << endl;
		for (int j = 0; j < 10; j++) {
			if (r >= 0.1 * j  && r < 0.1 * (j + 1)) {
				p[j]++;
			}
			else if (r == 1)
				p[9]++;
		}
		x0 = x;
	}
	out.close();

	out.open("gg.txt");
	for (int i = 0; i < 10; i++) {
		cout << p[i] << endl;
		out << p[i] << endl;
	}

	cout << endl;
	e = sum / N;
	cout << "E = " << e << endl;
	d = disp(num, N, e);
	cout << "D = " << d << endl;
	sigma = sqrt(d);
	cout << "sigma = " << sigma << endl;
	xi_2 = xi(p, 10);
	cout << "x^2 = " << xi_2 << endl;
	return 0;
}