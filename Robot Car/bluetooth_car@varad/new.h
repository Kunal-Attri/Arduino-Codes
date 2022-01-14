#ifndef NEW_H
  #define NEW_H
  //  new
  void* operator new(size_t sz) { return malloc(sz);}
  //  placement new
  void* operator new(size_t sz, void* ptr) { return ptr;}
  //  delete
  void operator delete(void* ptr) { free(ptr);};
#endif
