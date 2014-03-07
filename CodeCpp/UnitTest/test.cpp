#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello

#include<boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE ( inversement )
{
    BOOST_CHECK ( == 4) ;
}
