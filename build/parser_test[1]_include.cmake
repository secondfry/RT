if(EXISTS "/Users/oadhesiv/school21-rtv1/build/parser_test[1]_tests.cmake")
  include("/Users/oadhesiv/school21-rtv1/build/parser_test[1]_tests.cmake")
else()
  add_test(parser_test_NOT_BUILT parser_test_NOT_BUILT)
endif()
