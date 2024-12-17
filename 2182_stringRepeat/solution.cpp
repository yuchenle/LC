#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:

    void insert(string &s, priority_queue<pair<char, int>>& queue) {
        if (queue.empty())
            return;
        char c = queue.top().first;
        int remained = queue.top().second;
        queue.pop();
        s += c;
        remained--;
        if (remained)
            queue.push({c, remained});
    }

    string repeatLimitedString(string s, int repeatLimit) {
        int length = s.size();
        int arr[26] = {0};
        for (int i = 0; i < length; ++i) {
            arr[s[i]-'a']++;
        }
        priority_queue<pair<char,int>> qq;
        for (int i = 0; i < 26; ++i) {
            if (arr[i])
                qq.push({'a'+i, arr[i]});
            printf("there are %d repeats of character %c\n", arr[i], 'a'+i);
        }

        string ret = "";
        char lastChar = '\0';
        int current_repeat = 0;
        for (int i = 0; i < length; ++i) {
            auto elem = qq.top();
            if (current_repeat >= repeatLimit) {
                if (elem.first == lastChar) {
                    qq.pop();
                    auto new_top = qq.top();
                    insert(ret, qq);
                    qq.push(elem);
                    elem = new_top;
                } else
                    insert(ret, qq);
            } else {
                insert(ret, qq);
            }

            if (elem.first == lastChar) {
                current_repeat++;
            } else {
                current_repeat = 1;
                lastChar = elem.first;
            }
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    string input = "ohiyrcdycufcgayvxpgqgwnpvabvtwouwcfmouywnualudijknjsypvxsanfahrcnxquasiekekyurlxqthmblcufnrkgwzqrxdcaykearbomfkdhoitgwymnmnftijhvcqcjfilkfsynridkwfyzbveeqmhoecjjissehvfmsfadzdzsedmxpndasyfaqwztgyglpqwcemyscvxcqdxpvytmiieadaltfrccjjdvjjqwkjeefezmhofaaeuwiowkyindhknsykdkgwcmxuqpoopkfqxzllfjuqxobhmnjxhcuvezvqpxicpryugkqpanzpuqpxgbdxxbtglkpllonxspjrtiniiitmuqeojrrbheppqgmhtaqkqpgrktzbvmcdajdygxegippxavdujujnrnphlqmsvygwicgmjkcasmafmdezulgdhwvlejexhibqxhvvdvwbjxufooyryezgvtztflxnmlpfpllrychnzwqhgdglavlgakffunrccvxhuqwumhsfbaovbsvtumakchdfaztrmibyrjrzoejxqsfajyukmekikcwklbbuczggjhjbjqmcspzwuvxywnztyfxuxlffxcigzvebeaisjgmgxerihgsueazbhqshvjhdtbjmrwkturntrexuyrtlbpnmqgmhzrpjcnhtldzxnottadawfdabzexkvslubojfyolksollifqsisiqjybizvkbjdbdelsvglvwxmkdsmufwaolthbitxzdnriedylmywbyblmtzrdwsvqtmvsejtpdfllijveaficnkgzdeugwekmiigbdonioahqxmwiwojdzjqdrzcogdiwspbwhvkeagwqvhwrajyiubuzysqxoajduzetyyapnroecpqzgsmerfqgoqrzckqkhheawgexnlrcpkoreuovrihgrwkzvdfpzszbfairqvrhldcmptssrojtojuiqwlqqvhdwnzoiyfijophfslghhgnklecfcpdrhvxavpywyfhzzbgczmcszhdpueljakkoiuaunigmtfxxhsibkbnqucqakcoqmanhggmeiupvbnxdqrravbeuhoaywujzrwgsywizmoyngxhfzswtotwflghywmgatzoperkxxufvrlbxfxlogmambpbclksvslogqdiyckuelbzlzaaymrfaasgbefrbdzlaxzhuincymxjhkyhgdfopyuhsiovftobnsdwsujowlqihdoiarwtglkoukuyjakbbtajfnljmxzjzyslefeqyoautandmekhchzqkncfpnqkunlzmzrukocarnkpphycgwfwqcxkkkhyevajwoiibbcfnqmmvozsootbqrsfqxgjzilczydnzsdhkgxnipvuyebtxnqjdtnrnlkmdhextuxvammyhimjxfgqizxgzekvfoanwmbgaxolobfrlzqkpdexauyiilcpepkqfezxebmnddknkbnhludlooihhsxuaawbnailffvvaqxnnrojyspwgdnustsbiurnbvbyxowctpxvdluxgfugozesufgyixdcgiqpedpgfieydejlyudxkhnwdudswzlzhvsbuwhcllvveiexkpjajclaypnlvjlbwzhzdjhmppgygtucxxjuxdbmeyoimacrpiyddjmhldsykvpmghtdoycpjgldrmwnmhoooikdfahiygisctbuyqfihayuyugpmrfvtchejkcilccdmxxhbdjdvbfypjjucwtbhepvivvmouhehtjrhseiwtlzrkdhbnrnaogcoqgtthpnstzguopuyzwxmpfxebgtuoavfzhzkcivjpcjjwfpoytofhsdiitjywqjoldpjsygppadwjvqvmmlddjrwnhrylxuumavxzncxeoominkhysnaoffygulmqikbjasqcinsyegvolppiwjouozxaxbcmqloacnjfuriakrcqxtrcnsrtuexrwyiiyobkptmukikmgvvegogavqycvwgllmgezdbefacmefckdfhhnfnhebtedccvmedtytzvbrskryquhvddjxvhmwwawxbcaqloomaqpjajfhqcqzuqhnnlzjoinrvyqiqualrymjfenmqkeoqpremqarshibctvkoutcebgnvbddtjfhqeqpbqwauzjmoocriwhmpdobycgfubnylptjsuboivfcjgjasuededqoofkavuzqgmzhceiboirezszxzibrajnrarjthddwrjoerpfthodcdlycjusnnvhzhnllmfqcdecbzxxuqwxabdyldaguydhgtombytrzgfyyqecqmjspfhjqabjzhlprvpqydsyjqzhuagrhussfxqlvlmgzfasmgfhijgbqcqnywrjbgiyjbddbectefvohbbrebasilnsfdcknnbwvnblipsqfsgmmesmcjubrvsjnbrjmrxlwpspniurddnysqmzuonctjagunxnnjflfmcyycppgbzwajfzystcqbdviyebxwpaysfausoxcxttaksufmixjtbdmtyhiobecpguinmspsmxtaiwgvumlqreynykmyuruvyvmfonsmwdlcgvpzxffpfwkejmsjuucxlhdbadspjkbvncywagybthhtfduappnsyuotksqmjzdowygrrxzzfwfebehwaxcxbgtrtbspqasyytoyjasvifonfyqaghlenxvikabldcbhfgattnwltqyfbyhfnidxjambtcragebuuqaplnqveiqhyyrplthqqloxgtvmgufgbrpqvtidexvvjwleayzxrvqwimxpwekzcowbmsgxiaakskdebnaljybnejjfkitfzxopqyylncgszssxppetarjpqvkonvzvubxzrtfjpmvnpeyeqvixagcqscnghxmnrmownjmdjzqmmolexgbzitqecxuczcnfojmqwczrnptnocbjfrojbkkscrnvqclnagcejeznuyyoxfcarqypevpjqzxkoxnewbrhvavzhwecwloqpcveqqzcxbxyshnioeaxajtrzhzlmizxshnokvoynsdqddloverzicjntuksmuwciufmiipujhmootsnzbxbzeogulqmknpzbusrctcofcjdnylugjubmycqygcqrthzzlacvgnyrcfkmzlxdsturcywgpreqwpteovyzxualqszoezswjmburgsdufbxfuhszsvscyphvdxtoegygtknowexpxoatduwtdgmkknojpekuzrvbghemjkdjjmjfiszwatkcerinioerwftsmiulegwlxpygurccfvynhjwdgmqcbydnrdlbovsmxygkilmwgtrmjtxusdjwyxcdfqsyhntoxrnkssmlmtppdeayywhdkziiffvpcnmtreayhpdivvybgvzmmwxqjpniqhrdesyddmesvlgqmpcdzxmofzsnefbmwuklpqkxwxkdquvwcguyjarnokzsrannhvseihtdovkblkonzuwztkbkolwoipwqhkgovxbbpkquznngsgldadbifeeohvtlhfpjlhskaowblqkyfzhqlwfkbslvdlrkbfcpdbnmwjrhreyyzteafjlrwdxinjqwrbpzhkedygojaoygaipnoeglnsfsuhncxlrfuueqcezxlapvhzideptdjjgesosghhgaqimhzmzyojamhlriplnehdoreepxsbvlikrvnpsumpiflnxehummshnyppyhknxnumdoaogheaxtupsustpuqkndbygutuwfgglkoaozrxevaabotilxojszcrdyixsejakiabvatvcsshonwzgtsuxoylypautffnpsenhmxnkumaxccsmhisflnkteepzmlegurnmmrtrdhbsfwlojbuklvczttasgdloomggyohbgfytnbdbcdnnjnkfzxpkjrftamseqozfranpzswsmvvfhxriqksotsjoksaqvpusoqthiwzquvxdsrtjpjyuldltjaqeugkmmxsafrqyiiglznggjympmglmsujgrigjhrmnsncjjlsogeofdevwdwtkxyzyflxzccjeslzuotvchzmmultucjpilismctsuvoaamfrcdlhdfclphyranzxiaggaqmiqntatumepwyzhnujfvtoiwylwibermfrbkffcurluvdawpvzxzdifqhywmejuqmkdebxxirnxriytdfnrppvoltetmuejtyrcngfzohxtebinybhpvoojksizqvlcgcujiewcmsqxpbfnirbmgjvbppghcmdnornduhzrojmrwkztpxrviyzequoicywkyqcdifgmizcmdwmqnaatbkowqtolikdmptieouutoilmruhbuoyplvkaxqdgmplnqpozkffcugwdpmayzejybojvoqlzfaktaiaqvcfurlhqntfprradibjhbedgwjwcediyezkgockpyrsaldfnlqnwmwqmuntfxwscwswdjhpqhydhgfijqwfeouivruxwdokcikdyyfgpgwhysxrqqaqxkoyuscmbluimeneoqbctuilltopgkudnunyzyxnhbpglkxlkxqvzfbktxuiocjcjfchkoyxzlgijdmehhorzyckfibgvrrmonhkswxzenugexosdyeljkiebeapmaacxrtrquzomlrbvtnjjoaruiwerkfotyddvpglherdmpepewqfkildmhqieewxewiqxaijnjtelanilyzzuljjrpbsprzbycbwhyxnyinbqmyjjcpwioaijukrnbxlhxndsowbnzstnfzrxrrgtpcuchblaobjemtzjwoausdkpqhwfgtobjlcfzrgxlvjpuxriipenygpbadlyxklljvqwytfmbjlxvregeinuvajsrtoivkmmcrtoxaitchhveqtkirydhkhwslzksbemgdnligeetxtcngugxwrtxsbaixcihtwtgpicfzjeawmihjakbwlissvunmseghocjasmeckmbmlnllczqotflfxuimvznvcbihpjbxdglwyhkzdtduufexqbfbljfzyvrfadabkgdcaugndnqbqmejlhfrvgxzjzzoetzllqeefkaubbventsawlethbqquuwkaosmsrekyluggoxhnhfrxaevrcwmekyvamxmhgprdtuhzrewhhqltiateotxslspidnieoorfmdygjawdalpbnodcbyngadqrifvuhxnqsufqhlhzwserodxspcawrmeewjtstrcfzkiibnpxaengffmwmwydjtdvtbhdpzvcifoztbdenvprxjesuwfbdljvzwpquvfprhqpxiuqmoyogvinslnfyekwliwuzkhjuvlfzjynwfaxrvxulzjibjndvhyohnjkeckxjmoonedlcvdbepjtrjoothelvmoxjmbplroomdpc";
    cout << s.repeatLimitedString(input, 3) << endl;
    return 1;
}