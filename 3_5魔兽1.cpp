#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int WARRIORKINDNUM=5;
enum color{red,blue};
//red_w{iceman、lion、wolf、ninja、dragon};
//blue_w{lion、dragon、ninja、iceman、wolf};
//w_queue{dragon 、ninja、iceman、lion、wolf};
int w_strength[5];
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
    if (!createsuccess()) {
        printf("headquarter stops making warriors\n");
        making_w=0;
    }
}
int headquarter:: createsuccess(){
    int c_strength=hqstrength[warriorkind];	
    int i=1;
    while((life<c_strength)&&(i<WARRIORKINDNUM)){
    	warriorkind=(warriorkind+1)%WARRIORKINDNUM;
    	c_strength=hqstrength[warriorkind];	
    	i++;
	} 
    if (life>=c_strength){
        num++;
	    create(warriorkind);
        life-=c_strength;
        warriorkind=(warriorkind+1)%WARRIORKINDNUM;
        return 1;
    }else{
        return 0;
    }
}
void headquarter:: create(int kindnum){
    char kindname[7];
    if (hqcolor){
        switch(kindnum){
                case(0):strncpy(kindname,"lion\0",7);break;
                case(1):strncpy(kindname,"dragon\0",7);break;
                case(2):strncpy(kindname,"ninja\0",7);break;
                case(3):strncpy(kindname,"iceman\0",7);break;
                case(4):strncpy(kindname,"wolf\0",7);break;
        }
    }
    else {
        switch(kindnum){
                case(0):strncpy(kindname,"iceman\0",7);break;
                case(1):strncpy(kindname,"lion\0",7);break;
                case(2):strncpy(kindname,"wolf\0",7);break;
                case(3):strncpy(kindname,"ninja\0",7);break;
                case(4):strncpy(kindname,"dragon\0",7); break;
        }
    }
    printf("%s %d born with strength %d,%d %s in ",kindname,num,hqstrength[kindnum],++(totalwarriors[kindnum]),kindname);
    if (hqcolor) printf("blue ");else printf("red ");
    printf("headquarter\n");
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
