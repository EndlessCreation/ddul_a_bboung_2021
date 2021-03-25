#include <iostream>
using namespace std;
int main(){
    int C;
    int N;
    int arr[1000];
    cin >> C;
    for(int i=0;i<C;i++){
        cin >> N;
        int sum=0;
        double num=0;
        for(int j=0;j<N;j++){
            cin >> arr[j];
            sum+=arr[j];
        }
        double avg=sum/N;
        for(int j=0;j<N;j++){
            if(arr[j]>avg) num++;
        }
        cout << fixed;
        cout.precision(3);
        cout << num/N*100 << '%' << '\n';
    }
}