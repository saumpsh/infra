cc_library(
  name="linkstamped_library",
  linkstamp="linkstamped_library.cc"
)

cc_binary(
  name="verify_scm_status",
  srcs=["verify_scm_status.cc"],
  deps=[":linkstamped_library"],
  stamp = 1,
)
