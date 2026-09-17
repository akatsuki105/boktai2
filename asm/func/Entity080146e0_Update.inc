	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080145C4 @ =0x030044BC
	ldr r0, [r0]
	cmp r0, #0
	beq _080145C8
	adds r4, r5, #0
	adds r4, #0x24
	movs r6, #5
_080145A6:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080145B4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0801442c
_080145B4:
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r6, #1
	cmp r6, #0
	bge _080145A6
	b _080145F8
	.align 2, 0
_080145C4: .4byte 0x030044BC
_080145C8:
	adds r4, r5, #0
	adds r4, #0x24
	movs r6, #5
_080145CE:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080145EC
	ldrb r0, [r4, #2]
	cmp r0, #8
	bhi _080145E4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08014148
	b _080145EC
_080145E4:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08014094
_080145EC:
	movs r0, #0xe2
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r6, #1
	cmp r6, #0
	bge _080145CE
_080145F8:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
