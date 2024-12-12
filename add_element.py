def plusOne(digits):
    # Start from the rightmost digit
    n = len(digits)

    for i in range(n - 1, -1, -1):
        # If the current digit is less than 9, add 1 and return the result
        if digits[i] < 9:
            digits[i] += 1
            return digits

# Otherwise, set it to 0 and continue to the next more significant digit
        digits[i] = 0

# If all digits were 9, add a new leading 1 at the beginning
    return [1] + digits
