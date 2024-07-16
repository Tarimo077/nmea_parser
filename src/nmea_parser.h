#ifndef NMEA_PARSER_H
#define NMEA_PARSER_H

#include <string>
#include <vector>

struct NMEAData {
    std::string sentenceType;
    std::string time;
    std::string latitude;
    std::string longitude;
    std::string speed;
    std::string course;
    std::string date;
};

class NMEAParser {
public:
    std::vector<NMEAData> parseFile(const std::string &filename);
    NMEAData parseSentence(const std::string &sentence);

private:
    std::vector<std::string> split(const std::string &s, char delimiter);
    std::string formatLatitude(const std::string &lat, const std::string &dir);
    std::string formatLongitude(const std::string &lon, const std::string &dir);
    std::string formatTime(const std::string &time);
};

#endif // NMEA_PARSER_H
