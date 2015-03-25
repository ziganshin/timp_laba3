/** \file spiski.cpp
*/
#include <iostream>
#include <stdlib.h>
#include<clocale>
using namespace std;
/**struct item*/
struct item
{
    int data;
    item *next;
    
};
/**function add*/
void add(item *&top,int pos, int x)
{
    int j=1;
    int i; item *pnew, *p=top;
    pnew=new item; pnew->data=x;
    if (pos<=1||top==NULL) 
    {
        pnew->next=top; top=pnew;
    }
    else
    {
        for(i=1;i<pos-1;i++) 
            if (p->next!=NULL) 
            {    
                p=p->next;
                j++;
            }
        if (pos<=j+1)
        {
            pnew->next=p->next; p->next=pnew;
        }
    }
}
/**function print*/
void print(item *top)
{
    item *p=top;
    while (p!=NULL) 
    {
        cout<<p->data<<' '; 
        p=p->next;
    }
    cout<<endl;
}
/**function delete*/
void delet(item *&top, int pos2)
    {
        item *a=top,*b;
        int i=0;
        while(a!=NULL)
        {
            a=a->next;
            i++;
        }
        if(pos2>i||pos2<1) 
        {
            cout<<"this position not in spisok!"<<endl;
        }
        
        else
        {
            if(pos2==1)
            {
                a=top->next;
                top=a;
            }
            if (pos2>1)
            {
                i=1;
                a=top;
                while (i!=pos2-1) 
                {
                    i++; a=a->next;
                }
                b=a->next;
                a->next=b->next;
                delete b;
            }
        }
}
/**function main() */
int main() 
{
    setlocale(LC_ALL,"Russian");
     int pos, pos1, pos2, otv, da;
     item *first, *last;
     int x,r,k,m,y,j;
    item *top=NULL;
    
        cout<<"vvedite kol-vo elementov v spiske: ";
        cin>>k;
        if (k!=0)
            for (int i=1; i<=k; i++) 
            {
                r=rand()%100;
                add(top,i,r); 
            }
        print(top); 
        
    
        cout<<"vvedi number of position for vstavki: ";
        cin>>pos;
        cout<<"vvedi znachenie elementa for vstavki: ";
        cin>>x;
        add(top,pos,x); 
        print(top);
    
        cout<<"enter number of position elementa for delete: ";
        cin>>pos2;
        delet(top,pos2);
        print(top);

    cin.get();
    cin.get();
}