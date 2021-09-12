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

namespace adapter {
    void run_test(void);
}

namespace facade {
    void run_test(void);
}

namespace test {

void execute() {
    cout << "Starting Design pattern testing...\n";
    decorator::run_test();
    cout << "\n\n";

    strategy::run_test();
    cout << "\n\n";

    observer::run_test();
    cout << "\n\n";

    factory::run_test();
    cout << "\n\n";

    abstract_factory::run_test();
    cout << "\n\n";
    
    command::run_test();
    cout << "\n\n";

    singleton::run_test();
    cout << "\n\n";

    adapter::run_test();
    cout << "\n\n";

    facade::run_test();
} // End of execute function

} // End of test namespace
} // End of design_patterns namespace
