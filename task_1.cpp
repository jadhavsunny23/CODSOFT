#include<iostream>
 using namespace std;
 int main()
 {
    int random=3;
    int user_num;

    for(;;)
    {
        cout<<"\nRandom number is generated, Can you guess it !: ";
        cin>>user_num;
        if(user_num < random)
            cout<<"It is too low";
        else if(user_num > random)
            cout<<"It is too high";
        else if(user_num == random)
        {
            cout<<"Yes, That's the Correct Number";
            break;
        }
    }
    return 0;
 }