#include <iostream>
class Yakit{
  double mesafe;
  double yakit;
   public:
     Yakit(): mesafe(0),yakit(0){}                  //Deger girilmezse
     Yakit(double mesafe){                         //Eger sadece mesafe degeri girilirse
        this->mesafe = mesafe;
        this->yakit = 0;
     }
     Yakit(double mesafe,double yakit){             // Eger mesafe ve yakit degeri girilirse
        this->mesafe = mesafe;
        this->yakit = yakit;
     }
     Yakit operator+(Yakit &ptr){                     //mesafeleri ve yakıtlari topluyorum
         double mesafe = this->mesafe + ptr.mesafe;
         double yakit = this->yakit + ptr.yakit;
        return Yakit(mesafe,yakit);                   
     }
     Yakit operator =(Yakit ptr) {                   
         this->mesafe =ptr.mesafe;    
         this->yakit =ptr.yakit;         
         return Yakit(this->mesafe,this->yakit);
      }
     friend void printMasraf(Yakit *ptr){                                // Yazdirma Fonksiyonu
        std::cout << ">> " << ptr->mesafe  << " km icin yakilan yakit : " << Masraf(ptr) << " litre " <<  std::endl;
    }
    friend double Masraf(Yakit *ptr);
};
double Masraf(Yakit *ptr){                   
   double yakit = (ptr->mesafe * 7)/200 ;                   //Ilk basta yakiti buluyorum   
   yakit = (yakit * 115)/100 + (yakit*90)/100;            // Ruzgarli ve ruzgarsiz yakacak yakiti bulup topladim
   return (yakit);
}

int main(){
   Yakit a(1000,2000),b(2000),c(3000),d;
   a = b + c;
   printMasraf(&a);
   d = a + c;
   printMasraf(&d);
   std::cout << ">> Kullanilan Yakit : " << Masraf(&d);
}
