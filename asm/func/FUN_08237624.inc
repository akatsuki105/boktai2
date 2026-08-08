	push {r4, r5, r6, r7, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r6, r3, #0
	ldr r3, [sp, #0x14]
	movs r7, #0
	ldrb r2, [r5]
	ldr r1, _08237644 @ =0x030044E0
	lsls r0, r0, #3
	adds r1, r0, r1
	ldrh r0, [r1, #2]
	ands r0, r4
	cmp r0, #0
	beq _08237648
	adds r2, r3, #0
	b _0823765A
	.align 2, 0
_08237644: .4byte 0x030044E0
_08237648:
	ldrh r0, [r1]
	ands r0, r4
	cmp r0, #0
	beq _08237658
	cmp r2, r3
	bge _0823765E
	adds r2, #1
	b _0823765A
_08237658:
	movs r2, #0
_0823765A:
	cmp r2, r3
	blt _08237662
_0823765E:
	movs r2, #0
	adds r7, r6, #0
_08237662:
	strb r2, [r5]
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
