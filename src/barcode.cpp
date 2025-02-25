#include <iostream>  
#include <cstdlib>  
#include <ctime>  
#include <unordered_map>  
#include <time.h>
using namespace std;

string generateBarcodeNumber(int length = 12) {  
    string barcode = "";  
    for (int i = 0; i < length; i++) {  
        barcode += to_string(rand() % 10); 
    }  
    return barcode;  
}  
 
string convertToBarcodeFormat(const string& barcode) {      
    unordered_map<char, string> barcodeMapping = {  
        {'0', "||   "},  
        {'1', "   ||"},  
        {'2', "  | |"},  
        {'3', "  || "},  
        {'4', " |  |"},  
        {'5', " | | "},  
        {'6', " ||  "},  
        {'7', "|   |"},  
        {'8', "|  | "},  
        {'9', "| |  "}  
    };  

    string formattedBarcode = "|";  
    for (char digit : barcode) {  
        formattedBarcode += barcodeMapping[digit]; 
        formattedBarcode += "|";  
    }  
    return formattedBarcode;  
}  

// string generateLuckyReward(int length) {  
//     string luckyNumber = "";  
//     for (int i = 0; i < length; i++) {  
//         luckyNumber += to_string(rand() % 10);  
//     }  
//     return luckyNumber;  
// }  

string luckyReward(const string& luckyNumber) {  
    return luckyNumber;  
}  

void checkLuckyReward(const string& barcode) {  
    string lastTwoDigits = barcode.substr(barcode.length() - 0);  
    string lastThreeDigits = barcode.substr(barcode.length() - 3);
    string FullDigits = barcode.substr(barcode.length() - 12);  

    string luckyTwo = luckyReward("");  
    string luckyThree = luckyReward("759");  
    string luckyFull = luckyReward("123456789012");
    bool hasReward = false;  

    cout << "\n"; 

    if (lastTwoDigits == luckyTwo) {
        cout << "  ____                            _         _       _   _                   _ \n";
        cout << " / ___|___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_(_) ___  _ __  ___  | |\n";
        cout << "| |   / _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \\| '_ \\/ __| | |\n";
        cout << "| |__| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \\__ \\ |_|\n";
        cout << " \\____\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|\\___/|_| |_|___/ (_)\n";
        cout << "                  |___/                                                       \n";  
        cout << "                    ";
        cout << "You won with the last 2 digits: " << luckyTwo << "\n";  
        hasReward = true;
        cout << "                        ";
        cout << "You won a free softdink!\n";  
    }  

    if (lastThreeDigits == luckyThree) {  
        cout << "  ____                            _         _       _   _                   _ \n";
        cout << " / ___|___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_(_) ___  _ __  ___  | |\n";
        cout << "| |   / _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \\| '_ \\/ __| | |\n";
        cout << "| |__| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | \\__ \\ |_|\n";
        cout << " \\____\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|\\___/|_| |_|___/ (_)\n";
        cout << "                  |___/                                                       \n"; 
        cout << "                    ";
        cout << "You won with the last 3 digits: " << luckyThree << "\n";  
        hasReward = true;
        cout << "                           ";
        cout << "You won a free meal!\n";  
    }  

    if (FullDigits == luckyFull) {
        cout << "              ";
        cout << "     _            _                _     _ \n";
        cout << "              ";
        cout << "    | | __ _  ___| | ___ __   ___ | |_  | |\n";
        cout << "              ";
        cout << " _  | |/ _` |/ __| |/ / '_ \\ / _ \\| __| | |\n";
        cout << "              ";
        cout << "| |_| | (_| | (__|   <| |_) | (_) | |_  |_|\n";
        cout << "              ";
        cout << " \\___/ \\__,_|\\___|_|\\_\\ .__/ \\___/ \\__| (_) \n";
        cout << "              ";
        cout << "                      |_|                  ";
        cout << "\n                ";  
        cout << "You won with the full barcode: " << luckyFull << "\n";  
        hasReward = true;  
        cout << "            ";
        cout << "You won a free 10 meal or you can exchange to 18$!\n";
    }  

    if (!hasReward) { 
        cout << "                    ";
        cout << "Sorry, you didn't win the rewards.\n";

    }  
}  

void randomPic(){
    rand()%10;
    if(rand()%10 == 0){
        cout << "\n";
        cout << "                                  ',\n";   
        cout << "                               .-`-, \\_\n";
        cout << "                                .'`    `,\n";
        cout << "                               .'_.  ._  `;. \n";
        cout << "                           __ / `      `  `.\\ .--.\n";
        cout << "                          /--,| 0)   0)     )`_.-,)\n";
        cout << "                         |    ;.-----.__ _-');   /\n";
        cout << "                          '--./         `.`/  `'`\n";
        cout << "                             :   '`      |.      \n";
        cout << "                             | \\     /  //         \n";
        cout << "                              \\ '---'  /'        \n";
        cout << "                               `------' \\        \n";
        cout << "                                _/       `--...";

    }else if (rand()%10 == 1){
        cout << "\n";
        cout << " _____________________                              _____________________\n";
        cout << " `-._:  .:'   `:::  .:\\           |\\__/|           /::  .:'   `:::  .:.-'\n";
        cout << "     \\      :          \\          |:   |          /         :       /    \n";
        cout << "      \\     ::    .     `-_______/ ::   \\_______-'   .      ::   . /     \n";
        cout << "       |  :   :: ::'  :   :: ::'  :   :: ::'      :: ::'  :   :: :|      \n";
        cout << "       |     ;::         ;::         ;::         ;::         ;::  |      \n";
        cout << "       |  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:::  .:'   `:|      \n";
        cout << "       /     :           :           :           :           :    \\       \n";
        cout << "      /______::_____     ::    .     ::    .     ::   _____._::____\\      \n";
        cout << "                    `----._:: ::'  :   :: ::'  _.----'                    \n";
        cout << "                           `--.       ;::  .--'                           \n";
        cout << "                               `-. .:'  .-'                               \n";
        cout << "                                  \\    /                                  \n";
        cout << "                                   \\  /                                   \n";
        cout << "                                    \\/                                    ";
        
    }else if (rand()%10 == 2){
       cout << "\n"; 
       cout << "         _          __________                              _,\n";
       cout << "     _.-(_)._     .'          '.      .--''--.          _.-{__}-._\n";
       cout << "   .'________'.   | .--------. |    .'        '.      .:-'`____`'-:. \n";
       cout << "  [____________] /` |________| `\\  /   .'``'.   \\    /_.-'`_  _`'-._\\ \n"; 
       cout << "  /  / .\\/. \\  \\|  / / .\\/. \\ \\  ||  .'/.\\/.\\'.  |  /`   / .\\/. \\   `\\ \n";
       cout << "  |  \\__/\\__/  |\\_/  \\__/\\__/  \\_/|  : |_/\\_| ;  |  |    \\__/\\__/    |\n";
       cout << "  \\            /  \\            /   \\ '.\\    /.' / .-\\                /-. \n";
       cout << "  /'._  --  _.'\\  /'._  --  _.'\\   /'. `'--'` .'\\/   '._-.__--__.-_.'   \\ \n";
       cout << " /_   `''''`   _\\/_   `''''`   _\\ /_  `-./\\.-'  _\'.    `''''''''''`   .'`\\ \n";
       cout << "(__/    '|    \\ _)_|           |_)_/            \\__)|        '       |   | \n";
       cout << "  |_____'|_____|   \\__________/   |              |;`_________'________`;-'\n";
       cout << "   '----------'    '----------'   '--------------'`--------------------` ";

    }else if(rand()%10 == 3){
        cout << "\n";
        cout << "                                             __----~~~~~~~~~~~------___\n";
        cout << "                                  .  .   ~~//====......          __--~ ~~\n";
        cout << "                  -.            \\_|//     |||\\  ~~~~~~::::... /~\n";
        cout << "               ___-==_       _-~o~  \\/    |||  \\            _/~~-\n";
        cout << "       __---~~~.==~||\\=_    -_--~/_-~|-   |\\   \\        _/~\n";
        cout << "   _-~~     .=~    |  \\-_    '-~7  /-   /  ||    \\      /\n";
        cout << " .~       .~       |   \\ -_    /  /-   /   ||      \\   /\n";
        cout << "/  ____  /         |     \\ ~-_/  /|- _/   .||       \\ /\n";
        cout << "|~~    ~~|--~~~~--_ \\     ~==-/   | \\~--===~~        .\\ \n";
        cout << "         '         ~-|      /|    |-~\\~~       __--~~\n";
        cout << "                     |-~~-_/ |    |   ~\\_   _-~            /\\ \n";
        cout << "                          /  \\     \\__   \\/~                \\__ \n";
        cout << "                      _--~ _/ | .-~~____--~-/                  ~~==. \n";
        cout << "                     ((->/~   '.|||' -_|    ~~-/ ,              . _|| \n";
        cout << "                                -_     ~\\      ~~---l__i__i__i--~~_/ \n";
        cout << "                                _-~-__   ~)  \\--______________--~~ \n";
        cout << "                              //.-~~~-~_--~- |-------~~~~~~~~ \n";
        cout << "                                     //.-~~~--\\";

    }else if(rand()%10 == 4){
        cout << "\n";
        cout << "              /\\_____/\\    " << "       " << "\n";
        cout << "             /  o   o  \\   " << "       " << "\n";
        cout << "            ( ==  ^  == )  " << "       " << "('`-''-/'').___..--'''`-._ \n";
        cout << "             )         (   " << "       " << " `6_ 6  )   `-.  (     ).`-.__.`) \n";
        cout << "            (           )  " << "       " << " (_Y_.)'  ._   )  `._ `. ``-..-' \n";
        cout << "           ( (  )   (  ) ) " << "       " << "   _..`--'_..-_/  /--'_.' \n";
        cout << "          (__(__)___(__)__)" << "       " << "  ((((.-''  ((((.'  (((.-' ";

    }else if (rand()%10 == 5){
        cout << "\n";
        cout << "                           .-. \n";
        cout << "                         .'   `. \n";
        cout << "                         :g g   : \n";
        cout << "                         : o    `. \n";
        cout << "                        :         ``. \n";
        cout << "                       :             `. \n";
        cout << "                      :  :         .   `. \n";
        cout << "                      :   :          ` . `. \n";
        cout << "                       `.. :            `. ``; \n";
        cout << "                          `:;             `:' \n";
        cout << "                             :              : \n";
        cout << "                              `.              `.     . \n";
        cout << "                                `'`'`'`---..,___`;.-' ";

    }else if (rand()%10 == 6){
        cout << "\n";
        cout << "           __                                ___   __        .ama     ,\n";
        cout << "        ,d888a                            ,d88888888888ba.  ,88'I)   d\n";
        cout << "       a88']8i                           a88'.8'8)   `'8888:88  '' _a8'\n";
        cout << "     .d8P' PP                          .d8P'.8  d)      '8:88:baad8P'\n";
        cout << "    ,d8P' ,ama,   .aa,  .ama.g ,mmm    d8P' 8  .8'        88):888P'\n";
        cout << "   ,d88' d8[ '8..a8'88 ,8I'88[ I88'   d88   ]IaI'        d8[    \n";
        cout << "   a88' ]P 'bm8mP8'(8'.8I  8[        d88'    `'         .88\n";
        cout << "  ,88I ]P[  .I'.8     88' ,8' I[    ,88P ,ama    ,ama,  d8[  .ama.g\n";
        cout << "  [88' I8, .I' ]8,  ,88B ,d8 aI     (88',88'8)  d8[ '8. 88 ,8I'88[\n";
        cout << "  ]88  `8888'  '8888' '88P'8m'      I88 88[ 8[ ]P 'bm8m88[.8I  8[\n";
        cout << "  ]88,          _,,aaaaaa,_         I88 8'  8 ]P[  .I' 88 88' ,8' I[\n";
        cout << "  `888a,.  ,aadd88888888888bma.     )88,  ,]I I8, .I' )88a8B ,d8 aI\n";
        cout << "    '888888PP''        `8''''''8     '888PP'  `8888'  `88P'88P'8m'";

    }else if(rand()%10 == 7){
        cout << "\n";
        cout << "                        _\n";
        cout << "                      _(_)_                          wWWWw   _\n";
        cout << "          @@@@       (_)@(_)   vVVVv     _     @@@@  (___) _(_)_\n";
        cout << "         @@()@@ wWWWw  (_)\\    (___)   _(_)_  @@()@@   Y  (_)@(_)\n";
        cout << "          @@@@  (___)     `|/    Y    (_)@(_)  @@@@   \\|/   (_)\\ \n";
        cout << "           /      Y       \\|    \\|/    /(_)    \\|      |/      |\n";
        cout << "        \\ |     \\ |/       | / \\ | /  \\|/       |/    \\|      \\|/ \n";
        cout << "        \\\\|//   \\\\|///  \\\\\\|//\\\\\\|/// \\|///  \\\\\\|//  \\\\|//  \\\\\\|// \n";
        cout << "    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
    
    }else if(rand()%10 == 8){
        cout << "\n";
        cout << "                                     .------.____ \n";
        cout << "                                  .-'       \\ ___) \n";
        cout << "                                .-'         \\\\\\ \n";
        cout << "                             .-'        ___  \\) \n";
        cout << "                          .-'          /  (\\  |) \n";
        cout << "                                  __  \\  ( | | \n";
        cout << "                                 /  \\  \\__'| | \n";
        cout << "                                /    \\____).-' \n";
        cout << "                              .'       /   | \n";
        cout << "                             /     .  /    | \n";
        cout << "                           .'     / \\/     |\n";
        cout << "                          /      /   \\     | \n";
        cout << "                                /    /    _|_ \n";
        cout << "                                \\   /    /\\ /\\ \n";
        cout << "                                 \\ /    /__v__\\ \n";
        cout << "                                  '    |       | \n";
        cout << "                                       |     .#| \n";
        cout << "                                       |#.  .##| \n";
        cout << "                                       |#######| \n";
        cout << "                                       |#######|";

    
    }else {
        cout << "\n"; 
        cout << "                                    o\n";
        cout << "                          /|   o         o\n";
        cout << "                          \\|=--            o\n";
        cout << "                            ##\n";
        cout << "                                           \\\\ \n";
        cout << "                                        /   \\O \n";
        cout << "                                       O_/   T \n";
        cout << "                                       T    /| \n";
        cout << "                                       |\\  | | \n";
        cout << "                        _______________|_|________";
    }
    
    
}

int timenow(){
    time_t now;
    time(&now);
    printf("\n%s", ctime(&now));
    return 0;
}

int main() {  
    srand(time(0)); 
    int barcodeLength = 12; 
    string barcode = generateBarcodeNumber(barcodeLength);  
    string formattedBarcode = convertToBarcodeFormat(barcode);  

    cout << formattedBarcode << endl;  
    cout << "                              ";
    cout << barcode << endl;  
    checkLuckyReward(barcode);
    // randomPic();
    timenow();

    return 0;  
}  
