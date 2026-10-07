	push {r4, lr}
	adds r2, r1, #0
	ldrh r1, [r2, #0x3e]
	subs r1, #1
	movs r3, #0
	strh r1, [r2, #0x3e]
	movs r4, #0xa
	movs r0, #0xa
	strh r0, [r2, #0x3a]
	lsls r1, r1, #0x10
	cmp r1, #0
	bgt _0800CE02
	strh r3, [r2, #0x3e]
	ldrb r0, [r2, #3]
	cmp r0, #1
	bhi _0800CE18
	ldrb r1, [r2, #2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2, #2]
	movs r0, #6
	strb r0, [r2, #3]
	str r3, [r2, #4]
	movs r0, #1
	strb r0, [r2, #1]
	adds r0, r2, #0
	adds r0, #0x41
	strb r4, [r0]
	adds r0, #0x4b
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	movs r0, #0x85
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #1
	b _0800CE1A
_0800CE02:
	adds r0, r2, #0
	adds r0, #0x41
	strb r4, [r0]
	adds r0, #0x4b
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	ldr r0, _0800CE20 @ =0x00000217
	bl PlaySound_082406e0
_0800CE18:
	movs r0, #0
_0800CE1A:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800CE20: .4byte 0x00000217
