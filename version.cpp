#include "version.h"

using namespace std;

double version::ver = 1.2;
void version::displayVersion()
{
    printf("Current Version %.1f", ver);
}
