class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:

        ans = []
        line = []
        temp = maxWidth

        # STEP 1: Create the lines
        for word in words:

            # +1 because we need a space before the new word
            if temp < len(word) + (1 if line else 0):

                ans.append(line)

                line = [word]
                temp = maxWidth - len(word)

            else:

                if line:
                    temp -= 1

                line.append(word)
                temp -= len(word)

        # Add last line
        ans.append(line)


        # STEP 2: Justify each line
        result = []

        for i in range(len(ans)):

            line = ans[i]

            # Last line
            if i == len(ans) - 1:

                new_line = " ".join(line)

                new_line += " " * (maxWidth - len(new_line))

                result.append(new_line)

                continue


            # Calculate total spaces needed
            word_chars = sum(len(word) for word in line)

            spaces = maxWidth - word_chars

            # Only one word
            if len(line) == 1:

                new_line = line[0] + " " * spaces

                result.append(new_line)

                continue


            # Number of gaps
            gaps = len(line) - 1

            # Spaces per gap
            space_each = spaces // gaps

            # Extra spaces
            extra = spaces % gaps

            new_line = ""

            for j in range(len(line) - 1):

                new_line += line[j]

                # Left gaps get extra spaces
                new_line += " " * (
                    space_each + (1 if j < extra else 0)
                )

            # Add last word
            new_line += line[-1]

            result.append(new_line)

        return result
    