#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;
void ListPrint(list<int>:: iterator i, list<int>::iterator j){
	if (i != j) {
		printf("%d",*i);
		++i;
	}
	for (; i != j;++i){
		printf(" %d",*i);
	}
	printf("\n");
}
int main(){
	 // freopen("in.txt","r", stdin);
	 // freopen("out.txt","w",stdout);
	string inst;
	list <int> v[10005];
	int n, num, instn, n1;
	scanf("%d",&instn);
	while(instn--){//scanf可以用吗
		cin>>inst;
		if (inst == "new") {
			scanf("%d",&n);
		} else
			if (inst == "add") {
				scanf("%d %d",&n,&num);
				v[n].push_front(num);
			} else 
				if (inst == "merge"){
				scanf("%d %d",&n,&n1);
				v[n].merge(v[n1]);
				} else 
					if (inst == "unique"){
						scanf("%d",&n);
						v[n].sort();
						v[n].unique();
					} else 
						if (inst == "out"){
							scanf("%d",&n);
							v[n].sort();
							ListPrint(v[n].begin(), v[n].end());
						}
	}
}
