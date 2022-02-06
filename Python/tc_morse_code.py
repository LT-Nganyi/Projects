import string

letters = list(string.ascii_lowercase[:])
morse = ['.-','-...','-.-.','-..','.','..-.','--.','....','..','.---','-.-','.-..','--','-.','---','.--.','--.-','.-.','...','-','..-','...-','.--','-..-','-.--','--..']

letter_morse_dict = dict(zip(letters,morse))
letter_morse_dict[' ']= ''

morse_letter_dict = dict(zip(morse,letters))
morse_letter_dict['']= ' '

#print(len(morse_letter_dict))

def translate_to_morse(words):
    words = words.lower().strip()
    print('   '.join([letter_morse_dict[x] for x in words]))
    return '   '.join([letter_morse_dict[x] for x in words])

def translate_from_morse(morse_string):
    morse_string = morse_string.split('   ')
    print(''.join([morse_letter_dict[x] for x in morse_string]))
    return ''.join([morse_letter_dict[x] for x in morse_string])
    
try:
    translate_from_morse('...   ---   ...')
    #translate_from_morse(translate_to_morse('Any string'))
except KeyError as err:
   print('\nWrong morse code character or spacing used!\n  Use 3 spaces between letters and 6 spaces between words.')
