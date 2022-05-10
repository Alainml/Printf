
# Printf

[42 Subject]

Recode of the printf() function from libc.
The prototype of ft_printf() is:

int ft_printf(const char *, ...);
  
 

Here are the requirements:

• Don’t implement the buffer management of the original printf().

• Your function has to handle the following conversions: cspdiuxX%



## Norminette

There are some peculiarities in the code due to the campus mandatory syntax
It is checked by Norminette, and makes us do less than 25 lines functions, 5 functions per file etc
## Mandatory

Program name  | libftprintf.a| 
--- | --- | 
Turn in files  | Makefile, *.h, */*.h, *.c, */*.c | 
Makefile | NAME, all, clean, fclean, re|
Libft authorized  | Yes
External functs | write, malloc, free, va_start, va_arg, va_copy, va_end
Description |Write a library that contains ft_printf(), a function that will mimic the original printf()

## Bonus

Bonus requierements:
• Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions.
• Manage all the following flags: ’# +’ (Yes, one of them is a space)

The bonus part (Only ’# +’ done) wasn't turned in due to some extra tests that weren't covered.
It might be done in the future with structures.