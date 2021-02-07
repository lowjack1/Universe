#include<iostream.h>
#include<conio.h>
void bubble_sorting(int [],int);
void main()
{
 int a[50];
 int n;
 cout<<"enter how many numbers you will be sort";
 cin>>n;
 cout<<"enter the values\n";
 for(int i=0;i<n;i++)
 cin>>a[i];
 bubble_sorting(a,n);
 double b[5]={5.8,6.8,9.3,2.6,4.5};
 bubble_sorting(b,n);
 cout<<"the sorted array is:-\n ";
 for(i=0;i<n;i++)
 cout<<a[i]<<" ";
 getch();
}

template <class x> void bubble_sorting(x *a,int size)
{
 int round,i;
 x temp;
 for(round=0;round<size;round++)
  for(i=0;i<(size-1)-round;i++)
   if(a[i]>a[i+1])
   {
    temp=a[i];
    a[i]=a[i+1];
    a[i+1]=temp;
   }
}
