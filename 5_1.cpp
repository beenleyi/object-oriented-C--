#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
	char * p;
    public:
	MyString(){
		p=NULL;
	}
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;
	}
	MyString(const MyString & s){
		if( s.p) {
			p = new char[strlen(s.p) + 1];
			strcpy(p,s.p);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }
	MyString & operator=(const MyString & s) {
		if (s.p!=p){
			if (p) delete [] p;
			if (s.p) {
				p = new char[strlen(s.p)+1];
				strcpy(p,s.p);
			}
			else p=NULL;
		}
		return *this;
	}
    MyString & operator=(const char * s){
		if (p!=s){
			if (p) delete [] p;
			if (s) {
				p = new char[strlen(s) + 1];
				strcpy(p,s);
			}
			else p=NULL;
		}
		return *this;
	}
    friend ostream & operator<<(ostream & o, const MyString &s){
		if (s.p) o << s.p;
    	return o;
	}
    MyString(MyString & s){
		p = new char[strlen(s.p)+1];
		strcpy(p,s.p);
		
	}
    //����MyString+MyString
    MyString operator+(const MyString & s) const{
        MyString tmp(p);
		strcat(tmp.p,s.p);
        return tmp;
    }
    //����MyString[]
    char & operator[](int n) const{
        return p[n];
    }
    //����MyString+s
    MyString operator+(const char * p){
        MyString tmp1(p);
        return *this+tmp1;
    }
    //����MyString+=
    MyString & operator+=(const char * s){
        *this=*this+s;
        return *this;
    }
    //����s+MyString
    friend MyString operator+(const char * p, MyString & s){
        MyString tmp(p);
        return tmp+s;
    }
    //����()
    MyString operator()(int n,int m){
        MyString tmp(*this);
        int i=0;
        while (i<m){
        	tmp.p[i]=tmp.p[i+n];
        	i++;
		}
		tmp.p[i]='\0';
		return tmp;
    }
    int compare(const MyString & s ){
    	char *stmp=s.p,*tmp=p;int f;
    	while (stmp && tmp){
    		f=strcmp(tmp,stmp);
    		if (f==-1) return -1;//С�� 
    		else if (f==1) return 1;//���� 
    		stmp++;tmp++;
		}
		return 0;
	}
	int operator<(const MyString &s){
		if (this->compare(s)==-1) return 1;
		else return 0;	
	} 
	int operator==(const MyString &s){
		if (this->compare(s)==0) return 1;
		else return 0;	
	}	
	int operator>(const MyString &s){
		if (this->compare(s)==1) return 1;
		else return 0;	
	}
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1�Ĵ��±�0��ʼ����Ϊ4���Ӵ�
	cout << s1(0,4) << endl;
	//s1�Ĵ��±�5��ʼ����Ϊ10���Ӵ�
	cout << s1(5,10) << endl;
	return 0;
}
