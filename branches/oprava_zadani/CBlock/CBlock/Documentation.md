\page doc Dokumentace projektu CBlock

## Teoretický popis: Termín datový kontejner
Termín kontejner představuje v oblasti návrhu datových struktur a algoritmů takový datový typ, který umožňuje za běhu programu sdružovat více prvků (stejného nebo i různého typu) 
do jedné společné složené datové struktury. Výhody spojené s používáním kontejneru lze najít například v jednoduchém předání všech prvků takového kontejneru do funkce pomocí 
jediného argumentu (typu kontejner), nebo pro předání více hodnot z funkce, kde návratovou hodnotou je opět jediná hodnota (typu kontejner). Hlavní výhodou je ovšem možnost 
provedení operace nad všemi prvky kontejneru pomocí zápisu jediného volání služby, kterou zajistí přímo daný kontejner v rámci svého API. Mezi takové služby může patřit 
dealokace paměti všech prvků v kontejneru, vytisknutí všech prvků v kontejneru a další operace spojené se správou prvků v kontejneru. 
Prvky vkládané do Vašeho budoucího datového kontejneru budou právě instance třídy `CBlock`. Ale i na samotnou třídu `CBlock` lze pohlížet jako na primitivní kontejner mající
jedinou hodnotu.

### Třída CBlockBase
Třída `CBlockBase` implementuje všechny vlastnosti, které jsou společné pro jakékoliv prvky lineárního obousměrně
vázaného seznamu, tj. obsahuje ukazatel \p iNext, ze kterého je možné určit odkaz na další prvek, a ukazatel \p iPrev, ze kterého je možné určit odkaz na předchozí prvek.
Dále implementuje mechanismy konstrukce, modifikace hodnot ukazatele a základní kontrolní mechanismy. Tato třída neobsahuje v definici žádná užitečná data, 
které by měl každý prvek seznamu obsahovat. Definuje tak pouze základní rozhraní, které bude společné všem prvkům bez ohledu na typ a množství užitečných dat.

Prvek třídy `CBlockBase` je možné zrušit (destruktorem) pouze pokud jeho ukazatele \p iNext a \p iPrev ukazují na \c nullptr - a není tedy součástí většího seznamu.

Třída dále obsahuje složku [iExtraInt](\ref CBlockBase::iExtraInt), která je potřebná pro realizaci některých projektů. Lze ji například použít jako: __multimnožina__ 
(_kde obsahuje počet opakujících se prvků_ `CBlock` _stejné hodnoty_), __mapa__ (_kde obsahuje hodnotu klíče pro daný prvek_ `CBlock`), __asociativní pole__ 
(_kde obsahuje výslednou_ `int` _hodnotu, pro kterou je daný_ `CBlock` _klíčem_), __prioritní fronta__ (_kde obsahuje hodnotu priority daného prvku_ `CBlock`).


### Třída CBlock
Třída `CBlock` obsahuje prvek (nebo prvky) mající hodnotu, kterou jako třída zapouzdřuje (`bool`, `TWeekDay`, __long__, __TInterval__).
\note _V předchozím řádku nahraďte tučně označenou část textu názvy typů, které Vám byly zadány na cvičeních!_

Úlohou třídy `CBlock` je v definici mít složku \p iValue, jenž představuje užitečná data, která bude každý prvek seznamu obsahovat. 
Dále je třeba vhodně upravit (případně doplnit, ne však vytvořit nové) metody určené pro konstrukci a likvidaci prvku tak, aby bylo možné nový prvek efektivně konstruovat a využívat.
Třída `CBlock` je navíc správcem své vlastní hodnoty \p iValue a proto definuje základní metody pro zjištění, nastavení této hodnoty a zároveň zajišťuje pro nadřazené 
vyšší části programu metody pro porovnání dvou prvků `CBlock` dle této hodnoty,
čímž izoluje nadřazené části od nutnosti znát konkrétní datový typ složky \p iValue.
Třída `CBlock` má předka `CBlockBase`, který zajišťuje funkce spojené s lineárním seznamem a obsahuje pomocný prvek (potřebný v některých projektech) \p iExtraInt.

Vzorové dodané třídy `CBlock` (`bool`, `TWeekDay`) v projektu nesmíte měnit. Zároveň ovšem program musí pracovat
se všemi (čtyřmi) implementacemi třídy `CBlock` (ale ne současně). Z toho plyne, že vámi tvořené třídy musí mít stejné
vlastnosti rozhraní jako vzorově dodané třídy, a že metody, které bude mít vaše třída navíc, není možné ve tvořeném
kontejneru používat (protože by kontejner nešel pro vzorové třídy přeložit).

### Jmenné prostory CBlock_xxxx (`CBlock_bool`, `CBlock_TWeekDay`)
Návrh programu i Vaše zadání požaduje nezávislost na vnitřní implementaci třídy `CBlock` (konkrétním datovém typu složky \p iValue). To znamená, že všechny implementace musí obsahovat
stejné/společné metody, ale mohou se lišit v implementaci (datové členy a činnost metod). Nutné metody jsou dány požadavkem na funkčnost vzorové a neměnné funkce main(). Její kód tedy definuje požadované vlastnosti/rozhraní třídy. Návrh navíc umožňuje, 
aby uživatel mohl 
odkomentováním řádku přepínat mezi vnitřními implementacemi `CBlock`. Tento mechanismus je zajištěn pomocí definice každé z variant `CBlock` ve vlastním jmenném prostoru
`CBlock_NAZEV_TYPU`. Díky této skutečnosti může existovat v programu několik stejně pojmenovaných tříd `CBlock`, neboť názvy existují ve svém vlastním oboru 
viditelnosti (jmenném prostoru).

Volba dané varianty `CBlock` je potom prováděna v souboru CBlock.h, odkomentovaním toho řádku, který exportuje daný jmenný prostor do globálního prostoru jmen.
\code{.cpp}
using CBlock = 
		CBlock_bool::CBlock;
//		CBlock_char::CBlock;
//		CBlock_int::CBlock;
//		CBlock_float::CBlock;
//		CBlock_TWeekDay::CBlock;
\endcode


## Realizace dalších variant tříd CBlock
V současnosti projekt obsahuje tyto varianty tříd `CBlock`, z nichž je každá definována ve svém jmenném prostoru:
- `CBlock_bool::CBlock`
- `CBlock_TWeekDay::CBlock`

__Tyto dvě třídy jsou pevně zadány a je zakázáno modifikovat jejich zdrojové texty!__ Pro každou další variantu `CBlock` nadefinujte nový jmenný prostor `CBlock_NAZEV_TYPU` 
a v něm implementujte novou variantu třídy `CBlock`.
\note Mechanismus by samozřejmě bylo možné realizovat i zcela automaticky (překladač sám dle potřeby programátora vygeneruje novou variantu třídy `CBlock` pomocí 
definované šablony, případně bude umožnovat dynamickou identifikaci typu a tím umožní mít při běhu programu v jednom seznamu různé varianty prvků `CBlock`.
Protože tyto techniky patří svým rozsahem k pokročilejším, rozhodli jsme se jim v tomto projektu vyhnout.



## Testovací hlavní program
Hlavní program v souboru main.cpp představuje základní sadu testů, které ověřují správnou funkci libovolné varianty třídy `CBlock`. Seznamte se s obsahem hlavního 
programu a trasujte si jednotlivá volání.

### Testovací hodnoty
Aby bylo možné provádět testování spojené s parametry datového typu daného `CBlock`, je nutné, aby vstupní parametry nabývaly různých hodnot, podle aktuálního datového typu (zvoleného v `CBlock.h`). 
Proto je nutné generovat pro různé implementace `CBlock` hodnoty vstupních parametrů správného datového typu.
Každá z implementací třídy `CBlock` proto obsahuje šest základních metod vracejících hodnotu datového typu, který je vhodný pro vložení do složky \p iValue. Projděte si 
uvedené mechanismy a snažte se pochopit jejich vliv na nezávislost kódu hlavního programu. Jelikož tyto funkce jsou umístěny ve stejném jmenném prostoru jako překládaná varianta 
`CBlock`, jsou při generování hodnot vždy správné datové typy, odpovídají typům parametrů. Každá varianta `CBlock` bude tedy mít ve svém jmenném prostoru své vlastní funkce 
pro generování hodnot.

Jedná se o tyto metody:
- `TestValue0()` (např. `CBlock_bool::CBlock::TestValue0()`)
- `TestStringValue0()` (např. `CBlock_bool::CBlock::TestStringValue0`)
- `TestValue1()` (např. `CBlock_bool::CBlock::TestValue1`)
- `TestStringValue1()` (např. `CBlock_bool::CBlock::TestStringValue1`)
- `TestValueRandom()` (např. `CBlock_bool::CBlock::TestValueRandom`)
- `TestStringRandom()` (např. `CBlock_bool::CBlock::TestStringValueRandom`)

### Další kontrolní vlastnosti prvku
Třída `CBlock` obsahuje několik kontrolních a ladicích mechanismů, které budete jistě chtít využívat.

- Členskou proměnnou \p iInstanceInfo typu `ClassInfo` obsahující počítadlo vzniklých instancí (viz dále).
- Pokud budete v metodách třídy `CBlock` dynamicky alokovat paměť nezapomeňte na kontroly dealokace paměti pomocí knihovny check.
- Pokud je prováděn překlad v _Debug režimu_ je při každém spuštění zajištěna identická inicializace generátoru náhodných čísel. Tím při každém krokování programu bude 
generován pro stejná vstupní data identický seznam (výsledný kontejner bude obsahovat prvky se stejnými hodnotami pro každé spuštění). Až si budete jisti, že program je 
funkční, zkuste přepnout překlad do _Release režimu_ a ověřit správnou funkci celého 
kontejneru při různých počátečních podmínkách generátoru náhodných čísel.

- Již základní společná třída `CBlockBase` (a tedy i každý její potomek `CBlock`) obsahuje kontrolní mechanismus.
Prvek při své destrukci kontroluje, zda není součástí seznamu dalších prvků a pokud ano, generuje chybové hlášení případně i výjimku `std::runtime_error`.
Možno navolit volbou \ref KCBlockDtorNoException v CBlockBase.h.


### Třída ClassInfo
Třída `ClassInfo` implementuje mechanismus automatického počítání vzniklých objektů a mechanismus 
jednoznačné identifikace \c ClassInfo<>::ID "ID" instancí za běhu programu. Tento mechanismus 
se Vám bude hodit při ladění programu pro rozlišení jednotlivých objektů 
(každý objekt má po celou dobu svého života stejné "ID" přidělené při vzniku). 

Všechny Vaše třídy by měly obsahovat datovou složku [iInstanceInfo](\ref CBlock_bool::CBlock::iInstanceInfo) 
třídy `ClassInfo`, čímž 
zajistíte Vašim třídám tyto ladicí vlastnosti. Samotná třída `ClassInfo` je definována jako šablona umožňující, vznik různých variant této třídy - (generické programování 
resp. metaprogramování).

Mezi ladicí metody třídy `ClassInfo` patří:
- \c ClassInfo<T>::Total() - počítadlo vzniklých instancí třídy `T`
- \c ClassInfo<T>::Living() - počítadlo v daném okamžiku existujících instancí třídy `T`
- \c ClassInfo<T>::ID() resp. [CBlock::ID()](\ref CBlock_bool::CBlock::ID) - unikátní číselné označení dané instance


\attention Projděte si všechny uvedené kontrolní i ladicí mechanismy, snažte se pochopit jejich smysl a využití při trasování programu. Získané vědomosti se Vám budou rozhodně 
hodit, například když se nějaká část Vašeho programu začne chovat "podezřele" či přímo "nepřátelsky". 

\note Hodně štěstí při realizaci Vašeho projektu. Nebojte se, ono to půjde. Hlavně _nepropadejte panice!_ ;-)

Pety 201X / 2022 modified Richter


