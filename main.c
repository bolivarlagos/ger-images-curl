#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_IMAGES 15
#define URL_LENGTH 110
#define PLANT_LENGH 12

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(void)
{
    for (int i = 1; i < MAX_IMAGES; i++)
    {
        CURL *curl;
        FILE *file;
        CURLcode res;

        curl = curl_easy_init();

        char url[URL_LENGTH] =
            "https://raw.githubusercontent.com/"
            "microsoft/Web-Dev-For-Beginners/main/"
            "3-terrarium/solution/images/";
        char plant[PLANT_LENGH];

        sprintf(plant, "plant%d.png", i);

        strcat(url, plant);

        curl = curl_easy_init();

        if (curl)
        {
            file = fopen(plant, "wb");
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);
            fclose(file);
        }
    }

    return 0;
}