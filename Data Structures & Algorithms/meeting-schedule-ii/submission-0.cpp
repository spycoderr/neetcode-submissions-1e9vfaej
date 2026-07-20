/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
   public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> events;
        int overlaps = 0;
        int maxoverlaps = 0;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            events[intervals[i].start]++;
            events[intervals[i].end]--;
        }
            for (auto it : events) {
                overlaps = overlaps + it.second;
                if (overlaps > maxoverlaps) {
                    maxoverlaps = overlaps;
                }
            }
              return maxoverlaps;
        }
      
    
};
