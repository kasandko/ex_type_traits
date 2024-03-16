#include <unordered_set>
#include <unordered_map>
#include <string>
#include <functional>
#include <iostream>

#include "test_op_traits.h"

using TestFunc = std::function<bool()>;
const std::unordered_map<std::string, TestFunc> ALL_TESTS = {
    {"testBinOpsTrivial", &testBinOpsTrivial},
    {"testBinMutOpsTrivial", &testBinMutOpsTrivial},
};

class Main
{
public:
    Main(int argc, char* argv[])
        : tests_to_run(toSet(argc, argv))
    {
    }

    int run()
    {
        std::cout << "#### START TESTS. ####" << std::endl;
        int failed_count = 0;
        for (const auto & [test_name, test_func] : ALL_TESTS)
        {
            if (tests_to_run.count(test_name) > 0u || tests_to_run.empty())
            {
                std::cout << "TEST '" << test_name << "':" << std::endl;
                if (!test_func())
                {
                    std::cout << "  FAIL" << std::endl;
                    failed_count++;
                }
                else
                {
                    std::cout << "  PASS" << std::endl;
                }
            }
        }

        const size_t tests_count = tests_to_run.empty() ? ALL_TESTS.size() : tests_to_run.size();
        std::cout
            << "#### FINISH. ####\n"
            << "Run: " << tests_count << "/" << ALL_TESTS.size()
            << ", Fail: " << failed_count
            << ", Pass: " << tests_count - static_cast<size_t>(failed_count)
            << std::endl;

        return failed_count;
    }

protected:

    std::unordered_set<std::string> toSet(int argc, char* argv[])
    {
        std::unordered_set<std::string> set;
        for (int i = 1 /* Skip exe file. */; i < argc; ++i)
            set.emplace(std::string(argv[i]));

        return set;
    }

private:
    std::unordered_set<std::string> tests_to_run;
};

int main(int argc, char* argv[])
{
    Main m(argc, argv);
    return m.run();
}
