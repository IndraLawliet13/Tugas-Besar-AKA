import matplotlib.pyplot as plt

# Data
n_values = [10, 100, 1000, 10000, 20000]
iterative_times = [0.0000232260, 0.0005268220, 0.1252734200, 128.5021021040, 1096.8593017660]
recursive_times = [0.0000336720, 0.0005315700, 0.1254246880, 128.3378747990, 1093.4230650120]

# --- 1. Grafik Masing-Masing Algoritma ---

# Grafik Iteratif
plt.figure(figsize=(8, 5))
plt.plot(n_values, iterative_times, label='Iteratif', marker='o', linestyle='-', color='b')
plt.xlabel('Jumlah Suku (n)')
plt.ylabel('Waktu Eksekusi (detik)')
plt.title('Waktu Eksekusi Algoritma Iteratif')
plt.xscale('log')  # Skala logaritmik untuk sumbu x
plt.grid(True)
plt.show()
print()

# Grafik Rekursif
plt.figure(figsize=(8, 5))
plt.plot(n_values, recursive_times, label='Rekursif', marker='x', linestyle='--', color='r')
plt.xlabel('Jumlah Suku (n)')
plt.ylabel('Waktu Eksekusi (detik)')
plt.title('Waktu Eksekusi Algoritma Rekursif')
plt.xscale('log')  # Skala logaritmik untuk sumbu x
plt.grid(True)
plt.show()
print()

# --- 2. Grafik Perbandingan ---

plt.figure(figsize=(10, 6))
plt.plot(n_values, iterative_times, label='Iteratif', marker='o', linestyle='-', color='b')
plt.plot(n_values, recursive_times, label='Rekursif', marker='x', linestyle='--', color='r')
plt.xlabel('Jumlah Suku (n)')
plt.ylabel('Waktu Eksekusi (detik)')
plt.title('Perbandingan Waktu Eksekusi: Iteratif vs Rekursif')
plt.xscale('log')
plt.yscale('log') # Skala logaritmik untuk kedua sumbu
plt.legend()
plt.grid(True)
plt.show()
