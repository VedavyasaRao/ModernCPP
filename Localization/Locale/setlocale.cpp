//sets classic C locale
setlocale(LC_ALL,std::locale.classic());

//also sets classic C locale
setlocale(LC_ALL,"C");

//sets locale from environment variable LANG
setlocale(LC_ALL,"");

//sets a specific locale
setlocale(LC_ALL,"kn_IN.UTF-8");

// create a specific locale object and  set it as the global
std::locale::global(std::locale("en_US.ISO8859-1"));      
