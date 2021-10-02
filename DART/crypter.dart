class Crypter {
  static const _THRESHOLD = 255;

  static String encrypt(String value, String key) {
    if (key == null || key.isEmpty || value == null) return "";

    final List<int> encrypted = [];
    String revKey = key.split('').reversed.join();
    final keyLimit = revKey.length;

    for (int i = 0; i < value.length; i++) {
      encrypted.add(
        (value.codeUnitAt(i) + revKey.codeUnitAt(i % keyLimit)) % _THRESHOLD,
      );
    }
    return String.fromCharCodes(encrypted);
  }

  static String decrypt(String encrypted, String key) {
    final List<int> decrypted = [];
    String revKey = key.split('').reversed.join();
    final keyLimit = revKey.length;

    for (int i = 0; i < encrypted.length; i++) {
      decrypted.add(
        (encrypted.codeUnitAt(i) - revKey.codeUnitAt(i % keyLimit)) %
            _THRESHOLD,
      );
    }
    return String.fromCharCodes(decrypted);
  }
}
