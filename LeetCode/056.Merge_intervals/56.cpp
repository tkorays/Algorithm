/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

Subscribe to see which companies asked this question.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 #include <vector>
 using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    static int mySort(Interval a, Interval b) {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()) return vector<Interval>();
        std::sort(intervals.begin(), intervals.end(), Solution::mySort);
        vector<Interval> ret;
        ret.push_back(intervals[0]);
        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i].start <= ret.back().end) {
                ret.back().end = ret.back().end < intervals[i].end ? intervals[i].end : ret.back().end;
            } else {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};