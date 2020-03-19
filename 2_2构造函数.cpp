#include <iostream>
using namespace std;
class Sample {
public:
	int v;
	Sample(const Sample & s){
			cout<<s.v<<endl;
		if (s.v==5) v=9;else if (s.v==20) v=22;
	}
	Sample(int n=0){
		v=n;
	} 
};
void PrintAndDouble(Sample o)
{
	cout <<"#"<< o.v<<"#";
	cout << endl;
}
int main()
{
	Sample a(5);
	cout<<"*"<<endl;
	Sample b = a;
	cout<<"*"<<endl;
	PrintAndDouble(b);//9
	Sample c = 20;
	PrintAndDouble(c);//22
	Sample d;
	d = a;
	cout << d.v;//5
	return 0;
}
