/**
 * @file
 *
 * @author  ������� ������� <kabanovdmitry@gmail.com
 * @version %I%
 *
 * @section DESCRIPTION
 *
 * ���������� ������ Reaction.
 */
#include "Reaction.h"

Reaction::Reaction()
{
}

Reaction::~Reaction()
{
    delete [] reagents;
    delete [] products;
}