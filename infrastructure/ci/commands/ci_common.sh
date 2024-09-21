function print_banner(){
    echo -e "\n\n\e[95m\e[1m\e[4m${1}...\e[0m"
}
function print_error(){
    echo -e "\033[31m${1}\033[0m"
}

function print_green(){
    echo -e "\033[32m${1}\033[0m"
}

echo_and_run() {
  echo "$*"
  "$@"
}
