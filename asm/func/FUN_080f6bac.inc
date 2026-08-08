	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r2, _080F6BC0 @ =0x000001DF
	adds r1, r6, r2
	ldrb r1, [r1]
	cmp r1, #0xa
	beq _080F6BC4
	movs r0, #0
	b _080F6C5C
	.align 2, 0
_080F6BC0: .4byte 0x000001DF
_080F6BC4:
	ldr r7, _080F6C64 @ =0x0000049C
	adds r1, r6, r7
	ldr r1, [r1]
	movs r2, #0x80
	lsls r2, r2, #7
	ands r1, r2
	cmp r1, #0
	beq _080F6C5C
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r2, #0xc9
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r4, #0
	movs r5, #0
	strh r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080e5098
	adds r0, r6, #0
	bl FUN_080e499c
	movs r7, #0xc1
	lsls r7, r7, #1
	adds r2, r6, r7
	ldr r0, _080F6C68 @ =0xFFFFF634
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r3, #2
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldrh r1, [r2]
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #3
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _080F6C6C @ =0x00000469
	adds r0, r6, r1
	strb r4, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r6, r1
	str r5, [r0]
	adds r7, #2
	adds r1, r6, r7
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x26
	strh r0, [r1]
	ldrh r0, [r2]
	ands r0, r3
	cmp r0, #0
	beq _080F6C5A
	ldr r1, _080F6C70 @ =0x00000454
	adds r0, r6, r1
	ldr r0, [r0]
	ldrh r2, [r6]
	movs r1, #3
	bl FUN_080d9a9c
_080F6C5A:
	movs r0, #1
_080F6C5C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080F6C64: .4byte 0x0000049C
_080F6C68: .4byte 0xFFFFF634
_080F6C6C: .4byte 0x00000469
_080F6C70: .4byte 0x00000454
