def main():
    import re
    text = """
Yesterday all my troubles seemed so far away.
Now it looks as though they're here to stay.
Oh, I believe in yesterday.

Suddenly I'm not half the man I used to be.
There's a shadow hanging over me.
Oh, yesterday came suddenly.

Why she had to go, I don't know, she wouldn't say.
I said something wrong, now I long for yesterday.

Yesterday love was such an easy game to play.
Now I need a place to hide away.
Oh, I believe in yesterday.

Why she had to go, I don't know, she wouldn't say.
I said something wrong, now I long for yesterday.

Yesterday love was such an easy game to play.
Now I need a place to hide away.
Oh, I believe in yesterday.
    """
    text = text.lower()

    # 특수문자 제거하고 단어만 추출
    words = re.findall(r'\b\w+\b', text)

    word_count = {}

    for word in words:
        word_count[word] = word_count.get(word, 0) + 1

    for word, count in word_count.items():
        print(f"{word}: {count}번")

if __name__ == "__main__":
    main()
