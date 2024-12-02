teclas = {
  'a': 1, 'b': 2, 'c': 3,
  'A': 4, 'B': 5, 'C': 6,
  'd': 1, 'e': 2, 'f': 3,
  'D': 4, 'E': 5, 'F': 6,
  'g': 1, 'h': 2, 'i': 3,
  'G': 4, 'H': 5, 'I': 6,
  'j': 1, 'k': 2, 'l': 3,
  'J': 4, 'K': 5, 'L': 6,
  'm': 1, 'n': 2, 'o': 3,
  'M': 4, 'N': 5, 'O': 6,
  'p': 1, 'q': 2, 'r': 3, 's': 4,
  'P': 5, 'Q': 6, 'R': 7, 'S': 8,
  't': 1, 'u': 2, 'v': 3,
  'T': 4, 'U': 5, 'V': 6,
  'w': 1, 'x': 2, 'y': 3, 'z': 4,
  'W': 5, 'X': 6, 'Y': 7, 'Z': 8,
  ' ': 1
}
text = input()
total_toques = 0
for letra in text:
  total_toques += teclas[letra]
print(total_toques)
