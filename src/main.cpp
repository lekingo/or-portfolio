#include <iostream>
#include <string>
#include <memory>


struct City
{
    int id;
    double x, y;
};

class Widget {
    public:
        Widget() {
            std::cout << "Widget created" << std::endl;
        }

        ~Widget() {
            std::cout << "Widget destroyed." << std::endl;
        }
    
};

int main(){
    double x = 5.0; 
    if (x>2){
        std::cout << "x est plus grand que 2" << std::endl;
    }
    else
    {
        std::cout << " x est plus petit ou égal à 2" << std::endl;
    }

    for (x=1;x<10; x++){
        std::cout << x << std::endl;
    }

    while (x<15){
        x++;
        std::cout << x << std::endl;
    }

    std::cout << x << std::endl;

    std::cout << "hello" << std::endl;
    City test = {1,2,3};
    std::string tes2 = std::to_string(test.id);
    std::cout << tes2;

    {
        std::unique_ptr<Widget> test12 = std::make_unique<Widget>();
        std::cout << "Am I destroyed?" << std::endl;
    }

    std::cout << "And now, Am I destroyed?" << std::endl;
    return 0;
}
    







































// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <limits>

// struct City{
//     int id;
//     double x, y;
// };

// double distance(const City& a, const City& b){
//     return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
// }

// std::vector<int> greedyTSP(const std::vector<City>& cities){
//     int n = cities.size();
//     std::vector<bool> visited(n, false);
//     std::vector<int> tour;

//     int current = 0;
//     visited[current] = true;
//     tour.push_back(current);

//     for (int step = 1; step < n; step++) {
//         double best = std::numeric_limits<double>::infinity();
//         int next = -1;
//         for (int i = 0; i < n; i++) {
//             if (!visited[i] && distance(cities[current], cities[i]) < best) {
//                 best = distance(cities[current], cities[i]);
//                 next = i;
//             }
//         }
//         visited[next] = true;
//         tour.push_back(next);
//         current = next;
//     }
//     return tour;
// }

// int main(){
//     std::vector<City> cities = {
//         {0, 0.0, 0.0},
//         {1, 3.0, 4.0},
//         {2, 6.0, 1.0},
//         {3, 2.0, 7.0},
//         {4, 5.0, 5.0},
//     };

//     std::vector<int> tour = greedyTSP(cities);

//     std::cout << "Tour: ";
//     for (int id : tour) std::cout << id << " ";
//     std::cout << std::endl;

//     return 0;

// }