# wong_kar_wai
Terminal 2048

Available options :

- `-H` and `-W` for height and width respectively. Can't be > 30, otherwise will be set at `DEFAULT_HEIGHT` and `DEFAULT_WIDTH`
- `-s` for seed
- `-b` to set the base
- `-b` to set the win value

Default values are set in `wong.h` :

```
...
# define DEFAULT_BASE 2
# define DEFAULT_WIDTH 4
# define DEFAULT_HEIGHT 4
# define DEFAULT_WIN_VALUE 2048
...
```

### INSTALL AND PLAY
```
$ make
$ ./game_2048
```
