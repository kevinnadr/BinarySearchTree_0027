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


class BinarySearchTree 
{
public:
    Node* root;

    //constructor for BinarySearchTree class
    BinarySearchTree()
    {
        root = nullptr; //inisialisasi root dengan nullptr (pohon kosong)
    }

   void insert()
   {
        int x;
        cout << "Masukkan Nilai: ";
        cin >> x; // Mengambil input nilai dari pengguna

        //step 1: Allocate memory for new node
        Node* newNode = new Node(); // Membuat node baru

        //step 2: Assign value to the data field of the new node
        newNode->info = x; // Menetapkan nilai yang dimasukkan ke dalam node baru
