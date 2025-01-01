main_64.c:

1. The buffer should be 64k bytes, that is 65536 bytes. You should define a
   macro containing the buffer size.
   
2. Identifiers in C are usually shorter (think buf instead of buffer). Note that
   fopen() returns FILE*, while open() returns an int, a file descriptor.
   input_file should be rather called fd or input_desc.
   
3. read(n) may return -1 (error), 0 (EOF), or a number of bytes read between 1
   and n. The calculation of the position relies on read() returning 64 until
   the last time when bytes_read may be < 64. There should be a variable
   tracking the number of bytes read in total. index variable becomes
   unnecessary. Also, for() loop becomes out of place. Consider using while()
   loop instead.

4. Consider using perror() when read() returns -1.

5. You still need to enable spellchecker in your editor.

You should prepare a 100M file which contains spaces or zeros and a period right
in the end. Then you should compare the runtimes for the two versions of the
program. You may even have a graph of how the runtime depends on the buffer
size.
