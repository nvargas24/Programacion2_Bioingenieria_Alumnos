#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[3] = {1, 2, 3};
    vector<int> vec = {1, 2, 3};

    vec.push_back(4); // agrega elemento

    cout << "Arreglo: ";
    for(int i = 0; i < (sizeof(arr)/sizeof(arr[0])) ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Vector: ";
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }

    return 0;
}

