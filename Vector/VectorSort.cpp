#include <bits/stdc++.h>
using namespace std;
int TotalMarks(vector<int> marks)
{
    return marks[0] + marks[1] + marks[2];
}
bool compare(pair<string, vector<int>> s1, pair<string, vector<int>> s2)
{
    vector<int> m1 = s1.second;
    vector<int> m2 = s2.second;
    return TotalMarks(m1) > TotalMarks(m2);
}
int main()
{
    vector<pair<string, vector<int>>> student_marks = {
        {"Raj", {10, 20, 11}},
        {"Prajakta", {10, 21, 3}},
        {"Harshit", {4, 5, 6}},
        {"Zeus", {10, 60, 50}}};
    sort(student_marks.begin(), student_marks.end(), compare);
    for (auto x : student_marks)
    {
        cout << x.first << " " << TotalMarks(x.second) << endl;
    }
    return 0;
}