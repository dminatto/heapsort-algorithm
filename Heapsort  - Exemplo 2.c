
# include <iostream.h>
# include <conio.h>

void main()
{
 clrscr();
 int a[50],size;
 int p,c;
 cout<<"Entre com o tamanho do Array :";
 cin>>size;

 cout<<"Entre com o valor de A[1] :";
 cin>>a[1];
 for(int i=2;i<=size;i++)
 {
    cout<<"Entre com o valor de A["<<i<<"] :";
    cin>>a[i];
    p=i/2;
    c=i;
    while(1)
    {
    if( a[c] > a[p])
    {
        int t=a[c];
        a[c]=a[p];
        a[p]=t;
    }
    c=p;
    p=p/2;
    if(p<1)
    {
        break;
    }
    }
 }
 cout<<endl<<"Heap ..."<<endl;
 for(i=1;i<=size;i++)
 {
    cout<<endl;
    cout<<"Indice["<<i<<"] :"<<a[i];
 }

 int j=size;
 int lc,rc;
 while(j>1)
 {
     if(a[1] > a[j])
     {
    int t=a[1];
    a[1]=a[j];
    a[j]=t;
    j--;
     }
     else
     {
    j--;
    continue;
     }

     p=1;
     while(p < j)
     {
     lc=p*2;
     rc=p*2 + 1;
     if(lc>=j || rc >=j)
     {
            break;
     }
     if(a[p] < a[lc] && a[lc] > a[rc])
     {
    int temp=a[lc];
    a[lc]=a[p];
    a[p]=temp;
    p=lc;
     }
     elseif (a[p] < a[rc] && a[rc] > a[lc])
     {
    int temp=a[rc];
    a[rc]=a[p];
    a[p]=temp;
    p=rc;
     }
     else
     {
      break;
     }
     }
 }

 cout<<endl<<"Lista Ordenada ..."<<endl;
 for(i=1;i<=size;i++)
 {
    cout<<endl;
    cout<<"Indice["<<i<<"] :"<<a[i];
 }

 getch();
}
