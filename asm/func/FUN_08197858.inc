	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08197886
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x5a
	strb r1, [r0]
	movs r0, #1
	b _08197888
_08197886:
	movs r0, #0
_08197888:
	cmp r0, #0
	bne _0819788E
	b _0819798E
_0819788E:
	movs r6, #0
	ldr r1, _081979D0 @ =0x00000AC8
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r6, r2
	bge _08197906
	adds r5, r0, #0
_0819789C:
	movs r0, #0x2c
	adds r3, r6, #0
	muls r3, r0, r3
	adds r2, r4, r3
	ldr r1, _081979D4 @ =0x00000AFC
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x7c
	strh r1, [r0]
	ldr r1, _081979D8 @ =0x00000AFE
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r1, r2, #0
	adds r1, #0x7e
	strh r0, [r1]
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r2, #0
	adds r0, #0x80
	strh r1, [r0]
	ldr r1, _081979DC @ =0x00000AE6
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r2, #0
	adds r0, #0x66
	strb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x60
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #1
	bl Div
	lsls r2, r6, #2
	movs r3, #0x87
	lsls r3, r3, #3
	adds r1, r4, r3
	adds r1, r1, r2
	muls r0, r6, r0
	str r0, [r1]
	adds r6, #1
	ldrh r0, [r5]
	cmp r6, r0
	blt _0819789C
_08197906:
	movs r1, #0x8a
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	str r1, [r0]
	ldr r2, _081979E0 @ =0x00000449
	adds r0, r4, r2
	strb r1, [r0]
	movs r3, #0x89
	lsls r3, r3, #3
	adds r2, r4, r3
	movs r0, #5
	strb r0, [r2]
	movs r2, #0xcf
	lsls r2, r2, #4
	adds r0, r4, r2
	strh r1, [r0]
	movs r6, #0
	ldr r3, _081979D0 @ =0x00000AC8
	adds r0, r4, r3
	ldr r1, _081979E4 @ =FUN_08196a64
	mov sb, r1
	ldr r2, _081979E8 @ =FUN_081958b4
	mov sl, r2
	ldrh r3, [r0]
	cmp r6, r3
	bge _0819796E
	ldr r7, _081979EC @ =0x0000FFFB
	movs r1, #0xc3
	lsls r1, r1, #1
	adds r3, r4, r1
	adds r5, r4, #0
	ldr r2, _081979F0 @ =0x000002C6
	mov r8, r2
	mov ip, r0
_0819794C:
	ldrh r1, [r3]
	adds r0, r7, #0
	ands r0, r1
	strh r0, [r3]
	mov r0, r8
	adds r2, r5, r0
	ldrh r1, [r2]
	adds r0, r7, #0
	ands r0, r1
	strh r0, [r2]
	adds r3, #0x50
	adds r5, #0x50
	adds r6, #1
	mov r1, ip
	ldrh r1, [r1]
	cmp r6, r1
	blt _0819794C
_0819796E:
	ldr r2, _081979F4 @ =0x00000C4C
	adds r0, r4, r2
	mov r3, sb
	str r3, [r0]
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	mov r2, sl
	str r2, [r0]
	ldr r3, _081979F8 @ =0x00000CC3
	adds r1, r4, r3
	movs r0, #0
	strb r0, [r1]
	ldr r0, _081979FC @ =0x0000016F
	bl PlaySound_082406e0
_0819798E:
	adds r0, r4, #0
	bl FUN_08196378
	movs r6, #0
	ldr r1, _081979D0 @ =0x00000AC8
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r6, r0
	blt _081979A2
	b _08197A9E
_081979A2:
	movs r2, #0x8a
	lsls r2, r2, #3
	adds r7, r4, r2
	ldr r3, _08197A00 @ =gSineTable
	mov r8, r3
	mov sb, r8
	movs r0, #0x87
	lsls r0, r0, #3
	adds r5, r4, r0
_081979B4:
	ldr r0, [r5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r7]
	muls r0, r1, r0
	cmp r0, #0
	blt _08197A04
	asrs r1, r0, #0xa
	b _08197A0A
	.align 2, 0
_081979D0: .4byte 0x00000AC8
_081979D4: .4byte 0x00000AFC
_081979D8: .4byte 0x00000AFE
_081979DC: .4byte 0x00000AE6
_081979E0: .4byte 0x00000449
_081979E4: .4byte FUN_08196a64
_081979E8: .4byte FUN_081958b4
_081979EC: .4byte 0x0000FFFB
_081979F0: .4byte 0x000002C6
_081979F4: .4byte 0x00000C4C
_081979F8: .4byte 0x00000CC3
_081979FC: .4byte 0x0000016F
_08197A00: .4byte gSineTable
_08197A04:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08197A0A:
	movs r0, #0x2c
	adds r2, r6, #0
	muls r2, r0, r2
	adds r2, r4, r2
	ldr r3, _08197A40 @ =0x00000AFC
	adds r0, r4, r3
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0x7c
	strh r0, [r1]
	ldr r1, _08197A44 @ =0x00000AFE
	adds r0, r4, r1
	ldrh r0, [r0]
	adds r2, #0x7e
	strh r0, [r2]
	ldrb r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, [r7]
	muls r0, r1, r0
	cmp r0, #0
	blt _08197A48
	asrs r2, r0, #0xa
	b _08197A4E
	.align 2, 0
_08197A40: .4byte 0x00000AFC
_08197A44: .4byte 0x00000AFE
_08197A48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r2, r0, #0
_08197A4E:
	movs r0, #0x2c
	adds r1, r6, #0
	muls r1, r0, r1
	adds r1, r4, r1
	movs r3, #0xb0
	lsls r3, r3, #4
	adds r0, r4, r3
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r1, #0x80
	strh r0, [r1]
	movs r1, #0x89
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r0, [r5]
	adds r0, r0, r1
	str r0, [r5]
	cmp r0, #0xff
	ble _08197A90
	movs r2, #0xcf
	lsls r2, r2, #4
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0x46
	bls _08197A8A
	ldr r0, _08197AC8 @ =0x00000169
	bl PlaySound_082406e0
_08197A8A:
	ldr r0, [r5]
	subs r0, #0xff
	str r0, [r5]
_08197A90:
	adds r5, #4
	adds r6, #1
	ldr r3, _08197ACC @ =0x00000AC8
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r6, r0
	blt _081979B4
_08197A9E:
	ldr r1, _08197AD0 @ =0x00000C4C
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08197AAE
	adds r0, r4, #0
	bl _call_via_r1
_08197AAE:
	movs r2, #0xcf
	lsls r2, r2, #4
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08197AC8: .4byte 0x00000169
_08197ACC: .4byte 0x00000AC8
_08197AD0: .4byte 0x00000C4C
