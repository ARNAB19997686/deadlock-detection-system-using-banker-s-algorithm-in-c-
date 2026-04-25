#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;
   // Resources currently allocated to each process
    vector<vector<int>> alloc(n, vector<int>(m));
   // Maximum resources each process may need
    vector<vector<int>> maxm(n, vector<int>(m));
    //Remaining resources needed
    vector<vector<int>> need(n, vector<int>(m));
    //Resources currently available in system
    vector<int> avail(m);

    cout << "Enter Allocation Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    cout << "Enter Max Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maxm[i][j];

    cout << "Enter Available Resources:\n";
    for (int i = 0; i < m; i++)
        cin >> avail[i];

    // Need calculation
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maxm[i][j] - alloc[i][j];

    vector<int> work = avail;
    vector<bool> finish(n, false);
    vector<int> safeSeq;

    int count = 0;

    while (count < n) {
        bool found = false;

        for (int p = 0; p < n; p++) {
            if (!finish[p]) {
                bool canExecute = true;

                for (int j = 0; j < m; j++) {
                    if (need[p][j] > work[j]) {
                        canExecute = false;
                        break;
                    }
                }

                if (canExecute) {
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[p][j];

                    safeSeq.push_back(p);
                    finish[p] = true;
                    found = true;
                    count++;
                }
            }
        }

        if (!found) {
            cout << "\nSystem is NOT in SAFE state (Deadlock risk)\n";
            return 0;
        }
    }

    cout << "\nSystem is in SAFE state\nSafe Sequence: ";
    for (int   i : safeSeq)
        cout << "P" << i << " ";

    cout << endl;
    return 0;
}