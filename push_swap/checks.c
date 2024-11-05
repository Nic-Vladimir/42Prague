

// function which checks the character if it is alphanumerical
int ft_isalpha(int c) {
  if ((c >= 58 && c <= 126) || (c >= 33 && c <= 42) || (c == 44) || (c == 46) ||
      (c == 47))
    return (1);
  return (0);
}

// Here arguments are send to make ASCII check
// regarding the alphanumeric values
void alpha_check(char **argv) {
  int i;
  int j;

  i = 1;
  while (argv[i]) {
    j = 0;
    while ((argv[i][j]) != '\0') {
      if (ft_isalpha(argv[i][j]))
        ft_error();
      j++;
    }
    i++;
  }
}

// With this function it is checked
// whether arguments include alfanumeric or not
int check_args(char **argv) {
  alpha_check(argv);
  if (!check_error(argv, 1, 0))
    return (false);
  return (true);
}

// chec if the chracter is negative
int sign(int c) {
  if (c == '+' || c == '-')
    return (1);
  return (0);
}

// check if the character is digit
int digit(int c) {
  if ((c >= 48) && (c <= 57))
    return (1);
  return (0);
}

// check if character is space character
int space(int c) {
  if (c == ' ')
    return (1);
  return (0);
}

// function to check if given arguments is valid
int check_error(char **argv, int i, int j) {
  while (argv[i]) {
    j = 0;
    while ((argv[i][j] != '\0')) {
      if (sign(argv[i][j])) {
        j++;
        if (!digit(argv[i][j]))
          return (false);
      } else if (digit(argv[i][j])) {
        j++;
        if (argv[i][j] == '\0')
          break;
        if (!digit(argv[i][j]) && !space(argv[i][j]))
          return (false);
      }
      j++;
    }
    i++;
  }
  return (true);
}

// While arguments are valid, we start to add them
// into stack here one by one with while loop.
// Atoi takes the number and turn it into an integer
// value where we can make math operations.
// With stack new we create a new node for the current
// argument without linking it to list.
// We make linking stage in ft_add_back call.
void list_args(char **argv, t_stack **stack_a) {
  long i;

  i = 1;
  while (argv[i] != NULL) {
    ft_add_back(stack_a, ft_stack_new(ft_atoi(argv[i])));
    i++;
  }
}

// This function does three things.
// 1. It checks if the number of input is less than 2.
// 2. It checks if the number of input is equal to 2.
//    If it is, it means it is a quoted string.
// 3. It checks if the number of input is greater than 2.
//     If it is, it lists the arguements.
t_stack *ft_parse(int argc, char **argv) {
  t_stack *stack_a;
  int i;
  int j;

  i = 1;
  stack_a = NULL;
  if (argc < 2)
    ft_error();
  else if (argc == 2)
    stack_a = ft_parse_args_quoted(argv);
  else {
    list_args(argv, &stack_a);
  }
  return (stack_a);
}

// This function free the string which is
// the integer values in between quotes.
void ft_freestr(char **lst) {
  char *n1;

  if (!lst)
    return;
  while (*lst) {
    n1 = *lst;
    lst++;
    free(n1);
  }
  *lst = NULL;
}

// Function to parse the arguments from the quoted string
// and send them to list_args function to add them into list.
// With ft_split we split numbers from spaces.
t_stack *ft_parse_args_quoted(char **argv) {
  t_stack *stack_a;
  char **tmp;
  int i;
  int j;

  stack_a = NULL;
  i = 0;
  tmp = ft_split(argv[1], 32);
  list_args(tmp, &stack_a);
  ft_freestr(tmp);
  free(tmp);
  return (stack_a);
}
