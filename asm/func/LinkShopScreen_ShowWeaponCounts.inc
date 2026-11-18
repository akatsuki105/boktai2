	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #8
	ldr r2, _081E345C @ =0x00001610
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E3460
	movs r0, #1
	b _081E3462
	.align 2, 0
_081E345C: .4byte 0x00001610
_081E3460:
	movs r0, #0
_081E3462:
	cmp r0, #0
	bne _081E3468
	b _081E3582
_081E3468:
	movs r6, #0
	bl CountSellableWeapons
	adds r4, r0, #0
	movs r2, #0
	cmp r4, #9
	ble _081E347E
_081E3476:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E3476
_081E347E:
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #0
	ble _081E349E
_081E3496:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E3496
_081E349E:
	movs r1, #0xca
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	bl CountSellableOrEmptySlots
	adds r4, r0, #0
	adds r2, r6, #0
	cmp r4, #9
	ble _081E34C4
_081E34BC:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E34BC
_081E34C4:
	movs r1, #0x89
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #0
	ble _081E34E4
_081E34DC:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E34DC
_081E34E4:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	ldr r1, _081E358C @ =0x00000BB4
	adds r0, r5, r1
	ldrb r4, [r0]
	adds r2, r6, #0
	cmp r4, #9
	ble _081E350A
_081E3502:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E3502
_081E350A:
	movs r3, #0xa1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #0
	ble _081E352A
_081E3522:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E3522
_081E352A:
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	ldr r1, _081E3590 @ =0x00000BB5
	adds r0, r5, r1
	ldrb r4, [r0]
	adds r2, r6, #0
	cmp r4, #9
	ble _081E3550
_081E3548:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E3548
_081E3550:
	movs r3, #0xb9
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #0
	ble _081E3570
_081E3568:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E3568
_081E3570:
	movs r1, #0xad
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, _081E3588 @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
_081E3582:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E3588: .4byte 0x00000AA8
_081E358C: .4byte 0x00000BB4
_081E3590: .4byte 0x00000BB5
