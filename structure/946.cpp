//
// Created by olga on 03/02/20.
//

#include <iostream>
#include <deque>

using namespace std;

int main(){
    int N;
    cin >> N;
    deque<int> state;
    for (int i = 0; i < N; ++i) {
        int act;
        cin >> act;
        switch (act){
            case 1:
                int book;
                cin >> book;
                state.push_front(book);
                break;
            case 2:
                int book2;
                cin >> book2;
                state.push_back(book2);
                break;
            case 3:
                cout << state.front() << " ";
                state.pop_front();
                break;
            case 4:
                cout << state.back() << " ";
                state.pop_back();
                break;
        }
    }
    return 0;
}