	push {r4, r5, lr}
	sub sp, #0x14
	adds r4, r0, #0
	ldr r0, _080E176C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080E1770 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r4, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, r1
	bgt _080E1774
	adds r0, r4, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	cmp r0, r1
	blt _080E1774
	movs r5, #1
	ldrh r0, [r4, #0x28]
	cmp r0, #1
	beq _080E17BC
	b _080E177C
	.align 2, 0
_080E176C: .4byte 0x030046A0
_080E1770: .4byte 0x00000942
_080E1774:
	movs r5, #0
	ldrh r0, [r4, #0x28]
	cmp r0, #0
	beq _080E17BC
_080E177C:
	str r1, [sp]
	ldr r0, [r4, #0x1c]
	str r0, [sp, #4]
	ldr r0, [r4, #0x20]
	str r0, [sp, #8]
	ldr r1, _080E17AC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r0, sp
	str r0, [r1, #4]
	cmp r5, #0
	beq _080E17B0
	ldrh r0, [r4, #0x18]
	cmp r0, #0
	beq _080E17BC
	bl FUN_082318ac
	movs r0, #1
	strh r0, [r4, #0x28]
	b _080E17BC
	.align 2, 0
_080E17AC: .4byte 0xFFFF0000
_080E17B0:
	ldrh r0, [r4, #0x1a]
	cmp r0, #0
	beq _080E17BC
	bl FUN_082318ac
	strh r5, [r4, #0x28]
_080E17BC:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
