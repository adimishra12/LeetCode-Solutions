class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int closestx, closesty;
        if(x2 <= xCenter)
            closestx = x2;
        else if(x1 > xCenter)
            closestx = x1;
        else
            closestx = xCenter;

        if(y2 <= yCenter)
            closesty = y2;
        else if(y1 > yCenter)
            closesty = y1;
        else
            closesty = yCenter;

        return sqrt((closestx - xCenter)*(closestx - xCenter) + (closesty - yCenter)*(closesty - yCenter)) <= radius;
        
    }
};