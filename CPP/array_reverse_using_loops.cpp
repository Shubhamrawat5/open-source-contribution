#include <iostream>
using namespace std;
  
int main(){
    int input[500], output[500], count, i;
      
    cout << "Enter number of elements in array\n";
    cin >> count;
     
    cout << "Enter " << count << " numbers \n";
      
    for(i = 0; i < count; i++){
        cin >> input[i];
    }
      
    // Copy numbers from inputArray to outputArray in 
    // reverse order 
    for(i = 0; i < count; i++){
        output[i] = input[count-i-1];
    }    
    // Print Reversed array
    cout << "Reversed Array\n";
    for(i = 0; i < count; i++){
        cout << output[i] << " ";
    }
          
    return 0;
}