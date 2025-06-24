#include "lib/ktp.cpp"

int main() {
    int jumlah;
    cout << "Berapa banyak KTP yang ingin dibuat? ";
    cin >> jumlah;
    clearInputBuffer();

    vector<KTP> dataKTP(jumlah);
    string dataArray[100][5]; // Tambahan array 2 dimensi

    for (int i = 0; i < jumlah; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        inputKTP(dataKTP[i]);

        stringstream ss;
		ss << dataKTP[i].nik;
		dataArray[i][0] = ss.str();
        dataArray[i][1] = dataKTP[i].nama;
        dataArray[i][2] = dataKTP[i].jenis_kelamin ? "Laki-laki" : "Perempuan";
        dataArray[i][3] = dataKTP[i].alamat;
        dataArray[i][4] = dataKTP[i].pekerjaan;
    }

    cout << "\n=== Semua Data KTP ===\n";
    tampilkanSemuaKTPRekursif(dataKTP);

    char edit;
    cout << "\nApakah Anda ingin mengedit data? (y/n): ";
    cin >> edit;
    clearInputBuffer();

    while (edit == 'y' || edit == 'Y') {
        int indeks;
        cout << "Masukkan nomor KTP yang ingin diedit (1 - " << jumlah << "): ";
        cin >> indeks;
        clearInputBuffer();

        if (indeks >= 1 && indeks <= jumlah) {
            editKTP(dataKTP[indeks - 1]);
            displayKTP(dataKTP[indeks - 1], indeks - 1);
        } else {
            cout << "Nomor tidak valid.\n";
        }

        cout << "\nApakah Anda ingin mengedit data lagi? (y/n): ";
        cin >> edit;
        clearInputBuffer();
    }

    simpanDataKeFile(dataKTP);

    char cari;
    cout << "\nApakah Anda ingin mencari dan menampilkan data tertentu? (y/n): ";
    cin >> cari;
    clearInputBuffer();

    while (cari == 'y' || cari == 'Y') {
        cariKTP(dataKTP);
        cout << "\nIngin mencari data lain? (y/n): ";
        cin >> cari;
        clearInputBuffer();
    }

    // Tampilkan ringkasan dari array 2D
    tampilkanRingkasanArray(dataArray, jumlah);

    cout << "\nTerima kasih.\n";
    return 0;

