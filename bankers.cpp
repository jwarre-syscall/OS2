#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() 
{
    int n, m;

    // Open the input file
    string filename;
    cout << "Enter input filename: ";
    cin >> filename;
    ifstream infile(filename);
    
    if (!infile) {
        cerr << "Error: could not open input.txt\n";
        return 1;
    }

    // Read number of processes and resources
    infile >> n >> m;

    vector<vector<int>> alloc(n, vector<int>(m));
    vector<vector<int>> max(n, vector<int>(m));
    vector<int> avail(m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            infile >> alloc[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            infile >> max[i][j];

    for (int j = 0; j < m; j++)
        infile >> avail[j];

    // Calculate Need Matrix
    vector<vector<int>> need(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    vector<int> safeSeq(n);
    vector<bool> finish(n, false);
    vector<int> work = avail;
    int count = 0;

    while (count < n) 
    {
        bool found = false;
        for (int i = 0; i < n; i++) 
        {
            if (!finish[i]) {
                bool possible = true;
                for (int j = 0; j < m; j++) 
                {
                    if (need[i][j] > work[j]) 
                    {
                        possible = false;
                        break;
                    }
                }
                if (possible) 
                {
                    for (int j = 0; j < m; j++)
                        work[j] += alloc[i][j];
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) 
        {
            cout << "System is not in a safe state.\n";
            return 0;
        }
    }

    cout << "System is in a safe state.\nSafe sequence is: ";
    for (int i = 0; i < n; i++)
        cout << "P" << safeSeq[i] << " ";
    cout << endl;

    return 0;
}
