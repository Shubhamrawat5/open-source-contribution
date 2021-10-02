class Acronym {
  String abbreviate(String fullForm) {
    RegExp re = RegExp(r"[a-zA-Z]+");
    return re
        .allMatches(fullForm)
        .map((e) => e.group(0)[0].toUpperCase())
        .join();
  }
}
