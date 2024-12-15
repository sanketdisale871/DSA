class Solution {
    private:
    double findChange(int pass, int stu){
        double chng = double(pass+1/stu+1) - double(pass/stu);
        return chng;
    }

public:
  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    auto profit = [&](double pass, double total) {
        return (pass + 1) / (total + 1) - pass / total;
    };
    double total = 0;
    priority_queue<pair<double, array<int, 2>>> pq;
    for (auto &c : classes) {
        total += (double) c[0] / c[1];
        pq.push({profit(c[0], c[1]), {c[0], c[1]}});
    }
    while (extraStudents--) {
        auto [added_profit, c] = pq.top(); pq.pop();
        total += added_profit;
        pq.push({profit(c[0] + 1, c[1] + 1), {c[0] + 1, c[1] + 1}});
    }
    return total / classes.size();
}
};