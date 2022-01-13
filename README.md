# ScreamConverter
Converts ascii text to binary or arbitrary characters.
This is *only* compatible with ascii characters, I don't think it would work very well if you tried to use any characters that take up more than 8 bits.

Configuration is done via a config.txt file.
There should be three characters in the file.
The first one controls whether it outputs regular binary or replaces ones and zeros with corresponding characters. Set to 0 for normal binary, or anything else for arbitrary characters.
The second and third characters control what characters zeros and ones get replaced with, if the program is running in arbitrary-character mode.

Put the text you wish to convert in input.txt, the converted text will appear in output.txt.

You must create your own input and config files for this to work, it will create a new output.txt file if there is none. Beware of existing output.txt files being overwritten.
