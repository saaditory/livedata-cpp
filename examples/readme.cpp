/**
 * This example is based on the implementation explained in the README.md file.
 * 
 * Created by Saad Khan on Dec 4, 2021.
*/

#include <iostream>
#include "../include/livedata/livedata.h"

using namespace std;

class LdObserver : public Observer<string>
{
public:
     void onChanged(string newValue)
     {
          cout << "LiveData value has been updated to: " << newValue;
     }
};

int main()
{
     LiveData<string> ld("default value");

     LdObserver *ldo = new LdObserver;

     ld.observe(ldo);

     ld.setValue("new value");

     string currentValue = ld.getValue();

     cout << endl
          << "Current value of LiveData is: " << currentValue << endl;

     return 0;
}
