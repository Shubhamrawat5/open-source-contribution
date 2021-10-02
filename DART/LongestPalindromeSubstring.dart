void main() {
  String s = "babad";

  print("Longest palindrome SubString : ${findString(s)}");
}

String findString(String s) {
  if (s == null || s.length < 1) {
    return "";
  }
  int startIndex = 0;
  int endIndex = 0;

  for (int i = 0; i < s.length; i++) {
    int len1 = checkPalindromeLengthFromMiddle(s, i, i);
    int len2 = checkPalindromeLengthFromMiddle(s, i, i + 1);
    int len = (len1 > len2) ? len1 : len2;

    if (len > endIndex - startIndex) {
      startIndex = i - ((len-1) ~/ 2);
      endIndex = i + (len ~/ 2);
    }
  }

  return s.substring(startIndex, endIndex+1);
}

int checkPalindromeLengthFromMiddle(String s, int leftIndex, int rightIndex) {
  if (s == null || leftIndex > rightIndex) {
    return 0;
  }

  while (leftIndex >= 0 && rightIndex < s.length && (s[leftIndex] == s[rightIndex])) {
    leftIndex--;
    rightIndex++;
  }

  return rightIndex - leftIndex - 1;
}
