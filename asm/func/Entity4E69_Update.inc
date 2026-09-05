	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	adds r0, #0x23
	ldrb r2, [r0]
	cmp r2, #1
	bne _0802232E
	strb r5, [r4, #0x1f]
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	beq _080222D0
	ldrh r0, [r4, #0x1a]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0x1a]
	strh r5, [r4, #0x1c]
	strb r1, [r4, #0x1e]
	strb r2, [r4, #0x1f]
_080222D0:
	ldrb r0, [r4, #0x1f]
	cmp r0, #0
	beq _08022316
	strh r5, [r4, #0x1c]
	b _080222E6
_080222DA:
	adds r0, r4, #0
	bl FUN_08022128
	ldrh r0, [r4, #0x1c]
	adds r0, #1
	strh r0, [r4, #0x1c]
_080222E6:
	movs r1, #0x18
	ldrsh r0, [r4, r1]
	movs r2, #0x1a
	ldrsh r1, [r4, r2]
	ldrh r2, [r4, #0x1c]
	bl FUN_0823a840
	adds r1, r0, #0
	cmp r1, #0
	bne _080222DA
	ldrh r5, [r4, #0x1c]
	cmp r5, #0
	bne _08022314
	ldrh r0, [r4, #0x20]
	cmp r0, #0
	beq _0802230C
	movs r1, #0
	bl Script_ExecById
_0802230C:
	adds r0, r4, #0
	adds r0, #0x23
	strb r5, [r0]
	b _0802233E
_08022314:
	movs r5, #1
_08022316:
	ldr r0, [r4, #0x68]
	cmp r0, #0
	beq _0802232E
	subs r0, #1
	str r0, [r4, #0x68]
	cmp r0, #0
	bne _0802232E
	adds r0, r4, #0
	adds r0, #0x78
	movs r1, #1
	bl FUN_08022488
_0802232E:
	adds r0, r4, #0
	bl FUN_0802216c
	cmp r5, #0
	beq _0802233E
	adds r0, r4, #0
	bl FUN_08022210
_0802233E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
