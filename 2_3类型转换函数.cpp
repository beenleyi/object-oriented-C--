#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
	Complex(char str[]){
		int k=0,j=0;
		char buf[65];
		while (str[k]!='+') {
			buf[j++]=str[k];
			k++;
		}
		buf[j]='\0';
		k++;
		j=0;
		r=atof(buf);
		while (str[k]!='i'){
			buf[j++]=str[k];k++;
		}
		buf[j]='\0';i=atof(buf);
		//printf("%lf %lf",r,i);
	}
	Complex(){
		r=0;i=0;
	};
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
