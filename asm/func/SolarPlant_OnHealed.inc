	push {r4, lr}
	adds r3, r0, #0
	adds r4, r2, #0
	adds r4, #0xf4
	ldrb r0, [r4]
	cmp r0, #0
	bne _080A465C
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _080A465C
	ldr r0, _080A4664 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A4668 @ =0x00000942
	adds r0, r0, r1
	adds r1, r2, #0
	adds r1, #0xf0
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0x20
	strb r0, [r4]
	ldr r0, _080A466C @ =0x03002C44
	ldr r1, [r0]
	movs r0, #1
	strb r0, [r1, #0x19]
_080A465C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A4664: .4byte 0x030046A0
_080A4668: .4byte 0x00000942
_080A466C: .4byte 0x03002C44
