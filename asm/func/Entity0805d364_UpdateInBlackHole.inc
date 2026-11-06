	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805CBCE
	movs r0, #0
	strb r0, [r4]
	movs r1, #0x1c
	ldrsh r0, [r4, r1]
	movs r2, #0x14
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #0x20
	ldrsh r1, [r4, r3]
	movs r5, #0x18
	ldrsh r2, [r4, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, _0805CBE0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805CBE4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805CBE8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r4, #7]
_0805CBCE:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	bne _0805CBEC
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805CD00
	.align 2, 0
_0805CBE0: .4byte 0x030046B8
_0805CBE4: .4byte 0x000003FF
_0805CBE8: .4byte 0x0203B400
_0805CBEC:
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _0805CC2C
	ldr r3, _0805CC20 @ =0x0203B400
	ldr r1, _0805CC24 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0805CC28 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r4, #6]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	b _0805CC2E
	.align 2, 0
_0805CC20: .4byte 0x0203B400
_0805CC24: .4byte 0x030046B8
_0805CC28: .4byte 0x000003FF
_0805CC2C:
	subs r0, #1
_0805CC2E:
	strb r0, [r4, #7]
	adds r3, r4, #0
	adds r3, #0x14
	movs r5, #0x1c
	ldrsh r2, [r4, r5]
	movs r1, #0x14
	ldrsh r0, [r4, r1]
	subs r2, r2, r0
	movs r5, #0x20
	ldrsh r0, [r4, r5]
	movs r5, #4
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r6, r1, r0
	ldrh r1, [r4, #0x16]
	movs r5, #0x16
	ldrsh r0, [r4, r5]
	movs r5, #0x1e
	ldrsh r2, [r4, r5]
	adds r5, r3, #0
	cmp r0, r2
	ble _0805CC68
	subs r0, r1, #1
	b _0805CC6E
_0805CC68:
	cmp r0, r2
	bge _0805CC70
	adds r0, r1, #1
_0805CC6E:
	strh r0, [r4, #0x16]
_0805CC70:
	ldr r0, _0805CC98 @ =0x00000FFF
	cmp r6, r0
	bhi _0805CCE4
	mov r3, sp
	ldrb r6, [r4, #6]
	ldr r2, _0805CC9C @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _0805CCA0
	asrs r1, r0, #0xc
	b _0805CCA6
	.align 2, 0
_0805CC98: .4byte 0x00000FFF
_0805CC9C: .4byte gSineTable
_0805CCA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805CCA6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _0805CCC0
	asrs r0, r0, #0xc
	b _0805CCC6
_0805CCC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CCC6:
	strh r0, [r3, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x14]
	adds r0, r0, r3
	strh r0, [r4, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r5, #4]
	adds r0, r0, r3
	strh r0, [r5, #4]
_0805CCE4:
	adds r0, r4, #0
	adds r0, #0x7c
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl Entity0805d364_SetElemAnim
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
_0805CD00:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
