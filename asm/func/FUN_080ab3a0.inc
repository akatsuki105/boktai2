	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r2, r1, #0
	movs r6, #0x9c
	lsls r6, r6, #1
	add r6, sb
	ldrb r0, [r6, #1]
	adds r0, #1
	strb r0, [r6, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080AB3C2
	b _080AB4DC
_080AB3C2:
	ldrb r1, [r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #8
	adds r7, r6, r0
	adds r1, r7, #0
	adds r1, #0x28
	movs r0, #1
	mov ip, r0
	movs r0, #1
	strb r0, [r1]
	str r2, [r7, #0x34]
	ldr r4, _080AB468 @ =0x0203B400
	ldr r5, _080AB46C @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r3, _080AB470 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r2, #0x7f
	ands r0, r2
	movs r2, #0xc0
	lsls r2, r2, #1
	mov r8, r2
	add r0, r8
	strh r0, [r7, #0x32]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r2, #0x2a
	adds r2, r2, r7
	mov r8, r2
	strb r0, [r2]
	adds r1, #1
	ands r1, r3
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	mov r1, ip
	ands r0, r1
	adds r0, #2
	adds r1, r7, #0
	adds r1, #0x2b
	strb r0, [r1]
	movs r0, #0
	strh r0, [r7, #0x2c]
	ldr r0, _080AB474 @ =FUN_080ab278
	str r0, [r7, #0x40]
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	movs r0, #0x9e
	lsls r0, r0, #1
	add r0, sb
	ldr r1, [r0]
	adds r0, r7, #0
	movs r2, #4
	bl FUN_0822dafc
	ldrh r3, [r7, #0x32]
	ldr r2, _080AB478 @ =0x085B0A08
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _080AB47C
	asrs r3, r0, #0xc
	b _080AB482
	.align 2, 0
_080AB468: .4byte 0x0203B400
_080AB46C: .4byte 0x030046B8
_080AB470: .4byte 0x000003FF
_080AB474: .4byte FUN_080ab278
_080AB478: .4byte 0x085B0A08
_080AB47C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080AB482:
	ldr r1, [r7, #0x34]
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r7, #0x18]
	ldrh r0, [r1, #2]
	strh r0, [r7, #0x1a]
	ldrh r3, [r7, #0x32]
	ldr r2, _080AB4AC @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	adds r2, r1, #0
	cmp r0, #0
	blt _080AB4B0
	asrs r1, r0, #0xc
	b _080AB4B6
	.align 2, 0
_080AB4AC: .4byte 0x085B0A08
_080AB4B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AB4B6:
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	movs r1, #0
	strh r0, [r7, #0x1c]
	movs r2, #1
	strb r2, [r7, #0xf]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bls _080AB4D2
	strb r1, [r6]
_080AB4D2:
	strb r1, [r6, #1]
	movs r0, #0x9d
	lsls r0, r0, #1
	add r0, sb
	strb r2, [r0]
_080AB4DC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
