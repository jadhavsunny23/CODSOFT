#include<iostream>
using namespace std;
int main()
{
    int value1, value2;
    char op, choice;

    for(;;)
    {
        cout<<"\nEnter the operator(+, -, *, /, %) you want to perform operation:";
        cin>>op;
        cout<<"\nEnter the value 1:";
        cin>>value1;
        cout<<"Enter the value 2:";
        cin>>value2;
        switch(op)
        {
            case '+': cout<<value1 <<'+' <<value2 <<'=' <<value1 + value2;
                      break;
            case '-': cout<<value1 <<'-' <<value2 <<'=' <<value1 - value2;
                      break;
            case '*': cout<<value1 <<'*' <<value2 <<'=' <<value1 * value2;
                      break;
            case '/': if(value2 != 0)
                        cout<<value1 <<'/' <<value2 <<'=' <<(float)value1 / value2;
                      else
                        cout<<"Cannot divide by 0";
                      break;
            case '%': if(value2 != 0)
                        cout<<value1 <<'%' <<value2 <<'=' <<value1 % value2;
                      else
                        cout<<"Cannot divide by 0";
                      break;
            default : cout<<"INVALID OPERATOR!! PLEASE ENTER VALID OPERATOR";
                      break;

        }
        cout<<"\nDo you want to perform another operation? Press(y/n):";
        cin>>choice;
        if(choice!='y' && choice!='Y')
        {
                break;
        }
    }
    return 0;
}