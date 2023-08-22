#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

// 2
int numberEqualFour(const std::vector<int> &vec) {
    return std::count(vec.begin(), vec.end(), 4);
}
void printNumberEqualFour(const std::vector<int> &vec) {
    std::cout << numberEqualFour(vec) << std::endl;
}

// 3
bool graterThanFour(int num) {
    return num > 4;
}
int numberGraterThanFour(const std::vector<int> &vec) {
    return std::count_if(vec.begin(), vec.end(), graterThanFour);
}
void printNumberGraterThanFour(const std::vector<int> &vec) {
    *std::ostream_iterator<int>(std::cout, "\n") = numberGraterThanFour(vec);
}
// 4
bool lessThanEight(int num) {
    return num < 8;
}
void deleteLessThanEight(std::vector<int> &vec) {
    vec.erase(std::remove_if(vec.begin(), vec.end(), lessThanEight), vec.end());
}

// 5, 8
void printCurrent(int num) {
    std::cout << num << ' ';
}
void printVector(const std::vector<int> &vec) {
    std::for_each(vec.begin(),vec.end(),printCurrent),(std::cout<<std::endl);
}

// 7
int currentDifference(int num1,int num2) {
    return num1 - num2;
}
void differenceVector(std::vector<int> &emptyVec, const std::vector<int> &vec) {
    std::transform(vec.begin(),std::prev(vec.end()),std::next(vec.begin()),std::back_inserter(emptyVec),currentDifference);
}

// 9
int sumVector(const std::vector<int> &vec) {
    return std::accumulate(vec.begin(), vec.end(), 0);
}

void printSumVector(const std::vector<int> &vec) {
    std::cout << sumVector(vec) << std::endl;
}

int main() {
    std::vector<int> vec = {4, 4, 4, 6, 10, 20,30, 7};

    std::cout << "Original vector: ";
    printVector(vec);

    std::cout << "Number of elements equal to 4: ";
    printNumberEqualFour(vec);

    std::cout << "Number of elements greater than 4: ";
    printNumberGraterThanFour(vec);

    std::cout << "After deleting elements less than 8: ";
    deleteLessThanEight(vec);
    printVector(vec);

    std::vector<int> diffVector;
    differenceVector(diffVector, vec);

    std::cout << "Difference vector: ";
    printVector(diffVector);

    std::cout << "Sum of the difference vector: ";
    printSumVector(diffVector);

    return 0;
}

