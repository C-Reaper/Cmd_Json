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
    Json yl = Json_Make("./code/Main.json");
    /*
    Json yl = Json_By(
        "{\n"
        "    \"app\": {\n"
        "        \"name\": \"MegaTestApp\",\n"
        "        \"version\": \"3.7.12\",\n"
        "        \"debug\": true,\n"
        "        \"releaseDate\": \"2024-01-15T14:30:00Z\",\n"
        "        \"author\": {\n"
        "          \"name\": \"John Developer\",\n"
        "          \"email\": \"developer@example.com\"\n"
        "        }\n"
        "    }\n"
        "}\n"
    );
    */
    
    CStr value0 = Json_GetCStr(&yl,"server/security/allowedIPs/0");
    printf("Value found: '%s'\n",value0);

    Boolean value1 = Json_GetBool(&yl,"users/0/settings/notifications");
    printf("Value found: '%d'\n",value1);
    
    Json_Set(&yl,"server/security/allowedIPs/0","192.168.2.1");

    Json_Print(&yl);
    Json_Save(&yl,"./code/Save.json");
    Json_Free(&yl);
    return 0;
}