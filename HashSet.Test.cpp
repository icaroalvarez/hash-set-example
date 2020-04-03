#include "catch.hpp"
#include "HashSet.h"

SCENARIO("64 bit hashing set")
{
    GIVEN("A hash set")
    {
        constexpr auto totalBuckets{30};
        HashSet hashSet{totalBuckets};

        THEN("The set is empty")
        {
            REQUIRE(hashSet.empty());
        }

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

            AND_WHEN("The set is cleared")
            {
                hashSet.clear();

                THEN("The set is empty")
                {
                    REQUIRE(hashSet.empty());
                }

                THEN("There are no collisions")
                {
                    REQUIRE_FALSE(hashSet.collisionCount());
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

        WHEN("Trying to remove a value that is not in the set")
        {
            hashSet.erase(1);

            THEN("The number of values is still the same")
            {
                REQUIRE(hashSet.empty());
            }
        }
    }
}