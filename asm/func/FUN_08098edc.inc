	push {r4, lr}
	adds r3, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r0, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #5
	beq _08098F20
	ldr r4, _08098F1C @ =0x030046A0
	ldr r0, [r4]
	adds r2, r0, #0
	adds r2, #0x42
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r0, #0x93
	lsls r0, r0, #1
	cmp r1, r0
	ble _08098F0C
	movs r0, #0
	strh r0, [r2]
_08098F0C:
	ldr r0, [r4]
	adds r0, #0x42
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #7
	adds r0, r3, r2
	strh r1, [r0]
	b _08098F2A
	.align 2, 0
_08098F1C: .4byte 0x030046A0
_08098F20:
	movs r4, #0x80
	lsls r4, r4, #7
	adds r1, r3, r4
	movs r0, #0
	strh r0, [r1]
_08098F2A:
	movs r2, #0
	movs r1, #3
	ldr r4, _08098F44 @ =0x0000400B
	adds r0, r3, r4
_08098F32:
	strb r2, [r0]
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _08098F32
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08098F44: .4byte 0x0000400B
