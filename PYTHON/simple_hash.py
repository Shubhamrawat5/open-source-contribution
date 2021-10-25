import hashlib

string = "hash"

md5 = hashlib.md5(string.encode())

print md5.hexdigest()
