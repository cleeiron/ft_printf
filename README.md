*This project has been created as part of the 42 curriculum by clpincho.*

# ft_printf

A small, self-contained implementation of `printf`, written in C as part of the 42 curriculum.

## Description

The goal of **ft_printf** is to recreate the mandatory behavior of the standard C `printf` function while learning to work with **variadic functions** (`va_list`, `va_start`, `va_arg`, and `va_end`).

The project produces a static library named `libftprintf.a` and exposes the following function:

```c
int ft_printf(const char *format, ...);
```

It writes formatted output to standard output and returns the number of characters written, or `-1` if a write operation fails.

### Supported conversions

| Conversion | Description |
| :---: | --- |
| `%c` | Single character |
| `%s` | String |
| `%p` | Pointer address in hexadecimal |
| `%d` | Signed decimal integer |
| `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Lowercase hexadecimal integer |
| `%X` | Uppercase hexadecimal integer |
| `%%` | Literal percent sign |

This implementation covers the **mandatory part only**. Optional flags, field widths, and precision are not implemented.

## Instructions

### Compilation

Clone the repository and build the static library:

```sh
git clone <repository-url>
cd <repository-directory>
make
```

The Makefile creates `libftprintf.a` using `cc` with `-Wall -Wextra -Werror` and `ar`.

Other available Makefile targets:

```sh
make all       # Build the library
make clean     # Remove object files
make fclean    # Remove object files and the library
make re        # Rebuild from scratch
```

### Usage

Include the header in a C file:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! Answer: %d\n", "42", 42);
    return (0);
}
```

Compile and link your program with the library:

```sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o example
./example
```

Expected output:

```text
Hello, 42! Answer: 42
```

## Algorithm and Design Choices

### 1. Sequential format parsing

`ft_printf` reads the format string one character at a time. Ordinary characters are written directly. When it encounters `%`, it examines the next character and delegates the corresponding conversion to `ft_conversion`.

This single-pass approach is straightforward to follow and avoids creating an intermediate output buffer, as required by the subject.

### 2. Variadic argument handling

The function uses `va_start` to initialize a `va_list`, `va_arg` to retrieve each argument with the type expected by its conversion, and `va_end` to finish processing. The conversion dispatcher keeps argument handling separate from the main format-parsing loop.

### 3. Small, focused output functions

The implementation separates character output, string output, signed decimal numbers, unsigned/base conversion, and pointer addresses into dedicated helpers. For example, `ft_print_char` handles a single `write` call, while `ft_print_str` writes a string character by character.

This modular structure makes each conversion easier to reason about, test, and maintain.

### 4. Recursive number conversion

`ft_print_nb_base` uses recursive division and modulo to print the digits of a number in the correct order. A digit alphabet determines the base and whether hexadecimal letters are lowercase or uppercase:

- `0123456789` for decimal
- `0123456789abcdef` for lowercase hexadecimal
- `0123456789ABCDEF` for uppercase hexadecimal

Signed decimal output is handled separately, using a wider integer type to safely represent the magnitude of `INT_MIN`.

### 5. Pointer formatting and error propagation

Pointer values are converted to hexadecimal with a `0x` prefix. On the target Linux environment, null strings and null pointers are displayed as `(null)` and `(nil)`, respectively.

Each output helper returns its number of written characters, or `-1` when writing fails. These return values are propagated to `ft_printf`, which accumulates the total and stops on an output error.

### Data structures

No dynamic data structure or heap allocation is needed. The implementation uses a `va_list` for variadic arguments, simple counters for parsing and output length, and constant strings as digit alphabets for base conversion. This keeps memory usage small and avoids unnecessary allocations.

## Testing

The implementation was manually compared against the standard `printf` for all mandatory conversions, multiple conversions in a single call, `INT_MIN`, `UINT_MAX`, null strings and pointers, embedded `\0` characters, return values, and write-error propagation.

These tests are useful checks, but do not replace a full evaluation against the project requirements.

## Resources

- **42 ft_printf subject (version 12.1):** official project requirements and supported conversions.
- **YouTube tutorials and educational videos:** additional explanations of variadic functions, `va_list`, number bases, and how `printf` works. These were learning resources, not code copied into the project.
- [printf(3) — Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html): formatting and conversion behavior.
- [stdarg(3) — Linux manual page](https://man7.org/linux/man-pages/man3/stdarg.3.html): working with variadic arguments.
- [write(2) — Linux manual page](https://man7.org/linux/man-pages/man2/write.2.html): writing to standard output and handling errors.

### AI usage

AI was used **only as a learning and understanding aid**, to clarify concepts such as variadic arguments, recursive number conversion, and error handling, and to discuss testing approaches and compiler messages. **AI was not used to write the project's C implementation.** AI also assisted with the wording and organization of this README.
