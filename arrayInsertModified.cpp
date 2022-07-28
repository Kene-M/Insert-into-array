#include <iostream>

using namespace std;

int findId(int, int [], int);
int insertId(int, int [], int);

int main()
{
    const int MAX_SIZE = 100;

    int sid[MAX_SIZE] = { 1, 3, 6, 8, 10};
    int index, id, sz = 5;

    for(int j= 0; j < 5; j++)
    {
        cout << "Enter the student id: ";
        cin >> id;
        index = findId(id, sid, sz);
        if (index > 0){
            cout << id << " found at position " << index << endl;
        }
        else{
            cout << id << " not found \n";
            insertId(id, sid, sz);
            sz = sz + 1;
        }

    }

    for (int i=0; i < sz; i++)
        cout << sid[i] << " ";


}

// should return the index of val if it is present in the array
// otherwise return -1
int findId(int val, int arrId[], int sz)
{
    for (int i = 0; i < sz; i++){
            if (val == arrId[i])
                return i;
    }
    return(-1);
}

int insertId(int val, int arrId[], int sz)
{
    int i;
    for (i = 0; i < sz; i++)
    {
        if (val < arrId[i])
                break;
    }
    // position found. Now move everyone to the right by one position
    for (int j = sz - 1; j >= i; j--){
         arrId[j+1] = arrId[j]; // move one position to the right
    }
    arrId[i] = val;
    cout << val << " inserted into the array" << endl;
}
