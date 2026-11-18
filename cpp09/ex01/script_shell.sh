#!/bin/bash

# RPN tester - run it from the ex01/ directory:  bash test_rpn.sh
# It rebuilds the project, then checks valid and invalid expressions.
# The OCF debug prints (colors + "... CALLED" lines) are ignored on purpose:
# only the result line on stdout and the content of stderr are checked.

BIN=./RPN
ESC=$(printf '\033')
GREEN="${ESC}[32m"
RED="${ESC}[31m"
RESET="${ESC}[0m"
ERR_FILE=$(mktemp)
trap 'rm -f "$ERR_FILE"' EXIT

PASS=0
FAIL=0

# strips ANSI colors and the constructor/destructor debug lines
clean()
{
	sed "s/${ESC}\[[0-9;]*m//g" | grep -v "CALLED"
}

# report <0|1> <label> <details>   (0 = pass, 1 = fail)
report()
{
	if [ "$1" -eq 0 ]; then
		PASS=$((PASS + 1))
		printf "%sPASS%s  %s\n" "$GREEN" "$RESET" "$2"
	else
		FAIL=$((FAIL + 1))
		printf "%sFAIL%s  %s\n" "$RED" "$RESET" "$2"
		printf "      %s\n" "$3"
	fi
}

# check_ok <expression> <expected result> [label]
# stdout must be exactly the result, stderr must be empty
check_ok()
{
	local out err label
	label="${3:-[$1] -> $2}"
	out=$("$BIN" "$1" 2>"$ERR_FILE" | clean)
	err=$(cat "$ERR_FILE")
	if [ "$out" = "$2" ] && [ -z "$err" ]; then
		report 0 "$label"
	else
		report 1 "$label" "got stdout: '$out' | stderr: '$err'"
	fi
}

# check_err <label> [args...]
# nothing must be printed as a result, something must be printed on stderr
check_err()
{
	local out err label
	label="$1"
	shift
	out=$("$BIN" "$@" 2>"$ERR_FILE" | clean)
	err=$(cat "$ERR_FILE")
	if [ -z "$out" ] && [ -n "$err" ]; then
		report 0 "$label -> error"
	else
		report 1 "$label -> error" "got stdout: '$out' | stderr: '$err'"
	fi
}

# err_case <expression>: shortcut for a single bad expression
err_case()
{
	check_err "[$1]" "$1"
}

# chain <N>: builds "9 9 * 9 * 9 * ..." with N nines, so the result is 9^N
chain()
{
	local s="9 9 *" i=2
	while [ "$i" -lt "$1" ]; do
		s="$s 9 *"
		i=$((i + 1))
	done
	echo "$s"
}

echo "== build =="
if [ ! -f Makefile ]; then
	echo "Makefile not found (run this script from ex01/)"
	exit 1
fi
if ! make re >/dev/null 2>&1 || [ ! -x "$BIN" ]; then
	echo "build failed: run 'make re' by hand to see the errors"
	exit 1
fi
echo "build ok"

echo
echo "== valid expressions =="
# examples from the subject
check_ok "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
check_ok "7 7 * 7 -" "42"
check_ok "1 2 * 2 / 2 * 2 4 - +" "0"
# every operator, shortest input
check_ok "1 1 +" "2"
check_ok "9 9 *" "81"
check_ok "5 3 -" "2"
check_ok "8 2 /" "4"
# operand order and integer division
check_ok "2 8 /" "0"
check_ok "3 5 -" "-2"
check_ok "0 9 - 9 *" "-81"
check_ok "0 5 /" "0"
check_ok "0 0 +" "0"
# longer expressions
check_ok "9 3 / 2 *" "6"
check_ok "1 2 + 3 + 4 +" "10"
check_ok "5 1 2 + 4 * + 3 -" "14"
check_ok "9 8 7 6 5 4 3 2 1 + + + + + + + +" "45"
# extra spaces are fine
check_ok "  1 1 +  " "2"
check_ok "1   1   +" "2"
# big results (need a wide type)
check_ok "$(chain 10)" "3486784401" "[9^10 chain, bigger than INT_MAX] -> 3486784401"
check_ok "$(chain 19)" "1350851717672992089" "[9^19 chain, close to LONG_MAX] -> 1350851717672992089"

echo
echo "== invalid expressions =="
# subject example and foreign characters
err_case "(1 + 1)"
err_case "1 a +"
err_case "1 1 ."
err_case $'1\t1 +'
# empty and almost empty
err_case ""
err_case "     "
err_case "1 1"
# operators without enough operands
err_case "1 +"
err_case "+ 1 1"
err_case "1 + 1"
err_case "+ + +"
err_case "1 1 + +"
# operands left on the stack
err_case "1 2 3"
err_case "1 1 1 +"
err_case "1 1 + 1"
# bad tokens: multi-digit numbers, glued tokens, signs, decimals
err_case "12 3 +"
err_case "123++"
err_case "1 1 +1"
err_case "1 1 ++"
err_case "-5 3 +"
err_case "1.5 2 +"
# division by zero (direct and computed)
err_case "5 0 /"
err_case "0 0 /"
err_case "9 3 - 3 3 - /"
# overflow of the result (9^20 > LONG_MAX): expected to be an error
check_err "[9^20 chain, overflow]" "$(chain 20)"
# wrong number of arguments
check_err "(no arguments)"
check_err "(two arguments)" "1 1 +" "2"

echo
echo "== $PASS passed, $FAIL failed =="
exit $((FAIL > 0))