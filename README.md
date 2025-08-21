# InnerRetina 
## it is necessary to install [NERUON][https://www.neuron.yale.edu/phpBB/viewforum.php?f=33]

## init_gui.hoc
### main script
- how to excecute: nrngui init_gui.hoc

## cell
### include the templates of each cell types

## mod
### mod file for ion channels, synapses, input currents
- how to use (make dll) 1: change current directory to "mod/"
- how to use (make dll) 2: execute "nrnivmodl" command
- how to use (make dll) 3: mv directory "arm64 (or "x86_64") to the same directory as init_gui.hoc

## src
### source files for setting parameters etc.
