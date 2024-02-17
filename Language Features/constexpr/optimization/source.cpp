#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

struct data
{
const char *name;
short yob;
const char *description;
};

constexpr auto ntop10 = 10;
constexpr array<data, ntop10> top10
{{
{"Marilyn Monroe",1926 ,"American actress, singer, model"},
{"Abraham Lincoln",1809 ,"US President during American civil war"},
{"Nelson Mandela",1918 ,"South African President anti-apartheid campaigner"},
{"Queen Elizabeth II",1926 ,"British monarch since 1954"},
{"John F. Kennedy",1917 ,"US President 1961 – 1963"},
{"Martin Luther King",1929 ,"American civil rights campaigner"},
{"Winston Churchill",1874 ,"British Prime Minister during WWII"},
{"Donald Trump",1946 ,"Businessman, US President."},
{"Bill Gates",1955 ,"American businessman, founder of Microsoft"},
{"Muhammad Ali",1942 ,"American Boxer and civil rights campaigner"}
}};

constexpr double vyasa (double trijya) {return 2.0 * trijya ;}
constexpr double diaherea (double trijya) {return vyasa(trijya) / 2.0 * 3.14 * vyasa(trijya) / 2.0;}
constexpr double gems[] {diaherea(10),diaherea(20),diaherea(30),diaherea(40)};

constexpr data famouslist[] = 
{
{"Marilyn Monroe",1926 ,"American actress, singer, model"},
{"Abraham Lincoln",1809 ,"US President during American civil war"},
{"Nelson Mandela",1918 ,"South African President anti-apartheid campaigner"},
{"Queen Elizabeth II",1926 ,"British monarch since 1954"},
{"John F. Kennedy",1917 ,"US President 1961 – 1963"},
{"Martin Luther King",1929 ,"American civil rights campaigner"},
{"Winston Churchill",1874 ,"British Prime Minister during WWII"},
{"Donald Trump",1946 ,"Businessman, US President."},
{"Bill Gates",1955 ,"American businessman, founder of Microsoft"},
{"Muhammad Ali",1942 ,"American Boxer and civil rights campaigner"},
{"Mahatma Gandhi",1869 ,"Leader of Indian independence movement"},
{"Mother Teresa",1910 ,"Macedonian Catholic missionary nun"},
{"Christopher Columbus",1451 ,"Italian explorer"},
{"Charles Darwin",1809 ,"British scientist, theory of evolution"},
{"Elvis Presley",1935 ,"American musician"},
{"Albert Einstein",1879 ,"German scientist, theory of relativity"},
{"Paul McCartney",1942 ,"British musician, member of Beatles"},
{"Queen Victoria", 1819 ,"British monarch 1837 – 1901"},
{"Pope Francis",1936 ,"First pope from the Americas"},
{"Jawaharlal Nehru",1889 ,"Indian Prime Minister 1947 – 1964"},
{"Leonardo da Vinci",1452 ,"Italian, painter, scientist, polymath"},
{"Vincent Van Gogh",1853 ,"Dutch artist"},
{"Franklin D. Roosevelt",1882 ,"US President 1932 – 1945"},
{"Pope John Paul II",1920 ,"Polish Pope"},
{"Thomas Edison", 1847 ,"American inventor"},
{"Rosa Parks",1913 ,"American civil rights activist"},
{"Lyndon Johnson",1908 ,"US President 1963 – 1969"},
{"Ludwig Beethoven",1770 ,"German composer"},
{"Oprah Winfrey",1954 ,"American TV presenter, actress, entrepreneur"},
{"Indira Gandhi",1917 ,"Prime Minister of India 1966 – 1977"},
{"Eva Peron",1919 ,"First Lady of Argentina 1946 – 1952"},
{"Benazir Bhutto",1953 ,"Prime Minister of Pakistan 1993 – 1996"},
{"George Orwell",1903 ,"British author"},
{"Vladimir Putin",1952 ,"Russian leader"},
{"Dalai Lama",1938 ,"Spiritual and political leader of Tibetans"},
{"Walt Disney",1901 ,"American film producer"},
{"Neil Armstrong",1930 ,"US astronaut"},
{"Peter Sellers",1925 ,"British actor and comedian"},
{"Barack Obama",1961 ,"US President 2008 – 2016"},
{"Malcolm X",1925 ,"American Black nationalist leader"},
{"J.K.Rowling",1965 ,"British author"},
{"Richard Branson",1950 ,"British entrepreneur"},
{"Pele",1940 ,"Brazilian footballer, considered greatest of 20th century."},
{"Angelina Jolie",1975 ,"Actress, director, humanitarian"},
{"Jesse Owens",1913 ,"US track athlete, 1936 Olympics"},
{"John Lennon",1940 ,"British musician, member of the Beatles"},
{"Henry Ford",1863 ,"US Industrialist"},
{"Haile Selassie",1892 ,"Emperor of Ethiopia 1930 – 1974"},
{"Joseph Stalin",1879 ,"Leader of Soviet Union 1924 – 1953"},
{"Lord Baden Powell",1857 ,"British Founder of scout movement"},
{"Michael Jordan",1963 ,"US Basketball star"},
{"Vladimir Lenin",1870 ,"Leader of Russian Revolution 1917"},
{"Ingrid Bergman",1915 ,"Swedish actress"},
{"Fidel Castro",1926 ,"President of Cuba 1976 – 2008"},
{"Leo Tolstoy",1828 ,"Russian author and philosopher"},
{"Greta Thunberg",2003 ,""},
{"Pablo Picasso",1881 ,"Spanish modern artist"},
{"Oscar Wilde",1854 ,"Irish author, poet, playwright"},
{"Coco Chanel",1883 ,"French fashion designer"},
{"Charles de Gaulle",1890 ,"French resistance leader and President 1959 – 1969"},
{"Amelia Earhart",1897 ,"Aviator"},
{"John M Keynes",1883 ,"British economist"},
{"Louis Pasteur",1822 ,"French chemist and microbiologist"},
{"Mikhail Gorbachev",1931 ,"Leader of Soviet Union 1985 – 1991"},
{"Plato",423 ,"Greek philosopher"},
{"Adolf Hitler",1889 ,"leader of Nazi Germany 1933 – 1945"},
{"Sting",1951 ,"British musician"},
{"Elon Musk",1971 ,"Business magnate, and entrepreneur."},
{"Mary Magdalene",4,"devotee of Jesus Christ"},
{"Alfred Hitchcock",1899 ,"English / American film producer, director"},
{"Michael Jackson",1958 ,"American musician"},
{"Madonna",1958 ,"American musician, actress, author"},
{"Mata Hari",1876 ,"Dutch exotic dancer, executed as spy"},
{"Cleopatra",69 ,"Queen of Egypt"},
{"Grace Kelly",1929 ,"American actress, Princess of Monaco"},
{"Malala Yousafzai",1997 ,"Pakistani human rights activist"},
{"Steve Jobs",1955 ,"co-founder of Apple computers"},
{"Ronald Reagan",1911 ,"US President 1981-1989"},
{"Lionel Messi",1987 ,"Argentinian footballer"},
{"Babe Ruth",1895 ,"American baseball player"},
{"Bob Geldof",1951 ,"Irish musician, charity worker"},
{"Roger Federer",1981 ,"Swiss Tennis player"},
{"Sigmund Freud",1856 ,"Austrian psychoanalyst"},
{"Woodrow Wilson",1856 ,"US president 1913 – 1921"},
{"Mao Zedong",1893 ,"Leader of Chinese Communist revolution"},
{"Katherine Hepburn",1907 ,"American actress"},
{"Audrey Hepburn",1929 ,"British actress and humanitarian"},
{"David Beckham",1975 ,"English footballer"},
{"Tiger Woods",1975 ,"American golfer"},
{"Usain Bolt",1986 ,"Jamaican athlete and Olympian"},
{"Carl Lewis",1961 ,"US athlete and Olympian"},
{"Prince Charles",1948 ,"Heir to British throne"},
{"Jacqueline Kennedy Onassis",1929 ,"American wife of JF Kennedy"},
{"Joe Biden",1942 ,"US President"},
{"Kim Kardashian",1980 ,"American socialiate"},
{"C.S. Lewis",1898 ,"British author"},
{"Billie Holiday",1915 ,"American jazz singer"},
{"J.R.R. Tolkien",1892 ,"British author"},
{"Billie Jean King",1943 ,"American tennis player and human rights activist"},
{"Margaret Thatcher",1925 ,"British Prime Minister 1979 – 1990"}
};



int main() 
{
}