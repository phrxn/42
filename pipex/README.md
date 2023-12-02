# pipex

<p align="center">
  <img src="https://raw.githubusercontent.com/phrxn/phrxn/master/42/badges/pipexm.png" />
</p>

## Compile

``make`` to compile the mandatory <br>
``make bonus`` to compile the project with bonus

## Run and Usage Mandatory

```
Usage:./pipex file1 "cmd1" "cmd2" file2

file1: input file to first cmd1
cmd1: first command for pipe with or without parameters examples: "ls"  "ls -l"
cmd2: last command for pipe with or without parameters examples: "ls"  "wc -c"
file2: output file to last cmd2
```

## Run and Usage Bonus

```
Usage: ./pipex {[here_doc LIMITER] | [file_in]} cmd1 cmd2 [... cmdn] file_out
```
