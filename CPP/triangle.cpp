#include <iostream>

using namespace std;

int main()
{
    int height;
    cin >> height;
    
    char width;
	cin >> width;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j <= height-i; j++) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            cout << width << " ";
        }
        cout << endl;
        
    }
    
    return 0;
}
