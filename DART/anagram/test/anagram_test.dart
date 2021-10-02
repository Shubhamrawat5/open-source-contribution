import 'package:anagram/anagram.dart';
import 'package:test/test.dart';

final anagram = Anagram();

void main() {
  group("simple tests", simpleTests);

  group("slightly less simple tests", slightlyLessSimpleTests);

  group("more challenging tests", moreChallengingTests);

  /// Edge cases are scenarios that are problems that occur under specific conditions
  /// Read more: https://en.wikipedia.org/wiki/Edge_case
  group("edge case tests", edgeCaseTests);
}

void simpleTests() {
  test('no matches', () {
    final List<String> result = anagram.findAnagrams('diaper', <String>['hello', 'world', 'zombies', 'pants']);
    expect(result, equals(<String>[]));
  }, skip: false);
}

void slightlyLessSimpleTests() {
  test('detects two anagrams', () {
    final List<String> result = anagram.findAnagrams('master', <String>['stream', 'pigeon', 'maters']);
    expect(result, equals(<String>['stream', 'maters']));
  }, skip: true);

  test('does not detect anagram subsets', () {
    final List<String> result = anagram.findAnagrams('good', <String>['dog', 'goody']);
    expect(result, equals(<String>[]));
  }, skip: true);

  test('detects anagram', () {
    final List<String> result = anagram.findAnagrams('listen', <String>['enlists', 'google', 'inlets', 'banana']);
    expect(result, equals(<String>['inlets']));
  }, skip: true);

  test('detects three anagrams', () {
    final List<String> result =
        anagram.findAnagrams('allergy', <String>['gallery', 'ballerina', 'regally', 'clergy', 'largely', 'leading']);
    expect(result, equals(<String>['gallery', 'regally', 'largely']));
  }, skip: true);

  test('detects multiple anagrams with different case', () {
    final List<String> result = anagram.findAnagrams('nose', <String>['Eons', 'ONES']);
    expect(result, equals(<String>['Eons', 'ONES']));
  }, skip: true);
}

void moreChallengingTests() {
  test('does not detect non-anagrams with identical checksum', () {
    final List<String> result = anagram.findAnagrams('mass', <String>['last']);
    expect(result, equals(<String>[]));
  }, skip: true);

  test('detects anagrams case-insensitively', () {
    final List<String> result = anagram.findAnagrams('Orchestra', <String>['cashregister', 'Carthorse', 'radishes']);
    expect(result, equals(<String>['Carthorse']));
  }, skip: true);

  test('detects anagrams using case-insensitive subject', () {
    final List<String> result = anagram.findAnagrams('Orchestra', <String>['cashregister', 'carthorse', 'radishes']);
    expect(result, equals(<String>['carthorse']));
  }, skip: true);

  test('detects anagrams using case-insensitive possible matches', () {
    final List<String> result = anagram.findAnagrams('orchestra', <String>['cashregister', 'Carthorse', 'radishes']);
    expect(result, equals(<String>['Carthorse']));
  }, skip: true);
}

void edgeCaseTests() {
  test('does not detect an anagram if the original word is repeated', () {
    final List<String> result = anagram.findAnagrams('go', <String>['go Go GO']);
    expect(result, equals(<String>[]));
  }, skip: true);

  test('anagrams must use all letters exactly once', () {
    final List<String> result = anagram.findAnagrams('tapper', <String>['patter']);
    expect(result, equals(<String>[]));
  }, skip: true);

  test('words are not anagrams of themselves (case-insensitive)', () {
    final List<String> result = anagram.findAnagrams('BANANA', <String>['BANANA', 'Banana', 'banana']);
    expect(result, equals(<String>[]));
  }, skip: true);

  test('words other than themselves can be anagrams', () {
    final List<String> result = anagram.findAnagrams('LISTEN', <String>['Listen', 'Silent', 'LISTEN']);
    expect(result, equals(<String>['Silent']));
  }, skip: true);
}
