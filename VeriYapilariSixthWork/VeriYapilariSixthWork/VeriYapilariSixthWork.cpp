/*

1) Stack (yığın) veri yapısı, hangi mantığa göre çalışır, açıklayınız.

  Stack (yığın), verilerin son giren ilk çıkar (LIFO - last in first out) mantığına 
  göre işlem gördüğü bir veri yapısıdır.Bu yapıda, veriler yığının tepesine 
  eklenir ve çıkarılır. Yığın başlangıçta boştur ve her bir veri ekleme işlemi 
  yığının tepesine eklenir. Veri çıkarma işlemi ise yığının 
  tepesindeki veriyi çıkarır ve yığının boyutunu azaltır.
  Ayrıca, yığında bulunan en üstteki veriyi gösteren bir işaretçi bulunur. 
  Bu işaretçi, yığının hangi noktasında işlem yapılacağını gösterir.

2) Stack veri yapısı ile avantajlar ve dezavantajlar kısaca açıklayınız.

  Stack (yığın) veri yapısının avantajları şunlardır:

  Hızlı işlem: Stack, verilerin son giren ilk çıkar (LIFO) mantığına göre çalıştığından, veri çıkarma işlemi hızlıdır.
  Basit yapısı: Stack, basit ve anlaşılır bir veri yapısıdır. Push ve pop işlemleri dışında başka işlemler içermez.
  Bellek yönetimi: Programlama dillerinde işlemci kaydı ve çağrı yığını gibi bellek yönetimi işlemlerinde kullanılabilir.
  Geri alma işlemi: Stack, geri alma (undo) işlemleri gibi işlemler için kullanılabilir. Örneğin, metin editöründe geri alma işlemi yığın kullanılarak gerçekleştirilir.

  Stack veri yapısının dezavantajları şunlardır:

  Boyut sınırlaması: Yığının boyutu sınırlıdır. Eğer yığın kapasitesi dolarsa, yeni veriler yığına eklenemez.
  Dolu yığın: Yığın doluysa ve yeni bir veri eklenecekse, eski verileri çıkarmadan yapılacak ekleme işlemi, veri kaybına neden olabilir.
  Veri saklama: Yığın, sadece en üstteki veriyi saklar. Yığının diğer bölümlerindeki verilere erişmek için tüm verilerin çıkarılması gerekir.
  Bellek yönetimi: Bellek yönetimi, yanlış kullanıldığında veya yığın boyutu dikkatlice ayarlanmadığında sorunlara neden olabilir.

3) FIFO (First-In, First-Out), LIFO (Last-In, First-Out) kavramlarını açıklayınız.

  FIFO yöntemi, verilerin ilk giren ilk çıkar mantığına göre işlem görür. 
  Yani, veriler yığının altına eklenir ve yığının tepesinden çıkarılır.
  Örneğin, bir kuyrukta ilk giren kişi (ilk veri) ilk çıkar,
  son giren kişi (son veri) ise en son çıkar.

  LIFO yöntemi ise, verilerin son giren ilk çıkar mantığına göre işlem görür. 
  Yani, veriler yığının tepesine eklenir ve yığının tepesinden çıkarılır. 
  Örneğin, bir yığında son eklenen veri en üstte durur ve ilk çıkar.

 
*/

#include <iostream>
#define MAX_SIZE 100

using namespace std;

int stack[MAX_SIZE]; // Son Giren İlk Çıkar  mantığı ile çalışan dizi
int top = -1; // Yığının en üstündeki elemanın dizideki indisini gösteren değişken


void ekle(int value) {
        top++;
        stack[top] = value;
        cout << "Yigina ekle= " << value << endl;
        // Yığının ekleme yaptıktan sonra mevcut durumunu ekrana yazdırma kısmı
        cout << " Mevcut Yigin: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    
}


void cikar() {
        int removed = stack[top];
        top--;
        cout << "Yigindan sil= " << removed << endl;
        // Yığından çıkarma yaptıktan sonra mevcut durumunu ekrana yazdırma kısmı
        cout << " Mevcut Yigin: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
}

int main()
{
    ekle(5); 
    ekle(10); 
    ekle(15); 

    cikar(); 
    cikar(); 
    cikar(); 

    return 0;
}
