#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
	private:
		char name[25];
		int age,num,grade[4];
		double gpa;
	public: 
		void input(){
			char c=getchar();
			int i=0;
			while(c!=','&&c!=EOF){
				name[i++]=c;
				c=getchar();
			}
			name[i]='\0';
			scanf("%d,%d,%d,%d,%d,%d",&age,&num,&grade[0],&grade[1],&grade[2],&grade[3]);
		}
		void calculate(){
			gpa=((double)(grade[0]+grade[1]+grade[2]+grade[3]))/4;
		}
		void output(){
			printf("%s,%d,%d,%g\n",name,age,num,gpa);
		}
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}
