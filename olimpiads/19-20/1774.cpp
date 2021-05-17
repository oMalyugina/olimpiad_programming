//
// Created by Olga Malyugina on 28.01.21.
//

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

struct Fragment {
    int start;
    int end;
    int number;

    Fragment(int s, int e, int n) : start(s), end(e), number(n) {};
};

void create_edges(const vector<Fragment> &fragments, map<int, vector<Fragment>> &edges, int d) {
    for (const Fragment fragment: fragments) {
        int start = d - fragment.start;
        if (edges.find(start) == edges.end()) {
            vector<Fragment> tmp;
            tmp.push_back(fragment);
            edges[start] = tmp;
        } else {
            edges[start].push_back(fragment);
        }
    }
}

bool is_euler_path_possible(const map<int, vector<Fragment>> &edges, int &start, int &end) {
    map<int, int> input_edges;
    for (const auto &vertex2edges:edges) {
        for (const Fragment edge:vertex2edges.second) {
            if (input_edges.find(edge.end) == input_edges.end()) {
                input_edges[edge.end] = 1;
            } else {
                input_edges[edge.end]++;
            }
        }
    }
    for (const auto &vertex2edges:edges) {
        int diff = input_edges[vertex2edges.first] - vertex2edges.second.size();
        if (diff > 1 or diff < -1) {
            return false;
        }
        if (diff == 0) {
            continue;
        }
        if (diff == 1) {
            if (end != -1)
                return false;
            end = vertex2edges.first;
        }
        if (diff == -1) {
            if (start != -1)
                return false;
            start = vertex2edges.first;
        }
    }
    return true;
}

vector<Fragment> find_euler_circle(map<int, vector<Fragment>> &edges, int start) {
    vector<int> path;
    stack<int> seen;
    seen.push(start);
    vector<Fragment> result;
    stack<Fragment> deleted_edges;
    while (not seen.empty()) {
        if (edges[seen.top()].empty()) {
            path.push_back(seen.top());
            if (not deleted_edges.empty()){
                result.push_back(deleted_edges.top());
                deleted_edges.pop();
            }
            seen.pop();
        } else {
            Fragment edge = edges[seen.top()].back();
            edges[seen.top()].pop_back();
            deleted_edges.push(edge);
            seen.push(edge.end);
        }
    }
    std::reverse(result.begin(),result.end());
    return result;
}


bool is_edges_empty(const map<int, vector<Fragment>> &edges) {
    for(const auto &vertex2edges:edges){
        if (not vertex2edges.second.empty()){
            return false;
        }
    }
    return true;
}

vector<int> del_new_edge(const vector<Fragment>& path, int start, int end) {
    int index_start = -1;
    for (int i = 0; i < path.size(); ++i) {
        if (path[i].number==-1)
            index_start = i;
    }
    vector<int> res;
    for (int j = index_start+1; j < path.size(); ++j) {
        res.push_back(path[j].number);
    }
    for (int j = 0; j < index_start; ++j) {
        res.push_back(path[j].number);
    }
    return res;
}

int compute_d(vector<int> &parts) {
    int d_i = parts[1];
    for (int i = 2; i < parts.size() - 1; ++i) {
        if (parts[i] != d_i)
            return -1;
    }
    return d_i;
}

int main() {

    int n;
    cin >> n;

    int d = -1;
    vector<Fragment> fragments;
    for (int i = 0; i < n; ++i) {
        int m, s;
        cin >> m >> s;
        vector<int> parts(m + 1, 0);
        int prev = 0;
        for (int j = 0; j < m; ++j) {
            int tmp;
            cin >> tmp;
            parts[j] = tmp - prev;
            prev = tmp;
        }
        parts[m] = s - prev;
        if (parts.size() > 2) {
            int d_i = compute_d(parts);
            if (d_i == -1) {
                cout << "No";
                return 0;
            }
            if (d == -1)
                d = d_i;
            else {
                if (d != d_i) {
                    cout << "No";
                    return 0;
                }
            }
        }
        Fragment tmp(parts[0], parts.back(), i+1);
        fragments.push_back(tmp);
    }
    vector<int> possible_d;
    if (d == -1){
        int min1 = 1000000001, min2= 1000000001, max1 = -1, max2=-1;
        for(const Fragment& fragment:fragments){
            if (fragment.start>=max1){
                max2=max1;
                max1 = fragment.start;
            }
            if (fragment.end <= min1){
                min2 = min1;
                min1 = fragment.end;
            }
        }
        possible_d.push_back(min1+max1);
        possible_d.push_back(min1+max2);
        possible_d.push_back(min2+max1);
        possible_d.push_back(min2+max2);
    }
    else{
        possible_d.push_back(d);
    }
    for (const auto d:possible_d) {
        map<int, vector<Fragment>> edges;
        create_edges(fragments, edges, d);

        int start = -1, end = -1;
        if (not is_euler_path_possible(edges, start, end)) {
            continue;
        }
        if (start == -1) {
            start = edges.begin()->first;
        }
        if (end == -1)
            end = edges.begin()->first;
        Fragment additional(end, start, -1);
        edges[end].push_back(additional);
        vector<Fragment> path = find_euler_circle(edges, start);
        if (not is_edges_empty(edges)){
            continue;
        }
        vector<int> res = del_new_edge(path, start, end);
        cout << "Yes" << endl;
        for (int vertex:res)
            cout << vertex << " ";
        return 0;
    }
    cout << "No";
    return 0;
}





