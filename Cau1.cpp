#include <iostream>
using namespace std;
int main()
{
  int n;
  long S = 0;
  do
  {
    cout<<"\nNhập n: ";
    cin>>n;
    if(n <= 0)
    {
      cout<<"\n Nhập số phải lớn hơn 0, nhập lại !";
    }
  }while(n <= 0);
  cout<<"ước số là: ";
  for(int i = 1; i <= n; i++)
  {
    if(n % i == 0)
    {
      cout<< i << "\t";
      S = S + i;
    }
  }
  cout<<"\nTổng của ước là "<<S;
 
}