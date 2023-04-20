#include <iostream>
#include <type_traits>
#include <cmath>

using namespace std;

// Templated function for floating-point types
template <typename T>
typename enable_if<is_floating_point<T>::value, T>::type
half(T value) {
    return value / 2;
}

// Function for integer types
template <typename T>
typename enable_if<is_integral<T>::value, T>::type
half(T value) {
    return static_cast<T>((value + (value % 2)) / 2);
}

int main() {
    // Test the functions with different numeric types
    double d = 10.0;
    float f = 12.5f;
    int i = 7;

    cout << "Half of " << d << " is " << half(d) << endl;
    cout << "Half of " << f << " is " << half(f) << endl;
    cout << "Half of " << i << " is " << half(i) << endl;

    return 0;
}
