#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string outNum = ""; //Output Variable
    int userNum = 0; 
    int startPower = 0; //Highest power of 2

    cout << "Waiting for userinput" << "\n";
    cin >> userNum;
    cout << "your number is "<< userNum<< "\n";

    //Calculate highest power of 2
    int tempNum = userNum;
    while (tempNum >= 1) {
        startPower += 1;
        tempNum = tempNum/2;
    }

    startPower -= 1;
    //Convert number from denary to binary
    for (int i = startPower; i >= 0; i--){
        if ((userNum - (1 << i)) >= 0){
            userNum -= 1 << i;
            outNum += "1";
        }
        else{
            outNum += "0";
        }
    }

    cout << "Your binary number is " << outNum;

    return 0;
}