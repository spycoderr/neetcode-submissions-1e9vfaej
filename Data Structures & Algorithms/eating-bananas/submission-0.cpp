class Solution {
   public:
    int check(vector<int>& piles, int mid) {
        int time = 0;

        for (int i = 0; i < piles.size(); i++) {
            time += ceil((double)piles[i] / mid);
        }

        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxu = 0;

        for (int i = 0; i < piles.size(); i++) {
            maxu = max(maxu, piles[i]);
        }

        int left = 1;
        int right = maxu;
        int final = maxu;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int ans = check(piles, mid);

            if (ans <= h) {
                final = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return final;
    }
};
