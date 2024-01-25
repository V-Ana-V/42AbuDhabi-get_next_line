# 42AbuDhabi-get_next_line
the code for the get_next_line project at 42 Abu Dhabi
## Edge cases to consider:

### 1. Empty Files:
The code should correctly handle empty files. If read returns 0 immediately (indicating EOF), buffer remains empty and buf_extract would return an empty string or handle it according to its implementation.

### 2. Files without Newlines:
The loop in read_line continues until a newline is found or EOF is reached. In the case of no newlines, it should read the entire file content and then return.

### 3. Files with Lines Longer than BUFFER_SIZE:
The loop in read_line should handle this by continuously appending to buffer until a newline is found or EOF is reached. This should work correctly as long as the memory allocation is successful.

### 4. Files with Lines Shorter than BUFFER_SIZE:
The read function will read up to BUFFER_SIZE bytes or until EOF. For shorter lines, it should work correctly, capturing the line and breaking out of the loop when a newline is encountered.

### 5. Multiple Calls to get_next_line on the Same File Descriptor:
The static variable buffer maintains the state between calls, allowing for successive lines to be read with multiple calls. This should handle sequential line reads correctly.

####The tests:
1) Francinette: https://github.com/xicodomingues/francinette
2) Tripoiulle: https://github.com/Tripouille/gnlTester
