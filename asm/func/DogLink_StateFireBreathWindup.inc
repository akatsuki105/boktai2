	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _081C9A7C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C9A80
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081C9A82
	.align 2, 0
_081C9A7C: .4byte 0x0000046D
_081C9A80:
	movs r0, #0
_081C9A82:
	cmp r0, #0
	beq _081C9A8E
	adds r0, r5, #0
	movs r1, #0x11
	bl Enemy_PlayAnim
_081C9A8E:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	movs r1, #0
	strh r1, [r0, #8]
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	strh r1, [r0, #0xe]
	adds r0, r4, #0
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _081C9B16
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r2, r0, #6
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [sp]
	str r1, [sp, #4]
	cmp r2, #1
	beq _081C9ADA
	cmp r2, #1
	bgt _081C9AC8
	cmp r2, #0
	beq _081C9AD2
	b _081C9B10
_081C9AC8:
	cmp r2, #2
	beq _081C9AE2
	cmp r2, #3
	beq _081C9AFC
	b _081C9B10
_081C9AD2:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, #0x80
	b _081C9AE8
_081C9ADA:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, #0x80
	b _081C9B02
_081C9AE2:
	mov r0, sp
	ldrh r1, [r0]
	subs r1, #0xa0
_081C9AE8:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081C9AF8 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	b _081C9B10
	.align 2, 0
_081C9AF8: .4byte 0xFFFF0000
_081C9AFC:
	mov r0, sp
	ldrh r1, [r0, #4]
	subs r1, #0x80
_081C9B02:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081C9B4C @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
_081C9B10:
	mov r0, sp
	bl DogLink_SpawnSpark
_081C9B16:
	cmp r4, #0x1e
	ble _081C9B42
	ldr r4, _081C9B50 @ =DogLink_StateFireBreath
	movs r3, #0x25
	ldr r0, _081C9B54 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081C9B58 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_081C9B42:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081C9B4C: .4byte 0xFFFF0000
_081C9B50: .4byte DogLink_StateFireBreath
_081C9B54: .4byte 0x0000046D
_081C9B58: .4byte 0x0000046B
