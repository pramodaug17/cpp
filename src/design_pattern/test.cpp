/*
 * Test suite for all design pattern
 */
#include <iostream>

using namespace std;

namespace design_patterns {
/* Forwaqre declaration */
namespace decorator {
    void run_test(void);
}
namespace strategy {
    void run_test(void);
}
namespace observer {
    void run_test(void);
}
namespace factory {
    void run_test(void);
}
namespace abstract_factory {
    void run_test(void);
}
namespace command {
    void run_test(void);
}
namespace singleton {
    void run_test(void);
}

namespace test {

void execute() {
    cout << "Starting Design pattern testing...\n";
    decorator::run_test();
    strategy::run_test();
    observer::run_test();
    factory::run_test();
    abstract_factory::run_test();
} // End of execute function

} // End of test namespace
} // End of design_patterns namespace
