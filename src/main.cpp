#include "nmea_parser.h"
#include <iostream>

int main() {
    NMEAParser parser;
    std::vector<NMEAData> data = parser.parseFile("jogging_path.txt");

    for (const auto &entry : data) {
        std::cout << "Type: " << entry.sentenceType << "\n";
        std::cout << "Time: " << entry.time << "\n";
        std::cout << "Latitude: " << entry.latitude << "\n";
        std::cout << "Longitude: " << entry.longitude << "\n";
        if (!entry.speed.empty()) {
            std::cout << "Speed: " << entry.speed << " knots\n";
        }
        if (!entry.course.empty()) {
            std::cout << "Course: " << entry.course << "°\n";
        }
        if (!entry.date.empty()) {
            std::cout << "Date: " << entry.date << "\n";
        }
        std::cout << "------------------------\n";
    }

    return 0;
}
