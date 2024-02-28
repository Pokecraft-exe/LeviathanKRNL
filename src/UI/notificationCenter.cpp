#include "notificationCenter.hpp"
#include "queue.hpp"
#include "kernel.h"
#include "font.hpp"
extern "C" void DrawSquare(int x, int y, int size_x, int size_y, uint32_t color);

queue<GUI::notify::notification> notifications;

namespace GUI {
    namespace notify {
        void notify(notification message){
            notifications.push_back(message);
        }

        void drawNotification(notification notify) {
            int screenWidth = framebuffer->width;
            //DrawSquare()
        }

        void main() {
            while(1) {
                for (auto notify : notifications) {
                    drawNotification(notify);
                }
            }
        }
    }
}