//
// Created by Olga Malyugina on 27.04.21.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;
int m, k, message_len;
int base = 4;

struct STEP {
    int x;
    int y;

    STEP() = default;

    STEP(int x_, int y_) : x(x_), y(y_) {};
};
//ifstream in("/tmp/game.in");
//ofstream out("/tmp/game.out");

void end_game(int game_number) {
    if (game_number % 2 == 0) {
        cout << 0 << endl;
    } else {
        int r, c;
        cin >> r >> c;
        cout << 0 << endl;
    }
}

bool is_possible_step(vector<STEP> &history, STEP current) {
    for (STEP h_step:history) {
        if (current.x >= h_step.x and current.y >= h_step.y)
            return false;
    }
    return true;
}

void finish_game(bool bot_step, vector<STEP> &history) {
    if (bot_step) {
        int x, y;
        cin >> x >> y;
        history.emplace_back(x, y);
        if (x == 1 and y == 1){
            history.clear();
            return;
        }
    }
    int max_x = 15, max_y = 15;
    for (STEP h_step:history) {
        if (h_step.x == 1)
            max_y = min(max_y, h_step.y);
        if (h_step.y == 1)
            max_x = min(max_x, h_step.x);
    }
    if (is_possible_step(history, STEP(2, 2))) {
        cout << "2 2" << endl;
        history.emplace_back(2, 2);
        int x, y;
        cin >> x >> y;
        if (x == 1 and y == 1){
            history.clear();
            return;
        }
        history.emplace_back(x, y);
        if (x == 1)
            max_y = min(max_y, y);
        if (y == 1)
            max_x = min(max_x, x);
    }
    while (true) {
        if (max_x == max_y and max_x == 2) {
            cout << "1 1" << endl;
            return;
        }
        if (max_y > max_x) {
            cout << 1 << " " << max_x << endl;
            max_y = max_x;
        } else if (max_y < max_x) {
            cout << max_y << " " << 1 << endl;
            max_x = max_y;
        } else {
            cout << 1 << " " << max_y - 1 << endl;
            max_y--;
        }
        int x, y;
        cin >> x >> y;
        if (x == 1 and y == 1){
            history.clear();
            return;
        }
        history.emplace_back(x, y);
        if (x == 1)
            max_y = min(max_y, y);
        if (y == 1)
            max_x = min(max_x, x);
    }
}

int convert_message(string part) {
    int index = 3;
    int res = 0;
    for(char c:part){
        if (c == '1'){
            res += pow(2,index);
        }
        index--;
    }
    res += 16;
    return res;
}

string decode_message(int part){
    part-=16;
    int index = 3;
    string res = "";
    if (part >=8){
        res = res+'1';
        part-=8;
    }else{
        res = res+'0';
    }
    if (part >=4){
        res = res+'1';
        part-=4;
    }else{
        res = res+'0';
    }
    if (part >=2){
        res = res+'1';
        part-=2;
    }else{
        res = res+'0';
    }
    if (part >=1){
        res = res+'1';
        part-=1;
    }else{
        res = res+'0';
    }
    return res;
}

void encoder() {
    string message;
    cin >> m >> k >> message_len;
    cin >> message;
    int cur_index = 0;
    int game_number = 0;
    int first_step = true;
    vector<STEP> history;
    while (cur_index < message.size()) {
        if (game_number % 2 and first_step) {
            int x, y;
            cin >> x >> y;
            history.emplace_back(x, y);
            if (x==1 and y == 1){
                game_number++;
                first_step=true;
                history.clear();
                continue;
            }
        }
        int next_step = convert_message(message.substr(cur_index, 4));
        bool made = false;
        for (int i = next_step; i >=1; --i) {
            if (is_possible_step(history, STEP(next_step, i))){
                history.emplace_back(next_step, i);
                cout << next_step << " " << i << endl;
                made = true;
                break;
            }
            if (is_possible_step(history, STEP(i, next_step))){
                history.emplace_back(i, next_step);
                cout << i << " " << next_step << endl;
                made = true;
                break;
            }
        }
        if (made){
            cur_index+=4;
            first_step=false;
            int x,y;
            cin >> x >> y;
            history.emplace_back(x,y);
            if (x==1 and y == 1){
                game_number++;
                first_step=true;
                history.clear();
                continue;
            }
        }
        else{
            finish_game(false, history);
            history.clear();
            game_number++;
            first_step=true;
        }
    }
    if (not history.empty()){
        finish_game(false,history);
        game_number++;
    }
    end_game(game_number);
}

void decoder() {
    int number_games;
    cin >> m >> k >> message_len >> number_games;
    vector<int> res;
    vector<STEP> history;
    for (int i = 0; i < number_games; ++i) {
        int x, y;
        cin >> x >> y;
        history.emplace_back(x,y);
        while (x != 1 or y != 1) {
            cin >> x;
            cin >> y;
            history.emplace_back(x,y);
        }
    }
    int game_number = 0;
    bool bot_step = false;
    bool first_step = true;
    int my_x,my_y, bot_x, bot_y;
    for (STEP step:history) {
        if (first_step){
            bot_step = game_number%2==1;
        }
        if (bot_step){
            bot_x=step.x;
            bot_y=step.y;
            if (bot_x==1 and bot_y ==1){
                first_step=true;
                game_number++;
                continue;
            }
            first_step = false;
            bot_step = false;
        }else{
            my_x=step.x;
            my_y=step.y;
            if (my_x==1 and my_y == 1){
                first_step=true;
                game_number++;
                continue;
            }
            if (my_x >15 or my_y > 15){
                int ans = max(my_x, my_y);
                res.push_back(ans);
            }
            first_step=false;
            bot_step = true;
        }
    }
    for (int c:res) {
        cout << decode_message(c);
    }
    cout << endl;

}

int main() {

    int run;
    cin >> run;
    if (run == 1) {
        encoder();
    } else
        decoder();
    return 0;
}