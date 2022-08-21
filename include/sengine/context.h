#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <sengine/export.h>
#include <sengine/color.h>

namespace SEngine
{
    class Context
    {
    private:
        Color clear_color;
        Color draw_color;
    public:
        Context();

        void set_color(Color color);
        void set_clear_color(Color color);
        void clear();

        ~Context();
    };
    
} // namespace SEngine


#endif