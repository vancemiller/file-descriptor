#ifndef FILE_DESCRIPTOR_HPP
#define FILE_DESCRIPTOR_HPP

namespace wrapper {
class FileDescriptor {
  private:
    int fd;
  public:
    /**
      * Manages the lifetime of an open file descriptore
      */
    FileDescriptor(int open_fd) noexcept;
    FileDescriptor(FileDescriptor& o) = delete;
    FileDescriptor(const FileDescriptor& o) = delete;
    FileDescriptor(FileDescriptor&& o) noexcept;
    FileDescriptor &operator=(FileDescriptor &&o) noexcept;
    ~FileDescriptor(void) noexcept;
    int get(void) const noexcept;
    bool operator==(int fd) const noexcept;
    bool operator!=(int fd) const noexcept;
};
} // namespace wrapper

#endif
