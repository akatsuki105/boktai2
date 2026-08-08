	push {r4, lr}
	adds r4, r0, #0
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080F3538 @ =0x030047A4
	ldr r1, _080F353C @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _080F3510
	movs r1, #4
	ldr r0, _080F3540 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F354C
_080F3510:
	movs r1, #2
	movs r3, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _080F3544 @ =0x00000469
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r3, [r0]
	adds r1, #0x1a
	adds r0, r4, r1
	str r2, [r0]
	ldr r2, _080F3548 @ =0x0000046C
	adds r0, r4, r2
	strb r3, [r0]
	b _080F3564
	.align 2, 0
_080F3538: .4byte 0x030047A4
_080F353C: .4byte 0x030047A0
_080F3540: .4byte 0x03002BC0
_080F3544: .4byte 0x00000469
_080F3548: .4byte 0x0000046C
_080F354C:
	ldr r1, _080F356C @ =0x0000046A
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _080F3570 @ =0x00000634
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080F3564:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080F356C: .4byte 0x0000046A
_080F3570: .4byte 0x00000634
