#pragma once
#include "string.hpp"
#include "font.hpp"

namespace GUI {
    namespace notify {
        class notification
        {
        private:
            string from;
            string msg;
        public:
            notification(string program, string message);
        };
        
        void notify(notification notify);
    }
}