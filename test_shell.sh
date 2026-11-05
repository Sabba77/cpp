#!/bin/bash
# Test per cpp06/ex00 (ScalarConverter)
# Uso: bash test_convert.sh [percorso_eseguibile]   (default: ./convert)
#
# Assunzioni (modificale qui sotto se le tue scelte sono diverse):
#  - un input non valido stampa esattamente INVALID_MSG
#  - il messaggio d'uso inizia con "Usage"
#  - precisione fissa a 1 cifra decimale
#  - '+', '-', '.' da soli sono char; ".5" e "5." sono double validi

BIN="${1:-./convert}"
INVALID_MSG="INVALID TYPE"

GREEN=$'\033[32m'
RED=$'\033[31m'
BOLD=$'\033[1m'
RESET=$'\033[0m'

pass=0
fail=0

# report <nome> <atteso> <ottenuto>
report()
{
	if [ "$3" == "$2" ]; then
		pass=$((pass + 1))
		printf "%s[OK]%s   %s\n" "$GREEN" "$RESET" "$1"
	else
		fail=$((fail + 1))
		printf "%s[FAIL]%s %s\n" "$RED" "$RESET" "$1"
		printf "  atteso:\n"
		printf '%s\n' "$2" | sed 's/^/    /'
		printf "  ottenuto:\n"
		printf '%s\n' "$3" | sed 's/^/    /'
	fi
}

# t <argomento> <char> <int> <float> <double>
t()
{
	local expected actual
	printf -v expected "char: %s\nint: %s\nfloat: %s\ndouble: %s" "$2" "$3" "$4" "$5"
	actual=$("$BIN" "$1" 2>&1)
	report "convert [$1]" "$expected" "$actual"
}

# tinv <argomento>   (input non valido)
tinv()
{
	local actual
	actual=$("$BIN" "$1" 2>&1)
	report "convert [$1] -> invalido" "$INVALID_MSG" "$actual"
}

# tusage <argomenti...>   (numero di argomenti sbagliato)
tusage()
{
	local actual
	actual=$("$BIN" "$@" 2>&1 | head -n 1)
	if [[ "$actual" == Usage* ]]; then
		pass=$((pass + 1))
		printf "%s[OK]%s   convert con %d argomenti -> usage\n" "$GREEN" "$RESET" "$#"
	else
		fail=$((fail + 1))
		printf "%s[FAIL]%s convert con %d argomenti -> usage\n" "$RED" "$RESET" "$#"
		printf "  ottenuto: [%s]\n" "$actual"
	fi
}

section()
{
	printf "\n%s== %s ==%s\n" "$BOLD" "$1" "$RESET"
}

if [ ! -x "$BIN" ]; then
	echo "Eseguibile non trovato: $BIN (compila prima, o passa il percorso come argomento)"
	exit 1
fi

section "1. Esempi della consegna"
t "0"      "Non displayable" 0 "0.0f" "0.0"
t "nan"    "impossible" "impossible" "nanf" "nan"
t "42.0f"  "'*'" 42 "42.0f" "42.0"

section "2. Int e confini del char"
t "65"     "'A'" 65 "65.0f" "65.0"
t "32"     "' '" 32 "32.0f" "32.0"
t "126"    "'~'" 126 "126.0f" "126.0"
t "127"    "Non displayable" 127 "127.0f" "127.0"
t "128"    "impossible" 128 "128.0f" "128.0"
t "-42"    "Non displayable" -42 "-42.0f" "-42.0"
t "-128"   "Non displayable" -128 "-128.0f" "-128.0"
t "-129"   "impossible" -129 "-129.0f" "-129.0"

section "3. Confini dell'int"
t "2147483647"  "impossible" 2147483647 "2147483648.0f" "2147483647.0"
t "2147483648"  "impossible" "impossible" "2147483648.0f" "2147483648.0"
t "-2147483648" "impossible" -2147483648 "-2147483648.0f" "-2147483648.0"
t "-2147483649" "impossible" "impossible" "-2147483648.0f" "-2147483649.0"
t "16777217"    "impossible" 16777217 "16777216.0f" "16777217.0"

section "4. Float e double"
t "4.2f"   "Non displayable" 4 "4.2f" "4.2"
t "-4.2f"  "Non displayable" -4 "-4.2f" "-4.2"
t "4.2"    "Non displayable" 4 "4.2f" "4.2"
t ".5"     "Non displayable" 0 "0.5f" "0.5"
t "5."     "Non displayable" 5 "5.0f" "5.0"
t "42.9"   "'*'" 42 "42.9f" "42.9"
t "-0"     "Non displayable" 0 "-0.0f" "-0.0"

section "5. Limite noto: precisione fissa a 1 decimale"
t "42.123" "'*'" 42 "42.1f" "42.1"
t "0.05"   "Non displayable" 0 "0.1f" "0.1"

section "6. Overflow di float e double"
t "340282366920938463463374607431768211456.0" \
	"impossible" "impossible" "impossible" "340282366920938463463374607431768211456.0"
t "340282346638528859811704183484516925440.0" \
	"impossible" "impossible" "340282346638528859811704183484516925440.0f" "340282346638528859811704183484516925440.0"
t "$(printf '9%.0s' $(seq 1 400))" \
	"impossible" "impossible" "impossible" "impossible"

section "7. Char"
t "a"      "'a'" 97 "97.0f" "97.0"
t "'a'"    "'a'" 97 "97.0f" "97.0"
t "'5'"    "'5'" 53 "53.0f" "53.0"
t "5"      "Non displayable" 5 "5.0f" "5.0"
t "*"      "'*'" 42 "42.0f" "42.0"
t "-"      "'-'" 45 "45.0f" "45.0"
t "+"      "'+'" 43 "43.0f" "43.0"
t "."      "'.'" 46 "46.0f" "46.0"
t " "      "' '" 32 "32.0f" "32.0"

section "8. Pseudo-literal"
t "nan"    "impossible" "impossible" "nanf" "nan"
t "nanf"   "impossible" "impossible" "nanf" "nan"
t "+inf"   "impossible" "impossible" "+inff" "+inf"
t "+inff"  "impossible" "impossible" "+inff" "+inf"
t "-inf"   "impossible" "impossible" "-inff" "-inf"
t "-inff"  "impossible" "impossible" "-inff" "-inf"

section "9. Input non validi"
tinv "abc"
tinv ""
tinv "4.2.3"
tinv "42f"
tinv "4.2ff"
tinv "--5"
tinv "+."
tinv "inf"
tinv "NaN"
tinv "1e5"
tinv "4 2"
tinv "''"
tinv "'ab'"

section "10. Numero di argomenti"
tusage
tusage 1 2

printf "\n%sRisultato:%s %s%d OK%s, %s%d FAIL%s\n" \
	"$BOLD" "$RESET" "$GREEN" "$pass" "$RESET" "$RED" "$fail" "$RESET"

[ "$fail" -eq 0 ]