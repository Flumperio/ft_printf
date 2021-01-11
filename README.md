# ft_printf
Nombre del programa: libftprintf.a

Ficheros de entrega:
*.c, */*.c, *.h, */*.h, Makefile

Makefile:
all, clean, fclean, re, bonus

Funciones externas autorizadas:
malloc, free, write, va_start, va_arg, va_copy,
va_end

Descripción
Escriba una librería que contiene ft_printf,
une funcion que reproduzca el comportamiento del
verdadero printf

• El prototipo de ft_printf debe ser int ft_printf(const char *, ...);
• Tienes que volver a programar la función printf de la libc
• No debes hacer el sistema de buffer, a diferencia del verdadero printf
• Tendrá que gestionar las siguientes conversiones: cspdiuxX %
• Tendrá que gestionar cualquier combinación de flags ’-0.*’ y el tamaño mínimo del campo con todas las conversiones
• Se comparará su entrega con el verdadero printf
• Use el comando ar para su librerÃa, estÃ¡ prohibido el uso de libtool.
