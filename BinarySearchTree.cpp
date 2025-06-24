#include <iostream>              // Mengimpor library untuk input/output standar
using namespace std;             // Menggunakan namespace std agar tidak perlu menulis std:: di depan fungsi/benda dari std

class Node                      // Mendefinisikan kelas Node untuk struktur data pohon biner
{
public:
    int info;                   // Menyimpan data/informasi pada node
    Node* leftchild;            // Pointer ke anak kiri (subtree kiri)
    Node* rightchild;           // Pointer ke anak kanan (subtree kanan)

    //constructor for Node class
    Node()                      
    {
        leftchild = nullptr;    // Inisialisasi anak kiri dengan nullptr (belum ada anak kiri)
        rightchild = nullptr;   // Inisialisasi anak kanan dengan nullptr (belum ada anak kanan)
    }
};

