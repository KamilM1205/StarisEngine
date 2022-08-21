#ifndef SENGINE_H
#define SENGINE_H

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

namespace SEngine
{
    enum WindowMode {
        Windowed,
        FullScreen,
    };

    class EXPORT SEngine
    { 
        private:
            int x, y;
            int WIDTH, HEIGHT;
            WindowMode wm;
            char* title;

        public:
            SEngine(char*);
            void set_title(char*);
            void set_window_mode(WindowMode);
            void run();
            ~SEngine();
    };

} // namespace SEngine

#endif