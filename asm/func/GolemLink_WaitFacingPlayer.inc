	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	adds r5, r4, #0
	ldr r7, _081C0858 @ =0x0000046C
	adds r1, r4, r7
	ldrb r0, [r1]
	cmp r0, #0
	beq _081C0800
	movs r0, #0
	strb r0, [r1]
_081C0800:
	adds r0, r4, #0
	bl GolemLink_TryChaseHitTarget
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _081C0852
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	strb r0, [r5, #5]
	ldr r7, _081C085C @ =0x00000484
	adds r5, r4, r7
	ldr r0, [r5]
	cmp r0, #0x77
	ble _081C084C
	movs r1, #2
	movs r2, #5
	subs r7, #0x1c
	adds r0, r4, r7
	strb r3, [r0]
	adds r7, #1
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _081C0860 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	adds r7, #0x1b
	adds r0, r4, r7
	str r3, [r0]
	ldr r0, _081C0858 @ =0x0000046C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081C0864 @ =0x000006BC
	adds r0, r6, r1
	strh r3, [r0]
_081C084C:
	ldr r0, [r5]
	adds r0, #1
	str r0, [r5]
_081C0852:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C0858: .4byte 0x0000046C
_081C085C: .4byte 0x00000484
_081C0860: .4byte 0x0000046A
_081C0864: .4byte 0x000006BC
