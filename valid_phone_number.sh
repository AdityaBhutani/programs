# Bash Script

# https://leetcode.com/problems/valid-phone-numbers/

# Writing a Bash Script - Some Rules: 
# 1. In Bash we use '\' to escape next one trailing character. By this we mean, If we want
# 	 to match a single left paranthesis '(' -- we cannot use '(' directly because it has a special
# 	 meaning in regular expression --. Se we have to use '(' to indicate that we want to match
# 	 to '('.
# 2. '^' denote the starting of a line.
# 3. '$' denote the end of a line.
# 4. '{M}' is used to denote to match exaclty M times of the previous occurence/regex
# 5. '(...)' is used to group pattern/regex together


# 						FOR xxx-xxx-xxxx												 FOR (xxx) xxx-xxxx
grep -e '\(^[0-9]\{3\}-[0-9]\{3\}-[0-9]\{4\}$\)' -e '\(^([0-9]\{3\})[ ][0-9]\{3\}-[0-9]\{4\}$\)' file.txt