#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<int> a){

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
vector<int> merge(vector<int> a1, vector<int> a2)
{

    int i = 0, j = 0;
    vector<int> v1;
    while(i < a1.size() && j < a2.size())
    {
        if(a1[i] > a2[j]){
            v1.push_back(a2[j]);
            j++;
        }
        else if(a1[i]<a2[j]){
            v1.push_back(a1[i]);
            i++;
        }
        else{
            v1.push_back(a1[i]);
            i++;
        }
    }
    
    while(i < a1.size())
    {
        v1.push_back(a1[i]);
        i++;
    }    
    
    while(j < a2.size())
    {
        v1.push_back(a2[j]);
        j++;
    }

    return v1;
}

bool compare(vector<int> a,vector<int>b){
    return a.size() > b.size();
}

int main(){

    int n;
    vector<vector<int>> A;
    cout <<"Enter the number of arrays: \n";
    cin >> n;

    for (int i = 0; i < n;i++){
        cout << "Enter the size of array " << i+1 << endl;
        int size;
        cin >> size;
        cout <<"Please enter "<< size <<" elements of the array "<< i+1 <<" : " << endl;
        vector<int> p(size);
        for (int j = 0; j < size;j++){
            cin >> p[j];
        }

        sort(p.begin(), p.end());
        A.push_back(p);
        
    }

              
    
    while(A.size() != 1)
    {
        sort(A.begin(), A.end(), compare);
        vector<int> a = A.back();
        A.pop_back();
        vector<int> b = A.back();
        A.pop_back();
        vector<int> c = merge(a, b);
        A.push_back(c);
    }

    cout<<A[0].size()<< endl;
    print(A[0]);
   
    return 0;
}