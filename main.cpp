#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    cout << "==================================================================\n";
    cout << "  TEST OVERVIEW (what each test does)\n";
    cout << "==================================================================\n";
    cout << "test1  = empty (default constructor)\n";
    cout << "test2  = \"Hello\" (created from const char*)\n";
    cout << "test3  = copy of test2 (via copy constructor)\n";
    cout << "test4  = test2 + test1 -> \"Hello World\"\n";
    cout << "test5  = test4 * 2 -> \"Hello WorldHello World\"\n";
    cout << "test6  = test4 * 0 -> empty string\n";
    cout << "test7  = test4 * -1 -> invalid / length = 0\n";
    cout << "test8  = copy of test4 (for == and != checks)\n";
    cout << "test9  = const String(test4) (for const operator[] test)\n";
    cout << "test10 = assigned from test4, then set to nullptr (clears content)\n";
    cout << "test11 = constructed from nullptr (empty string)\n";
    cout << "test12 = test2 + test1 + \"!\" -> \"Hello World!\"\n";
    cout << "==================================================================\n";
    cout << "\n\n\n";
    
    
    // constructors
    String test1;              // empty
    String test2("Hello");     // from const char*
    String test3 = test2;      // copy constructor

    cout << "===================================" << '\n';
    cout << "|  1. assignment from const char  |" << '\n';
    cout << "===================================" << '\n';
    cout << '\n';
    cout << "test2: "; test2.print(); cout << '\n';
    cout << "test3 (copy of test2): "; test3.print(); cout << '\n';

    test1 = " World";
    cout << "test1 after test1 = \" World\": "; test1.print(); cout << '\n';

    cout << '\n';
    cout << "======================" << '\n';
    cout << "|  2. concatenation  |" << '\n';
    cout << "======================" << '\n';
    cout << '\n';
    String test4 = test2 + test1;   // "Hello World"
    cout << "test4 = test2 + test1: "; test4.print(); cout << '\n';
 
    cout << '\n';
    cout << "=========================" << '\n';
    cout << "|  3. multiplication *  |" << '\n';
    cout << "=========================" << '\n';
    cout << '\n';
    String test5 = test4 * 2;
    cout << "test5 = test4 * 2: "; test5.print(); cout << '\n';

    cout << '\n';
    cout << "=========================================" << '\n';
    cout << "|  4. multiplication by 0 and negative  |" << '\n';
    cout << "=========================================" << '\n';
    cout << '\n';
    
    String test6 = test4 * 0;
    cout << "test6 (test4 * 0) length = " << test6.length() << ", content: '";
    test6.print(); cout << "'\n";

    String test7 = test4 * -1;
    cout << "test7 (test4 * -1) length = " << test7.length() << '\n';

    cout << '\n';
    cout << "===============" << '\n';
    cout << "|  5. length  |" << '\n';
    cout << "===============" << '\n';
    cout << '\n';
    cout << "test5.length() = " << test5.length() << '\n';

    cout << '\n';
    cout << "=====================================" << '\n';
    cout << "|  6. comparisons with const char*  |" << '\n';
    cout << "=====================================" << '\n';
    cout << '\n';
    cout << boolalpha;
    cout << "test5 == \"Hello WorldHello World\" ? "
        << (test5 == "Hello WorldHello World") << '\n';
    cout << "test4 == \"Hello World\" ? " << (test4 == "Hello World") << '\n';
    cout << "test4 != \"xxx\" ? " << (test4 != "xxx") << '\n'; // != with const char*

    cout << '\n';
    cout << "====================================" << '\n';
    cout << "|  7. comparison String == String  |" << '\n';
    cout << "====================================" << '\n';
    cout << '\n';
    String test8 = test4;
    cout << "test8 == test4 ? " << (test8 == test4) << '\n';
    cout << "test8 != test5 ? " << (test8 != test5) << '\n';

    cout << '\n';
    cout << "=============================" << '\n';
    cout << "|  8. operator[] non-const  |" << '\n';
    cout << "=============================" << '\n';
    cout << '\n';
    try {
        cout << "test4[0] = " << test4[0] << '\n';
        test4[0] = 'h';
        cout << "after test4[0] = 'h': "; test4.print(); cout << '\n';
    }
    catch (const out_of_range& ex) {
        cout << "Index error: " << ex.what() << '\n';
    }

    cout << '\n';
    cout << "=======================================================" << '\n';
    cout << "|  9.operator[] const (demonstrating const overload)  |" << '\n';
    cout << "=======================================================" << '\n';
    cout << '\n';
    const String test9 = test4;
    cout << "test9[0] (const overload) = " << test9[0] << '\n';

    cout << '\n';
    cout << "================================" << '\n';
    cout << "|  10. assignment from String  |" << '\n';
    cout << "================================" << '\n';
    cout << '\n';
    String test10;
    test10 = test4;
    cout << "test10 (assigned from test4): "; test10.print(); cout << '\n';

    cout << '\n';
    cout << "============================================" << '\n';
    cout << "|  11. assignment nullptr -> empty string  |" << '\n';
    cout << "============================================" << '\n';
    cout << '\n';
    test10 = nullptr;
    cout << "test10 after test10 = nullptr (should be empty). length = " << test10.length() << '\n';
    cout << "test10.print(): ";
    test10.print();
    cout << '\n';

    cout << '\n';
    cout << "==================================" << '\n';
    cout << "|  12. constructor from nullptr  |" << '\n';
    cout << "==================================" << '\n';
    cout << '\n';
    String test11(nullptr);
    cout << "test11.length() = " << test11.length() << " (should be 0)\n";

    cout << '\n';
    cout << "===========================================================================" << '\n';
    cout << "|  13. chaining addition (demonstrates const char* -> String conversion)  |" << '\n';
    cout << "===========================================================================" << '\n';
    cout << '\n';
    String test12 = test2 + test1 + String("!");
    cout << "test12 = test2 + test1 + \"!\" => "; test12.print(); cout << '\n';

    cout << '\n';
    cout << "==========================================" << '\n';
    cout << "|  14. explicit comparison with nullptr  |" << '\n';
    cout << "==========================================" << '\n';
    cout << '\n';
    cout << "empty string == nullptr ? " << (test11 == nullptr) << '\n';
    cout << "test4 == nullptr ? " << (test4 == nullptr) << '\n';

    return 0;
}
