#include<iostream>

using namespace std;

int main()
{
    int x = 26;
    int num[200] = {0}, divi7[200] = {0}, divi3[200] ={0}, divi_both[200] = {0}, divi_not[200] = {0};    //array to store data
                                                                                                        //initialized to a zero array.
    int cnt_7 = 0, cnt_3 = 0, cnt_both = 0, cnt_not = 0;    //counters to count how many elements in each array
    int sum_7 = 0, sum_3 = 0, sum_both = 0, sum_not = 0;

    for(int i = 0; i < 200; i++)    //generate consecutive numbers from 26 to 225, total of 200 numbers
    {
        num[i] = x + i;
    }

    //check if they are divisible by 7 or 3 or both or both not.
    for(int i = 0; i < 200; i++)
    {
        if(num[i] % 7 == 0 && num[i] % 3 == 0)
        {
            divi_both[cnt_both++] = num[i];
        }
        else if(num[i] % 7 == 0)
        {

            divi7[cnt_7++] = num[i];
        }
        else if(num[i] % 3 == 0)
        {
            divi3[cnt_3++] = num[i];
        }
        else
        {
            divi_not[cnt_not++] = num[i];   
        }    
    }

    //calculating the sum of each array.
    for(int i = 0; i < 200; i++)
    {
        sum_7 += divi7[i];
        sum_3 += divi3[i];
        sum_both += divi_both[i];
        sum_not += divi_not[i];
    }

    cout << hex << "sum_7: " << sum_7 << "\nsum_3: " << sum_3 << "\nsum_both: " << sum_both << "\nsum_not: " << sum_not;
    cout << endl;  
    return 0;
}