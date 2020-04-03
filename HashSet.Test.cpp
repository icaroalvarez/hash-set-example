#include "catch.hpp"
#include "HashSet.h"

SCENARIO("64 bit hashing set")
{
    GIVEN("A hash set")
    {
        constexpr auto totalBuckets{30};
        HashSet hashSet{totalBuckets};

        WHEN("Hash set is populated with values")
        {
            constexpr auto totalValues{100};
            for (int i = 0; i < totalValues; i++)
            {
                hashSet.insert(i);
            }

            THEN("The elements contained can be retrieved")
            {
                REQUIRE(hashSet.size() == totalValues);
            }

            THEN("The collision count can be retrieved")
            {
                REQUIRE(hashSet.collisionCount() == 70);
            }

            THEN("Existing a certain value can be checked")
            {
                REQUIRE(hashSet.contains(42));
            }

            THEN("A certain value can be removed from the set")
            {
                hashSet.erase(42);

                AND_THEN("The total count is correct")
                {
                    REQUIRE(hashSet.size() == totalValues - 1);
                }

                AND_THEN("The value is not in the set anymore")
                {
                    REQUIRE_FALSE(hashSet.contains(42));
                }
            }
        }

        WHEN("The set is populated with the same value")
        {
            hashSet.insert(24);
            hashSet.insert(24);

            THEN("The second insertion is omitted")
            {
                REQUIRE(hashSet.size() == 1);
            }
        }
    }
}