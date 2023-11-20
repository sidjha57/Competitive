#include <iostream>
#include <vector>
#include <algorithm>

// Definition for an Interval
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// The merge function
std::vector<Interval> merge(std::vector<Interval> &A) {
    std::vector<Interval> mergedIntervals;
    std::sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++) {
        if (i == 0 || A[i].start > mergedIntervals.back().end) {
            mergedIntervals.push_back(A[i]);
        } else if (mergedIntervals.back().end >= A[i].start) {
            mergedIntervals.back().end = std::max(mergedIntervals.back().end, A[i].end);
        }
    }
    return mergedIntervals;
}

int main() {
    // Create sample input intervals
    std::vector<Interval> sampleIntervals;
    sampleIntervals.push_back(Interval(1, 3));
    sampleIntervals.push_back(Interval(2, 6));
    sampleIntervals.push_back(Interval(8, 10));
    sampleIntervals.push_back(Interval(15, 18));

    // Call the merge function
    std::vector<Interval> mergedIntervals = merge(sampleIntervals);

    // Print the merged intervals
    std::cout << "Merged Intervals:" << std::endl;
    for (const Interval& interval : mergedIntervals) {
        std::cout << "[" << interval.start << ", " << interval.end << "] ";
    }
    std::cout << std::endl;

    return 0;
}
