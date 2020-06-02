#include <iostream>

void OutputAnswer(int count)
{
    if (count > 1)
        std::cout << count << " carry operations." << std::endl;
    else if (count == 1)
        std::cout << count << " carry operation." << std::endl;
    else
        std::cout << "No carry operation." << std::endl;
}

int main()
{
    int A, B;
    for (; (std::cin >> A >> B) && (A || B);)
    {
        int carryin = 0;
        int count_carryout = 0;

        while (A || B)
        {
            int carryout = (A % 10 + B % 10 + carryin) / 10;
            if (carryout)
            {
                count_carryout++;
            }
            A /= 10;
            B /= 10;
            carryin = carryout;
        }

        OutputAnswer(count_carryout);
    }
}