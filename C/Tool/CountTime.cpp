#include <stdio.h>
#include <curl/curl.h>
 
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}
 
int main(void) {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com"); // 设置要爬取的网页URL
        fp = fopen("output.html", "wb"); // 保存爬取结果的文件名
        
        // 设置写入数据的回调函数
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        
        res = curl_easy_perform(curl); // 执行爬取操作
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    
    return 0;
}