#include <iostream>

using namespace std;

int main(){
    
int server, request, value, hash;

cout << "Enter number of servers: ";
cin >> server;

cout << "Enter number of requests: ";
cin >> request;

int arr[server];

for (int m = 0; m < server; m++) {
arr[m] = 0; 
    }

for (int i = 0; i < request; i++) {
cout << "Send request " << i + 1 << ": ";
cin >> value;

hash = value % server; // hashing
arr[hash]++; 
cout << "Request " << value << " sent to server " << hash << endl;
    }

cout << "\nRequests sent per server:\n";
for (int j = 0; j < server; j++) {
cout << "Server " << j + 1 << ": " << arr[j] << " requests\n";
    }

return 0;
}
