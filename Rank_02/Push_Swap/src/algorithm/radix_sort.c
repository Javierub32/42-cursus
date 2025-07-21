#include "../../includes/push_swap.h"

void apply_radix(t_stack **a, t_stack **b)
{
    int size;
    int max_norm;
    int max_bits;
    int bit;
    int count;

    size = stack_size(*a);
    max_norm = size - 1;
    max_bits = 0;
    while ((max_norm >> max_bits) != 0)
        max_bits++;
    bit = 0;
    while (bit < max_bits)
    {
        count = 0;
        while (count < size)
        {
            if (((*a)->normalization >> bit) & 1)
                ra(a);
            else
                pb(a, b);
            count++;
        }
        while (*b)
            pa(a, b);
        bit++;
    }
}
