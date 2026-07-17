class Solution {
   public:
    bool check(vector<pair<int, int>>& hehe, int index, int finish_index, int fuel) {
        if (index == finish_index) {
            return true;
        }

        fuel = fuel + hehe[index].first - hehe[index].second;

        if (fuel < 0) {
            return false;
        }

        return check(hehe, (index + 1) % hehe.size(), finish_index, fuel);
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<pair<int, int>> hehe;

        for (int i = 0; i < gas.size(); i++) {
            hehe.push_back({gas[i], cost[i]});
        }

        for (int i = 0; i < hehe.size(); i++) {
            if (hehe[i].first - hehe[i].second < 0) {
                continue;
            }

            bool ok = check(hehe, (i + 1) % hehe.size(), i, hehe[i].first - hehe[i].second);

            if (ok) {
                return i;
            }
        }

        return -1;
    }
};
