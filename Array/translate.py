# Corrected mapping Braille patterns to English characters
# Separate dictionaries for alphabets and symbols

# Alphabet Braille to English
braille_to_eng_alphabets = {
    "O.....": "a", "O.O...": "b", "OO....": "c", "OO.O..": "d",
    "O..O..": "e", "OOO...": "f", "OOOO..": "g", "O.OO..": "h",
    ".OO...": "i", ".OOO..": "j", "O...O.": "k", "O.O.O.": "l",
    "OO..O.": "m", "OO.OO.": "n", "O..OO.": "o", "OOO.O.": "p",
    "OOOOO.": "q", "O.OOO.": "r", ".OO.O.": "s", ".OOOO.": "t",
    "O...OO": "u", "O.O.OO": "v", ".OOO.O": "w", "OO..OO": "x",
    "OO.OOO": "y", "O..OOO": "z"
}


braille_to_eng_number = {
    # Numbers
    "O.....": "1", "O.O...": "2", "OO....": "3", "OO.O..": "4",
    "O..O..": "5", "OOO...": "6", "OOOO..": "7", "O.OO..": "8",
    ".OO...": "9", ".OOO..": "0", ".O...O": "."
}

# Special symbol 
num = ".O.OOO"
cap = ".....O"
space = "......"


# Invert both dictionaries to create English to Braille mappings
eng_to_braille_alphabets = {v: k for k, v in braille_to_eng_alphabets.items()}

eng_to_braille_numbers = {v: k for k, v in braille_to_eng_number.items() }


def translate_to_braille(text):
    result = []
    number_flag = False

    for char in text:
        if char.isupper():
            result.append(cap)  # Assuming cap is defined for capitalization
            char = char.lower()

        if char.isdigit():
            if not number_flag:
                result.append(num)  # Assuming num is defined for numbers
                number_flag = True
            result.append(eng_to_braille_numbers[char])  # Assuming eng_to_braille_numbers is defined
        elif char == " ":
            result.append(space)  # Assuming space is defined for space
            number_flag = False  # Reset number flag after a space
        else:
            # Check in alphabets 
            braille_char = eng_to_braille_alphabets.get(char) 
            if braille_char:
                result.append(braille_char)
            else:
                print(f"Warning: Character '{char}' not found in Braille mapping.")
            number_flag = False

    return "".join(result)

def translate_to_english(braille):
    result = []
    i = 0
    capital_flag = False
    number_flag = False

    while i < len(braille):
        symbol = braille[i:i+6]
        
        if symbol == num:  # Number follows
            number_flag = True
        elif symbol == cap:  # Capital follows
            capital_flag = True
        elif symbol == space:  # Space
            result.append(" ")
            number_flag = False  # Reset number flag after a space
        else:
            if number_flag:
                char = braille_to_eng_number.get(symbol, "")
                result.append(char)
            else:
                # Default to interpreting as a letter
                char = braille_to_eng_alphabets.get(symbol, "")
        
                if capital_flag:
                    char = char.upper()
                    capital_flag = False
                result.append(char)

        i += 6

    return "".join(result)


# Main function to handle input
def main():
    import sys
    input_text = " ".join(sys.argv[1:]) 

    if all(c in ['O', '.', ] for c in input_text):
        # input_text = input_text.replace('O', 'O')  # Normalize Braille symbols
        print(translate_to_english(input_text))
    else:
        print(translate_to_braille(input_text))

if __name__ == "__main__":
    main()
