	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r2, _08242AE0 @ =0x08DA9E68
	ldrb r0, [r6]
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r0, r4, #0
	adds r1, r1, r2
	ldm r1!, {r2, r3, r5}
	stm r0!, {r2, r3, r5}
	ldm r1!, {r2, r3, r5}
	stm r0!, {r2, r3, r5}
	ldm r1!, {r2, r3, r5}
	stm r0!, {r2, r3, r5}
	ldrh r0, [r6, #2]
	strh r0, [r4, #6]
	movs r0, #1
	ldrsb r0, [r6, r0]
	strh r0, [r4, #8]
	ldrb r0, [r6, #4]
	cmp r0, #0
	bne _08242AE4
	movs r0, #0
	strb r0, [r4, #0xc]
	movs r2, #1
	adds r1, r4, #0
	adds r1, #0xc
	movs r3, #0
_08242AD4:
	adds r0, r1, r2
	strb r3, [r0]
	adds r2, #1
	cmp r2, #0xb
	ble _08242AD4
	b _08242AFA
	.align 2, 0
_08242AE0: .4byte 0x08DA9E68
_08242AE4:
	movs r2, #0
	adds r5, r4, #0
	adds r5, #0xc
	adds r3, r6, #4
_08242AEC:
	adds r0, r5, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #0xb
	ble _08242AEC
_08242AFA:
	adds r3, r6, #0
	adds r1, r4, #0
	movs r2, #2
_08242B00:
	ldr r0, [r3, #0x10]
	str r0, [r1, #0x18]
	adds r3, #4
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _08242B00
	pop {r4, r5, r6}
	pop {r0}
	bx r0
