#include "nmea_parser.h"
#include <fstream>
#include <sstream>
#include <iomanip>

std::vector<NMEAData> NMEAParser::parseFile(const std::string &filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<NMEAData> data;

    while (std::getline(file, line)) {
        data.push_back(parseSentence(line));
    }

    return data;
}

NMEAData NMEAParser::parseSentence(const std::string &sentence) {
    NMEAData data;
    auto parts = split(sentence, ',');

    data.sentenceType = parts[0];

    if (data.sentenceType == "$GPGGA") {
        data.time = formatTime(parts[1]);
        data.latitude = formatLatitude(parts[2], parts[3]);
        data.longitude = formatLongitude(parts[4], parts[5]);
    } else if (data.sentenceType == "$GPGLL") {
        data.latitude = formatLatitude(parts[1], parts[2]);
        data.longitude = formatLongitude(parts[3], parts[4]);
        data.time = formatTime(parts[5]);
    } else if (data.sentenceType == "$GPRMC") {
        data.time = formatTime(parts[1]);
        data.latitude = formatLatitude(parts[3], parts[4]);
        data.longitude = formatLongitude(parts[5], parts[6]);
        data.speed = parts[7];
        data.course = parts[8];
        data.date = parts[9];
    }

    return data;
}

std::vector<std::string> NMEAParser::split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);

    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

std::string NMEAParser::formatLatitude(const std::string &lat, const std::string &dir) {
    return lat.substr(0, 2) + "°" + lat.substr(2) + "'" + dir;
}

std::string NMEAParser::formatLongitude(const std::string &lon, const std::string &dir) {
    return lon.substr(0, 3) + "°" + lon.substr(3) + "'" + dir;
}

std::string NMEAParser::formatTime(const std::string &time) {
    std::ostringstream formattedTime;
    formattedTime << time.substr(0, 2) << ":" << time.substr(2, 2) << ":" << time.substr(4, 2);
    if (time.size() > 6) {
        formattedTime << "." << time.substr(6);
    }
    return formattedTime.str();
}
