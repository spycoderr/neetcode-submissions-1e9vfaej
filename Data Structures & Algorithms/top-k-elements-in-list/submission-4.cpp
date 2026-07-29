class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> hehe;

        // Count frequency
        for (int num : nums) {
            hehe[num]++;
        }

        // Store {frequency, number}
        vector<pair<int, int>> arr;

        for (auto &[key, value] : hehe) {
            arr.push_back({value, key});
        }

       
        sort(arr.begin(), arr.end());

        vector<int> ans;

       int n = arr.size();

for (int i = n - 1; i >= n - k; i--) {
    ans.push_back(arr[i].second);
}

        return ans;
    }
};