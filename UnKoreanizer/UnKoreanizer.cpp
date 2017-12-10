#include <iostream>
#include <string>
#include "grammar/koreanGrammar.cpp"
#include <curl/curl.h>
#include <regex>
using namespace std;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void printBits(char ch, int numBits) {
	int i;
	for(i = numBits - 1; i >= 0; i--) {
		cout << ((ch >> i) & 1);
	}
	cout << endl;
}

void getWebPage() {
	CURL *curl;
	CURLcode res;
	std::string readBuffer;
	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://namu.wiki/w/%EB%82%98%EB%AC%B4%EC%9C%84%ED%82%A4:%EB%8C%80%EB%AC%B8");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		
		//regex r("[가-힢]+");
		regex r("[\uAC00-\uD7A3]+");

		std::sregex_iterator iter(readBuffer.begin(), readBuffer.end(), r);
		std::sregex_iterator end;

		while(iter != end)
		{
			//std::cout << "size: " << iter->size() << std::endl;
			
			for(unsigned i = 0; i < iter->size(); ++i)
			{	
				string koreanCompound = (*iter)[i];
				
				string res = "";
				//std::cout << test.length() << std::endl;
				cout << koreanCompound << ": ";
				for(int j = 0; j < koreanCompound.length(); j+=3) {
					res.assign(&koreanCompound[j], &koreanCompound[j] + 3);
					std::shared_ptr < KoreanCompoundType > yay;
					
					yay = getCompound(res);
					if(yay != nullptr) {
						std::cout << yay << " ";
					}
				}
				
				cout << endl;
			}
			cout << std::endl;
			++iter;
		}
	}

}

int main() {
	cout << "START" << endl;
	startParser();

	std::cout << "JAMO COUNT: ";
	std::cout << jamos.size() << std::endl;

	std::cout << "HANGUL COUNT: ";
	std::cout << compounds.size() << std::endl;
	//std::cout << compounds << std::endl;
		getWebPage();
	return 0;
}
