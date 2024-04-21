// These tests were created to test my project fumctions.
// Design - replacing Main function with this TEST Main.
// If you are also doing this project - your architecture and alg differ for sure.
// Be careful <3

#include "../incs/push_swap.h"

void stack_output(t_stack **a)
{
	t_stack	*at;
    at = *a;
	while (at != NULL)
	{
		ft_printf("%i; ", at->data);
		at = at->next;
	}
    ft_printf("\n");
}

void run_test_1(char **test, char *output)
{
    t_stack	*a;
    a = NULL;

    ft_printf("%s", output);
	if (st_fill(&a, test) == -1)
	    ft_printf("Error\n");
    else
        stack_output(&a);
}

void run_test_2(t_stack **test, void (*f)(t_stack**, char*), char *output)
{
    ft_printf("%s", output);
    (*f)(test, NULL);
    stack_output(test);
}

void run_test2p(t_stack **t1, t_stack **t2, void (*f)(t_stack**, t_stack**, char*), char *output)
{
    ft_printf("%s", output);
	(*f)(t1, t2, NULL);
    stack_output(t2);
    stack_output(t1);
}

void run_test_3(char **test, char *output)
{
    t_stack	*a;
    t_stack	*b;

    a = NULL;
    b = NULL;
    ft_printf("%s", output);
    st_fill(&a, test);
    stack_output(&a);
    sorter(&a, &b);
    stack_output(&a);
}

int	main(void)
{
    char *t1[2] = {" 1"};
    char *t2[6] = {"-1", "2", "3", "4", "5"};
    char *t3[6] = {"-1", "2", "+3", "4", "4"};
    char *t4[2] = {"1 2 3 4 5"};
    char *t5[4] = {"-1 2", "3", "4 5"};
    char *t6[4] = {"-1 2", "3", "4 4"};
    char *t7[6] = {"-1", "R", "3", "4", "5"};
    char *t8[2] = {"   1 2 3R 4 5"};
    t_stack *s1 = NULL;
    t_stack *s2 = NULL;
    st_insert(&s2, 10);
    t_stack *s3 = NULL;
    st_insert(&s3, 20);
    t_stack *s4 = NULL;
    st_insert(&s4, 3);
    st_insert(&s4, 6);
    st_insert(&s4, 9);
    t_stack *s5 = NULL;
    st_insert(&s5, 33);
    st_insert(&s5, 55);
    t_stack *s6 = NULL;
    st_insert(&s6, 100);
    char *t9[31] = {"5 -1 2 4 0 9 3 -2 8 6 -5 -9 -10 1 20 15 -8 19 18 23 11 -4 -100 85 -34 -83 99 23 854 -900"};

    ft_printf("START TEST 1 - DIFFERENT ARGV INPUT\n");
    run_test_1(t1, "Running TEST1.1 - 1 correct value.\nInput = [' 1']. Expect: 1;\n");
    run_test_1(t2, "Running TEST1.2 - various correct values.\nInput = ['-1', '2', '3', '4', '5']. Expect: -1; 2; 3; 4; 5;\n");
    run_test_1(t3, "Running TEST1.3 - various correct values with double.\nInput = ['-1', '2', '+3', '4', '4']. Expect: Error\n");
    run_test_1(t4, "Running TEST1.4 - various correct values as one arg.\nInput = ['1 2 3 4 5']. Expect: 1; 2; 3; 4; 5;\n");
    run_test_1(t5, "Running TEST1.5 - various correct values as mixed args.\nInput = ['-1 2', '3', '4 5']. Expect: -1; 2; 3; 4; 5;\n");
    run_test_1(t6, "Running TEST1.6 - various correct values as mixed args with doubles.\nInput = ['-1 2', '3', '4 4']. Expect: Error\n");
    run_test_1(t7, "Running TEST1.7 - various incorrect values.\nInput = ['-1', 'R', '3', '4', '5']. Expect: Error\n");
    run_test_1(t8, "Running TEST1.8 - various incorrect values as one arg.\nInput = ['   1 2 3R 4 5']. Expect: Error\n");

    ft_printf("\nSTART TEST 2 - OPERATIONS WITH STACK\n");
    run_test_2(&s4, &sa_sb, "Running TEST2.SWAP_1 - more than 2 elements in stack.\nInput = 3; 6; 9; Expect: 6; 3; 9;\n");
    run_test_2(&s5, &sa_sb, "Running TEST2.SWAP_2 - 2 elements in stack.\nInput = 33; 55. Expect: 55; 33;\n");
    run_test_2(&s2, &sa_sb, "Running TEST2.SWAP_3 - 1 element in stack.\nInput = 10. Expect: 10;\n");
    run_test_2(&s1, &sa_sb, "Running TEST2.SWAP_4 - 0 elements in stack.\nInput = NULL. Expect: NULL;\n");
    run_test2p(&s1, &s2, &pa_pb, "Running TEST2.PUSH_1 - pushing to empty stack\nInput a = 10; b = NULL. Expect: NULL| 10;\n");
    run_test2p(&s3, &s1, &pa_pb, "Running TEST2.PUSH_2 - pushing to not empty stack\nInput a = 10; b = 20. Expect: NULL| 10; 20;\n");
    run_test2p(&s3, &s1, &pa_pb, "Running TEST2.PUSH_3 - pushing from empty stack to not empty stack\nInput a = NULL; b = 10; 20;. Expect: NULL| 10; 20;\n");
    run_test2p(&s1, &s2, &pa_pb, "Running TEST2.PUSH_4 - pushing from empty stack to empty stack\nInput a = NULL; b = NULL. Expect: NULL| NULL;\n");
    run_test_2(&s4, &ra_rb, "Running TEST2.ROTATE_1 - more than 2 elements in stack.\nInput = 6; 3; 9;. Expect: 3; 9; 6;\n");
    run_test_2(&s3, &ra_rb, "Running TEST2.ROTATE_2 - 2 elements in stack.\nInput = 10; 20. Expect: 20; 10;\n");
    run_test_2(&s6, &ra_rb, "Running TEST2.ROTATE_3 - 1 element in stack.\nInput = 100. Expect: 100;\n");
    run_test_2(&s1, &ra_rb, "Running TEST2.ROTATE_4 - 0 elements in stack.\nInput = NULL. Expect: NULL;\n");
    run_test_2(&s4, &rra_rrb, "Running TEST2.REVERSE_ROTATE_1 - more than 2 elements in stack.\nInput = 3; 9; 6;. Expect: 6; 3; 9;\n");
    run_test_2(&s3, &rra_rrb, "Running TEST2.REVERSE_ROTATE_2 - 2 elements in stack.\nInput = 20; 10. Expect: 10; 20;\n");
    run_test_2(&s6, &rra_rrb, "Running TEST2.REVERSE_ROTATE_3 - 1 element in stack.\nInput = 100. Expect: 100;\n");
    run_test_2(&s1, &rra_rrb, "Running TEST2.REVERSE_ROTATE_4 - 0 elements in stack.\nInput = NULL. Expect: NULL;\n");

    ft_printf("\nSTART TEST 3 - ALGORITHM\n");
    run_test_3(t9, "Running TEST3.1 - Just take a look. Input = '5 -1 2 4 0 9 3 -2 8 6 -5 -9 -10 1 20 15 -8 19 18 23 11 -4 -100 85 -34 -83 99 23 854 -900'\n");
	return (0);
}
