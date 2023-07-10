#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>

using namespace std;

int main() {
    // Step 2: Parameter Setting
    unordered_map<string, int> ProductList = {
        {"p1", 10}, {"p2", 15}, {"p3", 20}, {"p4", 25}, {"p5", 30}, {"p6", 35}, {"p7", 50},
        {"p8", 40}, {"p9", 55}, {"p10", 60}, {"p11", 65}, {"p12", 75}, {"p13", 70},
        {"p14", 45}
    };
    int LB = 290;
    int UB = 310;
    set<vector<string>> ResultList; // Store Result List i.e. list of sets whose sum is between 90 and 210.
    int Iterations = 1000; // Number of Iterations

    // Step3: Start Program
    for (int i = 0; i < Iterations; ++i) {
        // Select combo size (i.e. number of products in a combo)
        int SetSize = rand() % (ProductList.size() - 2) + 2;

        // Select number of elements from Set
        vector<string> ComboList;
        for (const auto& pair : ProductList) {
            ComboList.push_back(pair.first);
        }
        random_shuffle(ComboList.begin(), ComboList.end());
        ComboList.resize(SetSize);
        sort(ComboList.begin(), ComboList.end());

        // Sum the products in ComboList
        int ComboSum = 0;
        for (const auto& product : ComboList) {
            ComboSum += ProductList[product];
        }

        // Check the Sum Between LB and UB
        if (ComboSum >= LB && ComboSum <= UB) {
            ResultList.insert(ComboList);
        }
    }

    // Print all the sets whose sum is between LB and UB
    for (const auto& r : ResultList) {
        cout << "(";
        for (int i = 0; i < r.size(); ++i) {
            cout << r[i];
            if (i < r.size() - 1) {
                cout << ", ";
            }
        }
        cout << ")" << endl;
    }

    // Print total sets
    cout << "\nTotal Sets: " << ResultList.size() << endl;

    return 0;
}
