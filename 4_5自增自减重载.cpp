#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
    char s[210];
	char ans[210];
    public:
    CHugeInt(char * str){
        strcpy(s,str);
    }
    CHugeInt(int n){
        sprintf(s,"%d",n);//从int转成string	
    }
    CHugeInt(){
	}
	friend CHugeInt & addint(CHugeInt & a, int b){
        int i=0;
		for (;i<210;i++) a.ans[i]='0'; 
        int la=strlen(a.s);
        char *s;
        s=new char[210];
        sprintf(s,"%d",b);
        int lb=strlen(s);
        int max=la>lb?la:lb;//有可能会最前面的空多一位0，当没有进位的时候，后面在输出的时候处理
        a.ans[max+1]='\0';
        int temp;
        while(la&&lb){
        	temp=a.ans[max];//注意必须将ans[max]暂存，因为后面改了值之后还需要再次用
            a.ans[max]=(temp-48+a.s[la-1]-48+s[lb-1]-48)%10+48;
            a.ans[max-1]=(temp-48+a.s[la-1]-48+s[lb-1]-48)/10+48;
            la--;lb--;max--;
        }
		if (la) 
            while(la) {
            	temp=a.ans[max];
                a.ans[max]=(a.s[la-1]-48-48+temp)%10+48;
                a.ans[max-1]=(a.s[la-1]-48-48+temp)/10+48;
                max--;
                la--;
            }
        else if (lb) while(lb) {
        		temp=a.ans[max];
           	    a.ans[max]=(s[lb-1]+temp-48-48)%10+48;
                a.ans[max-1]=(s[lb-1]+temp-48-48)/10+48;
                max--;lb--;
        }
    //处理可能多出的0 
	i=0;	
	if (a.ans[0]=='0'){ while (a.ans[i+1]!='\0') {a.ans[i]=a.ans[i+1];i++;}
	a.ans[i]='\0';}
	return a;
    }
    CHugeInt & operator+(CHugeInt & b){
		int n=atoi(b.s);
        return addint(*this,n);
    }
	friend CHugeInt &operator+(int n, CHugeInt & a){
        return addint(a, n);
    }
	CHugeInt & operator+(int n){
        return addint(*this,n);
    }
	CHugeInt & operator+=(int n){
        addint(*this,n);
        strcpy(s,ans);
        return *this;
    }
	CHugeInt & operator++(){
        addint (*this,1);
        strcpy(s,ans);
        return *this;
    }
	CHugeInt operator++(int ){
		CHugeInt tmp(s);
        addint (*this,1);
		strcpy(tmp.ans,tmp.s);
        strncpy(this->s,this->ans,210);
        return tmp;
    }
    friend ostream & operator<<(ostream & o, const CHugeInt & a){
        printf("%s",a.ans);
    	return o;
	}
};
int  main() 
{ 
	char s[210];
	int n;
	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);
		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
		cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
