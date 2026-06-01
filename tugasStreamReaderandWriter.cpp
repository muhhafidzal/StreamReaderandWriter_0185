#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class TokoElektronik 
{
private:
    array<string, 3> etalase;

public:
    TokoElektronik() 
    {
        etalase[0] = "Laptop Asus";
        etalase[1] = "Smartphone Samsung";
        etalase[2] = "Printer Epson";
    }

    string ambilProduk(size_t nomorRak) 
    {
        try 
        {
            return etalase.at(nomorRak);
        }
        catch (const out_of_range&) 
        {
            throw string
            (
                "Gagal Mengambil Barang : Rak nomor "
                + to_string(nomorRak)
                + " kosong atau tidak tersedia!"
            );
        }
    }
};

void bacaBarang() {
    ifstream file("gudang.txt");

    cout << "\n==== DAFTAR BARANG GUDANG ====\n";

    string barang;
    int no = 1;

    while (getline(file, barang)) 
    {
        cout << no++ << ". " << barang << endl;
    }

    if (no == 1) 
    {
        cout << "Gudang masih kosong.\n";
    }

    file.close();
}

void tambahBarang() 
{
    ofstream file("gudang.txt", ios::app);

    string barang;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Masukkan nama barang: ";
    getline(cin, barang);

    file << barang << endl;

    file.close();

    cout << "Barang berhasil ditambahkan!\n";
}

void updateBarang() 
{
    ifstream file("gudang.txt");

    vector<string> data;
    string barang;

    while (getline(file, barang)) 
    {
        data.push_back(barang);
    }

    file.close();

    if (data.empty()) 
    {
        cout << "Tidak ada data untuk diperbarui.\n";
        return;
    }

    bacaBarang();

    int nomor;
    cout << "Pilih nomor barang yang akan diubah: ";
    cin >> nomor;

    if (nomor < 1 || nomor > (int)data.size()) 
    {
        cout << "Nomor tidak valid!\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Masukkan nama barang baru: ";
    getline(cin, data[nomor - 1]);

    ofstream out("gudang.txt");

    for (string item : data) 
    {
        out << item << endl;
    }

    out.close();

    cout << "Data berhasil diperbarui!\n";
}

void hapusBarang() 
{
    ifstream file("gudang.txt");

    vector<string> data;
    string barang;

    while (getline(file, barang)) 
    {
        data.push_back(barang);
    }

    file.close();

    if (data.empty()) 
    {
        cout << "Tidak ada data untuk dihapus.\n";
        return;
    }

    bacaBarang();

    int nomor;
    cout << "Pilih nomor barang yang akan dihapus: ";
    cin >> nomor;

    if (nomor < 1 || nomor > (int)data.size()) 
    {
        cout << "Nomor tidak valid!\n";
        return;
    }

    data.erase(data.begin() + (nomor - 1));

    ofstream out("gudang.txt");

    for (string item : data) 
    {
        out << item << endl;
    }

    out.close();

    cout << "Data berhasil dihapus!\n";
}

void simulasiEtalase() 
{
    TokoElektronik toko;

    cout << "\n===== SIMULASI ETALASE =====\n";

    try 
    {
        cout << "\nSkenario 1 (Rak 1)\n";
        cout << "Barang: "
             << toko.ambilProduk(1)
             << endl;
    }
    catch (const string& pesan) 
    {
        cout << pesan << endl;
    }

    try 
    {
        cout << "\nSkenario 2 (Rak 5)\n";
        cout << "Barang: "
             << toko.ambilProduk(5)
             << endl;
    }
    catch (const string& pesan) {
        cout << pesan << endl;
    }
}
