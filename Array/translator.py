# Corrected mapping Braille patterns to English characters
braille_to_eng_alphabets = {
    
    # Symbols
    "..00.0": ".", "..0...": ",","..0.00": "?", "..000.": "!",
    "..00..": ":", "..0.0.": ";","....00": "-", ".0..0.": "/",
    ".00..0": "<", "0..00.": ">","0.0..0": "(", ".0.00.": ")",
    
    # Alphabets
    "0.....": "a", "0.0...": "b", "00....": "c", "00.0..": "d",
    "0..0..": "e", "000...": "f", "0000..": "g", "0.00..": "h",
    ".00...": "i", ".000..": "j", "0...0.": "k", "0.0.0.": "l",
    "00..0.": "m", "00.00.": "n", "0..00.": "o", "000.0.": "p",
    "00000.": "q", "0.000.": "r", ".00.0.": "s", ".0000.": "t",
    "0...00": "u", "0.0.00": "v", ".000.0": "w", "00..00": "x",
    "00.000": "y", "0..000": "z", 

}
# 0.00.. h
# 000... f
# 0...0. k
# .00.00
# 00..
braille_to_eng_number = {
    # Numbers
    "0.....": "1", "0.0...": "2", "00....": "3", "00.0..": "4",
    "0..0..": "5", "000...": "6", "0000..": "7", "0.00..": "8",
    ".00...": "9", ".000..": "0", ".0...0": "."
}

# Special symbol 
num = ".0.000"
cap = ".....0"
space = "......"


# Step 2: Invert the dictionary
eng_to_braille_alphabets = {v: k for k, v in braille_to_eng_alphabets.items()}

# Step 3: Manually add the '>' symbol back into the inverted dictionary
eng_to_braille_alphabets['>'] = "0..00."  # Manually ensuring '>' is in the inverted dictionary

eng_to_braille_numbers = {v: k for k, v in braille_to_eng_number.items() }

for key, value in eng_to_braille_alphabets.items():
    # if /key/ == '>':??
    print(f"Found >: {value} and {key}")




def translate_to_english(braille):
    result = []
    i = 0
    capital_flag = False
    number_flag = False

    while i < len(braille):
        symbol = braille[i:i+6]
        next_symbol = braille[i+6:i+12] if i + 6 < len(braille) else ""
        prev_symbol = braille[i-6:i] if i >= 6 else ""

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
                # Check for "O" vs. ">" disambiguation
                if symbol == "0..00." and prev_symbol in braille_to_eng_number.values() and next_symbol in braille_to_eng_number.values():
                    char = ">"
                if capital_flag:
                    char = char.upper()
                    capital_flag = False
                result.append(char)

        i += 6

    return "".join(result)



def translate_to_braille(text):
    result = []
    number_flag = False

    for char in text:
        if char.isupper():
            result.append(cap)
            char = char.lower()

        if char.isdigit():
            if not number_flag:
                result.append(num)
                number_flag = True
            result.append(eng_to_braille_numbers[char])
        elif char == " ":
            result.append(space)
            number_flag = False  # Reset number flag after a space
        else:
            braille_char = eng_to_braille_alphabets.get(char, "")
            if braille_char:  # Ensure the character exists in the mapping
                print(f"Translating '{char}' to Braille: '{braille_char}'")  # Debug statement
                result.append(braille_char)
            else:
                print(f"Warning: Character '{char}' not found in Braille mapping.")
            number_flag = False

    return "".join(result)



# Main function to handle input
def main():
    import sys
    input_text = sys.argv[1]

    if all(c in ['O', '.', ' ','0','o'] for c in input_text):
        input_text = input_text.replace('O', '0')  # Normalize Braille symbols
        print(translate_to_english(input_text))
    else:
        print(translate_to_braille(input_text))

if __name__ == "__main__":
    main()
