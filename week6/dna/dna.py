import csv
import sys


def main():

    if len(sys.argv) != 3:
        print("Needs 3 arguments")
        sys.exit(1)

    rows = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)

    with open(sys.argv[2], encoding='utf-8') as f:
        data = f.read()

    str_list = reader.fieldnames[1:]
    info = {}
    for str in str_list:
        info[str] = longest_match(data, str)

    for people in rows:
        match = True
        for str in str_list:
            if int(people[str]) != info[str]:
                match = False
                break
        if (match == True):
            print(people['name'])
            sys.exit(0)
    print('No match')


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
