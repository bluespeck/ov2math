#include <extern/catch/catch.hpp>
#include <src/ov2math/vector2.hpp>

// TODO: split tests into separate files

// vector2 tests


TEST_CASE("vector2 equality.", "[vector2]")
{
    using vector = ov2::math::vector2<float>;
    vector v1{ 0.f, 1.f }, v2{ 1.f, 0.f };
    
    REQUIRE(v1.x == 0.f);
    REQUIRE(v1.y == 1.f);
    REQUIRE(v2.x == 1.f);
    REQUIRE(v2.y == 0.f);
    REQUIRE(v1 != v2);
    v1 = v2;
    REQUIRE(v1 == v2);
    CHECK(v1.as_array()[1] == 0.f);
    CHECK(v1.as_array()[0] == 1.f);
}

TEST_CASE("vector2 operations.", "[vector2]")
{
    using vector = ov2::math::vector2<int>;
    vector v1{ 2, 1 }, v2{ 2, 3 };
    auto v_add = v1 + v2;
    auto v_sub = v1 - v2;
    auto v_mul_scalar_vec = 5 * v2;
    auto v_mul_vec_scalar = v2 * 3;
    auto v_div_vec_scalar = v2 / 2;

    CHECK(v_add.x == 4);
    CHECK(v_add.y == 4);

    CHECK(v_sub.x == 0);
    CHECK(v_sub.y == -2);

    CHECK(v_mul_scalar_vec.x == 10);
    CHECK(v_mul_scalar_vec.y == 15);
    
    CHECK(v_mul_vec_scalar.x == 6);
    CHECK(v_mul_vec_scalar.y == 9);
    
    CHECK(v_div_vec_scalar.x == 1);
    CHECK(v_div_vec_scalar.y == 1);
}

TEST_CASE("")
{

}