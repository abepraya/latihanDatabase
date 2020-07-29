#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Mahasiswa{
    public:
        string nama;
        string nim;
        string jurusan;

        Mahasiswa(string nama,string nim,string jurusan){
            Mahasiswa::nama = nama;
            Mahasiswa::nim = nim;
            Mahasiswa::jurusan = jurusan;
        }

        //method ini dipakai agar class Database dapat menyimpan objek/data
        //pakai string karena method di atas memakai tipe data string semua
        string allString(){
            return nama + " " + nim + " " + jurusan;
        }

};

class Database{
    public:
        ifstream in; //untuk membaca
        ofstream out; //untuk menulis
        string fileName;

        Database(const char* filename){
            Database::fileName = filename;
        }
        //method untuk menyimpan objek
        void save(Mahasiswa data){
            cout<<data.nama<<endl;
            cout<<data.nim<<endl;
            cout<<data.jurusan<<endl;

            Database::out.open(Database::fileName,ios::app); //akses untuk menyimpan data ke bentuk txt
            //cout << data.allString(); 
            Database::out << data.allString();
            Database::out.close();
        }

        //method untuk menampilkan objek yang telah dibuat
        void showAll(){
            Database::in.open(Database::fileName,ios::in);//akses untuk membuka isi objek
            string nama,nim,jurusan;
            int index = 1;

            //eof = end of file
            while (!Database::in.eof()){
                Database::in >> nama;
                Database::in >> nim;
                Database::in >> jurusan;
                cout << index++<<".";
                cout << nama<<"\t";
                cout << nim <<"\t";
                cout << jurusan <<endl;

                /*atau cara yang lebih ringkas dan rapih
                cout<<index++<<". "<<nama<<" "<<nim<<" "<<jurusan<<endl;
                */
            }
            Database::in.close();
        }
};


int main(int argc, const char** argv) {
    Database db = Database("data.txt");
    db.showAll();

    //user input
    string nama,nim,jurusan;
    cout <<"Masukan Data Mahasiswa !\n";
    cout << "Nama: "; 
    cin >> nama;
    cout <<"NIM: ";
    cin >> nim;
    cout << "Jurusan: ";
    cin >> jurusan;

    //objek-objek yang diperlukan
    Mahasiswa m1 = Mahasiswa(nama,nim,jurusan);

    //simulasi
    // Mahasiswa m1 = Mahasiswa("Argi","22591","S1 SI");
    // Database db = Database("data.txt");

    //save data ke database
    db.save(m1);
    //menampilkan data dari database
    db.showAll();
    return 0;
}