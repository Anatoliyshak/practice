#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, x2, y1, y2, x3, y3, x4, y4;
    float s1, s2, s3 = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    int l1 = min(x1,x2);
    int r1 = max(x1,x2);
    int t1 = max(y1,y2);
    int b1 = min(y1,y2);

    int l2 = min(x4,x3);
    int r2 = max(x4,x3);
    int t2 = max(y4,y3);
    int b2 = min(y4,y3);

    s1 = (r1 - l1) * (t1-b1);
    s2 = (r2 - l2) * (t2-b2);

    int lt = max(l1, l2);
    int rt = min(r1, r2);
    int t = min(t1, t2);
    int b = max(b1, b2);


    

    if (lt < rt and b < t) {
        s3 = (rt - lt) * (t - b);
    }
    cout << s1 + s2 - s3;
}