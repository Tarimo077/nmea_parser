#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "nmea_parser.h"

TEST_CASE("NMEAParser parses GPGGA sentence correctly") {
    NMEAParser parser;
    std::string sentence = "$GPGGA,123456.78,3723.2475,N,12202.3416,W,1,08,0.9,545.4,M,46.9,M,,*47";
    NMEAData data = parser.parseSentence(sentence);

    REQUIRE(data.sentenceType == "$GPGGA");
    REQUIRE(data.time == "12:34:56.78");
    REQUIRE(data.latitude == "37°23.2475'N");
    REQUIRE(data.longitude == "122°02.3416'W");
}

TEST_CASE("NMEAParser parses GPGLL sentence correctly") {
    NMEAParser parser;
    std::string sentence = "$GPGLL,4916.45,N,12311.12,W,225444,A,*1D";
    NMEAData data = parser.parseSentence(sentence);

    REQUIRE(data.sentenceType == "$GPGLL");
    REQUIRE(data.latitude == "49°16.45'N");
    REQUIRE(data.longitude == "123°11.12'W");
    REQUIRE(data.time == "22:54:44");
}

TEST_CASE("NMEAParser parses GPRMC sentence correctly") {
    NMEAParser parser;
    std::string sentence = "$GPRMC,235947,A,3723.2475,N,12202.3416,W,022.4,084.4,230394,003.1,W*6A";
    NMEAData data = parser.parseSentence(sentence);

    REQUIRE(data.sentenceType == "$GPRMC");
    REQUIRE(data.time == "23:59:47");
    REQUIRE(data.latitude == "37°23.2475'N");
    REQUIRE(data.longitude == "122°02.3416'W");
    REQUIRE(data.speed == "022.4");
    REQUIRE(data.course == "084.4");
    REQUIRE(data.date == "230394");
}
