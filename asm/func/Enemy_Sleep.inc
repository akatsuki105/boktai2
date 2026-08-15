	push {lr}
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _080ED82C
	bl FUN_080edda0
	adds r1, r0, #0
	cmp r1, #0
	beq _080ED82C
	ldr r2, _080ED830 @ =0x00000594
	adds r0, r1, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _080ED82C
	movs r3, #0xc8
	lsls r3, r3, #1
	adds r0, r1, r3
	ldrh r0, [r0]
	adds r3, #2
	adds r2, r1, r3
	strh r0, [r2]
	movs r0, #2
	subs r3, #0x10
	adds r2, r1, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_080ED82C:
	pop {r0}
	bx r0
	.align 2, 0
_080ED830: .4byte 0x00000594
