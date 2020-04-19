#include <iostream>
using namespace std;
class MyCin
{
	public:
	int v;
	MyCin & operator>>(int & n){
		if (!int(*this)) {
			v=-1;
			return *this;
		}
		cin>>n;
		v=n;
		return *this;
	}
	operator int(){
		if (v==-1) return 0;else return 1;
	}
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}
