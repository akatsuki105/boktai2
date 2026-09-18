	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x44
	movs r5, #0
	ldr r7, _08060124 @ =0x085ABAA4
_080600F0:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _08060114
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
_08060114:
	adds r5, #1
	adds r4, #0x3c
	cmp r5, #0x1f
	ble _080600F0
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08060124: .4byte 0x085ABAA4
