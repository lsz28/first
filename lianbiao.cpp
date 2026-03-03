#include<bits/stdc++.h>
using namespace std;
struct hezi
{
	int biao;
	hezi* next;
};
int main()
{
	hezi *h=new hezi;
	hezi* hh=new hezi;
	hezi* hhh=new hezi;
//	h->biao=10;
	hh->biao=20;
	hhh->biao=30;
	(*h).biao=10;
	
	h->next=hh;
	hh->next=hhh;
	hhh->next=NULL;
	
	hezi* p=h;
	while(p!=NULL)
	{
		cout<<p->biao<<endl;
		p=p->next;
	}
	return 0;
} 
