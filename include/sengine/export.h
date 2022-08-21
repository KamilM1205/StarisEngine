#ifndef EXPORT_H_
#define EXPORT_H_

#if defined(_MSC_VER)
    //  Microsoft 
    #define EXP __declspec(dllexport)
    #define IMP __declspec(dllimport)
#elif defined(__GNUC__)
    //  GCC
    #define EXP __attribute__((visibility("default")))
    #define IMP
#else
    //  do nothing and hope for the best?
    #define EXP
    #define IMP
    #pragma warning Unknown dynamic link import/export semantics.
#endif


 #ifdef  SENGINE_EXPORTS 
    /*Enabled as "export" while compiling the dll project*/
    #define EXPORT EXP
 #else
    /*Enabled as "import" in the Client side for using already created dll file*/
    #define EXPORT IMP
 #endif

#endif