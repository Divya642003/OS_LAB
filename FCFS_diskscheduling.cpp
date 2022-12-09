#include<iostream>
using namespace std;

int main()
{
    int n,i,j;
    cout<<"enter the number of elements in request array :";
    cin>>n;
    int rq[n];
    int head;
    cout<<"enter the value of initial head position :";
    cin>>head;
    cout<<"enter the values in request array :";
    for(auto &x:rq)
    cin>>x;
    int result=0;
    int seektime ;
    cout<<"enter the seek time for each track :";
    cin>>seektime;
    int seektime_array[n];
    int total_seek_time=0;
    for(i=0;i<n;i++)
    {
        int temp= rq[i]>head?rq[i]-head:head-rq[i];
        seektime_array[i]=seektime*temp;
        result = result +temp;
        head = rq[i];
        total_seek_time+=seektime_array[i];
    }
    cout<<"total number of seek operations are : "<<result<<endl;
    cout<<"total seek time for overall operations : "<<total_seek_time<<endl;
}