#include <iostream>
#include <atomic>

using namespace std;

enum TxStatus {Active=0,Aborted=1} ;
std::atomic< TxStatus  > status;

int main(int argc,char *argv[])
{
   status . store(Active);
   (cout << (status . load())) << std::endl;
   enum TxStatus expected = Active;
   enum TxStatus changed = Aborted;
   status . compare_exchange_strong(expected,changed);
   (cout << (status . load())) << std::endl;
   return 0;
}
