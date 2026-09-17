	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	ldr r0, _080020B4 @ =gEntity4AE5
	ldr r2, [r0]
	cmp r2, #0
	beq _080020AE
	ldr r0, _080020B8 @ =0x00000664
	adds r5, r2, r0
	ldr r1, [r5]
	cmp r1, #7
	bhi _080020AE
	lsls r1, r1, #1
	movs r7, #0xcd
	lsls r7, r7, #3
	adds r0, r2, r7
	adds r0, r0, r1
	strh r3, [r0]
	movs r3, #0
	cmp r3, r4
	bge _080020A4
	adds r7, r5, #0
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r5, r2, r0
_08002090:
	lsls r0, r3, #1
	ldr r1, [r7]
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r0, r5, r0
	ldm r6!, {r1}
	strh r1, [r0]
	adds r3, #1
	cmp r3, r4
	blt _08002090
_080020A4:
	ldr r7, _080020B8 @ =0x00000664
	adds r1, r2, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_080020AE:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080020B4: .4byte gEntity4AE5
_080020B8: .4byte 0x00000664
