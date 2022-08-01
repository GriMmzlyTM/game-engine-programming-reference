

#include <map>
#include <set>
#include <stack>
#include <unordered_map>

class Mem {
public:
    class Context {};
    static void PushAllocator(Context context) {}
    static void PopAllocator() {}
private:
    static std::stack<Context> _memStack;
    Mem() = default;
    ~Mem() = delete;
};

// Resource Acquisition Is Initialization
class AllocJanitor {
public:
    explicit AllocJanitor(Mem::Context context) {
        Mem::PushAllocator(context);
    }
    ~AllocJanitor() {
        Mem::PopAllocator();
    }
};

void f() {
    {
        auto size = 8;
        // Janitor allocated
        AllocJanitor janitor{Mem::Context()};
        auto pByteBuffer = new uint8_t[size];
        float* pFloatBuffer = new float[size];
    } // Janitor popped
}
