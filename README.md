# InnerRetina (model of an inner retinal circuit)
## it is necessary to install [NEURON]([https://www.neuron.yale.edu/phpBB/viewforum.php?f=33](https://neuron.yale.edu/neuron/]).

## init.hoc
### main script

## createcells.hoc
### makes instances of cell models and adds input curents

## cell/
### contains templates of each cell type

## mod/
### contains mod files
- how to make library by using mod files, see how to use [NEURON]([https://www.neuron.yale.edu/phpBB/viewforum.php?f=33](https://nrn.readthedocs.io/en/8.2.6/)).

## src/
### files for setting model parameters and for writing ouput file
- parameters.hoc: sets model parameters
- in order to create fig.4 (simulations for normal, Trpm1KO, mGlur6KO, rd1 models),
- it is necessary to edit the corresponding part of this file.
