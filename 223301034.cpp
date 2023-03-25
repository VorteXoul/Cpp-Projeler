#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
int main(){
	double num1,num2,result;
	char process,x;				// Değişkenleri tanımladık
	bool esc=true;
	while(esc==true){
		cout << "Enter the calculate process(If you want exit,press ESC) : ";
		x=getch();																	//Esc çıktısı bekleniyor eger esc basılmazsa program devam ediyor
		if((char)x==27){
			esc=false;
			break;
		}
		cin >> num1 >> process >> num2;		//Hesaplanmak istenen işlem giriliyor
		if (!cin.good()){
			cin.clear();						//Eğer alınan değer ile tanımlanan değişken türü birbiri türünden değilse program başa dönüyor
			cin.sync();
			cout << "Invalid value" << endl;
			continue;
		}
		switch(process){					// Hangi işlemi yapacağını sorgulatıp işlemi yapıyoruz
			case '+':
				result =num1 + num2;
				break;
			case '-':
				result= num1-num2;
				break;
			case '*':
				result= num1*num2;
				break;
			case '/':
				if (num2==0){
					cout << "A number cannot be divided by 0 Try again...\n";
					continue;
				}
				else{
					result= num1 / num2;
					break;
				}
			case '%':
				result =fmod(num1,num2);
				break;
			default:
				cout << "Invalid value"<<endl;
				continue;
		}
		cout << "-Result-"<< endl;
		cout << num1 << process << num2 << "=" << result << endl;		// Sonucu yazdırıyoruz
	}
}
