/* This code snippet was ripped out of the gcc 
 * documentation and slightly modified to work
 * with gcc 4.x
 */
#ifndef SGI_HASHMAP_H
#define SGI_HASHMAP_H

/* To use gcc extensions.
 */
#ifdef __GNUC__
  #if __GNUC__ < 3 // GCC 2.x
    #include <hash_map.h>
    namespace sgi { using ::hash_map; }; // inherit globals
  #else
    #if __GNUC__ < 4 // GCC 3.x
      #include <ext/hash_map>
      #if __GNUC_MINOR__ == 0
        namespace sgi = std; // GCC 3.0
      #else
        namespace sgi = ::__gnu_cxx; // GCC 3.1 and later
      #endif
    #else
       #if __GNUC__ < 5 // GCC 4.x
         #if __GNUC_MINOR__ < 3 // GCC 4.0, 4.1 and 4.2
           #ifdef __clang__ // Clang identifies as GCC 4.2
             #undef __DEPRECATED
           #endif
           #include <ext/hash_map>
           namespace sgi = ::__gnu_cxx;
         #else
           #undef __DEPRECATED
           #include <backward/hash_map>
           namespace sgi = ::__gnu_cxx;
         #endif
       #else // GCC 5.x
         #undef __DEPRECATED
         #include <backward/hash_map>
         namespace sgi = ::__gnu_cxx;
       #endif
     #endif
  #endif
#else      // ...  there are other compilers, right?
///WINDOWS
//namespace sgi = std;
//#endif
//arp-cache.h:“hash_map”: 不是“std”的成员
#ifndef WIN32
namespace sgi = std;
#else
#include <hash_map>
namespace sgi = stdext;
#endif
#endif
///WINDOWS

#endif /* SGI_HASHMAP_H */
