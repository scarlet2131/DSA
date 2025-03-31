# Step 1: Create the original dictionary
braille_to_eng_alphabets = {
    # Symbols
    "..00.0": ".", 
    "..0...": ",",
    "..0.00": "?", 
    "..000.": "!",
    "..00..": ":", 
    "..0.0.": ";",
    "....00": "-", 
    ".0..0.": "/",
    ".00..0": "<", 
    "0..00.": ">",  # Ensure this is correct
    "0.0..0": "(", 
    ".0.00.": ")",

    # Alphabets
    "0.....": "a", 
    "0.0...": "b", 
    "00....": "c", 
    "00.0..": "d",
    "0..0..": "e", 
    "000...": "f", 
    "0000..": "g", 
    "0.00..": "h",
    ".00...": "i", 
    ".000..": "j", 
    "0...0.": "k", 
    "0.0.0.": "l",
    "00..0.": "m", 
    "00.00.": "n", 
    # "0..00.": "o", 
    "000.0.": "p",
    "00000.": "q", 
    "0.000.": "r", 
    ".00.0.": "s", 
    ".0000.": "t",
    "0...00": "u", 
    "0.0.00": "v", 
    ".000.0": "w", 
    "00..00": "x",
    "00.000": "y", 
    "0..000": "z"
}

# Step 2: Invert the dictionary
eng_to_braille_alphabets = {v: k for k, v in braille_to_eng_alphabets.items()}

# Step 3: Test if we can retrieve each key from the inverted dictionary
print("Testing dictionary lookups:")
print(f"Braille for '>': {eng_to_braille_alphabets.get('>')}")      # Expected output: "0..00."
print(f"Braille for '<': {eng_to_braille_alphabets.get('<')}")      # Expected output: ".00..0"
print(f"Braille for 'u': {eng_to_braille_alphabets.get('u')}")      # This should return None as '&' is not in the original dict
print(f"Braille for 'v': {eng_to_braille_alphabets.get('v')}")      # This should return None as '=' is not in the original dict

# Check if specific keys exist in the inverted dictionary
print("\nChecking if specific keys exist in the inverted dictionary:")
for key in [">", "<", "u", "v"]:
    if key in eng_to_braille_alphabets:
        print(f"Key '{key}' exists with value: {eng_to_braille_alphabets[key]}")
    else:
        print(f"Key '{key}' does NOT exist!")






# # Symbols Braille to English
# braille_to_eng_symbols = {
#     "..00.0": ".", "..0...": ",", "..0.00": "?", "..000.": "!",
#     "..00..": ":", "..0.0.": ";", "....00": "-", ".0..0.": "/",
#     ".00..0": "<", "0..00.": ">", "0.0..0": "(", ".0.00.": ")"
# }

# 0.00.. h
# 000... f
# 0...0. k
# .00.00
# 00..