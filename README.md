# DASBOB - Lindos Layout
This is my custom 3x6, 3 thumb cluster split keyboard layout. In this branch (knorwegian-layout), the keymap is designed for norwegian keyboard input language set on the OS. 
For a little build log see [my website](https://sjur.dev/assets/projects/keyboards/).

<img src="assets/dasbob-coffe.jpg" alt="Typing and coffe" width="50%"

## Compilation guide
To compile this keyboard layout, first install QMK locally: https://docs.qmk.fm/newbs_getting_started
Then, navigate to the `qmk_firmware/keyboards/` directory and clone this repository. 
```
cd ~/qmk_firmware/keyboards/ 
clone https://github.com/Apostrophel/qmk-dasbob-lindos dasbob
```
Check if QMK recognizes the new keyboard/layout with `qmk list-keyboards | grep dasbob`.

Complile the layout:
```
qmk compile -kb dasbob -km lindos
```

Now you can enter bootloader mode with the keyboard (double press reset button) and flash (drag and drop the compiled file)!

## Layout
This layout uses home row mods in the GASC (GUI, ALT, Shift, Control) order, Mod-tap for the three thumb cluster buttons, and combos for various brackets.
Its a pretty efficient layout (for me), minimising number of layers to keep track of. I have also designed all layer functionality for activly holding the 
layer button. The keyboard is returned to the base layer as soon as the mod-tap layer button is released. 

### Layers 
Other than the base layer with home row mods, there is the symbols/numbers layer (NUM) and the navigation layer (NAV).

### Abbreviations
SPC - Space
BSP - Back Space
psc - print screen
p.u - page up
p.d - page down
c.w - caps word
hom - home 

 
#### Base layer (BASE)
    Tap:                                                        Hold: 
       ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
       │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │           │   │   │   │   │   │       │   │   │   │   │   │
       ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
       │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ : │           │GUI│ALT│SHF│CTR│   │       │   │CTR│SHF│ALT│GUI│
       ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
       │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ _ │           │   │   │   │   │   │       │   │   │   │   │   │
       └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
                 ┌───┐                   ┌───┐                               ┌───┐                   ┌───┐
                 │ESC├───┐           ┌───┤DEL│                               │FUN├───┐           ┌───┤FUN│
                 └───┤SPC├───┐   ┌───┤BSP├───┘                               └───┤SYM├───┐   ┌───┤SYM├───┘
                     └───│TAB│   │RET├───┘                                       └───│NAV│   │NAV├───┘
                         └───┘   └───┘                                               └───┘   └───┘

##### Combo mappings for brackets
| Left Hand | Symbol | Right Hand | Symbol |
|-----------|--------|------------|--------|
| `d + f`   | `"`    | `j + k`    | `'`    |
| `s + f`   | `(`    | `j + l`    | `)`    |
| `a + f`   | `/`    | `j + :`    | `\`    |
| `x + v`   | `{`    | `m + .`    | `}`    |
| `w + r`   | `[`    | `u + o`    | `]`    |
| `q + r`   | `<`    | `u + p`    | `>`    |

#### Symbol numeric layer (SYM)
    Tap:                                                        Hold:
       ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
       │ @ │ ~ │ | │ ^ │   │       │   │ 7 │ 8 │ 9 │ ` │           │   │   │   │   │   │       │   │   │   │   │   │
       ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
       │ # │ % │ - │ + │ = │       │ 0 │ 4 │ 5 │ 6 │ $ │           │GUI│ALT│SHF│CTR│   │       │   │CTR│SHF│ALT│GUI│
       ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
       │c.w│ & │ ? │ ! │ * │       │ . │ 1 │ 2 │ 3 │ , │           │   │   │   │   │   │       │   │   │   │   │   │
       └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
                 ┌───┐                   ┌───┐                               ┌───┐                   ┌───┐
                 │ESC├───┐           ┌───┤DEL│                               │   ├───┐           ┌───┤   │
                 └───┤SPC├───┐   ┌───┤BSP├───┘                               └───┤FUN├───┐   ┌───┤FUN├───┘
                     └───│TAB│   │RET├───┘                                       └───│NAV│   │NAV├───┘
                         └───┘   └───┘                                               └───┘   └───┘

#### Navigation layer (NAV)
    Tap:                                                       Hold:                                                                                                                                                         
       ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐          ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
       │   │   │   │   │ 🕪│       │hom│p.u│p.d│end│ 🕪│          │   │   │   │   │   │       │   │   │   │   │   │
       ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤          ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
       │   │   │   │   │ 🕩│       │ ← │ ↑ │ ↓ │ → │ 🕩│          │   │   │   │   │   │       │   │   │   │   │   │
       ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤          ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
       │   │   │   │   │ 🕨│       │psc│   │   │   │ 🕨│          │   │   │   │   │   │       │   │   │   │   │   │
       └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘          └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
                 ┌───┐                   ┌───┐                              ┌───┐                   ┌───┐          
                 │ESC├───┐           ┌───┤DEL│                              │   ├───┐           ┌───┤   │          
                 └───┤SPC├───┐   ┌───┤BSP├───┘                              └───┤   ├───┐   ┌───┤   ├───┘          
                     └───│TAB│   │RET├───┘                                      └───│   │   │   ├───┘              
                         └───┘   └───┘                                              └───┘   └───┘                  
                                    * psc - print screen
#### Function layer (FUN)
    Tap:                                                
       ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
       │   │   │ æ │ ø │   │       │   │F7 │F8 │F9 │F10│
       ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
       │ å │   │c+-│c+p│a+4│       │   │F4 │F5 │F6 │F11│
       ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
       │   │   │   │   │uni│       │   │F1 │F2 │F3 │F12│
       └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
                 ┌───┐                   ┌───┐          
                 │ESC├───┐           ┌───┤DEL│          
                 └───┤SPC├───┐   ┌───┤BSP├───┘          
                     └───│TAB│   │RET├───┘              
                         └───┘   └───┘                  
       *uni = unicode switcher
       *c+-/p = these are ctrl+minus and ctrl+pluss shortcuts
       * a+4 - alt+f4

