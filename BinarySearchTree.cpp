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

        //step 3: make the leftchild and rightchild of the new node point to nullptr
        newNode->leftchild = nullptr; // Anak kiri node baru diinisialisasi ke nullptr
        newNode->rightchild = nullptr; // Anak kanan node baru diinisialisasi ke nullptr

        //step 4: locate the node which will be the parent of the new node
        Node* parent = nullptr; // Inisialisasi parent sebagai nullptr
        Node* currentNode = nullptr;
        search(x, parent, currentNode); // Mencari posisi yang tepat untuk node baru

        //step 5: if parent is nullptr, the tree is empty
        if (parent == nullptr) 
        {
            root = newNode; // step 5a: Jika pohon kosong, node baru menjadi root

            // step 5b: exit
            return;
        } 

        //step 6: if the value of the new node is less than the value of the parent node
        if (x < parent->info) 
        {
            parent->leftchild = newNode; // step 6a: Node baru menjadi anak kiri dari parent

            // step 6b: exit
            return;
        } 
        //step 7: if the value of the new node is greater than or equal to the value of the parent node
        else if (x >= parent->info)
        {
            parent->rightchild = newNode; // step 7a: Node baru menjadi anak kanan dari parent

            // step 7b: exit
            return;
        }
    }

    void search(int element, Node*& parent, Node*& currentNode) 
    {
        // Fungsi untuk mencari posisi yang tepat untuk node baru
        currentNode = root; // Mulai pencarian dari root
        parent = nullptr; // Inisialisasi parent sebagai nullptr

        // Loop untuk mencari posisi yang tepat untuk node baru
        while((currentNode != nullptr) && (currentNode->info != element)) 
        {
            parent = currentNode; // Set parent ke currentNode
            if (element < currentNode->info) 
                currentNode = currentNode->leftchild; // Pindah ke subtree kiri
            else 
                currentNode = currentNode->rightchild; // Pindah ke subtree kanan
            
        }
    }

    void inorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty." << endl; // Jika pohon kosong, tampilkan pesan
            return; // Keluar dari fungsi
        }

        if (ptr == nullptr) // Jika pointer tidak null
            return;


        inorder(ptr->leftchild); // Kunjungi subtree kiri
        cout << ptr->info << " "; // Tampilkan nilai node saat ini
        inorder(ptr->rightchild); // Kunjungi subtree kanan
    }

    void preorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is empty." << endl; // Jika pohon kosong, tampilkan pesan
            return; // Keluar dari fungsi
        }

        if (ptr == nullptr) // Jika pointer tidak null
            return;


        cout << ptr->info << " "; // Tampilkan nilai node saat ini
        preorder(ptr->leftchild); // Kunjungi subtree kiri
        preorder(ptr->rightchild); // Kunjungi subtree kanan
    }

