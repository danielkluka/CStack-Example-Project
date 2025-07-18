\mainpage Úvod a zadání


| Projekt BPC-PPC				| 2022															| Hodnocení zadání (max 6b)	| Hodnocení CBlock, hlavička max(14b)	| Hodnocení projektu max(20b)	|
| ---							| ---															| ---						| ---									| ---							|
| Autor 1:						| `23964754`, __Petyovský__ Petr, petyovsky@vut.cz				|							|										|								|
| Autor 2:						| `12656536`, __Richter__ Miloslav, richter@vut.cz				|							|										|								|
| Autor 3:						| `ID`, __Příjmení__ Jméno, login@vut.cz						|							|										|								|
| Autor 4:						| `ID`, __Příjmení__ Jméno, login@vut.cz						|							|										|								|
| Datum zadání:					| 25.10.2022													|							|										|								|
| Datum odevzdání zadání:		| 10.11.2022 (včetně);upřesní stránky kurzu;					|							|										|								|
| Datum odevzdání hlavička:		|  1.12.2022 (včetně);upřesní stránky kurzu;					|							|										|								|
| Datum finálního odevzdání:	| 21.12.2022 (včetně);upřesní stránky kurzu;					|							|										|								|


## Úvodní poznámky


V následujícím textu je vzor zadání.
Tučně jsou označeny prvky, které se mohou lišit obsahem, ale které platí obecně pro třídu kontejner.
Tyto pasáže je nutné nahradit upraveným textem s významem pro konkrétní kontejner (tyto vámi upravené části zůstanou zvýrazněny).
V tomto okamžiku nás nezajímá implementace pomocí jazyka, ale u metod a operátorů vždy slovně popište, 
jak si představujete jejich činnost. _Činnost popište tak, aby byl popis dostatečný k realizaci_ = jak byste ji zadali externímu programátorovi, aby jasně věděl jak se má metoda/funkce chovat. 
U metod a operátorů bude tedy uvedeno: název, parametry, popis činnosti (tj. jakým způsobem se ze vstupních proměnných vytvoří proměnné výstupní), popis použití, popis smyslu a významu funkce (anotace/synopsis). 
Tento popis se později stane součástí komentáře/helpu ve zdrojovém textu (Doxygen).

U každé metody/funkce zadání uveďte monogram jednoho z autorů, který daný kód bude realizovat. __Metody označené jako autor1
jsou povinné metody (konstruktory, operátor=, streamy), použitelné ostatními metodami, a proto je vhodné je při tvorbě realizovat přednostně a kvalitně__. Každý student by měl realizovat část každého bodu zadání (pokud to zadání umožňuje).

Uvedené poznámky (Note) v odevzdávaném zadání nebudou (= __vymažte je__), slouží pouze jako doporučení a upřesnění.
U některých variant zadání kontejneru mohou nastat problémy s tím, že daná vlastnost (metoda) kontejneru nemá \em "nejlogičtější" využití – zkuste si nějaké (byť méně logické) využití vymyslet 
(z hlediska programátorské praxe je to samozřejmě špatně, protože metody by měly být logické a snadno chápatelné, ale my zde dáme prioritu procvičení, výuce a použití daného typu metod). 
Každý z autorů by měl napsat alespoň jednu metodu příp. operátor daného typu.

Vývoj projektu je možný v libovolném prostředí a kompilátoru C++ ([g++](http://gcc.gnu.org/), [clang++](http://clang.llvm.org/), [XCode](https://developer.apple.com/xcode/download/)), 
ale referenčním překladačem bude [Microsoft Visual Studio 2022](http://www.visualstudio.com/).

Preferovaným jazykem C++ _zdrojových textů_ je angličtina, případně čeština bez diakritiky. Pro dokumentaci ve zdrojových souborech tedy používejte český jazyk bez háčků a čárek (tj. pouze ASCII znaky). 
Popřípadě používejte jazyk anglický (pokud ho umíte na odpovídající úrovni).

Ve zdrojových kódech (hlavička a kód kontejneru, funkce main, soubor testů) udržujte kód v blocích podle autorů, je-li to možné. Tyto bloky pouze prostorově vymezují prostor jednotlivých autorů a
nebudou vymezovány či používány jiným způsobem (například podmíněný překlad pomocí ifdef apod.) Celý kód všech autorů bude vždy společný a přeložitelný bez errorů (a pokud možno i bez warningů - platí i pro 
hlášení z generování dokumentace Doxygen) jako jednotlivý celek.

__Pokud něčemu nerozumíte, ptejte se (především na cvičeních). Práce je snažší pokud víte co děláte.__


## Zadání

### Popis datové struktury a výběr datových typů pro realizaci projektu

V rámci projektu se bude tvořit objektová knihovna zajišťující kontejnerové funkce pro prvky nesoucí hodnotu zvoleného typu.
Vnitřní implementace kontejneru bude realizována jako tzv. [obousměrně vázaný lineární seznam (doubly linked list)](https://en.wikipedia.org/wiki/Linked_list#Doubly_linked_list) 
tj. seznam prvků s hodnotami. 
Tato datová struktura umožňuje časově efektivní přidávání, odebíraní a vyhledávání prvků. 
_Snažte se tedy realizovat paměťově i časově úspornou implementaci kontejneru!_
Prvky vkládané do datové struktury `CContainer` budou instance třídy `CBlock`.

Třída `CBlock` bude prvkem kontejneru.
Ve výsledném projektu bude vytvořený kontejner schopen pracovat minimálně se čtyřmi různými 
implementacemi třídy `CBlock`. 
První dvě třídy `CBlock` Vám již byly dodány v rámci zadání a realizují zapouzdření typu 
`bool` a výčtového typu `TWeekDay` a je v rámci řešení projektu zakázána jejich modifikace. 
Podle těchto příkladů v rámci projektu vytvoříte dvě další třídy `CBlock`.

Třída `CContainer` je dodána v minimální podobě a v rámci projektu bude nutné ji dopracovat (přejmenovat, doplnit její funkčnost). 
Třída `CBlockBase` bude sloužit jako pomocná, zajišťující tvorbu vázaného seznamu, a z ní bude dědit třída `CBlock`. 
Třída `CBlockBase` bude obsahovat proměnnou \p iExtraInt (v `CBlock` realizující např. klíč či hodnotu). Zapouzdřovaná hodnota bude
reprezentována pomocí prvku \p iValue třídy `CBlock`.
Pomocné třídy budou nedílnou součástí projektu, ale v dalším textu budeme zmiňovat již pouze třídu `CBlock` a třídu reprezentující kontejner.

\attention
Kontejner budete realizovat bez podpory kontejnerových typů knihovny STL nebo jiných knihoven třetích stran. Prvky kontejneru budou realizovány
pomocí seznamu typu lineární seznam a jeho prvky budou instance třídy `CBlock`.
Kontejner bude realizován tak, aby uvnitř umožňoval práci s lineárními seznamy obecného rozměru. 
Kontejner musí správně pracovat pro všechny čtyři vytvořené třídy `CBlock`, ale nemusí s nimi pracovat současně v rámci jednoho překladu.


_Pozor! Nedodržení těchto podmínek znamená nesplnění základních požadavků zadání a hodnocení takového projektu bude bohužel 0 bodů!!!_


-----------------------------------------------------------------------------------------------------------------



\todo V následujících třech částech ponechejte v seznamu vždy pouze ty položky, které odpovídají Vašemu zadání projektu. U položky 3 definujte 
chování kontejneru. Datové typy z bodu 1 a 2 specifikujte též v prvním bodu zadání kontejneru.

\todo Místo všech názvů `CContainer` použijte v celé dokumentaci i kódu název kontejneru zvoleného v části zadání číslo 3.

První Vámi realizovaná třída `CBlock_TYP1` bude zapouzdřovat jeden ze základních typů, který si zvolte v části 1:

_Zadání část 1: základní datové typy (mimo bool), (zvolte jednu z možností):_
- Jeden z __celočíselných typů__: např.: (`signed / unsigned) char`, `short int`, `int`, `long int`
- Jeden z __reálných typů__: např.: `float`, `double`, `long double`
- __Výčtový typ enum__ např.: (měsíce, výčet barev, znak Morseovy abecedy, znamení zvěrokruhu)



Druhá Vámi realizovaná třída `CBlock_TYP2` bude zapouzdřovat jeden ze složených datových typů, který si zvolte v části 2:

_Zadání část 2: složené datové typy (třídy, struktury, pole) - (mimo TWeekDay - Dny v týdnu), (zvolte jednu z možností):_
- __Komplexní číslo__
- __Textový řetězec__ (dynamický)
- __Bod v prostoru__ (x,y,z)
- __Číselný interval__ <min,max>
- __Barevná informace__ (RGB složky)
- __Pole číselných hodnot__ typu `double`
- __Libovolný další__ např.: tón, krevní skupina, jméno a příjmení (dva členy), 


Třetí Vámi realizovaná třída bude samotný kontejner pracující s prvky třídy `CBlock`. Charakter a funkci kontejneru si zvolte v části 3:

_Zadání část 3: typ kontejneru implementován pomocí lineárního seznamu (zvolte jednu z možností):_
- __Fronta__ – jeden vstup, jeden výstup, architektura FIFO. Prvky jsou ve frontě v pořadí určeném dobou vstupu. Pořadí prvků na výstupu je shodné s pořadím prvků na vstupu.
- __Zásobník__ – jeden vstup, jeden výstup, architektura LIFO. Prvky jsou ve frontě v pořadí vstupu a při výskytu prvku je pořadí prvků na výstupu opačné oproti pořadí prvků na vstupu.
- __Prioritní fronta__ – jeden vstup, jeden výstup, architektura FIFO. Prvky vstupují do fronty vždy dodatečnou s informací o své prioritě, prvky vystupují z fronty v pořadí určeném prioritou a při stejné prioritě je pořadí prvků na výstupu shodné s pořadím prvků na vstupu.
- __Prioritní zásobník__ – jeden vstup, jeden výstup, architektura LIFO. Prvky vstupují do fronty vždy dodatečnou s informací o své prioritě, prvky vystupují z fronty na základě své priority a při výskytu prvku se stejnou prioritou je pořadí prvků na výstupu opačné oproti pořadí prvků na vstupu.
- __Množina__ – souhrn (kolekce) prvků, neumožňuje indexaci jednotlivých prvků, prvky stejné hodnoty se nemohou v množině opakovat. Mezi definované operace patří tzv. řezy. (tj. vznik nové množiny obsahující všechny prvky původní množiny, které jsou menší (resp. větší) než zadaná hodnota).
- __Multimnožina__ - (totéž co množina, navíc může obsahovat více prvků stejné hodnoty) – tj. hodnoty prvků se mohou opakovat, zajistěte efektivní využití paměti (neduplikujte fyzicky v seznamu prvky stejné hodnoty).
- __Asociativní pole__ – pole prvků typu `CBlock` umožňující indexaci hodnotou typu `int`. Asociativní pole předpokládá, že indexy jednotlivých vložených prvků nemusí tvořit spojitou řadu (tj. asociativní pole je pole prvků, který nemusí obsahovat všechny indexy v daném rozsahu posloupnosti).
- __Mapa__ - představuje seznam hodnot typu `int` a umožňuje indexaci těchto prvků pomocí hodnoty typu `CBlock`. Bude obsahovat metody pro vložení a odebrání prvku. Pro jednu konkrétní hodnotu indexu existuje vždy pouze jedna hodnota typu `int`.
- __Multimapa__ - (totéž co mapa, navíc může obsahovat pro jeden index typu `CBlock` obecně více prvků s různou hodnotou) – tj. pro jednu konkrétní hodnotu indexu může existovat několik hodnot typu `int`.


-----------------------------------------------------------------------------------------------------------------


### Vzorový text zadání:

\todo Od tohoto místa dále nahraďte tučně zapsané texty vhodnou modifikací pro Vaše zadání (značky pro tučné (tzv. Bold) zvýraznění neodstraňujte). Nezvýrazněný text nemažte - jedná se o povinné body zadání!!! 
U jednotlivých metod popište činnost tak, aby podle ní bylo jasné, _co bude metoda dělat_ (tj. jak na základě vstupů vznikne výsledek).
Dále viz úvodní poznámky.

Navrhněte třídu __CContainer__, která bude obsahovat prvky třídy `CBlock` a realizovat knihovnu pro práci s vybraným jednoduchým typem (__TYP1__) a složeným datovým typem (__TYP2__), 
který bude zapouzdřen ve třídě `CBlock`. 
Třída `CBlock` (společně s dalšími pomocnými datovými typy) je připravena pro práci s lineárním seznamem a její využití při tvorbě kontejneru je povinnou součástí projektu. Celá knihovna bude realizovat činnost __kontejneru__ podle následujících bodů. 
Pokud je to možné, bude splňovat očekávané chování (podobné jako u jednoduchých typů: `int`, `float`, atd.).
Navržená třída __CContainer__ splní následující:

1. Třída `CBlock` zapouzdřuje dva dodané (`bool`, `TWeekDay`) a dva zvolené datové typy: jeden základní: __TYP1 (např. int, float)__ a druhý složený: __TYP2, (realizující ... s vlastnostmi...)__. 
Tyto definované třídy budou vytvořeny ve svých jmenných prostorech: __CBlock_TYP1, CBlock_TYP2__.
\note Zde uveďte za NAZEV_TYPU typy zvolené pro třídy z části zadání č.1 a č.2.
\note Pro oba nové datové typy (z části zadání č.1 a č.2) uveďte, jaký typ budou zapouzdřovat (u výčtového typu definujte i jednotlivé názvy hodnot). Pro datový typ č.2 uveďte název nově definovaného složeného typu s informaci, zda půjde o definici: `typedef`, `struct`, `union`, `class`.

2. Vznik objektu třídy __CContainer__:
 - implicitní (tzv. default) konstruktor __který vynuluje/naplní prvky na hodnoty ...__ , ( __autor1__ )
 - kopykonstruktor - vytvoří vlastní kopii všech dat, ale bude mít unikátní `iID`. ( __autor1__ )
 - konverzní konstruktor z `CBlock`, __který ...__ ( __autor2__ )
 - konverzní konstruktor z typu __size_t (vytvářející seznam o daném počtu prvků CBlock, tak, že ...), ... ,__ ( __autor3__ )
 - konstruktor z dvojice hodnot reprezentujících: __počet prvků pole a samotné pole prvků CBlock - výsledný objekt se vytvoří způsobem ... , ...__ , ( __autor4__ )
 - konstruktor na základě C řetězce (_const char *_), jehož formát bude __hodnoty jednotlivých__ `CBlock` __oddělené čárkami. Řetězec bude mít tvar:...__. ( __autor2__ )
\note Celkem tedy – implicitní, kopykonstruktor, konverzní, konverzní z řetězce, s více parametry, ... – (minimální počet konstruktorů: 6ks)\n
\note Autora v dalších bodech zadání doplňte stejně jako je to u metod v tomto bodu zadání.
3. Počet vzniklých a aktuálních instancí třídy  __CContainer__ bude možné sledovat pomocí členské proměnné třídy `ClassInfo`, a bude možné je získat 
voláním metod této třídy `Total` a `Living`. Každá instance třídy __CContainer__ bude v této proměnné třídy `ClassInfo` obsahovat proměnnou `iID` sloužící k identifikaci instance 
 __CContainer__ (odpovídající pořadí vzniku). Identifikační hodnota instance musí být přístupná mimo třídu pomocí vhodné metody - `ID()`. ( __autor1__ )
4. Zánik objektu - destruktor __kontejneru__ bude implementován s mechanizmem odpočtu aktivních prvků pomocí proměnné třídy `ClassInfo`. 
   Dynamické členské prvky __ne/odalokuje a dále ...__. ( __autor1__ )
5. Budou implementovány operátory __kontejneru__ s příslušnými činnostmi:
 - operátor = pro přiřazení, vytvářející kopii hodnot (mimo `iID`, které si ponechá původní). Původní hodnoty ve výsledné proměnné přepíše, dynamické odalokuje. ( __autor1__ )
 - operátor __– jako__ unární operátor __minus pro inverzi kontejneru například jako: reverzace (otočení pořadí prvků), doplněk do plného kontejneru, nebo inverze jednotlivých hodnot CBlock.__ ( __autor2__ )
 - operátor __– jako__ binární operátor __minus pro rozdíl kontejnerů, který bude fungovat tak, že ...__ ( __autor3__ )
 - operátor + __pro … ,__ ( __autor4__ )
 - operátor += realizující a = a+b; __způsobem ... s činností ...__ ( __autor4__ )
 - relační operátory ==, !=, <=, > ,... __pro porovnání dvou kontejnerů (na základě obsahujících hodnot a jejich počtu).__ Výsledek bude získán zpracováním návratové hodnoty funkce `CompareDeep`. (__každý autor jeden__)
 - __libovolné další přetížitelné operátory__ 
 - Operátor (`operator size_t()`) pro konverzi kontejneru __na `size_t`, který bude reprezentovat počet prvků kontejneru__. ( __autor3__ ) 
 - Nečlenský operátor, využívající \c friend vlastností realizující __součet CBlock, float, int hodnoty__ a kontejneru. ( __autor4__ )
\note Celkem tedy – unárních (nejméně 3ks), binárních (nejméně 3ks), konverzní, nečlenský, relační (nejméně 3ks) – (celkem minimálně 12ks). U operátorů i metod z následujících bodů uveďte požadované informace (viz úvodní poznámky).
_Zadání bude obsahovat definici zvolené operace (tedy například co se myslí pod termínem odečtení kontejnerů, jak se bude chovat k prvkům kontejneru, popřípadě ke kontejnerům prázdným)_
6. Standardní vstup a výstup z instance třídy  __CContainer__ bude realizován pomocí streamů (realizovaný "friend" funkcí s využitím jejích vlastností) – přetížením operátorů << a >> ve stejném formátu navrženém pro konstruktor z `char *` (tj. __čárkami oddělený seznam hodnot ... ve tvaru ...__). ( __autor1__ )
7. Budou realizovány privátní a veřejné metody: 
 - veřejná metoda `PocetPrvku` pro zjištění počtu prvků v __kontejneru__, která nebude mít parametry... ( __autor2__ )
 - Charakteristické metody pro daný __kontejner__ (např. pro vložení a vyzvednutí prvku) s názvy __empty, ... , ... a ... , které vloží/vyberou prvek kam, proč, jak ...__ ( __autor3 a 4__ )
 - Metoda `Usage()`, která vrátí `double` hodnotu [v procentech] reprezentující efektivnost využití paměti při použití lineárního seznamu 
   prvků `CBlock` v poměru k reprezentaci kontejneru pomocí standardního C pole stejného počtu prvků jako je typ zapouzdřený ve třídě `CBlock`. ( __autor3__ )
 - Metoda __s názvem… (doplňte)__, která bude realizovat __funkcionalitu… (doplňte)__.
 - Privátní metoda `Compare`, která porovná "velikost" dvou kontejnerů, kde velikost je dána počtem prvků, a vrátí hodnotu -1,0 nebo 1 (první je kratší, stejné, první je delší). ( __autor4__ )
 - Privátní metoda `CompareDeep`, která porovná kontejnery i podle hodnot `CBlock` (návratové hodnoty jako u Compare). Výsledky získané voláním metod `Compare` a/nebo `CompareDeep` budou ke své činnosti používat relační operátory kontejneru. ( __autor1__ )
\note Pro privátní metody jsou nejvýhodnější funkce typu „uprav“, „přepočítej“, „zkontroluj“. Celkem tedy – minimálně 2ks privátní a 6ks veřejné.
\note U každé z metod definujte nejen její název, ale uveďte i informaci, co bude jejím úkolem z hlediska funkce __kontejneru__ (tj. textově popište její funkci, popř. smysl).
8. Budou realizovány metody, pro reverzaci (reverzace je __např. otočení pořadí prvků kontejneru__):
 - umožňující volání `bbb=aaa.Reverzuj()`, která mění __kontejner__ `aaa` na __reverzovaný kontejner (který se získá ...)__ `bbb`, 
 - umožňující volání `bbb=Reverzuj(aaa)`, která nechává __kontejner__ `aaa` nezměněn a vrací (temp objekt) __reverzovaný kontejner__ `bbb`. 
9. Použití dynamických dat ve třídě – __ne/předpokládám__.
10. Dědění __ne/předpokládám__ ve třídě __uveďte které, nebo žádné__.
11. Použití výjimek - __ne/předpokládám__.
12. Ve vlastním projektu se předpokládá i implementace metod vytvářených překladačem implicitně.
13. Ve třídě bude pro kontrolu korektní práce s pamětí implementována knihovna [Checker](http://www.uamt.fekt.vut.cz/~petyovsky/projects/checker/checker.zip).
14. Každý z autorů napíše pro tři vybrané metody (nepatřící do stejného bodu zadání) unit testovou metodu (jednu pro každou vybranou metodu). 
    Každá unit testová metoda bude obsahovat alespoň tři testy (assert...) pro vybranou metodu, z nichž alespoň dva nebudou pracovat s implicitně vytvořeným kontejnerem (tj. proměnná typu kontejner bude obsahovat prvky - alespoň čtyři). 
    Jeden z testů od každého autora bude obsahovat i testy alokované paměti (vyberte metodu pracující s pamětí).



### Poznámky k řešení (jsou součástí zadání):

Odvozené třídy `CBLOCK_NAZEV_TYPU` vypracujte v projektu CBlock, kde je ve funkci `main` 
demonstrována činnost `CBlock_bool`. 
Po odladění je použijte ve vlastním projektu při tvorbě __kontejneru__, 
kde vytvořte v `main` podobný testovací kód (pro třídu kontejneru) jako je ukázáno v projektu s CBlock.
Projekt CBlock chápejte jako ukázkový projekt, který demonstruje principy práce s CBlock, a lineárními seznamy a všemi dodanými třídami. Věřím, že pro Vás bude cennou studnicí vědomostí a zároveň vhodným testovacím _pískovištěm_
k pokusům a experimentům. Proto si jeho činnost prostudujte a snažte se ho pochopit do co nejmenších detailů. Pokud Vám tento testovací projekt přestane fungovat, obnovte poslední fungující verzi z repozitáře a zkuste to znovu. ;-)
_Aneb kdo nic nerozbije, ten se nic nenaučí._

Vytvořená implementace __kontejneru__ bude využívat vlastnosti třídy `CBlock` a musí 
umožňovat bezchybný překlad s libovolnou třídou `CBlock` (zapouzdřující některý z 
jednoduchých datových typů) bez nutnosti zásahu do zdrojových textů __kontejneru__!!!!
Implementace kontejneru tedy nebude závislá na typu ukládaných hodnot, protože bude 
využívat pouze definované rozhraní třídy `CBlock` (společné pro všechny typy), tak jak 
je uvedeno v testovacím příkladu. 
__CContainer__ proto implementujte tak, aby přímo nevyužíval (nevolal) Setter ani Getter 
metody třídy `CBlock`, jejichž hlavička je na zapouzdřujícím typu závislá!!! 

Celá hierarchie souboru projektu je patrná na následujícím obrázku.
\note _Nezapomeňte v obrázku upravit názvy tučně označených souborů._

\dotfile project_hierarchy.gv "Obr.1 - Nákres hierarchie souborů v projektu"



Vlastní realizace třídy pro __kontejner__ bude rozdělena na hlavičkový a zdrojový soubor (__CContainer.h__, __CContainer.cpp__). Další zdrojový soubor (main.cpp) bude reprezentovat program demonstrující vlastnosti a použití 
definované třídy __CContainer__. Všechny zdrojové a hlavičkové soubory budou obsahovat úvodní poznámku o svém názvu, stručném obsahu a řešitelích ve formátu pro systém Doxygen).

Demonstrační program bude realizován jako konzolová aplikace přeložitelná ve Visual C++ (prázdný projekt, přísnost (stupeň) překladu 3 na detekci chybových a varovných hlášení). 
Snažte se, aby demonstrační program byl napsán tak, aby při činnosti nevyžadoval zásahy obsluhy ani vstupní data z jiných speciálních souborů (s výjimkou operátoru pro standardní vstup). 
Demonstrační/testovací program bude inicializovat proměnné (v něm definovanými daty nezadávanými uživatelem) a na jejich základě bude demonstrovat činnost třídy a dále zobrazovat data na konzolu, 
nebo ukládat výsledky do souboru.
\ref doc "Dokumentaci" výsledného projektu realizujte pomocí nástroje [Doxygen](http://www.doxygen.org).

K tomuto odevzdávanému zadání nezapomeňte připsat do úvodu: (jména řešitelů, název projektu, datum zadání).

Pro lepší orientaci uvádíme krátkou motivaci k pojmu třída na odkazu:
[Motivace třída](http://www.uamt.fekt.vut.cz/~richter/vyuka/1920_XPPC/cviceni/motivace_trida.html).


Pokud Vás trápí nastavení [Unit testů](https://en.wikipedia.org/wiki/Test-driven_development) ve VS2022 zkuste si projít [tento postup pro VS2019](http://www.evernote.com/l/AElAKsn_ps1ONbQRPVcvgmGPXcK76B0P0qs/).

---
$Id: Introduction.md 3 2022-10-26 17:03:14Z petyovsky $

Poslední změna: $Date: 2022-10-05$
