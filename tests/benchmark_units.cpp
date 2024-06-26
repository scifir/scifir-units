#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING

#include "catch2/catch_all.hpp"
#include "../units/scalar_unit.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("Benchmark of scalar_unit class","[!benchmark]") {
	BENCHMARK("Sum of floats") {
		float a = 1.5f;
		float b = 2.5f;
		return a + b;
    };

	BENCHMARK("Sum of doubles") {
        double a = 1.5;
		double b = 2.5;
		return a + b;
    };

	BENCHMARK("Sum of long doubles") {
        long double a = 1.5;
		long double b = 2.5;
		return a + b;
    };

	BENCHMARK("Sum of scalar_unit class") {
		scalar_unit a = scalar_unit(1.5f,"m");
		scalar_unit b = scalar_unit(2.5f,"m");
		return a + b;
    };

	BENCHMARK("Substraction of floats") {
		float a = 1.5f;
		float b = 2.5f;
		return a - b;
    };

	BENCHMARK("Substraction of doubles") {
        double a = 1.5;
		double b = 2.5;
		return a - b;
    };

	BENCHMARK("Substraction of long doubles") {
        long double a = 1.5;
		long double b = 2.5;
		return a - b;
    };

	BENCHMARK("Substraction of scalar_unit class") {
		scalar_unit a = scalar_unit(1.5f,"m");
		scalar_unit b = scalar_unit(2.5f,"m");
		return a - b;
    };

	BENCHMARK("Product of floats") {
		float a = 1.5f;
		float b = 2.5f;
		return a * b;
    };

	BENCHMARK("Product of doubles") {
        double a = 1.5;
		double b = 2.5;
		return a * b;
    };

	BENCHMARK("Product of long doubles") {
        long double a = 1.5;
		long double b = 2.5;
		return a * b;
    };

	BENCHMARK("Product of scalar_unit class") {
		scalar_unit a = scalar_unit(1.5f,"m");
		scalar_unit b = scalar_unit(2.5f,"m");
		return a * b;
    };

	BENCHMARK("Division of floats") {
		float a = 1.5f;
		float b = 2.5f;
		return a / b;
    };

	BENCHMARK("Division of doubles") {
        double a = 1.5;
		double b = 2.5;
		return a / b;
    };

	BENCHMARK("Division of long doubles") {
        long double a = 1.5;
		long double b = 2.5;
		return a / b;
    };

	BENCHMARK("Division of scalar_unit class") {
		scalar_unit a = scalar_unit(1.5f,"m");
		scalar_unit b = scalar_unit(2.5f,"m");
		return a / b;
    };
}
