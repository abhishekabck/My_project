# include <bits/stdc++.h>
using namespace std;


    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
    sort(enemyEnergies.begin(), enemyEnergies.end());
    int points = 0;
    vector<bool> marked(enemyEnergies.size(), false);
    
    for (int i = 0; i < enemyEnergies.size(); i++) {
        if (currentEnergy >= enemyEnergies[i]) {
            points++;
            currentEnergy -= enemyEnergies[i];
        } else {
            currentEnergy += enemyEnergies[i];
            marked[i] = true;
        }
    }
    
    return points;
    }

int main(){
    vector<int> en = {3,2,2};
    int cur = 2;
    printf("%lld",maximumPoints(en,cur));
    return 0;
}



