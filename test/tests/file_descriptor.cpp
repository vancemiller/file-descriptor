#include "gtest/gtest.h"
#include "file_descriptor.hpp"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

namespace wrapper {

TEST(FileDescriptor, OpenClose) {
  FileDescriptor(open("./.test.tmp", O_CREAT));
  EXPECT_EQ(0, remove("./.test.tmp"));
}

TEST(FileDescriptor, OperatorEq) {
  FileDescriptor f(open("./.test.tmp", O_CREAT));
  EXPECT_TRUE(f != -1);
  EXPECT_EQ(0, remove("./.test.tmp"));
}

// TODO more tests

} // namespace wrapper
