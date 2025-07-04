\mainpage Úvod a zadání

| Projekt BPC-PPC CBlock Example	| 2022																		|
| ---								| ---																		|
| Název projektu:					| CBlock_bool, CBlock_TWeekDay, __CBlock_TYP1__, __CBlock_TYP2__			|
| Autor 1:							| `230122`, __Majnuš__ Martin, xmajnu01@vut.cz							    |
| Autor 2:							| `203251`, __Kluka__ Daniel, xkluka00@vut.cz							    |
| Autor 3:							| `230159`, __Prasek__ Šimon, xprase08@vut.cz								|
| Autor 4:							| `228732`, __Pešek__ David, xpesek13@vut.cz								|
| Datum zadání:						| 25.10.2022																|
| Datum finálního odevzdání:		| 21.12.2022																|


## Úvodní poznámky
Cílem tohoto testovacího projektu je pomoci Vám navrhnout a odzkoušet zadané varianty třídy `CBlock`.
Projekt již obsahuje plně funkční varianty `CBlock_bool::CBlock` a `CBlock_TWeekDay::CBlock`.
Vaším úkolem je naprogramovat další dvě varianty třídy `CBlock` dle zvoleného zadání a ověřit jejich 
fungování a kompatibilitu pomocí dodané funkce main() v souboru main.cpp.

Vývoj projektu je možný v libovolném prostředí a kompilátoru C++ ([g++](http://gcc.gnu.org/), [clang++](http://clang.llvm.org/)), ale referenčním překladačem 
bude [Microsoft Visual Studio 2022](https://visualstudio.microsoft.com/).

\attention Tento projekt (tj. adresář CBlock) je určen pouze pro testování a slouží pro kontrolu funkčnosti nových typů `CBlock`. 
Hodnocení funkčnosti nových tříd `CBlock` proto proběhne v tomto projektu. Hodnocení zadání, komentářů a zdrojů datového kontejneru, ale proběhne na základě dat v 
adresáři __Project__ (tj. "modrá" varianta dokumentace vygenerovaná pomocí Doxygen). Po odladění budou vytvořené soubory překopírovány (SVN copy) do adresáře `Project`.


## Doporučený postup
1.	Pročtěte si tuto dokumentaci (\ref doc) a dodané zdrojové texty. Význam symbolů a barevného značení u zobrazovaných grafů popisuje tato [legenda](graph_legend.html).
2.	Proveďte trasování dodané funkce `main` pro obě varianty tříd `CBlock`.
3.	Promyslete smysl celého programu a význam odlišností v jednotlivých variantách tříd `CBlock`.
4.	Navrhněte a implementujte obě nové varianty tříd `CBlock` do vlastních jmenných prostorů.
5.	Ověřte jejich správnou funkci na __nemodifikovaném__ těle funkce `main`.
6.	Doplňte dokumentaci Doxygen pro nově vytvořené soubory tříd `CBlock` (__jazykem C++ zdrojových textů je angličtina, nebo čeština bez diakritiky__). 
 Pro dokumentaci ve zdrojových souborech používejte český jazyk bez háčků a čárek (tj. pouze ASCII znaky). Popřípadě používejte jazyk anglický (pokud ho umíte na odpovídající úrovni).
 \note Soubor \c Doxyfile nemažte! Používejte tento dodaný soubor. Upravujte v něm pouze požadované položky (nadpis, logo, názvy nově přidaných souborů, atd.).
7.	Jakmile Vámi navržené varianty tříd `CBlock` budou fungovat správně a ohodnotí Vám je vyučující (společně s průběžným hodnocením hlavičkových souborů projektu), 
zkopírujte a začleňte si jejich zdrojové texty do dalšího projektu: adresář `Project`.


## Poznámky k řešení:
\done
Do tohoto textu nezapomeňte doplnit hlavičku (tj. jména řešitelů, varianty tříd `CBlock`, datum zadání).

\note Pro lepší orientaci uvádíme krátkou motivaci k pojmu třída na odkazu: [Motivace třída](http://www.uamt.fekt.vut.cz/~richter/vyuka/1920_XPPC/cviceni/motivace_trida.html).
