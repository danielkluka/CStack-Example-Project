\page tasks Doporučení pro zdárné dokončení projektu CKontejner
\n
Tento text shrnuje nejčastější chyby a nedorozumění při realizaci projektu v minulých letech. 
Přečtěte si proto tento text před odevzdáním a použijte ho ke korekcím vaší práce.

1.	Po každé opravě, u všech projektů (CBlock, Project) vyřešit poznámky z minulé
	opravy. Projít stránku Bug a doxygen příkazy bug přepsat na bugfix. Za
	poznámku z opravy připsat, kdo opravil a jak opravil (tj. jak se poznámka
	vyřešila - u jednoduchých poznámek nebo obecných upozornění stačí jméno, kdo
	upravil na bugfix). \n
\n
2.	Zadání a realizaci projektu kontrolovat proti původní dodané šabloně zadání
	a doplnit chybějící metody a prvky. (= konstruktory a destruktor. Možnost
	zjistit ID a počty prvků třídy. Operátory včetně nečlenského a konverzního.
	Streamy. Privátní a veřejné metody. Dvojici metod "typu Reverzuj".)
	Nejčastější chyby (popsané pro datový typ minulých projektů CXItem) najdete na -
	[http://www.uamt.fekt.vutbr.cz/~richter/vyuka/XPPC/cviceni/chyby_hlavicka.html](http://www.uamt.fekt.vut.cz/~richter/vyuka/1920_XPPC/cviceni/chyby_hlavicka.html)\n
\n
3.	Projekt musí jít přeložit bez chyb a bez významných varování (warnings). Bude
	obsahovat knihovnu Check.\n
\n
4.	Realizujte kontejner pro svůj datový typ CBlock, který musí projít
	testy prvního projektu CBlock s originálním main. (tj. změna na CBlock pro
	bool by neměla způsobit problémy v kontejneru).\n
\n
5.	V hlavičkovém souboru v definici třídy budou pouze prototypy metod a funkcí 
	(platí pro těla metod s kódem - tj. při finálním odevzdání).
	Celé metody s těly budou buď ve zdrojovém souboru nebo inline za definicí
	třídy.\n
\n
6.	Napište main ve stejném stylu jako u projektu CBlock s voláním
	všech vytvořených metod kontejneru. Část kódu demonstrující vstup z
	klávesnice dejte do komentáře "//".\n
\n
7.	Kde to u parametrů nebo návratových hodnot je možné, bude použita reference.
	U parametrů které se nemění včetně \c this bude \c const.\n
\n
8.	Vytvořte požadované testy. Pro každou metodu bude test obsahovat alespoň tři testy (=
	testový \c assert. Alespoň dva testy budou "významné" tj. budou pracovat s proměnnými
	naplněnými hodnotami (>2) a ne vytvořenými jako prázdné např. implicitními konstruktory).\n
\n
9.	U tří/čtyř (jeden na člena týmu) testů proveďte i test paměti. U ostatních může být pouze test na
	funkčnost.\n
\n
10.	Vytvoření dokumentace pomocí doxygen proběhne bez varování (warnings) (zkuste na
	příkazovém řádku příkaz \c "doxygen 2>err.txt" , který uloží do souboru
	err.txt chybová hlášení a na obrazovce ponechá pouze informační texty).\n
\n
11.	V dokumentaci bude ponecháno zadání z doby opravování - nemazat. K němu
	dopište změny na základě poznámek (označení _bug_ pouze změňte na _bugfix_) a změny, ke kterým jste se rozhodli
	během realizace.\n
\n
12.	V dokumentaci popište, co je váš kontejner, definujte jeho chování vůči
	klíči a hodnotě (= popište koncepci třídy). Popište vlastnosti a chování
	metod charakteristických pro daný kontejner (=>použití typických jmen metod 
	pro dané operace).\n
\n
13.	Při formulaci zadání napište dokumentaci pro členy třídy a u metod popište jejich činnost, funkci
	argumentů a návratové hodnoty. V další fázi řešení dokumentace musí souhlasit s aktuální verzí
	zdrojových textů.\n
\n
14.	Napište hodnocení/závěr, ve kterém popište nedostatky vašeho řešení (Co jste
	případně nestihli. Proč jste byli nuceni změnit zadání, hlavičku (oproti
	odevzdané verzi). Jaký k tomu byl důvod.).\n
\n
15.	**Všichni členové teamu budou mít srovnatelný a dostatečný počet commitů do
	svn.**
\n
\n
$Id: Tasks.md 3 2022-10-26 17:03:14Z petyovsky $
