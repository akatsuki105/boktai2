	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	ldr r0, _08234E10 @ =0x030046A4
	ldr r0, [r0]
	ldr r2, [r0, #0x10]
	ldrh r0, [r2]
	cmp r5, r0
	bhs _08234E0A
	lsls r0, r5, #2
	adds r0, #4
	adds r1, r2, r0
	adds r6, r1, #0
	ldrb r0, [r1]
	cmp r0, #0
	bne _08234E14
_08234E0A:
	movs r0, #0
	b _08234E36
	.align 2, 0
_08234E10: .4byte 0x030046A4
_08234E14:
	ldrb r1, [r1]
	cmp r3, r1
	blo _08234E1C
	movs r3, #0
_08234E1C:
	ldrh r0, [r6, #2]
	adds r1, r2, r0
	movs r0, #0
	strb r5, [r4]
	strb r7, [r4, #1]
	strb r3, [r4, #2]
	strb r0, [r4, #3]
	str r6, [r4, #4]
	ldrb r0, [r4, #2]
	lsls r0, r0, #3
	adds r0, r1, r0
	str r0, [r4, #8]
	movs r0, #1
_08234E36:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
