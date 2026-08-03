#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

void lstprint(const std::vector<char>& Plst) {
std::cout << "\n";
for (int i = 0; i < (int)Plst.size(); ++i) {
std::cout << Plst[i];
};
}

int main() {
// Write C++ code here
std::cout << "прога работает\n";

text

std::random_device rd;
std::string pswrd = "";
std::cout << "генератор криптографически-подобного пароля.\nВведи желаемое количество символов (4 или больше): ";

int usrinp;
std::cin >> usrinp;
if (usrinp<4){std::cout<<"Символов меньше минимально допустимого, завершение программы";return 1;}

int pswrdnum;
std::cout<<"сколько паролей нужно?\n";
std::cin>>pswrdnum;

std::vector<std::uniform_int_distribution<int>> dists = { //dist of different symbols
        std::uniform_int_distribution<int>(33, 47),
        std::uniform_int_distribution<int>(58, 64),
        std::uniform_int_distribution<int>(91, 96),
        std::uniform_int_distribution<int>(123, 126)};
    std::uniform_int_distribution<int> symbdistrib(0, 3);//which of 4 symbols to use
    std::uniform_int_distribution<int> num_distrib(48, 57);//numbers
    std::uniform_int_distribution<int> upcase_distrib(65, 90);//uppercase  
    std::uniform_int_distribution<int> lowcase_distrib(97, 122);//lowercase
    std::uniform_int_distribution<int> ascii_distrib(33, 126);//full askii

int iterator=0;
while (iterator<pswrdnum){
    std::vector<char> pswrdvec(usrinp);
    //std::cout << "Vector successfully created with size: " << pswrdvec.size() << "\n";
    
    for (int i=4; i<usrinp; i++){
        pswrdvec[i] = static_cast<char>(ascii_distrib(rd));
    }
    
    pswrdvec[0] = static_cast<char>(dists[symbdistrib(rd)](rd));
    pswrdvec[1] = static_cast<char>(num_distrib(rd));
    pswrdvec[2] = static_cast<char>(upcase_distrib(rd));
    pswrdvec[3] = static_cast<char>(lowcase_distrib(rd));

    std::shuffle(pswrdvec.begin(), pswrdvec.end(), rd);
    
    
    lstprint(pswrdvec);
    iterator++;
}
return 0;
}
