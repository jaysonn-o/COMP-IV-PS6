// "Copyright [2024] <Jason Ossai>"
#define BOOST_TEST_MODULE RandWriterTest
#include <boost/test/included/unit_test.hpp>
#include "RandWriter.hpp"

BOOST_AUTO_TEST_CASE(constructor_test) {
    BOOST_REQUIRE_NO_THROW(RandWriter("gagggagaggcgagaaa", 2));
    BOOST_REQUIRE_THROW(RandWriter("gag", 4), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(orderK_test) {
    RandWriter rw("gagggagaggcgagaaa", 2);
    BOOST_REQUIRE_EQUAL(rw.orderK(), 2);
}

BOOST_AUTO_TEST_CASE(freq_test) {
    RandWriter rw("gagggagaggcgagaaa", 2);
    BOOST_REQUIRE_EQUAL(rw.freq("ga"), 5);
    BOOST_REQUIRE_THROW(rw.freq("gag"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(kRand_test) {
    RandWriter rw("gagggagaggcgagaaa", 2);
    BOOST_REQUIRE_NO_THROW(rw.kRand("ga"));
    BOOST_REQUIRE_THROW(rw.kRand("xx"), std::invalid_argument);
    BOOST_REQUIRE_THROW(rw.kRand("gag"), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(generate_test) {
    RandWriter rw("gagggagaggcgagaaa", 2);
    BOOST_REQUIRE_NO_THROW(rw.generate("ga", 5));
    BOOST_REQUIRE_THROW(rw.generate("gag", 5), std::invalid_argument);
    BOOST_REQUIRE_THROW(rw.generate("xx", 5), std::invalid_argument);
    std::string result = rw.generate("ga", 10);
    BOOST_REQUIRE_EQUAL(result.length(), 10);
}
