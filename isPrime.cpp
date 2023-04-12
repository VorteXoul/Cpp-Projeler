#include <iostream>
#include <cmath>
#include <ctime>
bool hatabulma(long long int *ptrnum){          // Try catch ile hata bulma fonksiyonu yazdım
    try
    {
        if(*ptrnum<0){
            std::cout << ">> The data you entered is negative!.." << std::endl;
            throw 1;
        }
    }
    catch(int){
        return true;
    }
    return false;
}
int main(){
    bool hatasayac;                  // hata sayacı yukarıdan gelen deger icin 
    long long int num,result,i;               //girilecek sayi ve bolunce cikan sayi icin / i ise for döngüsü için 
    long int loop;
    while(true){
        bool ciftsayi=0,asalsayac=0;                         // eger cift sayiysa donguden cikmak icin / asalsayi mi degil mi sorgusu icin
        loop=0;                        //dongu sayisini hesaplamak icin                     
        std::cout<< "Enter the positive number (0 = Exit) :   ";
        std::cin >> num;
        if(!std::cin.good()){                       // girilen sayi long long int turunden mi kontrolu 
            std::cin.clear();
            std::cin.sync();
            std::cout <<">> The data you entered is invalid!.." << std::endl;
            continue;
        }
        if( num == 1 ){                                         // eger sayi 1 ise 
            std::cout << ">> 1 is not considered as a prime/composite number." <<std::endl;
            continue;
        }else if( num == 2 ){                                 //eger sayi 2 ise
            std::cout << ">> 2 is the only even number in prime numbers."<< std::endl;
            continue;
        }else if( num == 0 ){                                      //eger sayi 0 ise
            break;
        }
        hatasayac=hatabulma(&num);
        if( hatasayac == true ){                           // Gelen hata sayisi
            continue;
        }
        std::clock_t start;                             //sure baslangici
        start = std::clock();
        if(( num % 2 )==0){                            // sayı cift mi kontrolu 
            i =2 ;
            loop++;
            asalsayac=1;
            ciftsayi=1;         
        }else{                                          // eger sayi cift degilse 
            long long int sqrtnum=std::sqrt(num);
            for( i=1; i<=sqrtnum; i=i+2){               // donguye basliyor
                loop++;
                if(i==1) continue;

                if((num % i)==0){                       // Eger asal sayiysa dongu biter 
                    asalsayac=1;
                    break;
                }
            }
        }
            if( asalsayac == 1 ){                           // asal degilse
            result=num/i;                           
            std::cout <<">> " <<  num << " Composite | (" << i << " * " << result << ") | Loop : " << loop << " | Time : " <<(( std::clock() - start )) / (double) (CLOCKS_PER_SEC) << " s" << std::endl;
        }
            else if( asalsayac == 0 ){                      //asalsa 
            std::cout <<">> " << num << " Prime | (1 * " << num << ") | Loop : " << loop << " | Time " << (( std::clock() - start )) / (double) (CLOCKS_PER_SEC)<< " s" <<  std::endl;
        }
    }
}