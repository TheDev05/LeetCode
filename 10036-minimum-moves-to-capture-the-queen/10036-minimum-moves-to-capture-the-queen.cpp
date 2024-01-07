class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        
    int delta1 = 0;
    int delta2 = -1;

    int min = INT_MAX;
    if (a == e)
    {
        if (c == a && ((b < d && d < f) || (f < d && d < b))) {}
        else
            min = 1;
    }
    else if (b == f)
    {
        if (b == d && ((a < c && c < e) || (e < c && c < a))){}
        else
            min = 1;
    }

    if (2 < min)
        min = 2;

    if ((c < e && f > d) || (e < c && f < d))
        delta1 = (d - c), delta2 = f - e;
    else if ((c > e && d < f) || (e > c && f < d))
        delta1 = d + c, delta2 = e + f;

    if (delta1 == delta2)
    {
        int len = 1;
        if ((b - a == delta1) || (b + a == delta2))
            if ((a > c && e > a) || (a > e && c > a))
                len++;

        if (len < min)
            min = len;
    }

    return min;
    
    }
};