	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _08148584 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08148588
	movs r0, #1
	b _0814858A
	.align 2, 0
_08148584: .4byte 0x030047A4
_08148588:
	movs r0, #0
_0814858A:
	cmp r0, #0
	beq _081485C0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08148630
	ldrb r0, [r1, #4]
	movs r3, #1
	rsbs r3, r3, #0
	cmp r0, #3
	bhi _081485A6
	adds r3, r0, #0
_081485A6:
	cmp r3, #0
	blt _08148630
	movs r2, #8
	ldr r1, _081485BC @ =0x03002BC0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r0, r2
	cmp r0, #0
	beq _081485CC
	b _08148630
	.align 2, 0
_081485BC: .4byte 0x03002BC0
_081485C0:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08148630
_081485CC:
	ldr r1, _08148610 @ =0x000004A4
	adds r0, r4, r1
	ldr r6, [r0]
	adds r7, r4, #0
	adds r7, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	adds r5, r0, #0
	adds r5, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	beq _08148614
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _08148614
	cmp r0, #2
	beq _0814860C
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0814860C:
	movs r0, #1
	b _08148624
	.align 2, 0
_08148610: .4byte 0x000004A4
_08148614:
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, _0814862C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08148624:
	cmp r0, #0
	beq _08148630
	movs r0, #1
	b _08148632
	.align 2, 0
_0814862C: .4byte 0xFFFFFDFF
_08148630:
	movs r0, #0
_08148632:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
