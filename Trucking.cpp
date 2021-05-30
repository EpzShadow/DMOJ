#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;

int main() {
    int n, r, c;
   cin >> n;
   cin >> r;
   cin >> c;

    std::vector < unordered_map<int, int>>   weights;
    weights.resize(n);
    for (int i = 0; i < r; ++i) {
        int m1, m2, m3;
       cin >> m1;
       cin >> m2;
     cin >> m3;
        weights[m1 - 1][m2 - 1] =max(weights[m1 - 1][m2 - 1], m3);
        weights[m2 - 1][m1 - 1] = max(weights[m2 - 1][m1 - 1], m3);
    }
    unordered_set<int> visiting_cities;
    for (int i = 0; i < c; ++i) {
        int m1;
       cin >> m1;
        visiting_cities.insert(m1 - 1);
    }

    if (visiting_cities.size() == 0) return 0;
    int min_weigth_in_span_tree = numeric_limits<int>::max();
   unordered_set<int> cities_in_span_tree;
    int starting = *visiting_cities.begin();
    cities_in_span_tree.insert(starting);
    visiting_cities.erase(visiting_cities.begin());
   priority_queue < vector<int>> paths;
    for (const auto weight : weights[starting]) {
       vector<int> v{ weight.second, weight.first };
        paths.push(v);
    }
    while (visiting_cities.size() > 0) {
        while (true) {
            auto next_potential = paths.top();
            paths.pop();
            cities_in_span_tree.insert(next_potential[1]);
            for (const auto& weight : weights[next_potential[1]]) {
                vector<int> v{ weight.second, weight.first };
                if (cities_in_span_tree.count(v[1]) == 0) {
                    paths.push(v);
                }
            }
            if (min_weigth_in_span_tree > next_potential[0]) {
                min_weigth_in_span_tree = next_potential[0];
            }
            if (visiting_cities.count(next_potential[1]) > 0) {
                visiting_cities.erase(next_potential[1]);
                break;
            }

        }
    }
   cout << min_weigth_in_span_tree;
}
