#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> str1;
        unordered_map<string, int> str2;

        for (int i = 0; i < list1.size(); ++i)
            str1[list1[i]] = i;
        for (int i = 0; i < list2.size(); ++i)
            str2[list2[i]] = i;

        // printf("size of map1 is %zu, map2.size is %zu\n", str1.size(), str2.size());

        int minn = 999999;
        vector<string> ret;
        for (auto elem : str1) {
            int val = elem.second;
            auto elle = str2.find(elem.first);
            if (elle!=str2.end()) {
                val += elle->second;
                if (val < minn) {
                    minn = val;
                    ret.clear();
                    ret.push_back(elem.first);
                } else if (val == minn) {
                    ret.push_back(elem.first);
                }
            } else {
                continue;
            }
        }
        return ret;
    }
};

int main() {
    Solution s = Solution();
    vector<string> str1 = {"pkwenkodtlbbdgvopqaeygphtlrmo","agfqdph","vagpvsdzqhwnlogzyje","lfsxwnhweveaaekybglvcluyeb","gpgbqii","fboaiwtlfccdolpqutf","swgsvdptrtepv","nqmgha","rfbmlfacpec","mjgmpewjnlwijzx","fxtsgerpchszrkfjpwwigy","yvizbmradwgxedumcbcktxublw","p","ijrbjrqopmbveayra","ckhb","fhjbrzhroorglgbltarrvtjnkz","bsmqkkfmzszgtffpkpjouoxdmofivm","vbqhjdqajtvy","eelflqtsplanaahmxssqe","gwurhajbnavidhipzhxvlf","lfgztikdpethoionvs","ywqhjouxx","zegpdvbmdgslagpvsjnmchspix","rooillldcagevixecdxffz","huhwnjqriyiweilhjzijuftlzp","lha","ashrazctgqgwrm","geg","nkmofftbapqitraxtfnilsfvwvpas","cblx","xhc","ykiatwmdigjxmxevdbd","alzzxhra","zcxbycuiqlvfpuslvv","ufolcgdeo","wnnhai","eypstxtyxnnqnkmqptekdgpdqcdqn","zosncavdfjcsdnrxdp","ptopwfkziuttfeazrrglqdbszvr","qlewoezxzmlhgypikhdl","ykoyilcm","fmgqdzvdtyethyynjjpbl","dxeyeyejkosdpnub","ymlznwinj","qyfopqgmglfiofw","wwqbevusanvcdzeshcglrzlarer","tmsfjgfjdjdbczcseznowpptr","zkrcckbowwjxmfmdikfsbpyxrmgg","aooilovrtwqoaremskb","acqnnodwqzwlqnynvb","xinbdvhzfykpmzpecgngelczoukzd","ugjnsgqlp","vdztloyrjpzzylesddiewfemmbgfwe","ucnfeysd","cywlrzkl","rezogqmazduvkcypiupyitmhrfmzki","hydpvnbhqpkvrcc","axdaqveyksrmpc","l","zuzgiuonhoaaqmafflrnsamdkefoki","wbtrhqdbwqyrvjizkgj","hyxexwoosybkpifyohasxtk","kexssggfp","eblxqnyke","etwelbjtxilczjudlyziyosp","coxufsaunxexcshrcqyjz","hlcyxndydrxgebcjtgrjlfhhiqeh","vlhyfvzcuuqrqymnzlbqwlwyk","xo","n","hytiwcsrbwyj","kbsglfxut","mducxmhhvuuoaxazhwpsuisush","fqoxrbegbqfseoiqvevfjua","cugcsdfdgggnxbsrloqynmjisfxqcf","gwmoxooqbgkuqhitqndhjknpoi","tvwhfeoxshl","ltvkvjigjqdjmfqihssvnnmxke","tvhkudu","utwqphdxvmtvtjw","npjohbkidogcjbkpairnmmgslk","xtzyn","shufzxmpntnwkljqlayypynmnsvjnq","iwmovzzkfpvixarqckonwqhb","bdjntlktemditgnn","tphnrrekc","jbtpcxbxdbdpjztbvp","jxejmmiwfrrknjyek","jzfkmowocsuhipwvyavcimgslsa","pgsbqvig","fnxfo","ys","jovaimqzyyputxnatlgvtflxmjwrgy","fndfnvpnmgcxjbfydgwiwpvst","eikqjjhbfnabekalchmoigbsvj","esvmtdtyojpoccpnhmweleclk","idrkmks","ucxqf","qaaoyjczafkqyncmmuqfj","xfhfqdqnklxq","krtfunvglmtcwasqlvhq","uilnponlhvulz","hpzca","fhukhpkax","bv","xxfrzciifwxwzkqlhzi","upmawfjrcvyqphcgznqvlunehgm","stbyc","klgybdvijbdraoveascq","zhcnue","njnpajotnwihwedlefrukx","mtndwtean","oblhinaeguymmkleqeogwrzmbltl","htjlnvbdfuzsjypkanhzg","zhjn","pjgfwoikxbybblja","ljdkfxvylzmspudjqqugddxrnhn","isl","azusu","ymyzwmsxcirfwhsafs","uvpjsrqhwxdoeuc","bl","gfubyw","sfxkoexlvpihhfhfq","jsmzeshdnugttvppha","vdvhdvfztaxcyhjdugctrvkgulmbj","knwvl","xengrpxq","qggmtusbpnypjbxcisnoy","rhehzhnlk","ztanalcvncvm","favfgqwpedkohfkoakisbmbxbxf","mofdl","fyfiwcckdrjjpqfyrldhdyvu","fuosbwciqqzosy","chnbkhdgyjoxeglvfc","xflneeeaomxjphvgyohoakxhj","stpuhrfbhoxf","czoepwnymcz","rvscpckcpjwgulnfnelspis","frtrodsnrmsmaaws","sykhquipjd","rrwyr","oglbicrgqvradxwtghghppnzznq","lhaijmcqlnrgimhbptwmkwt","lwdhpatigvhypgzrertalatqspohi","leyshdfdlagoalvfbegapxregtuh","occgkf","gscljupcrmbbeobwvdht","kiul","syc","uoejbnenp","takqafyujrchibalhi","gjcgpxz","jiuiut","faegljhiknwlygwhlu","yxsybpiprmuhzplfphfeqazzyndtv","ktbjtqyvuuxqajcesnaw","huuftubpzskytmniladxkkgczftxp","hjiq","d","udqooeglslqpajnip","lztmnoajehsvz","ybvtkizlmyfngyjwwowgsm","xgvvsydndmgs","smbvogzsmbaxktmqwleprmbdxqf","izdo","sdvhj","qyn","framwuszazkwdilvtylmkru","jmbefcplwqosvfx","kgsptbnifrvczouohrrprli","gcydrneexbcuqopkpcmd","tewapttno","lmhuzhpzmym","yqzblljae","pgxnwszovqgqtcqpzmssneqejgjs","xwetnsmpotlpn","utraamepcsomyxsqbkshgyraleekxw","dvjhqppvoowntco","yohsoxdaubemaogltuk","nasrnrizinuypjdnjehqqoitmvk","xerymxgwvzcb","ouzklsdedbvwwketdhcfeuluvckf","ztindosdnqsyquuhzjzpxkbeefun","kfjirgxu","ypmskmp","wsi","pcfbmtafjvrurtrvjsumfjfttu","aqlwxsrxggtfnz","vbvbde","ceyogdjazwskvjbdwrvufpqcjrxpws","vfhpldeneeqxykmum","vuqxhsrspvqath","tloeehsq","zo","hsxjfwgbuorfznekqdvahrxgui","ctsetmijpnp","jjdizlchlorva","rvrfcepmxpeofenooth","qojwwpjt","gtdq","rbdbetwubqjppupythw","ccdllhhubyjxfmvmxdcmpzdwy","vs","ndfm","selamkurrltpjkt","whxez","woryubernrrwthyce","ozzcx","abtsca","nqyxdju","phuolroyieomapmirpvaldtksgl","yaqhaymtozosbacorzavpgdgl","dbzlkbdgrtavnorpfvuvnxwnzeoc","user","dbtfwbavxuxqzjtycorez","hhemkmkwuikfasranjgsjtug","obsskhdangnyiok","ikkzxhjapdmkyiutryhzvsijxzeo","hvbgprgostxbh","ecnzsirsqqqwldmzsat","pewwoxivlouurvfsadrc","lbujpsqpfk","eqjukrlgnbpuesgea","sgsnxtsznntdptmxjg","bpkwyfwccmnjqwdyhxrjaaxjcw","omvzwyrzlwstnwhwhssajzhbsd","ux","exlyaiolmjrca","zpdbagmcdfltcoiobkdrticgzeyn","bqbebomqulgwltbortyu","ihgevtuipgkvqgpkhlui","tvrippfy","pdbmjihtodwwa","siucrhynh","izvwi","bxhsxqhtbdsgpfeiqpdjumcjm","zrnnxdcd","mfpobuitnnxmkddwwzlfauosuzd","utolwmietafptpdnb","mkointotmaled","likkuxoyubyandcnm","mszirwc","qp","dhvshmxnljtsozhsjugbokxjiiapmb","jxibbfteyfqh","strbmsndazagstxvojxc","tpyrljqdhatboqrnnnq","whjktettjhafcviiivw","pqcetglnhibyhmveyblnlrymw","fdrcqutgrpfdaec","cyfypt","iezxlfmnhwlvpgzensnq","iznzwltutyxd","dlwbfch","qyxaibavemizoahxwhtjexaujzbm","nrqifrrhcxkuny","yymgcbawh","wd","ztuolqf","slrdlcqyevsjvobfd","glotjh","dsbds","tpetl","fryosmcawjsvbutg","hudmoskbkakhsjqyuhrrt","aww","xjluxthorodhosxkrn","fkyhahxbisvfjxj","vkslygnbphhvdpauxjnfn","vvxoqmsatgqanusjbyrxwdshvven","hyb","qxxowalutfwwpv","sntazpdaodhdaid","ws","tsg","crpwxtfukvethkwhtisxqmvohsx","qfcpjzokpxxhgqajgq","svzaumwyydtuveq","inmwdmzejyl","aexhlovhykxeoyxfi","zswuf","hiuxr","fcxnirvfxzevmveemo","cffdctpjzpgvuinotvnywxqph","yzjbscqhtfyuubljpkjmxt"};
    vector<string> str2 = {"yzjbscqhtfyuubljpkjmxt","cffdctpjzpgvuinotvnywxqph","fcxnirvfxzevmveemo","hiuxr","zswuf","aexhlovhykxeoyxfi","inmwdmzejyl","svzaumwyydtuveq","qfcpjzokpxxhgqajgq","crpwxtfukvethkwhtisxqmvohsx","tsg","ws","sntazpdaodhdaid","qxxowalutfwwpv","hyb","vvxoqmsatgqanusjbyrxwdshvven","vkslygnbphhvdpauxjnfn","fkyhahxbisvfjxj","xjluxthorodhosxkrn","aww","hudmoskbkakhsjqyuhrrt","fryosmcawjsvbutg","tpetl","dsbds","glotjh","slrdlcqyevsjvobfd","ztuolqf","wd","yymgcbawh","nrqifrrhcxkuny","qyxaibavemizoahxwhtjexaujzbm","dlwbfch","iznzwltutyxd","iezxlfmnhwlvpgzensnq","cyfypt","fdrcqutgrpfdaec","pqcetglnhibyhmveyblnlrymw","whjktettjhafcviiivw","tpyrljqdhatboqrnnnq","strbmsndazagstxvojxc","jxibbfteyfqh","dhvshmxnljtsozhsjugbokxjiiapmb","qp","mszirwc","likkuxoyubyandcnm","mkointotmaled","utolwmietafptpdnb","mfpobuitnnxmkddwwzlfauosuzd","zrnnxdcd","bxhsxqhtbdsgpfeiqpdjumcjm","izvwi","siucrhynh","pdbmjihtodwwa","tvrippfy","ihgevtuipgkvqgpkhlui","bqbebomqulgwltbortyu","zpdbagmcdfltcoiobkdrticgzeyn","exlyaiolmjrca","ux","omvzwyrzlwstnwhwhssajzhbsd","bpkwyfwccmnjqwdyhxrjaaxjcw","sgsnxtsznntdptmxjg","eqjukrlgnbpuesgea","lbujpsqpfk","pewwoxivlouurvfsadrc","ecnzsirsqqqwldmzsat","hvbgprgostxbh","ikkzxhjapdmkyiutryhzvsijxzeo","obsskhdangnyiok","hhemkmkwuikfasranjgsjtug","dbtfwbavxuxqzjtycorez","user","dbzlkbdgrtavnorpfvuvnxwnzeoc","yaqhaymtozosbacorzavpgdgl","phuolroyieomapmirpvaldtksgl","nqyxdju","abtsca","ozzcx","woryubernrrwthyce","whxez","selamkurrltpjkt","ndfm","vs","ccdllhhubyjxfmvmxdcmpzdwy","rbdbetwubqjppupythw","gtdq","qojwwpjt","rvrfcepmxpeofenooth","jjdizlchlorva","ctsetmijpnp","hsxjfwgbuorfznekqdvahrxgui","zo","tloeehsq","vuqxhsrspvqath","vfhpldeneeqxykmum","ceyogdjazwskvjbdwrvufpqcjrxpws","vbvbde","aqlwxsrxggtfnz","pcfbmtafjvrurtrvjsumfjfttu","wsi","ypmskmp","kfjirgxu","ztindosdnqsyquuhzjzpxkbeefun","ouzklsdedbvwwketdhcfeuluvckf","xerymxgwvzcb","nasrnrizinuypjdnjehqqoitmvk","yohsoxdaubemaogltuk","dvjhqppvoowntco","utraamepcsomyxsqbkshgyraleekxw","xwetnsmpotlpn","pgxnwszovqgqtcqpzmssneqejgjs","yqzblljae","lmhuzhpzmym","tewapttno","gcydrneexbcuqopkpcmd","kgsptbnifrvczouohrrprli","jmbefcplwqosvfx","framwuszazkwdilvtylmkru","qyn","sdvhj","izdo","smbvogzsmbaxktmqwleprmbdxqf","xgvvsydndmgs","ybvtkizlmyfngyjwwowgsm","lztmnoajehsvz","udqooeglslqpajnip","d","hjiq","huuftubpzskytmniladxkkgczftxp","ktbjtqyvuuxqajcesnaw","yxsybpiprmuhzplfphfeqazzyndtv","faegljhiknwlygwhlu","jiuiut","gjcgpxz","takqafyujrchibalhi","uoejbnenp","syc","kiul","gscljupcrmbbeobwvdht","occgkf","leyshdfdlagoalvfbegapxregtuh","lwdhpatigvhypgzrertalatqspohi","lhaijmcqlnrgimhbptwmkwt","oglbicrgqvradxwtghghppnzznq","rrwyr","sykhquipjd","frtrodsnrmsmaaws","rvscpckcpjwgulnfnelspis","czoepwnymcz","stpuhrfbhoxf","xflneeeaomxjphvgyohoakxhj","chnbkhdgyjoxeglvfc","fuosbwciqqzosy","fyfiwcckdrjjpqfyrldhdyvu","mofdl","favfgqwpedkohfkoakisbmbxbxf","ztanalcvncvm","rhehzhnlk","qggmtusbpnypjbxcisnoy","xengrpxq","knwvl","vdvhdvfztaxcyhjdugctrvkgulmbj","jsmzeshdnugttvppha","sfxkoexlvpihhfhfq","gfubyw","bl","uvpjsrqhwxdoeuc","ymyzwmsxcirfwhsafs","azusu","isl","ljdkfxvylzmspudjqqugddxrnhn","pjgfwoikxbybblja","zhjn","htjlnvbdfuzsjypkanhzg","oblhinaeguymmkleqeogwrzmbltl","mtndwtean","njnpajotnwihwedlefrukx","zhcnue","klgybdvijbdraoveascq","stbyc","upmawfjrcvyqphcgznqvlunehgm","xxfrzciifwxwzkqlhzi","bv","fhukhpkax","hpzca","uilnponlhvulz","krtfunvglmtcwasqlvhq","xfhfqdqnklxq","qaaoyjczafkqyncmmuqfj","ucxqf","idrkmks","esvmtdtyojpoccpnhmweleclk","eikqjjhbfnabekalchmoigbsvj","fndfnvpnmgcxjbfydgwiwpvst","jovaimqzyyputxnatlgvtflxmjwrgy","ys","fnxfo","pgsbqvig","jzfkmowocsuhipwvyavcimgslsa","jxejmmiwfrrknjyek","jbtpcxbxdbdpjztbvp","tphnrrekc","bdjntlktemditgnn","iwmovzzkfpvixarqckonwqhb","shufzxmpntnwkljqlayypynmnsvjnq","xtzyn","npjohbkidogcjbkpairnmmgslk","utwqphdxvmtvtjw","tvhkudu","ltvkvjigjqdjmfqihssvnnmxke","tvwhfeoxshl","gwmoxooqbgkuqhitqndhjknpoi","cugcsdfdgggnxbsrloqynmjisfxqcf","fqoxrbegbqfseoiqvevfjua","mducxmhhvuuoaxazhwpsuisush","kbsglfxut","hytiwcsrbwyj","n","xo","vlhyfvzcuuqrqymnzlbqwlwyk","hlcyxndydrxgebcjtgrjlfhhiqeh","coxufsaunxexcshrcqyjz","etwelbjtxilczjudlyziyosp","eblxqnyke","kexssggfp","hyxexwoosybkpifyohasxtk","wbtrhqdbwqyrvjizkgj","zuzgiuonhoaaqmafflrnsamdkefoki","l","axdaqveyksrmpc","hydpvnbhqpkvrcc","rezogqmazduvkcypiupyitmhrfmzki","cywlrzkl","ucnfeysd","vdztloyrjpzzylesddiewfemmbgfwe","ugjnsgqlp","xinbdvhzfykpmzpecgngelczoukzd","acqnnodwqzwlqnynvb","aooilovrtwqoaremskb","zkrcckbowwjxmfmdikfsbpyxrmgg","tmsfjgfjdjdbczcseznowpptr","wwqbevusanvcdzeshcglrzlarer","qyfopqgmglfiofw","ymlznwinj","dxeyeyejkosdpnub","fmgqdzvdtyethyynjjpbl","ykoyilcm","qlewoezxzmlhgypikhdl","ptopwfkziuttfeazrrglqdbszvr","zosncavdfjcsdnrxdp","eypstxtyxnnqnkmqptekdgpdqcdqn","wnnhai","ufolcgdeo","zcxbycuiqlvfpuslvv","alzzxhra","ykiatwmdigjxmxevdbd","xhc","cblx","nkmofftbapqitraxtfnilsfvwvpas","geg","ashrazctgqgwrm","lha","huhwnjqriyiweilhjzijuftlzp","rooillldcagevixecdxffz","zegpdvbmdgslagpvsjnmchspix","ywqhjouxx","lfgztikdpethoionvs","gwurhajbnavidhipzhxvlf","eelflqtsplanaahmxssqe","vbqhjdqajtvy","bsmqkkfmzszgtffpkpjouoxdmofivm","fhjbrzhroorglgbltarrvtjnkz","ckhb","ijrbjrqopmbveayra","p","yvizbmradwgxedumcbcktxublw","fxtsgerpchszrkfjpwwigy","mjgmpewjnlwijzx","rfbmlfacpec","nqmgha","swgsvdptrtepv","fboaiwtlfccdolpqutf","gpgbqii","lfsxwnhweveaaekybglvcluyeb","vagpvsdzqhwnlogzyje","agfqdph","pkwenkodtlbbdgvopqaeygphtlrmo"};
    auto res = s.findRestaurant(str1,str2);
    cout << res.size() << endl;
    return 0;
}