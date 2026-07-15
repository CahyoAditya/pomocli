# ⏱️ PomoCLI

**PomoCLI** adalah aplikasi Pomodoro Timer minimalis berbasis command-line interface (CLI) yang ditulis menggunakan bahasa pemrograman C. Aplikasi ini dirancang agar sangat ringan dan mengintegrasikan notifikasi desktop bawaan sistem operasi (Linux & macOS) untuk membantu Anda tetap fokus dan produktif.

---

## ✨ Fitur Utama

- **Pomodoro Loop Otomatis**: Siklus terstruktur yang terdiri dari sesi Fokus, Istirahat Pendek (Rest), dan Istirahat Panjang (Long Rest).
- **Notifikasi Sistem Bawaan (OS-Native)**:
  - **Linux**: Menggunakan utilitas `notify-send`.
  - **macOS**: Menggunakan AppleScript (`osascript`) dengan suara notifikasi default.
- **Sangat Ringan**: Dibuat murni dengan bahasa C tanpa dependensi eksternal tambahan.

---

## ⚙️ Cara Kerja Siklus (Default)

Secara default, aplikasi dikonfigurasi dengan pengaturan berikut (dalam hitungan detik/menit tergantung pengali `mul`):
- **Focus Time**: 25 unit waktu.
- **Short Rest**: 5 unit waktu.
- **Long Rest**: 15 unit waktu.
- **Siklus Sesi**: Setiap **4 sesi Fokus**, Anda akan mendapatkan **1 sesi Istirahat Panjang**.

---

## 🛠️ Persyaratan Sistem

Sebelum menjalankan aplikasi, pastikan Anda memiliki:
1. **C Compiler**: `gcc` atau `clang`.
2. **Sistem Notifikasi**:
   - **Linux**: Pastikan paket `libnotify` (untuk `notify-send`) sudah terinstal (biasanya sudah ada di sebagian besar distro linux desktop).
   - **macOS**: Tidak memerlukan instalasi tambahan karena menggunakan utilitas bawaan `osascript`.

---

## 🚀 Instalasi & Penggunaan

### 1. Klon Repositori (atau masuk ke folder proyek)
```bash
cd /home/aditya/Documents/pomocli
```

### 2. Kompilasi Kode
Gunakan GCC untuk mengompilasi file [main.c](file:///home/aditya/Documents/pomocli/main.c) menjadi file eksekutabel:
```bash
gcc main.c -o pomocli
```

### 3. Jalankan Aplikasi
```bash
./pomocli
```

---

## 🔧 Kustomisasi Waktu
Jika Anda ingin mengubah durasi waktu fokus, istirahat, atau pengali waktu dari detik ke menit, Anda dapat mengedit baris kode berikut di [main.c](file:///home/aditya/Documents/pomocli/main.c#L24):

```c
int focus = 25, rest = 5, lrest = 15, mul = 1, fsesi = 4;
```

**Penjelasan Variabel:**
- `focus`: Durasi sesi fokus (default: `25`).
- `rest`: Durasi sesi istirahat pendek (default: `5`).
- `lrest`: Durasi sesi istirahat panjang (default: `15`).
- `mul`: Pengali waktu. Ubah `mul = 60` jika ingin mengonversi satuan waktu di atas menjadi **menit** (karena defaultnya adalah detik untuk kemudahan pengujian).
- `fsesi`: Jumlah sesi fokus sebelum memulai istirahat panjang (default: `4`).
