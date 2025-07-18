def num_letters(text):
    letters = 0
    ltext = list(text)
    for i in range(len(text)):
        if (ltext[i].isalpha()):
            letters += 1
    return letters


def num_sentences(text):
    sentences = 0
    ltext = list(text)
    for i in range(len(text)):
        if (ltext[i] == '.' or ltext[i] == '?' or ltext[i] == '!'):
            sentences += 1
    return sentences


def num_words(text):
    return len(text.split())


def letters_per_words(letters, words):
    return (letters / words) * 100


def sentences_per_words(sentences, words):
    return (sentences / words) * 100


text = str(input("Text: "))
words = num_words(text)
letters = num_letters(text)
sentences = num_sentences(text)
sentences_per = sentences_per_words(sentences, words)
letters_per = letters_per_words(letters, words)
index = round(0.0588 * letters_per - 0.296 * sentences_per - 15.8)
if (index > 1 and index < 16):
    print("Grade", index)
elif (index < 1):
    print("Before Grade 1\n")
else:
    print("Grade 16+\n")
