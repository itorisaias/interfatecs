def justify_text(L, text):
    words = text.split()
    total_length = sum(len(word) for word in words)
    
    total_spaces = len(words) - 1 if len(words) > 1 else 0
    
    print(words, len(words), total_length)
    print(total_spaces)
    
    # if total_spaces == 0 or total_length >= L:
    #     spaces = [0.0] * (total_spaces + 1)
    # else:
    #     space_length = L - total_length
        
    #     if total_spaces > 0:
    #         base_space = space_length / total_spaces
    #         spaces = [round(base_space, 3)] * total_spaces
    #     else:
    #         spaces = [0.0]  # Sem espaços em branco

    #     spaces.append(0.0)
    
    # print(" ".join(f"{space:.3f}" for space in spaces))

L = 15
text = "o rato roeu a roupa do rei de Roma"
justify_text(L, text)
