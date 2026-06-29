class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;

        double hourangle = hour * 30.0 + minutes * 0.5;
        double minangle = minutes * 6.0;

        double diff = abs(hourangle - minangle);

        return min(diff, 360.0 - diff);
    }
};