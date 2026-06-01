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