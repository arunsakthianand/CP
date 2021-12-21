#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int N;
    vector<long long int> h;
    vector<long long int> cost;

    cin>>N;
    
    for (int i=0 ; i<N ; i++)
    {
        int temp;
        cin>>temp;
        h.push_back(temp);
    }

    for (int i=0 ; i<N ; i++)
    {
        int temp;
        cin>>temp;
        cost.push_back(0);
    }
    
    cost[1] = abs(h[0]-h[1]);
    
    for(int i=3 ; i<=N ; i++)
    {
        cost[i-1] = min( cost[i-2]+abs(h[i-1]-h[i-2]) , cost[i-3]+abs(h[i-1]-h[i-3]) );
    }
    
    cout<<cost[N-1];
    return 0;
}