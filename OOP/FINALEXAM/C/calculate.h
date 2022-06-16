template<typename T>
T calculate(char expressionType, int _x, int _y, int _z) {
    T x(_x);
    T y(_y);
    T z(_z);
    if (expressionType == 'A') {
        return x * x + y * y + z * z;
    }
    if (expressionType == 'B') {
        return x * y + y / z - x * z;
    }
    if (expressionType == 'C') {
        return y * 3 * z - x * z / (y - 2) - x * y / (z + 1);
    }
}