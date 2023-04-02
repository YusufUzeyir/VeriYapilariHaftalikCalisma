//211307012-Yusuf Üzeyir Kaya

#include<iostream>
using namespace std;

// Struct oluşturma
struct Node {
    Node* next;
    Node* prev;
    int data;

};

// Çift Bağlı Liste sınıfı
class ciftBagliListe {
private:
    Node* head;
public:
    ciftBagliListe() {
        head = NULL;
    }

    // Listenin başına düğüm ekleme
    void basaEkle(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
    }

    // Listenin sonuna düğüm ekleme
    void sonunaEkle(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next != NULL)
            last = last->next;
        last->next = newNode;
        newNode->prev = last;
    }

    // Listenin ortasına düğüm ekleme
    void  arayaEkle(int value, int key) {
        Node* newNode = new Node;
        newNode->data = value;
        Node* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << key << " bulunamadi." << endl;
            return;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Listenin başından düğüm silme
    void bastanSil() {
        if (head == NULL)
            return;
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        delete temp;
    }

    // Listenin sonundan düğüm silme
    void sondanSil() {
        if (head == NULL)
            return;
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        if (temp->prev != NULL)
            temp->prev->next = NULL;
        else
            head = NULL;
        delete temp;
    }

    // Listenin ortasından düğüm silme
    void aradanSil(int key) {
        Node* temp = head;
        while (temp != NULL && temp->data != key)
            temp = temp->next;
        if (temp == NULL) {
            cout << key << " bulunamadi." << endl;
            return;
        }
        if (temp->next == NULL) {
            cout << "Bu son dugum, sonrasi yok." << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        if (temp->next != NULL)
            temp->next->prev = temp;
        delete nodeToDelete;
    }

    // Listenin ileri yönündeki tüm düğümleri yazdırma
    void ileriYaz() {
        Node* temp = head;
        cout << "Ileri Yonde: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    // Listenin geri yönündeki tüm düğümleri yazdırma
    void geriYaz()
    {
        Node* temp = head;
        if (temp == NULL)
            return;
        while (temp->next != NULL)
            temp = temp->next;
        cout << "Geri Yonde: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};


// Test etme kısmı
int main() {
    ciftBagliListe dll;
    dll.basaEkle(10);
    dll.basaEkle(20);
    dll.basaEkle(30);
    cout << "Doubly Linked List: ";
    dll.ileriYaz();
    dll.sonunaEkle(40);
    dll.sonunaEkle(50);
    dll.sonunaEkle(60);
    cout << "Doubly Linked List: ";
    dll.ileriYaz();
    dll.arayaEkle(25, 20);
    cout << "Doubly Linked List: ";
    dll.ileriYaz();
    dll.bastanSil();
    dll.sondanSil();
    dll.aradanSil(20);
    cout << "Doubly Linked List: ";
    dll.ileriYaz();
    cout << endl;
    dll.geriYaz();
    return 0;
}


