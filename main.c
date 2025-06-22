#include <stdio.h>
#include <limits.h>

// Prototype ft_printf à adapter
int ft_printf(const char *format, ...);

typedef struct {
    const char *desc;
    const char *format;
    enum {STR, CHAR, INT, UINT, PTR, NONE} type;
    union {
        const char *s;
        char c;
        int i;
        unsigned int u;
        void *p;
    } arg;
} test_case_t;

void run_test(const test_case_t *tc)
{
    int ret_printf, ret_ftprintf;

    printf("Test: %s\n", tc->desc);

    switch (tc->type)
    {
        case STR:
            ret_printf = printf("printf    : ");
            ret_printf += printf(tc->format, tc->arg.s);
            ret_printf += printf("\n");

            ret_ftprintf = ft_printf("ft_printf : ");
            ret_ftprintf += ft_printf(tc->format, tc->arg.s);
            ret_ftprintf += ft_printf("\n");
            break;

        case CHAR:
            ret_printf = printf("printf    : ");
            ret_printf += printf(tc->format, tc->arg.c);
            ret_printf += printf("\n");

            ret_ftprintf = ft_printf("ft_printf : ");
            ret_ftprintf += ft_printf(tc->format, tc->arg.c);
            ret_ftprintf += ft_printf("\n");
            break;

        case INT:
            ret_printf = printf("printf    : ");
            ret_printf += printf(tc->format, tc->arg.i);
            ret_printf += printf("\n");

            ret_ftprintf = ft_printf("ft_printf : ");
            ret_ftprintf += ft_printf(tc->format, tc->arg.i);
            ret_ftprintf += ft_printf("\n");
            break;

        case UINT:
            ret_printf = printf("printf    : ");
            ret_printf += printf(tc->format, tc->arg.u);
            ret_printf += printf("\n");

            ret_ftprintf = ft_printf("ft_printf : ");
            ret_ftprintf += ft_printf(tc->format, tc->arg.u);
            ret_ftprintf += ft_printf("\n");
            break;

        case PTR:
            ret_printf = printf("printf    : ");
            ret_printf += printf(tc->format, tc->arg.p);
            ret_printf += printf("\n");

            ret_ftprintf = ft_printf("ft_printf : ");
            ret_ftprintf += ft_printf(tc->format, tc->arg.p);
            ret_ftprintf += ft_printf("\n");
            break;

        case NONE:
            ret_printf = printf("printf    : ");
            ret_printf += printf("%s", tc->format);
            ret_printf += printf("\n");

            ret_ftprintf = ft_printf("ft_printf : ");
            ret_ftprintf += ft_printf("%s", tc->format);
            ret_ftprintf += ft_printf("\n");
            break;
    }

    printf("ret printf    : %d\n", ret_printf);
    printf("ret ft_printf : %d\n", ret_ftprintf);

    if (ret_printf != ret_ftprintf)
        printf(">> MISMATCH in return values!\n");

    printf("-------------------------------------------------\n");
}

int main(void)
{
    test_case_t tests[] = {
        // Strings
        {"NULL string with width", "[%10s]", STR, {.s = NULL}},
        {"String with precision", "[%.5s]", STR, {.s = "HelloWorld"}},
        {"String with width and precision", "[%10.5s]", STR, {.s = "HelloWorld"}},
        {"String with left align", "[%-10.5s]", STR, {.s = "HelloWorld"}},

        // Characters
        {"Char simple", "[%c]", CHAR, {.c = 'A'}},
        {"Char with width", "[%5c]", CHAR, {.c = 'B'}},
        {"Char left align", "[%-5c]", CHAR, {.c = 'C'}},

        // Integers signed
        {"Int positive", "[%d]", INT, {.i = 42}},
        {"Int negative", "[%d]", INT, {.i = -42}},
        {"Int zero", "[%d]", INT, {.i = 0}},
        {"Int with width", "[%5d]", INT, {.i = 42}},
        {"Int with zero padding", "[%05d]", INT, {.i = 42}},
        {"Int with left align", "[%-5d]", INT, {.i = 42}},
        {"Int INT_MIN", "[%d]", INT, {.i = INT_MIN}},
        {"Int INT_MAX", "[%d]", INT, {.i = INT_MAX}},

        // Unsigned int
        {"Unsigned zero", "[%u]", UINT, {.u = 0}},
        {"Unsigned max", "[%u]", UINT, {.u = UINT_MAX}},
        {"Unsigned with width", "[%10u]", UINT, {.u = 123456}},
        {"Unsigned with zero padding", "[%010u]", UINT, {.u = 123456}},

        // Hexadecimal
        {"Hex lowercase", "[%x]", UINT, {.u = 305441741}},
        {"Hex uppercase", "[%X]", UINT, {.u = 305441741}},
        {"Hex with width", "[%10x]", UINT, {.u = 305441741}},
        {"Hex with zero padding", "[%010x]", UINT, {.u = 305441741}},

        // Pointer
        {"Pointer NULL", "[%p]", PTR, {.p = NULL}},
        {"Pointer valid", "[%p]", PTR, {.p = (void*)0x1234abcd}},

        // Percent
        {"Percent sign", "%%", NONE, {0}},
        {"Percent with width", "[%5%]", NONE, {0}},
        {"Percent left align", "[%-5%]", NONE, {0}},

	{"Int with zero padding and width", "[%010d]", INT, {.i = 123}},
	{"Int with zero padding, width and left align", "[%-010d]", INT, {.i = 123}}, // ‘-’ overrides ‘0’
	{"String with width, precision and left align", "[%-10.3s]", STR, {.s = "HelloWorld"}},
	{"String with width, precision, zero padding", "[%010.3s]", STR, {.s = "HelloWorld"}},
	{"Int zero with precision zero", "[%.0d]", INT, {.i = 0}},     // Should print nothing or just padding
{"Unsigned zero with precision zero", "[%.0u]", UINT, {.u = 0}},
{"String with precision zero", "[%.0s]", STR, {.s = "Hello"}},
{"Int large width & precision", "[%20.15d]", INT, {.i = 12345}},
{"String large width & precision", "[%20.10s]", STR, {.s = "Hello World!"}},
{"Pointer NULL with width", "[%10p]", PTR, {.p = NULL}},
{"Pointer valid with width", "[%20p]", PTR, {.p = (void*)0xdeadbeef}},
{"Very long string", "[%.50s]", STR, {.s = "This is a very long string to test precision cutting in ft_printf implementation"}},
{"Percent with width zero pad", "[%05%]", NONE, {0}},
{"Percent with width left align", "[%-5%]", NONE, {0}},


    };

    size_t n = sizeof(tests) / sizeof(tests[0]);
    for (size_t i = 0; i < n; i++)
        run_test(&tests[i]);

    return 0;
}

