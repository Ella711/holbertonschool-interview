# 0x09. UTF-8 Validation
## Details
 By: Carrie Ybay, Software Engineer at Holberton School Weight: 1Project will startOct 3, 2022 12:00 AM, must end byOct 7, 2022 12:00 AMwill be released atOct 5, 2022 12:00 AM An auto review will be launched at the deadline### Concepts
For this project, we expect you to look at this concept:
* [Python programming](https://intranet.hbtn.io/concepts/1143) 

## Resources
Read or watch :
* [UTF-8](https://intranet.hbtn.io/rltoken/qVyzvKu0K89D0Aiz2Ssvgw) 

* [Characters, Symbols, and the Unicode Miracle](https://intranet.hbtn.io/rltoken/fZDmbf_oigBn5Ziy7ai0pg) 

## Requirements
### General
* Allowed editors:  ` vi ` ,  ` vim ` ,  ` emacs ` 
* All your files will be interpreted/compiled on Ubuntu 14.04 LTS using  ` python3 `  (version 3.4.3)
* All your files should end with a new line
* The first line of all your files should be exactly  ` #!/usr/bin/python3 ` 
* A  ` README.md `  file, at the root of the folder of the project, is mandatory
* Your code should use the  ` PEP 8 `  style (version 1.7.x)
* All your files must be executable
## Tasks
### 0. UTF-8 Validation
          mandatory         Progress vs Score  Task Body Write a method that determines if a given data set represents a valid UTF-8 encoding.
* Prototype:  ` def validUTF8(data) ` 
* Return:  ` True `  if data is a valid UTF-8 encoding, else return  ` False ` 
* A character in UTF-8 can be 1 to 4 bytes long
* The data set can contain multiple characters
* The data will be represented by a list of integers
* Each integer represents 1 byte of data, therefore you only need to handle the 8 least significant bits of each integer
```bash
carrie@ubuntu:~/0x09-utf8_validation$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

validUTF8 = __import__('0-validate_utf8').validUTF8

data = [65]
print(validUTF8(data))

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print(validUTF8(data))

data = [229, 65, 127, 256]
print(validUTF8(data))

carrie@ubuntu:~/0x09-utf8_validation$

```
```bash
carrie@ubuntu:~/0x09-utf8_validation$ ./0-main.py
True
True
False
carrie@ubuntu:~/0x09-utf8_validation$

```
 Task URLs  Github information Repo:
* GitHub repository:  ` holbertonschool-interview ` 
* Directory:  ` 0x09-utf8_validation ` 
* File:  ` 0-validate_utf8.py ` 
 Self-paced manual review  Panel footer - Controls 
