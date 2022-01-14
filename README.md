# ScreamConverter
Converts ascii text to binary or arbitrary characters.
This is *only* compatible with ascii characters, I don't think it would work very well if you tried to use any characters that take up more than 8 bits.

Configuration is done via config.txt files.
There should be two characters in each file.
They should be the characters you want to use as zero and one, respectively. So to convert "lorem ipsum" into "aAAaAAaa aAAaAAAA aAAAaaAa aAAaaAaA aAAaAAaA aaAaaaaa  aAAaAaaA aAAAaaaa aAAAaaAA aAAAaAaA aAAaAAaA" and back, the files would both have to begin with "aA".

Put the text you wish to convert in input.txt, the converted text will appear in output.txt.
The decoder and encoder must use separate I/O files.

You must create your own input and config files for this to work, it will create a new output.txt file if there is none. Beware of existing output.txt files being overwritten.

The decoder input ignores whitespace characters, encoding using them is not a good idea. If the decoder encounters a character it is not configured to handle, it will treat is as if it was a zero, possibly causing inaccurate results.
