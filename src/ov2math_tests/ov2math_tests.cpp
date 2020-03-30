#include <extern/catch/catch.hpp>
#include <src/ov2math/vector2.hpp>

TEST_CASE("vector2 equality.", "[vector2]") {
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