#ifndef EVENT_H_
#define EVENT_H_

namespace SEngine {
    enum EventType {
        Mouse,
        Touch,
        Key,
    };

    class EventHandler {
        public:
            EventHandler();
            void HandleEvent();
            ~EventHandler();
    };
} // namespace SEngine

#endif