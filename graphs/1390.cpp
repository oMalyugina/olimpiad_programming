//
// Created by Olga Malyugina on 29.01.21.
//

#include <iostream>
#include <vector>
#include <stack>

struct Road{
    int town1;
    int town2;
    int door1;
    int door2;

    Road(int t1, int t2, int d1, int d2):town1(t1), town2(t2), door1(d1), door2(d2){}
    Road() = default;
};


using namespace std;

bool is_euler_circle_possible(const vector<vector<Road>> & cities) {
    for (int i = 1; i < cities.size(); ++i) {
        if (cities[i].size() % 2 == 1 or cities[i].empty())
            return false;
    }
    return true;
}


int door2town(int door){
    if (door%4==0)
        return door/4;
    else
        return int(door/4)+1;
}

void my_del_road(vector<vector<Road>> &cities, Road road_to_del) {
    vector<Road> roads1;
    for (Road road: cities[road_to_del.town1]){
        if (road.door2 != road_to_del.door2)
            roads1.push_back(road);
    }
    cities[road_to_del.town1] = roads1;

    vector<Road> roads2;
    for (Road road: cities[road_to_del.town2]){
        if (road.door2 != road_to_del.door1)
            roads2.push_back(road);
    }
    cities[road_to_del.town2] = roads2;
}

vector<Road> find_euler_circle(vector<vector<Road>> &cities) {
    vector<int> path;
    stack<int> seen;
    stack<Road> deleted_roads;
    vector<Road> roads;
    seen.push(1);
    while (not seen.empty()) {
        int current_town = seen.top();
        if (cities[current_town].empty()) {
            path.push_back(current_town);
            if (not deleted_roads.empty()) {
                roads.push_back(deleted_roads.top());
                deleted_roads.pop();
            }
            seen.pop();
        } else {
            Road next_road = cities[current_town].back();
            my_del_road(cities, next_road);
            deleted_roads.push(next_road);
            seen.push(next_road.town2);
        }
    }
    return roads;
}

bool is_edges_empty(const vector<vector<Road>> & cities) {
    for (int i = 1; i < cities.size(); ++i) {
        if (not cities[i].empty())
            return false;
    }
    return true;
}

int main() {

    int n;
    cin >> n;
    vector<vector<Road>> cities(n+1,vector<Road>(0));
    for (int i = 1; i < 2*n+1; ++i) {
        int v1,v2;
        cin >> v1 >> v2;
        int city1 = door2town(v1);
        int city2 = door2town(v2);
        cities[city1].push_back(Road(city1, city2, v1, v2));
        cities[city2].push_back(Road(city2, city1, v2, v1));
    }

    if (not is_euler_circle_possible(cities)){
        cout << "No";
        return 0;
    }
    vector<Road> res = find_euler_circle(cities);
    if (not is_edges_empty(cities)){
        cout << "No";
        return 0;
    }
    cout << "Yes" << endl;
    for (int j = res.size()-1; j >= 0; --j) {
        cout << res[j].door1 << " ";
        cout << res[j].door2 << " ";
    }
    return 0;
}








