#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
// 在此处补充你的代码
	int **p;
	int i,j;
	public:
		Array2(){
		}
		Array2(int x,int y){
			i=x;j=y;
			p=new int*[x];
			int k=0;
			for (;k<x;k++){
				p[k]=new int[y];
			}
		}
		int* operator[](int x){
			return p[x];
		}
		int operator()(int x,int y){
			return p[x][y];
		}
		Array2 & operator=(Array2 & a){
			i=a.i;
			j=a.j;
			p=new int*[i];
			int k=0;
			for (;k<i;k++){
				p[k]=new int[j]; 
			} 
			int l;
			for (k=0;k<i;k++)
			for (l=0;l<j;l++) p[k][l]=a[k][l];
			return *this;
		}
		~Array2(){
			int k=0;
			for (;k<i;k++) delete [] p[k];
			delete p;
		} 
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
