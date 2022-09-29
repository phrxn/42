# libft

<p align="center">
  <img src="https://raw.githubusercontent.com/phrxn/phrxn/master/42/badges/libftm.png" />
</p>
<p align="center">
	<b><i>Your very first own library.</i></b><br>
</p>

## Status
Finished: 2022-09-28. Grade: [![](https://raw.githubusercontent.com/phrxn/phrxn/master/42/grade/125_100.png)](https://github.com/phrxn/42/tree/main/libft).

## Run and Usage
``make`` to compile mandatory functions and create libft.a.

``make bonus`` to compile the bonus functions *without* mandatory party.

After creating libft.a its use/test can be done as follows:

```
#include "libft.h"

int main(void)
{
    char *string = "42SP";
    
    ft_putstr_fd("The \"42SP\" string size is: ", 1); 
    ft_putnbr_fd(ft_strlen(string), 1); 
    ft_putchar_fd('\n', 1); 
    
    return 0;
}
```

``gcc main.c libft.a``

``./a.out``
