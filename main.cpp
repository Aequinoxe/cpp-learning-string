#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    // constructors
    String test1;              // empty
    String test2("Hello");     // from const char*
    String test3 = test2;      // copy constructor

    cout << "test2: "; test2.print(); cout << '\n';
    cout << "test3 (copy of test2): "; test3.print(); cout << '\n';

    // assignment from const char*
    test1 = " World";
    cout << "test1 after test1 = \" World\": "; test1.print(); cout << '\n';

    // concatenation +
    String test4 = test2 + test1;   // "Hello World"
    cout << "test4 = test2 + test1: "; test4.print(); cout << '\n';

    // multiplication *
    String test5 = test4 * 2;
    cout << "test5 = test4 * 2: "; test5.print(); cout << '\n';

    // multiplication by 0 and negative
    String test6 = test4 * 0;
    cout << "test6 (test4 * 0) length = " << test6.length() << ", content: '";
    test6.print(); cout << "'\n";

    String test7 = test4 * -1;
    cout << "test7 (test4 * -1) length = " << test7.length() << '\n';

    // length
    cout << "test5.length() = " << test5.length() << '\n';

    // comparisons with const char*
    cout << boolalpha;
    cout << "test5 == \"Hello WorldHello World\" ? "
        << (test5 == "Hello WorldHello World") << '\n';
    cout << "test4 == \"Hello World\" ? " << (test4 == "Hello World") << '\n';
    cout << "test4 != \"xxx\" ? " << (test4 != "xxx") << '\n'; // != with const char*

    // comparison String == String
    String test8 = test4;
    cout << "test8 == test4 ? " << (test8 == test4) << '\n';
    cout << "test8 != test5 ? " << (test8 != test5) << '\n';

    // operator[] non-const
    try {
        cout << "test4[0] = " << test4[0] << '\n';
        test4[0] = 'h';
        cout << "after test4[0] = 'h': "; test4.print(); cout << '\n';
    }
    catch (const out_of_range& ex) {
        cout << "Index error: " << ex.what() << '\n';
    }

    // operator[] const (demonstrating const overload)
    const String test9 = test4;
    cout << "test9[0] (const overload) = " << test9[0] << '\n';

    // assignment from String
    String test10;
    test10 = test4;
    cout << "test10 (assigned from test4): "; test10.print(); cout << '\n';

    // assignment nullptr -> empty string
    test10 = nullptr;
    cout << "test10 after test10 = nullptr (should be empty). length = " << test10.length() << '\n';
    cout << "test10.print(): ";
    test10.print();
    cout << '\n';

    // constructor from nullptr
    String test11(nullptr);
    cout << "test11.length() = " << test11.length() << " (should be 0)\n";

    // chaining addition (demonstrates const char* -> String conversion)
    String test12 = test2 + test1 + String("!");
    cout << "test12 = test2 + test1 + \"!\" => "; test12.print(); cout << '\n';

    // explicit comparison with nullptr
    cout << "empty string == nullptr ? " << (test11 == nullptr) << '\n';
    cout << "test4 == nullptr ? " << (test4 == nullptr) << '\n';

    return 0;
}
