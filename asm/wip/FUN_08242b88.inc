	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	b _08242B92
_08242B90:
	adds r5, #1
_08242B92:
	cmp r5, #0xf
	bgt _08242BB0
	adds r0, r5, #0
	bl GetWeaponID
	cmp r0, #0
	bne _08242B90
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08242b6c
	ldrb r0, [r4, #1]
	cmp r0, #2
	bhi _08242BF6
	b _08242BB4
_08242BB0:
	movs r0, #0
	b _08242BF8
_08242BB4:
	ldrb r0, [r4, #1]
	ldr r1, _08242C00 @ =0x030046A0
	ldr r3, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	adds r2, r0, #0
	adds r2, #0x60
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08242BF6
	strh r5, [r2]
	ldrb r1, [r4, #1]
	cmp r1, #0
	bne _08242BF2
	adds r0, r3, #0
	adds r0, #0x58
	strh r1, [r0]
	ldr r0, _08242C04 @ =0x03002BE0
	ldr r4, [r0]
	cmp r4, #0
	beq _08242BF2
	adds r0, r5, #0
	bl GetWeapon
	adds r1, r0, #0
	adds r0, r4, #0
	bl weapon_08064664
_08242BF2:
	bl FUN_0809c28c
_08242BF6:
	movs r0, #1
_08242BF8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08242C00: .4byte 0x030046A0
_08242C04: .4byte 0x03002BE0
