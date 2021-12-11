#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(){
    ifstream in("Day-4\\input.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());

    vector<vector<int>> arr(1000, vector<int>(1000, 0));

    while(true){
        int x1,y1,x2,y2;
        char c;
        string g;

        cin >> x1 >> c >> y1 >> g >> x2 >> c >> y2;

        if(!cin) break;

        if(x1 == x2){
            if(y1 < y2) for(int y = y1; y <= y2; y++) arr[x1][y] += 1;
            else for(int y = y2; y <= y1; y++) arr[x1][y] += 1;
        }
        else if(y1 == y2){
            if(x1 < x2) for(int x = x1; x <= x2; x++) arr[x][y1] += 1;
            else for(int x = x2; x <= x1; x++) arr[x][y1] += 1;
        }
    }

    int c = 0, max = 0;
    for(int x = 0; x < arr.size(); x++){
        for(int y = 0; y < arr[x].size(); y++){
            if(arr[x][y] >= 2) c++;
        }
    }
    cout << c << " " << max << "\n";
}