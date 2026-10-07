	push {r4, r5, lr}
	adds r4, r1, #0
	ldrb r5, [r4, #3]
	cmp r5, #1
	bne _0800CD24
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0800CCE6
	ldr r0, _0800CD20 @ =0x00000219
	bl PlaySound_082406e0
_0800CCE6:
	ldrb r1, [r4, #2]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r4, #2]
	adds r0, r4, #0
	adds r0, #0x42
	ldrh r0, [r0]
	strh r0, [r4, #0x38]
	movs r0, #3
	strb r0, [r4, #3]
	str r2, [r4, #4]
	strb r5, [r4, #1]
	adds r1, r4, #0
	adds r1, #0x41
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	movs r0, #1
	b _0800CD64
	.align 2, 0
_0800CD20: .4byte 0x00000219
_0800CD24:
	movs r0, #1
	ldrb r1, [r4, #2]
	ands r0, r1
	cmp r0, #0
	bne _0800CD62
	cmp r1, #0
	bne _0800CD38
	ldr r0, _0800CD6C @ =0x00000219
	bl PlaySound_082406e0
_0800CD38:
	ldrb r1, [r4, #2]
	movs r0, #1
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r4, #2]
	adds r0, r4, #0
	adds r0, #0x42
	ldrh r0, [r0]
	strh r0, [r4, #0x38]
	adds r1, r4, #0
	adds r1, #0x41
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
_0800CD62:
	movs r0, #0
_0800CD64:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800CD6C: .4byte 0x00000219
