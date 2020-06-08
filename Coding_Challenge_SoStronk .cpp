#include <iostream>
#include <string>
#include <utility> 
#include<map>
#include <queue> 
#include<iterator>
#include<cstdlib> 
using namespace std;

multimap<int, string > fun(int start, int count, int avg1, vector <pair<string, int> >& arr, int avg2,  multimap<int, string  > &ans, string s1, string s2){
    if(count ==0){
        
        for(int i=start; i<arr.size(); i++){
            s2 += arr[i].first + ",";
            avg2 += arr[i].second;
        }
        //cout<<s1<<" "<<avg1/(arr.size()/2)<<" VS "<<s2<< " "<<avg2/(arr.size()/2)<<endl;
        //cout<<"-----------------------"<<endl;
        
        avg1 /= (arr.size()/2);
        avg2 /= (arr.size()/2);
        
        s1 += "(" + to_string(avg1) +") ";
        s2 += " (" + to_string(avg2) +")";
        ans.insert(make_pair(abs(avg2-avg1),s1 + " VS "+ s2));
        return ans;
    }
    --count;
     
    for(int i=start; i<arr.size()-count;  i++){
        
        fun(i+1, count, (avg1+arr[i].second), arr,avg2, ans, s1+ arr[i].first+"," , s2);
        s2 += arr[i].first +",";
        avg2 += arr[i].second;
    
    }
        
    return ans;
}

int main()
{
    
    int start =1;
    vector <pair<string, int> > arr;
    multimap<int,  string > ans;
    int n;
    string  temp1; int temp2;
    cout<<"enter how many players are playing ?? "<<endl;
    cin>>n;
    while((n & 1) == 1){
        cout<<"please enter even number.......because we need equal members of teams"<<endl;
            cout<<"enter how many players are playing ??"<<endl;
        cin>>n;
    }
    for(int i=0; i<n; i++){
        cout<<"enter name of "<<i+1<<" person : ";
        cin>>temp1;
        cout<<"enter score of  " << temp1 << " : ";
        cin>>temp2;
        arr.push_back(make_pair( temp1, temp2));
    }
    cout<<"..........................................."<<endl;

    int avg2 =0;
    int end = arr.size();
    int count = end/2;
    string s1 = arr[0].first+",";
    string s2 ;
    int avg1 = arr[0].second;
    count--;
    ans = fun(start, count, avg1, arr, avg2, ans,s1, s2 );
    multimap<int, string  > :: iterator i;
    for(i = ans.begin(); i != ans.end(); i++){
        cout<<i->second<<endl;
    }
}
