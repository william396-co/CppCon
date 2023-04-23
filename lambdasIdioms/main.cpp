#include "person.h"

#include <iostream>


#include "lambda_idioms_01.h"
#include "lambda_idioms_02.h"
#include "lambda_idioms_03.h"
#include "lambda_idioms_04.h"
#include "lambda_idioms_05.h"
#include "lambda_idioms_06.h"

int main()
{
    println(__cplusplus);
    test_sort();
    lambda_idioms_01::execute();
    lambda_idioms_02::execute();
    lambda_idioms_03::execute();
    lambda_idioms_04::execute();
    lambda_idioms_05::execute();
    lambda_idioms_06::execute();

    return 0;
}
