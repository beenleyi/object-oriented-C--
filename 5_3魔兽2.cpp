#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
const int WARRIORKINDNUM=5;
const char* hq_color[2]={"red","blue"};
const char* red_wname[5]={"iceman","lion","wolf","ninja","dragon"};
const char* blue_wname[5]={"lion","dragon","ninja","iceman","wolf"};
const char* weapon[3]={"sword","bomb","arrow"};
//w_queue{dragon 、ninja、iceman、lion、wolf};
int w_strength[5];
class warrior{
	public:
	int mynum,mystrength,mycolor;
	warrior(int hqcolor,int num,int strength,int kindnum,int total_in_hq){
		mynum=num;
		mystrength=strength;
		mycolor=hqcolor;
		const char* kindname;
		if (hqcolor) kindname=blue_wname[kindnum];
		else kindname=red_wname[kindnum];
		printf("%s %d born with strength %d,%d %s in ",kindname,num,strength,total_in_hq,kindname);
		if (hqcolor) printf("blue ");else printf("red ");
		printf("headquarter\n");
	};
};
class lion:public warrior{
	public:
	int myloyalty;
	lion(int hqcolor,int num,int strength,int kindnum,int total_lion_in_hq,int loyalty):warrior(hqcolor,num,strength,kindnum,total_lion_in_hq){
		myloyalty=loyalty;
		printf("It's loyalty is %d\n",myloyalty);
	}
};
class dragon:public warrior{
	public:
	double morale;
	int weaponnum1;
	dragon(int hqcolor,int num,int strength,int kindnum,int total_lion_in_hq,int life):warrior(hqcolor,num,strength,kindnum,total_lion_in_hq){
		weaponnum1=num%3;
		morale=life/(double)strength;
		printf("It has a %s,and it's morale is %.2lf\n",weapon[weaponnum1],morale);
	}
};
class ninja:public warrior{
	public:
	int weaponnum1,weaponnum2;
	ninja(int hqcolor,int num,int strength,int kindnum,int total_lion_in_hq):warrior(hqcolor,num,strength,kindnum,total_lion_in_hq){
		weaponnum1=num%3;
		weaponnum2=(num+1)%3;
		printf("It has a %s and a %s\n",weapon[weaponnum1],weapon[weaponnum2]);
	}
};
class iceman:public warrior{
	public:
	int weaponnum1;
	iceman(int hqcolor,int num,int strength,int kindnum,int total_lion_in_hq):warrior(hqcolor,num,strength,kindnum,total_lion_in_hq){
		weaponnum1=num%3;
		printf("It has a %s\n",weapon[weaponnum1]);
	}
};
class wolf:public warrior{
	public:
	wolf(int hqcolor,int num,int strength,int kindnum,int total_lion_in_hq):warrior(hqcolor,num,strength,kindnum,total_lion_in_hq){
	}
};
class headquarter{
	public:
    //hqcolor=0:red;hqcolor=1
    int hqcolor;
    int life,totalwarriors[WARRIORKINDNUM],num,hqstrength[WARRIORKINDNUM],making_w,warriorkind;
    headquarter(int k,int life);
    void makingwarrior();
    int createsuccess();
	void create(int kindnum);
};
headquarter::headquarter(int k,int totallife){
	hqcolor=k;
    int i;
    for (i=0;i<WARRIORKINDNUM;i++) totalwarriors[i]=0;
    num=0;
    life=totallife;
    making_w=1;
    warriorkind=0;
}

void headquarter:: makingwarrior(){
    int c_strength=hqstrength[warriorkind];	
    int i=1;
    while((life<c_strength)&&(i<WARRIORKINDNUM)){
    	warriorkind=(warriorkind+1)%WARRIORKINDNUM;
    	c_strength=hqstrength[warriorkind];	
    	i++;
	} 
    if (life>=c_strength){
        num++;
		life-=c_strength;
	    create(warriorkind);
        warriorkind=(warriorkind+1)%WARRIORKINDNUM;
    }else{
        printf("headquarter stops making warriors\n");
		making_w=0;
    }
}
void headquarter:: create(int kindnum){
    if (hqcolor){
        switch(kindnum){
                case(0):lion(hqcolor,num,hqstrength[kindnum],kindnum,++(totalwarriors[kindnum]),life);break;
                case(1):dragon(hqcolor,num,hqstrength[kindnum],kindnum,++(totalwarriors[kindnum]),life);break;
                case(2):ninja(hqcolor,num,hqstrength[kindnum],kindnum,++(totalwarriors[kindnum]));break;
                case(3):iceman(hqcolor,num,hqstrength[kindnum],kindnum,++(totalwarriors[kindnum]));break;
                case(4):wolf(hqcolor,num,hqstrength[kindnum],kindnum,++(totalwarriors[kindnum]));break;
        }
    }
    else {
        switch(kindnum){
                case(0):iceman(hqcolor,num,hqstrength[kindnum],kindnum,++(totalwarriors[kindnum]));break;
                case(1):lion(hqcolor,num,hqstrength[kindnum],kindnum,++(totalwarriors[kindnum]),life);break;
                case(2):wolf(hqcolor,num,hqstrength[kindnum],kindnum,++(totalwarriors[kindnum]));break;
                case(3):ninja(hqcolor,num,hqstrength[kindnum],kindnum,++(totalwarriors[kindnum]));break;
                case(4):dragon(hqcolor,num,hqstrength[kindnum],kindnum,++(totalwarriors[kindnum]),life); break;
        }
    }
}
int main(){
    int n,casenum=1;
    scanf("%d",&n);
    while(casenum<=n){
        int totallife,i,time=0;
        scanf("%d",&totallife);
        headquarter red_hq(0,totallife),blue_hq(1,totallife);
        for (i=0;i<WARRIORKINDNUM;i++) scanf("%d",&w_strength[i]);
        red_hq.hqstrength[0]=w_strength[2];
        red_hq.hqstrength[1]=w_strength[3];
        red_hq.hqstrength[2]=w_strength[4];
        red_hq.hqstrength[3]=w_strength[1];
        red_hq.hqstrength[4]=w_strength[0];
        blue_hq.hqstrength[0]=w_strength[3];
        blue_hq.hqstrength[1]=w_strength[0];
        blue_hq.hqstrength[2]=w_strength[1];
        blue_hq.hqstrength[3]=w_strength[2];
        blue_hq.hqstrength[4]=w_strength[4];
        printf("Case:%d\n",casenum);
        while(red_hq.making_w || blue_hq.making_w){
            if (red_hq.making_w){
                printf("%03d red ",time);
            	red_hq.makingwarrior();
            }
            if (blue_hq.making_w){
            	printf("%03d blue ",time);
            	blue_hq.makingwarrior();                
            }
            time++;
        }
        casenum++;
    }
    return 0;
}
