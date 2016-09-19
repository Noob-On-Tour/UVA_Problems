#include <iostream>
#include <complex>
#include <cstdio>
#include <vector>

using namespace std;
#define PI (2*acos(0))
int N;
double A, in, out, apothem;


double apothem1(double area) {
    return sqrt(area / PI);
}

double inscribedArea(int N, double polyArea) {
    return PI * (polyArea / (N * tan(PI / N)));
}


double circumscribedArea(double apothem) {
    double halfSide = apothem * tan(PI / N);
    double radius = sqrt(pow(apothem, 2) + pow(halfSide, 2));
    return PI * radius * radius;
}

int main() {
    vector<pair<double, double> > ans;
    while (true) {
        scanf("%d %lf", &N, &A);
        if (N < 3) break;
        in = inscribedArea(N, A);
        apothem = apothem1(in);
        out = circumscribedArea(apothem);
        ans.push_back(make_pair(out - A, A - in));
    }
    for (int i = 0; i < ans.size(); ++i) {
        printf("Case %d: %0.5f %0.5f", i + 1, ans[i].first, ans[i].second);
        printf("\n");
    }
}
