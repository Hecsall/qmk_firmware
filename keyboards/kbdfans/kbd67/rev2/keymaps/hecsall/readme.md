# Hecsall's keymap for kbd67


## **Setup**
Follow the initial setup as per [QMK docs - Setup](https://beta.docs.qmk.fm/tutorial/newbs_getting_started).\
I'm using WSL 1 on Windows 10.

After the `qmk setup`, probably it will be asked to **clone submodules**, type `Y`, but that will probably fail with an error, after that run `make git-submodule` to correctly sync all the submodules needed by QMK.


## **Compile the firmware**
```sh
qmk compile -kb kbdfans/kbd67/rev2 -km hecsall
```
