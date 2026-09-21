	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrb r0, [r7, #0xf]
	cmp r0, #0
	beq _08005F42
	subs r0, #1
	strb r0, [r7, #0xf]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08005F06
	ldr r1, [r7, #0x2c]
	ldrh r0, [r7, #0x10]
	strh r0, [r1]
	ldr r1, [r7, #0x2c]
	ldrh r0, [r7, #0x12]
	strh r0, [r1, #4]
	b _08005F42
_08005F06:
	ldr r6, _08005F48 @ =0x0203B400
	ldr r3, _08005F4C @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r5, _08005F50 @ =0x000003FF
	ands r1, r5
	str r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ldr r4, [r7, #0x2c]
	movs r2, #0xf
	ands r0, r2
	ldrh r2, [r7, #0x10]
	adds r0, r0, r2
	subs r0, #4
	strh r0, [r4]
	adds r1, #1
	ands r1, r5
	str r1, [r3]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ldr r2, [r7, #0x2c]
	movs r1, #7
	ands r0, r1
	ldrh r7, [r7, #0x12]
	adds r0, r0, r7
	subs r0, #4
	strh r0, [r2, #4]
_08005F42:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08005F48: .4byte 0x0203B400
_08005F4C: .4byte 0x030046B8
_08005F50: .4byte 0x000003FF
