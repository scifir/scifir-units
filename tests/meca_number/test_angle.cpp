#define CATCH_CONFIG_MAIN

#include "catch2/catch_all.hpp"
#include "../../meca_number/angle.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("angle class") {
	SECTION("Constructors of angle class")
    {
        angle a;
        CHECK(a.get_value() == 0.0f);
        angle b(10.0f);
        CHECK(b.get_value() == 10.0f);
        angle c(15.0);
        CHECK(c.get_value() == 15.0);
        angle d((long double)20.0);
        CHECK(d.get_value() == (long double)20.0);
        angle e(d);
        CHECK(e.get_value() == (long double)20.0);
        angle f(std::move(c));
        CHECK(f.get_value() == 15.0);
        angle g(5);
        CHECK(g.get_value() == 5.0f);
        angle h("10°");
        CHECK(h.get_value() == 10.0f);
        angle h2("10.768°");
        CHECK(h2.get_value() == 10.768f);
        angle i2("15 deg");
        CHECK(i2.get_value() == 15.0f);
        angle i3("0.349 rad");
        CHECK(i3.display() == "19.99°");
        angle i4("200 grad");
        CHECK(i4.display() == "180°");
        angle i5("0.5 tr");
        CHECK(i5.display() == "180°");
        scalar_unit j2("7 N");
        angle j(j2);
        CHECK(j.get_value() == 0.0f);
        scalar_unit k2("7 N");
        scalar_unit k3("2 N");
        angle k(scalar_unit(k2/k3));
        CHECK(k.get_value() == 3.5f);
        angle l(0.349f,angle::RADIAN);
        CHECK(l.display() == "19.99°");
        angle l2(0.349,angle::RADIAN);
        CHECK(l2.display() == "19.99°");
        angle l3(0.349l,angle::RADIAN);
        CHECK(l3.display() == "19.99°");
        angle l4(5,angle::RADIAN);
        CHECK(l4.display() == "286.47°");
        angle m1(100.0f,angle::GRADIAN);
        CHECK(m1.display() == "90°");
        angle m2(200.0,angle::GRADIAN);
        CHECK(m2.display() == "180°");
        angle m3(300.0l,angle::GRADIAN);
        CHECK(m3.display() == "270°");
        angle m4(350,angle::GRADIAN);
        CHECK(m4.display() == "315°");
        angle n1(0.25f,angle::TURN);
        CHECK(n1.display() == "90°");
        angle n2(0.5,angle::TURN);
        CHECK(n2.display() == "180°");
        angle n3(0.75l,angle::TURN);
        CHECK(n3.display() == "270°");
        angle n4(1,angle::TURN);
        CHECK(n4.display() == "0°");
    }

    SECTION("Assignments of angle class")
    {
        angle a2(10.0f);
        angle a;
        a = a2;
        CHECK(a.get_value() == 10.0f);
        angle b;
        b = angle(40.0f);
        CHECK(b.get_value() == 40.0f);
        angle c;
        c = 8.0f;
        CHECK(c.get_value() == 8.0f);
        angle d;
        d = "10 °";
        CHECK(d.get_value() == 10.0f);
        scalar_unit f2("7 N");
        scalar_unit f3("2 N");
        angle f;
        f = scalar_unit(f2/f3);
        CHECK(f.get_value() == 3.5f);
        scalar_unit g2("2 N");
        angle g;
        g = scalar_unit(g2);
        CHECK(g.get_value() == 0.0f);
    }

    SECTION("Operators of angle class with angle class")
    {
        angle a(30.0f);
        angle a2(20.0f);
        CHECK(bool((a + a2) == angle(50.0f)));
        angle b(30.0f);
        angle b2(20.0f);
        CHECK(bool((b - b2) == angle(10.0f)));
        angle c(30.0f);
        angle c2(2.0f);
        CHECK(bool((c * c2) == angle(60.0f)));
        angle d(30.0f);
        angle d2(2.0f);
        CHECK(bool((d / d2) == angle(15.0f)));
        angle e(5.0f);
        angle e2(2.0f);
        CHECK(bool((e ^ e2) == angle(25.0f)));
        angle f(10.0f);
        f += angle(5.0f);
        CHECK(f.get_value() == 15.0f);
        angle g(10.0f);
        g -= angle(5.0f);
        CHECK(g.get_value() == 5.0f);
        angle h(10.0f);
        h *= angle(2.0f);
        CHECK(h.get_value() == 20.0f);
        angle i(10.0f);
        i /= angle(2.0f);
        CHECK(i.get_value() == 5.0);
        angle j(10.0f);
        j ^= angle(2.0f);
        CHECK(j.get_value() == 100.0f);
    }

    SECTION("Operators of angle class with numbers")
    {
        angle a(10.0f);
        a++;
        CHECK(a.get_value() == 11.0f);
        angle b(10.0f);
        ++b;
        CHECK(b.get_value() == 11.0f);
        angle c(10.0f);
        c--;
        CHECK(c.get_value() == 9.0f);
        angle d(10.0f);
        --d;
        CHECK(d.get_value() == 9.0f);
    }

    SECTION("Functions of values and normalize_value()")
    {
        angle a(45.0f);
        a.invert();
        CHECK(a.get_value() == 225.0f);
        angle b(365.0f);
        CHECK(b.get_value() == 5.0f);
        angle c(-10.0f);
        CHECK(c.get_value() == 350.0f);
    }

    SECTION("to_scalar_unit() function")
    {
        angle a(40.0f);
        CHECK(bool(a.to_scalar_unit() == scalar_unit("40 deg")));
    }

    SECTION("Display of angles")
    {
        angle a(45.0f);
        CHECK(a.display() == "45°");
        angle b(-0.0f);
        CHECK(b.display() == "0°");
        angle c(60.0f);
        CHECK(to_string(c) == "60°");
    }

    SECTION("Conversion to degrees")
    {
        CHECK(radian_to_degree(3.1415927f) == 180.0f);
        CHECK(gradian_to_degree(200.0f) == 180.0f);
        CHECK(turn_to_degree(0.5f) == 180.0f);
    }

    SECTION("Conversion to radians")
    {
        CHECK(degree_to_radian(180.0f) == 3.1415927f);
        CHECK(gradian_to_radian(200.0f) == 3.1415998f);
        CHECK(turn_to_radian(0.5f) == 3.1415927f);
    }

    SECTION("Conversion to gradians")
    {
        CHECK(degree_to_gradian(180.0f) == 200.0f);
        CHECK(radian_to_gradian(3.1415927f) == 200.0f);
        CHECK(turn_to_gradian(0.5f) == 200.0f);
    }

    SECTION("Conversion to turns")
    {
        CHECK(degree_to_turn(180.0f) == 0.5f);
        CHECK(radian_to_turn(3.1415927f) == 0.5f);
        CHECK(gradian_to_turn(200.0f) == 0.5f);
    }

    SECTION("is_angle() function")
    {
        CHECK(is_angle("10°") == true);
        CHECK(is_angle("10.0°") == true);
        CHECK(is_angle("10 deg") == true);
        CHECK(is_angle("10 rad") == true);
        CHECK(is_angle("10 grad") == true);
        CHECK(is_angle("10 tr") == true);
        CHECK(is_angle("10A°") == false);
        CHECK(is_angle("10") == false);
        CHECK(is_angle("10.0.9°") == false);
    }

    SECTION("Parallel and orthogonal functions")
    {
        CHECK(scifir::parallel(angle(30.0f),angle(210.0f)) == true);
        CHECK(scifir::parallel(angle(20.0f),angle(20.0f)) == true);
        CHECK(scifir::parallel(angle(30.0f),angle(200.0f)) == false);
        CHECK(scifir::orthogonal(angle(30.0f),angle(120.0f)) == true);
        CHECK(scifir::orthogonal(angle(30.0f),angle(110.0f)) == false);
        CHECK(scifir::orthogonal(angle(30.0f),angle(300.0f)) == true);
        CHECK(scifir::orthogonal(angle(30.0f),angle(290.0f)) == false);
    }

    SECTION("Math functions of angle class")
    {
        CHECK(bool(scifir::sqrt(angle(25.0f)) == angle(5.0f)));
        CHECK(std::fabs(float(scifir::sqrt_nth(angle(125.0f),3)) - 5.0f) < 0.00001f);
        CHECK(std::fabs(scifir::sin(angle(20.0f)) - 0.34202f) < 0.00001f);
        CHECK(std::fabs(scifir::sin(angle(45.0f)) - 0.70710f) < 0.00001f);
        CHECK(std::fabs(scifir::cos(angle(45.0f)) - 0.70710f) < 0.00001f);
        CHECK(std::fabs(scifir::tan(angle(45.0f)) - 1.0f) < 0.00001f);
        CHECK(std::fabs(float(scifir::asin(0.45f) - angle(26.74368f))) < 0.00001f);
        CHECK(std::fabs(float(scifir::acos(0.45f) - angle(63.25631f))) < 0.00001f);
        CHECK(std::fabs(float(scifir::atan(0.45f) - angle(24.22774f))) < 0.00001f);
        CHECK(std::fabs(scifir::sinh(angle(45.0f)) - 0.868671f) < 0.00001f);
        CHECK(std::fabs(scifir::cosh(angle(45.0f)) - 1.32461f) < 0.00001f);
        CHECK(std::fabs(scifir::tanh(angle(45.0f)) - 0.655794f) < 0.00001f);
        CHECK(std::fabs(float(scifir::asinh(45.0f) - angle(257.82f))) < 0.01f);
        CHECK(std::fabs(float(scifir::acosh(45.0f) - angle(257.81f))) < 0.01f);
        CHECK(std::fabs(float(scifir::atanh(0.5f) - angle(31.47f))) < 0.01f);
    }

    SECTION("Comparators of angle class")
    {
        CHECK(bool(angle(10.0f) == angle(10.0f)));
        CHECK((angle(10.0f) == angle(6.0f)) == false);
        CHECK(bool(angle(10.0f) != angle(7.0f)));
        CHECK(bool(angle(5.0f) < angle(10.0f)));
        CHECK((angle(10.0f) < angle(5.0f)) == false);
        CHECK(bool(angle(10.0f) > angle(5.0f)));
        CHECK((angle(5.0f) > angle(10.0f)) == false);
        CHECK(bool((angle(6.0f) <= angle(8.0f))));
        CHECK(bool(angle(10.0f) >= angle(5.0f)));
    }

    SECTION("String operators of angle class")
    {
        CHECK(bool(angle(10.0f) == "10°"));
        CHECK(bool(angle(10.0f) != "8°"));
        CHECK(bool("10°" == angle(10.0f)));
        CHECK(bool("8°" != angle(10.0f)));
        string a = "angle: ";
        a += angle(20.0f);
        CHECK(a == "angle: 20°");
        CHECK(("angle: " + angle(20.0f)) == "angle: 20°");
        CHECK(("angle: 20°" == "angle: " + angle(20.0f)));
        CHECK((angle(20.0f)) + " angle" == "20° angle");
    }

    SECTION("Stream operators of angle class")
    {
        ostringstream a;
        a << angle(15.0f);
        CHECK(a.str() == "15°");
        stringstream b;
        b << "15°";
        angle b2;
        b >> b2;
        CHECK(b2.get_value() == 15.0f);
    }
}