# Castlevania 64 - Landmine (Custom Actor)

This repository contains an example custom actor for the Castlevania (Nintendo 64) videogame, fully created from scratch.
The actor in question is a landmine, which triggers an explosion when hit, instant-killing the player.

The repository includes the assets and code for the landmine custom actor, plus the complete assets for a modified version of the unused Test Grid map, which includes 5 instances of this actor defined.
This also contains various scripts that will inject all this data into an original Castlevania (USA v1.0) ROM.

* [Video](https://www.youtube.com/watch?v=9WHebJklzIo)

## Building (Ubuntu)
### Prerequisites
* [IDO 7.1](https://github.com/decompals/ido-static-recomp/releases) (place `cc` and all the other files in `tools/ido71`)
* [nOVL](https://github.com/Bsquo/nOVL/releases) (place `novl` in `tools/nOVL`)
* `mips64-ld`
* [ZAPD](https://github.com/NEstelami/ZAPD) (place `ZAPD.out` in `tools`)
* [LZKN64](https://github.com/Fluvian/lzkn64) (place `lzkn64` in `tools`)
* Python 3

### Build
* Place a Castlevania (USA v1.0) ROM (`sha1: 989A28782ED6B0BC489A1BBBD7BEC355D8F2707E`) in the root of the project and rename it to `cv64_custom_actor_test.z64`. Then, run `make`
* Said ROM should now be patched with the custom actor and the modded version of the Test Grid map with the 5 landmines. If you can't run the ROM, you might need to update the patched ROM's CRC using [rn64crc](https://www.smwcentral.net/?p=section&a=details&id=8799).

Enable the following GameShark code to warp to the Test Grid map:

```
81389EE0 001D
81389EE2 0000
81389EFE 0000
```

## Credits:
* ZZT32, ariahiro64, z64me, sauraen: For [nOVL](https://github.com/z64tools/nOVL), which this repository uses to convert textures from PNG to raw data.
* CrookedPoe, z64me: For [z64ovl](https://github.com/CrookedPoe/z64ovl). Although intended for the Zelda 64 games, they provide examples for rebuilding overlays.
* Fluvian: For [LZKN64](https://github.com/Fluvian/lzkn64), which can decompress and compress back files in the Nagano format, used in several Konami N64 games.
* [OoT Decomp](https://github.com/zeldaret/oot): For the Ultra 64 headers.

## More information:
* [Castlevania 64 - Research Spreadsheets](https://docs.google.com/spreadsheets/d/1nzh_nFf26oVZy6uWeNYiYGXAto6Yz3xypZwWqwJBBJQ/edit#gid=74717405)
* [CV64&LoD Speedruns Discord.](https://discord.gg/eKht382) Discord server for the CV64 / LoD community. Go to the #tech-talk channel for reverse engineering discussion.