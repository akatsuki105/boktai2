	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r7, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025E6E
	movs r3, #0
	strb r3, [r1]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #2
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	movs r3, #4
	bl Boss_PlayAnim
	ldr r2, _08025E9C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08025EA0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08025EA4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #3
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_08024068
	movs r0, #0xee
	lsls r0, r0, #2
	bl PlaySound_0824078c
_08025E6E:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08025E94
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08025EA8
_08025E94:
	adds r0, r4, #0
	bl FUN_080240b4
	b _08025F7E
	.align 2, 0
_08025E9C: .4byte 0x030046B8
_08025EA0: .4byte 0x000003FF
_08025EA4: .4byte 0x0203B400
_08025EA8:
	ldr r2, _08025EE8 @ =0x0000027A
	adds r0, r4, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08025EEC @ =0x00000FFF
	cmp r1, r0
	ble _08025F4A
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r3, [r0]
	adds r0, r4, #0
	adds r0, #0xc0
	ldr r1, [r0]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r0, [r0]
	movs r2, #0
	cmp r1, r0
	bhi _08025ED4
	movs r2, #1
_08025ED4:
	cmp r2, #0
	beq _08025EF0
	ldrh r1, [r3]
	adds r0, r4, #0
	adds r0, #0x50
	strh r1, [r0]
	ldrh r1, [r3, #4]
	adds r0, #4
	strh r1, [r0]
	b _08025F4A
	.align 2, 0
_08025EE8: .4byte 0x0000027A
_08025EEC: .4byte 0x00000FFF
_08025EF0:
	adds r0, r4, #0
	adds r0, #0xc8
	ldr r2, _08025F1C @ =0x0000055C
	adds r1, r4, r2
	adds r3, r4, #0
	adds r3, #0x58
	ldrb r5, [r0]
	ldrh r6, [r1]
	ldr r2, _08025F20 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08025F24
	asrs r1, r0, #0xc
	b _08025F2A
	.align 2, 0
_08025F1C: .4byte 0x0000055C
_08025F20: .4byte gSineTable
_08025F24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08025F2A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08025F42
	asrs r0, r0, #0xc
	b _08025F48
_08025F42:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08025F48:
	strh r0, [r3, #4]
_08025F4A:
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0x80
	bls _08025F5C
	subs r0, #0x80
	strh r0, [r1]
	b _08025F7E
_08025F5C:
	movs r2, #0
	movs r0, #0x80
	strh r0, [r1]
	ldr r1, _08025F88 @ =FUN_08025f8c
	movs r0, #8
	adds r3, r4, #0
	adds r3, #0xa3
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_08025F7E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08025F88: .4byte FUN_08025f8c
