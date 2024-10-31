namespace go_food
{
    const double HARGA_NUSANTARA = 100000.0, HARGA_BARAT = 150000.0, ONGKIR = 25000.0;

    void proses();
}

namespace go_ride
{
    const double TARIF_PER_KM = 3500.0;

    void proses();
}

namespace go_send
{
    const double TARIF = 5000.0, TARIF_TAMBAHAN = 25000.0;

    void proses();
}

namespace pembayaran
{
    const double DISKON_GOPAY = 0.2;

    struct HasilPembayaran;

    HasilPembayaran proses(double nominal);
}