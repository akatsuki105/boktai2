	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0x80
	lsls r1, r1, #6
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813CC6E
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0813CBE6
	cmp r1, #0
	blt _0813CBE6
	ldr r0, _0813CBEC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0813CBE6
	ldr r0, _0813CBF0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0813CBF4
_0813CBE6:
	movs r4, #0
	b _0813CC02
	.align 2, 0
_0813CBEC: .4byte 0x030046A8
_0813CBF0: .4byte 0x030046AC
_0813CBF4:
	ldr r0, _0813CC14 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0813CC02:
	mov r6, sp
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0813CC18
	adds r0, #4
	b _0813CC24
	.align 2, 0
_0813CC14: .4byte 0x030046A4
_0813CC18:
	ldr r0, _0813CC38 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0813CC24:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0813CC3C
	cmp r2, #2
	beq _0813CC40
	b _0813CC44
	.align 2, 0
_0813CC38: .4byte 0x030046A4
_0813CC3C:
	ldrb r0, [r6, #4]
	b _0813CC42
_0813CC40:
	ldrb r0, [r6]
_0813CC42:
	subs r1, r1, r0
_0813CC44:
	ldr r2, _0813CC78 @ =0x00000472
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, r1
	bge _0813CC6E
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r2, #0
	ldrsh r0, [r1, r2]
	rsbs r0, r0, #0
	movs r2, #0
	strh r0, [r1]
	adds r3, #4
	adds r1, r5, r3
	movs r3, #0
	ldrsh r0, [r1, r3]
	rsbs r0, r0, #0
	strh r0, [r1]
	strh r2, [r5, #0x10]
	strh r2, [r5, #0x14]
_0813CC6E:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813CC78: .4byte 0x00000472
