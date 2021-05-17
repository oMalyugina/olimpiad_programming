#include<iostream>

using namespace std;

int main(){
    string name1, name2, res;
    cin >> name1 >> name2;
    int start1=0, start2 = 0;
    for (int i = 122; i >= 97; --i)
    {
        char l = char(i);
        int pos1 = name1.find(l, start1);
        int pos2 = name2.find(l, start2);
        while (pos1 != string::npos and pos2 != string::npos){
            start1 = pos1+1;
            start2 = pos2+1;
            res = res+=l;
            int pos1 = name1.find(l, start1);
            int pos2 = name2.find(l, start2);
        }
    }

    cout << res;
    
    return 0;
}