#include <map>
#include <iostream>
#include <vector>

int main() {
    int N, M, value;
    std::cin >> N;
    std::string sensor;
    std::map<std::string, std::vector<int>> sensors_values;
    for (auto i = 0; i < N; i++) {
        std::cin >> sensor >> value;
        sensors_values[sensor].push_back(value);
    }
    std::cin >> M;
    for(auto i = 0; i < M; i++) {
        std::cin >> sensor;
        auto sensor_iterator = sensors_values.find(sensor);
        if (sensor_iterator == sensors_values.end()) {
            std::cout << "no data" << std::endl;
            continue;
        }
        auto& values = sensor_iterator->second;
        auto median_iterator = std::next(values.begin(),
            (static_cast<int>(values.size()) - 1) / 2);
        std::nth_element(values.begin(), median_iterator, values.end());
        std::cout << *median_iterator << std::endl;
    }
}