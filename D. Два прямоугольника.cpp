#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    float s1, s2, s3 = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    // находим левую, правую, верхнюю, нижнюю грыницы первого прямоугольника
    int l1 = min(x1, x2); 
    int r1 = max(x1, x2);  
    int t1 = max(y1, y2);  
    int b1 = min(y1, y2);  

    // находим левую, правую, верхнюю, нижнюю грыницы второго прямоугольника
    int l2 = min(x3, x4);
    int r2 = max(x3, x4);
    int t2 = max(y3, y4);
    int b2 = min(y3, y4);

    // Вычисление площадей прямоугольников
    s1 = (r1 - l1) * (t1 - b1);
    s2 = (r2 - l2) * (t2 - b2);

    // Нахождение координат пересечения
    int lt = max(l1, l2);  
    int rt = min(r1, r2); 
    int t = min(t1, t2);   
    int b = max(b1, b2);   

    // Вычисление площади пересечения, если оно существует
    if (lt < rt && b < t) {
        s3 = (rt - lt) * (t - b);
    }

    // Формула включений-исключений
    cout << s1 + s2 - s3;
}
