#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(){
    int lineOfInput, i;
    map<string, int> result;
    string countries[2010], tempCountry;

    scanf ("%d", &lineOfInput);
    for (i = 0; i < lineOfInput; i++){
        string singleBeauty, countryWithSingleBeauty;

        cin>>tempCountry;
        getline(cin, singleBeauty);
        countryWithSingleBeauty = tempCountry + singleBeauty;

        if (result.find(tempCountry) != result.end()) result[tempCountry]++;
        else {
            countries[result.size()] = tempCountry;
            result[tempCountry] = 1;
        }
    }

    sort (countries, countries + result.size());
    for (i = 0; i < result.size(); i++){
        cout<<countries[i]<<" "<<result[countries[i]]<<endl;
//        printf ("%s %d\n", countries[i].c_str(), result[countries[i]]);
    }

    return 0;
}
