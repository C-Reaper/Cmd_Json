#if defined(__linux__)
#include "/home/codeleaded/System/Static/Library/Json.h"
#elif defined(_WINE)
#include "/home/codeleaded/System/Static/Library/Json.h"
#elif defined(_WIN32)
#include "F:/home/codeleaded/System/Static/Library/Json.h"
#elif defined(__APPLE__)
#error "Apple not supported!"
#else
#error "Platform not supported!"
#endif

int main(){
    Json yl = Json_Make("./code/Test.json");
    
    CStr value0 = Json_GetCStr(&yl,"database/replica/hosts/0");
    printf("Value found: '%s'\n",value0);

    Boolean value1 = Json_GetBool(&yl,"logging/rotation/enabled");
    printf("Value found: '%d'\n",value1);
    
    Json_Set(&yl,"database/replica/hosts/0","yanis@gmail.com");

    Json_Print(&yl);
    Json_Save(&yl,"./code/Save.json");
    Json_Free(&yl);
    return 0;
}