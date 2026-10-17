	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _081E45AC @ =0x0000161A
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r3, _081E45B0 @ =0x00000BC4
	adds r0, r0, r3
	adds r5, r4, r0
	ldr r1, _081E45B4 @ =0x00001608
	adds r0, r4, r1
	ldr r0, [r0]
	ldr r3, _081E45B8 @ =0x0000159C
	adds r2, r4, r3
	adds r1, r5, #0
	bl FUN_08094d30
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E45C8
	bl FUN_08049f5c
	bl FUN_08049e5c
	ldr r1, _081E45BC @ =0x00001590
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl FUN_08094d48
	adds r0, r5, #0
	bl GetWeaponWearPose
	adds r2, r0, #0
	ldr r3, _081E45C0 @ =0x0000150C
	adds r0, r4, r3
	ldr r1, [r0, #8]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r0, #8]
	ldr r3, _081E45C4 @ =0x0000156C
	adds r1, r4, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r3, #0
	bl MainSprite_SetPose
	b _081E45D8
	.align 2, 0
_081E45AC: .4byte 0x0000161A
_081E45B0: .4byte 0x00000BC4
_081E45B4: .4byte 0x00001608
_081E45B8: .4byte 0x0000159C
_081E45BC: .4byte 0x00001590
_081E45C0: .4byte 0x0000150C
_081E45C4: .4byte 0x0000156C
_081E45C8:
	bl FUN_08049e5c
	ldr r1, _081E45E0 @ =0x0000150C
	adds r0, r4, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
_081E45D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E45E0: .4byte 0x0000150C
