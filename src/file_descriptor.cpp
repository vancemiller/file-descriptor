#include "file_descriptor.hpp"

#include <unistd.h>
#include <iostream>

namespace wrapper {

FileDescriptor::FileDescriptor(int open_fd) noexcept : fd(open_fd) {}
FileDescriptor::FileDescriptor(FileDescriptor&& o) noexcept : fd(o.fd) { o.fd = -1; }
FileDescriptor::~FileDescriptor(void) noexcept {
  if (fd == -1) return;
  if (close(fd) == -1) std::cerr << "WARNING: file close failed" << std::endl;
}
int FileDescriptor::get(void) const noexcept { return fd; }
bool FileDescriptor::operator==(int fd) const noexcept { return this->fd == fd; }
bool FileDescriptor::operator!=(int fd) const noexcept { return this->fd != fd; }

} // namespace wrapper

