//
// Created by Apple on 2019-05-03.
//
#include <iostream>

using namespace std;
/**
 * 1. Namespace can be used as additional information to distinguish functions,
 * classes, variables, etc. of the same name in different libraries. The
 * context is defined using the namespace. Essentially, a namespace defines
 * a scope.
 */

namespace first_space {
    void func() {
        cout << "Inside first_space" << endl;
    }
}

namespace second_space {
    void func() {
        cout << "Inside second_space" << endl;
    }
}

/**
 * The using namespace directive tells the compiler that subsequent code will use the
 * name in the specified namespace.
 */
using namespace first_space;

namespace first_nest_space {
    void func_nest() {
        cout << "Inside first_nest_space" << endl;
    }

    namespace second_nest_space {
        void func_nest() {
            cout << "Inside second_nest_space" << endl;
        }
    }
}

using namespace first_nest_space::second_nest_space;

int main() {

    first_space::func();
    func();
    second_space::func();
    func_nest();
    first_nest_space::func_nest();

    return 0;
}