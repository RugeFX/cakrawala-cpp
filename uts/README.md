# Tugas UTS Universitas Cakrawala
## Ahmad Zacky - Ilmu Komputer

## Mekanisme Program

Pengguna akan diminta untuk memilih layanan Go Ride, Go Food atau Go Send

### Jika Pengguna memilih layanan Go Ride

1. Pengguna menginputkan Jarak Tempuh dan Metode Pembayaran (GoPay/Cash)
2. Sebagai informasi tarif layanan ini adalah Rp 3500/km
3. Output yang diharapkan adalah Jarak Tempuh, Metode Pembayaran, dan Nominal Tagihan

### Jika Penggunan memilih layanan Go Food

1. Pengguna menginputkan Kategori Makanan (Nusantara/Barat), Jumlah pesanan (pcs) dan Metode Pembayaran (GoPay/Cash)
2. Sebagai informasi harga makanan Nusantara adalah Rp 100rb/pcs dan makanan Barat adalah Rp 150rb/pcs
3. Ongkos kirim flat Rp 25rb
4. Output yang diharapkan adalah Kategori Makanan, Jumlah Pesanan, Metode Pembayaran, dan Nominal Tagihan

### Jika Pengguna memilih layanan Go Send

1. Pengguna menginputkan Jarak Tempuh, Berat Barang, Volume Barang, dan Metode Pembayaran (GoPay/Cash)
2. Formula perhitungan tarif = Jarak Tempuh Berat Barang Volume Barang * 5000
3. Jika Volume Barang lebih dari 50 maka akan ada tambahan tarif flat sebesar Rp 25rb
4. Output yang diharapkan adalah Jarak Tempuh, Berat Barang, Volume Barang, Metode Pembayaran, dan Nominal Tagihan

### Catatan:

Karena sedang ada Promo Gopay

1. Jika Pelanggan pilih metode pembayaran Gopay maka akan ada diskon 20% dari total Nominal Tagihan
2. Jika Pelanggan pilih Cash harga normal