
#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <gmpxx.h> // Untuk presisi tinggi

using namespace std;
using namespace chrono;

// Fungsi faktorial (diperlukan untuk menghitung penyebut)
mpz_class factorial(int n) {
    mpz_class fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Algo A: Iteratif
mpf_class sin_iteratif(double x, int n) {
    mpf_set_default_prec(256); // Set presisi (sesuaikan sesuai kebutuhan)
    mpf_class x_mpf(x);
    mpf_class hasil = 0;
    for (int i = 0; i < n; i++) {
        mpf_class tanda = (i % 2 == 0) ? 1 : -1;
        mpf_class pembilang;
        mpf_pow_ui(pembilang.get_mpf_t(), x_mpf.get_mpf_t(), 2 * i + 1);
        mpz_class penyebut = factorial(2 * i + 1);
        hasil += tanda * (pembilang / penyebut);
    }
    return hasil;
}

// Algo B: Rekursif
mpf_class sin_rekursif(double x, int n) {
    mpf_set_default_prec(256);
    mpf_class x_mpf(x);
    if (n == 0) {
        return x_mpf;
    } else {
        mpf_class tanda = (n % 2 == 0) ? 1 : -1;
        mpf_class pembilang;
        mpf_pow_ui(pembilang.get_mpf_t(), x_mpf.get_mpf_t(), 2 * n + 1);
        mpz_class penyebut = factorial(2 * n + 1);
        return tanda * (pembilang / penyebut) + sin_rekursif(x, n - 1);
    }
}

// Fungsi untuk mengukur running time
double ukur_running_time(mpf_class (*fungsi)(double, int), double x, int n) {
    auto start_time = high_resolution_clock::now();
    fungsi(x, n);
    auto end_time = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(end_time - start_time);
    return time_span.count();
}

int main() {
    double x = M_PI / 4; // Contoh: x = pi/4
    int n_values[] = {10, 100, 1000, 10000, 20000}; // Jumlah suku yang akan diuji
    int num_n_values = sizeof(n_values) / sizeof(n_values[0]);

    cout << "Hasil perhitungan sin(x) (Iteratif vs Rekursif):" << endl;
    cout << fixed << setprecision(10);
    for (int i = 0; i < num_n_values; i++) {
        int n = n_values[i];
        mpf_class hasil_iteratif = sin_iteratif(x, n);
        mpf_class hasil_rekursif = sin_rekursif(x, n);
        cout << "n = " << n << ": Iteratif = " << hasil_iteratif << ", Rekursif = " << hasil_rekursif << endl;
    }

    cout << "\nRunning Time (Iteratif vs Rekursif):" << endl;
    for (int i = 0; i < num_n_values; i++) {
        int n = n_values[i];
        double waktu_iteratif = ukur_running_time(sin_iteratif, x, n);
        double waktu_rekursif = ukur_running_time(sin_rekursif, x, n);
        cout << "n = " << n << ": Iteratif = " << waktu_iteratif << " detik, Rekursif = " << waktu_rekursif << " detik" << endl;
    }

    return 0;
}
