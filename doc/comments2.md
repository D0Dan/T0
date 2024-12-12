The solution is generally correct. This is great.
A few possible improvements:

1. Return type of main() should be int, not void. main() function is special and
   some compilers may not complain about it but I recommend you stick to int
   return value. Correspondingly, return should return 0 (success). return 0
   from main() is the same as exit(0).

2. For C sources put opening parenthesis at the beginning of the new line. For example,
   int main(...)
   {
        // ...
   }

   not
   int main(...) {
        // ...
   }

   The same goes with other blocks (for, if-else, etc).

3. Add space between // and the text of the comment. For example,
   // This is a comment
   but
   //TODO or //FIXME

4. The error handling, especially when it comes to file errors, should return
   non-zero from main() or use exit(1). I prefer exit(1).

5. You use for() loop in unorthodox but correct way. Not a big problem.

6. You are reading the file byte-by-byte. This is very inefficient. You may keep
   this version of the program and write another one which reads the file in 64k
   or 1M chunks. When working with 1G file there will be serious difference in
   speed.

7. Comments are excessive. Unnecessary comments should be avoided. Add comments
   if the variable name or field name does not speak for itself. The source code
   should be obvious. Add comments when it is not.

8. Add automatic spellchecker to your editor.
