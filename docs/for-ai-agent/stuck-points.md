# Stuck points

A log of where `/decomp-func` got stuck on a function without reaching
MATCHING — not what worked (see `agbcc-quirks.md` /
`c-programmer-habits.md` for that), but where progress stalled and why.

**Why this exists:** a single stuck function might just be a hard function.
The same *kind* of stuck point recurring across multiple functions is a
different signal — it usually means something systemic (a missing idiom, a
tooling gap, a wrong struct layout) rather than bad luck on each individual
function. Check this file for a matching symptom before spending a fresh
round of manual iteration on a new function that looks similar.

**When to add an entry:** whenever a function is left at NON_MATCH/paused
without reaching a match — whether because the 10-iteration cap
(SKILL.md Step 7) was hit, or the user explicitly paused it. Not needed for
functions that end up MATCHING.

## Entry format

Just the function name (and file). No detail write-up.

## Log

- `VM_DecodeValue` (`src/vm.c`)
- `VM_MountScriptDirectory` (`src/vm.c`)
- `VM_ConvertEucJpToSjis` (`src/vm_ctrl1.c`)
- `FUN_08231698` (`src/vm.c`)
- `VM_Ctrl_Switch` (`src/vm_ctrl1.c`)
- `FUN_0822ea60` (`src/video.c`)
- `FUN_0822e920` (`src/video.c`)
- `FUN_0822f364` (`src/sprite_0822f284.c`)
- `FUN_0822bd28` (`src/video.c`)
- `FUN_082438e0` (`src/eeprom.c`)
- `FUN_08243828` (`src/eeprom.c`)
- `Rfu_FindPartnerByRecord` (`src/rfu_0824beb8.c`)
- `Demo_HandleMsgs` (`src/msgbus.c`)
- `FUN_082376a4` (`src/utility_08237468.c`)
- `Sio_CheckConnection` (`src/utility_08237468.c`)
- `Sio_Start` (`src/utility_08237468.c`)
- `FreezeEffect_SpawnSubParticle` (`src/freeze_effect.c`)
- `FreezeEffect_StateVanish` (`src/freeze_effect.c`)
- `LevelUpper_EmitWeaponLevelUpEffect` (`src/level_upper.c`)
- `TryPlayerLevelUp` (`src/level_upper.c`)
- `FUN_082372cc` (`src/sprite_082370cc.c`)
- `FUN_08236fac` (`src/code_08236f18.c`)
- `FUN_082363c4` (`src/hitbox.c`)
- `Hitbox_CheckOverlap` (`src/hitbox.c`)
- `FUN_08013288` (`src/entity_ec96.c`)
- `EntityEC96_Update` (`src/entity_ec96.c`)
- `Entity95A8_Update` (`src/solar_bamboo.c`)
- `MapPltt_PushCommand` (`src/entity_4ae5.c`)
- `ScalePltt` (`src/entity_4ae5.c`)
- `FUN_08001c10` (`src/entity_4ae5.c`)
- `MapPltt_SetFile` (`src/entity_4ae5.c`)
- `BlendPltt2` (`src/entity_4ae5.c`)
- `MapPltt_BlendRows` (`src/entity_4ae5.c`)
- `Entity4AE5_Init` (`src/entity_4ae5.c`)
- `Entity4AE5_Update` (`src/entity_4ae5.c`)
- `FUN_08009278` (`src/entity_83b2.c`)
- `Entity83B2_Destroy` (`src/entity_83b2.c`)
- `Entity83B2_Update` (`src/entity_83b2.c`)
- `VM_Sub883A` (`src/entity_83b2.c`)
- `FUN_0823bd14` (`src/camera.c`)
- `Camera_Translate` (`src/camera.c`)
- `FUN_0823c928` (`src/camera.c`)
- `FUN_08230134` (`src/sprite_0822f650.c`) — ARM ステート
- `MainSprite_SetAnimFrame` (`src/sprite_082370cc.c`)
- `MainSprite_GetAnimDuration` (`src/sprite_082370cc.c`)
- `ParticleShadow_FollowGround` (`src/shadow_0801381c.c`)
- `AuxShadow_FollowGround` (`src/shadow_08013b68.c`)
- `SignalStrengthIcon_Refresh` (`src/signal_strength_icon.c`)
- `SignalStrengthIcon_SetStrength` (`src/signal_strength_icon.c`)
- `Entity0800a89c_PurifyDarkBugs` (`src/entity_0800a89c.c`)
- `Entity0800a89c_UpdateCollectedBug` (`src/entity_0800a89c.c`)
- `FUN_081d0864` (`src/entity_081d0e20.c`)
- `Entity081d0e20_AllocElem` (`src/entity_081d0e20.c`)
- `Entity081d0e20_Destroy` (`src/entity_081d0e20.c`)
- `FUN_081d0c6c` (`src/entity_081d0e20.c`)
- `FUN_081d0718` (`src/entity_081d0e20.c`)
- `FUN_080ecf18` (`src/enemy_manager.c`)
- `FUN_080edce8` (`src/enemy_manager.c`)
- `FUN_080ede14` (`src/enemy_manager.c`)
- `FUN_080ed020` (`src/enemy_manager.c`)
- `FUN_080ed9d0` (`src/enemy_manager.c`)
