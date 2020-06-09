#include <iostream>
#include <string>
#include <utility> 
#include<map>
#include <queue> 
#include<iterator>
#include <iomanip> 
#include<cstdlib> 
using namespace std;

void fun(int start, int count, float avg1, vector <pair<string, float> >& arr, float avg2,  multimap<float, string  > &ans, string s1, string s2){
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
        ans.insert(make_pair(avg1-avg2,s1 + " VS "+ s2));
        return ;
    }
    --count;
     
    for(int i=start; i<arr.size()-count;  i++){
        
        fun(i+1, count, (avg1+arr[i].second), arr,avg2, ans, s1+ arr[i].first+"," , s2);
        s2 += arr[i].first +",";
        avg2 += arr[i].second;
    
    }
        
    return ;
}

int main()
{
    
    int start =1;
    vector <pair<string, float> > arr;
    multimap<float,  string > ans;
    int n;
    string  temp1; float temp2;
    cout<<"enter how many players are playing ?? "<<endl;
    try{
        cin>>n;
        if (std::cin.fail()) throw 1;
    }
    catch (int err){
        cout<<"please enter valid datatypes in fileds"<<endl;
        return 0;
    }
    while((n & 1) == 1){
        cout<<"please enter even number.......because we need equal members of teams"<<endl;
            cout<<"enter how many players are playing ??"<<endl;
        cin>>n;
    }
    for(int i=0; i<n; i++){        
        try{
            cout<<"enter name of "<<i+1<<" person : ";
            cin>>temp1;
            if (std::cin.fail()) throw 1;
            cout<<"enter score of  " << temp1 << " : ";
            cin>>temp2;
            if (std::cin.fail()) throw 1;

        }
        catch (int err){
            cout<<"please enter valid datatypes in fileds"<<endl;
            return 0;
        }
        arr.push_back(make_pair( temp1, temp2));
    }
    cout<<"...................OUTPUT........................"<<endl;
    cout<<endl;

    float avg2 =0;
    int end = arr.size();
    int count = end/2;
    string s1 = arr[0].first+",";
    string s2 ;
    float avg1 = arr[0].second;
    count--;
     fun(start, count, avg1, arr, avg2, ans ,s1, s2 );
    multimap<float, string  > :: iterator i;
    for(i = ans.begin(); i != ans.end(); i++){
        cout<<setprecision(1)<<i->second<<endl;
    }
    cout<<".............................................."<<endl;
    cout<<endl;
}
