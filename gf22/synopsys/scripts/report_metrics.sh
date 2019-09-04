echo "Combinational area"
grep -rnwH "Combinational area"  | awk '{split($1, a, "_");print a[3] " " $3}'
